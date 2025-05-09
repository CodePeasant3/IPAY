#include "PredictionClient.h"
#include "opencv2/core/types.hpp"
#include "opencv2/opencv.hpp"
#include "tensorflow/core/framework/tensor.pb.h"
#include "tensorflow_serving/apis/get_model_metadata.pb.h"
#include "tensorflow_serving/apis/predict.pb.h"
#include "tensorflow_serving/apis/prediction_service.grpc.pb.h"
#include <algorithm>
#include <cassert>
#include <cmath>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/support/status.h>
#include <iterator>
#include <numeric>
#include <vector>

int PredictionClient::Init(const std::string &target,
                           const ::tensorflow::TensorProto &&tensor_input,
                           const ::tensorflow::TensorProto &&tensor_output,
                           const std::string &model_name /* = "dogcat" */) {

  assert(tensor_input.tensor_shape().dim_size() == 4);
  assert(tensor_output.tensor_shape().dim_size() == 3);

  // Step.0: Assign to value
  model_name_ = model_name;
  tensor_input_.CopyFrom(tensor_input);
  tensor_output_.CopyFrom(tensor_output);

  // Step.1: Create channel
  channel_ = ::grpc::CreateChannel(target, grpc::InsecureChannelCredentials());
  if (!channel_) {
    std::cerr << "Channel create failed" << std::endl;
    return -1;
  }

  // Step.2: Create stub
  stub_ = ::tensorflow::serving::PredictionService::NewStub(channel_);
  if (!stub_) {
    std::cerr << "Create new stub failed" << std::endl;
    return -1;
  }

  return 0;
}

int PredictionClient::GetModelMetadata(GetModelMetadataResponse *response) {

  // Step.1: 构建必要上下文
  ::grpc::ClientContext context;
  ::tensorflow::serving::GetModelMetadataRequest request;
  request.mutable_model_spec()->set_name(model_name_);
  request.mutable_metadata_field()->Add("signature_def");

  // Step.2: 调用stub函数
  auto status = stub_->GetModelMetadata(&context, request, response);
  if (!status.ok()) {
    std::cerr << "GetModelMetadata failed" << std::endl;
    return -1;
  }

  return 0;
}

std::string PredictionClient::Predict(cv::Mat &&image, float score /* = 0.5 */,
                              const std::string &save_path /* = {} */) {

  if (image.empty()) {
    std::cerr << "image is empty" << std::endl;
    return "0";
  }

  // TODO: 确定1和2对应的是w和h,分别是哪一个
  const int image_w = tensor_input_.tensor_shape().dim(1).size();
  const int image_h = tensor_input_.tensor_shape().dim(2).size();
  const int result_class = tensor_output_.tensor_shape().dim(1).size();
  const int result_num = tensor_output_.tensor_shape().dim(2).size();

  std::cout << "image_w: " << image_w << std::endl
            << "image_h: " << image_h << std::endl
            << "result_class: " << result_class << std::endl
            << "result_num: " << result_num << std::endl;

  // Step.1: 构造必要上下文
  ::grpc::ClientContext context;
  PredictRequest request;

  // Step.2: 构造请求数据
  request.mutable_model_spec()->set_name(model_name_);
  request.mutable_model_spec()->set_signature_name("serving_default");

  // Step.3 处理输入图像

  cv::Mat convert_mat(image_w, image_h, CV_32FC3);
  float scale = 0.0;
  int padding_top = 0, padding_left = 0;
  letterbox_preprocess(image, convert_mat, &scale, &padding_top, &padding_left,
                       image_w);

  // Step.4: 填充数据
  ::tensorflow::TensorProto tensor_proto(tensor_input_);
  const size_t data_size = convert_mat.total() * convert_mat.elemSize();
  tensor_proto.set_tensor_content((char *)(convert_mat.data), data_size);
  auto &inputs = *request.mutable_inputs();
  inputs["images"].CopyFrom(tensor_proto);

  // Step.5: 调用远程并返回
  ::tensorflow::serving::PredictResponse response;
  auto status = stub_->Predict(&context, request, &response);

  // Step.6: 处理返回结果
  if (!status.ok()) {
    std::cerr << "Predict failed." << std::endl;
    return "0.0";
  }

  const auto &result = response.outputs().at("output0");

  auto filter_box =
      this->filterBoxByScores(result, scale, padding_top, padding_left, score);

  auto obj_box = this->nms(filter_box);

  auto amount = this->objToDouble(obj_box);

  std::cerr << "amount: " << amount << std::endl;

  // this->drawResult(obj_box, image, save_path, amount);

  return amount;
}

void PredictionClient::Final() {}

void PredictionClient::letterbox_preprocess(const cv::Mat &src, cv::Mat &dest,
                                            float *p_scale, int *p_padding_top,
                                            int *p_padding_left,
                                            int target_size /* = 640 */,
                                            bool normalization /* = true */
) {

  // 原始图像尺寸
  int src_h = src.rows;
  int src_w = src.cols;

  // 计算缩放比例
  float scale = std::min(static_cast<float>(target_size) / src_h,
                         static_cast<float>(target_size) / src_w);

  // 计算缩放后的新尺寸
  int new_w = static_cast<int>(src_w * scale);
  int new_h = static_cast<int>(src_h * scale);

  // 执行缩放
  cv::Mat resized;
  cv::resize(src, resized, cv::Size(new_w, new_h), 0, 0, cv::INTER_LINEAR);

  // 计算填充量
  int padding_w = target_size - new_w;
  int padding_h = target_size - new_h;

  // 均分填充到两侧（右侧/底部可能有1像素的余数）
  int padding_left = padding_w / 2;
  int padding_right = padding_w - padding_left;
  int padding_top = padding_h / 2;
  int padding_bottom = padding_h - padding_top;

  // 创建目标图像并填充
  cv::Mat padded = cv::Mat::zeros(target_size, target_size, src.type());
  padded.setTo(cv::Scalar(114, 114, 114)); // 填充灰色

  // 将缩放后的图像复制到中心
  resized.copyTo(padded(cv::Rect(padding_left, padding_top, new_w, new_h)));

  // 转换为RGB格式（如果需要）
  cv::cvtColor(padded, padded, cv::COLOR_BGR2RGB);

  if (normalization) {
    padded.convertTo(dest, CV_32FC3, 1.0f / 255.0);
  } else {
    padded.convertTo(dest, CV_32FC3, 1.0f);
  }

  *p_scale = scale;
  *p_padding_top = padding_top;
  *p_padding_left = padding_left;
}

int PredictionClient::drawResult(std::vector<BoxInfo> &boxs_info,
                                 cv::Mat &origin_image,
                                 const std::string &output_image /* = {} */,
                                 double amount /* = 0.0f */
) {

  const int image_w = tensor_input_.tensor_shape().dim(1).size();
  const int image_h = tensor_input_.tensor_shape().dim(2).size();

  cv::Mat convert_mat(image_w, image_h, origin_image.type());
  float scale = 0.0;
  int padding_top = 0, padding_left = 0;

  letterbox_preprocess(origin_image, convert_mat, &scale, &padding_top,
                       &padding_left, image_w, false);

  int pos_y = 20;
  for (const auto &box : boxs_info) {
    char s[64] = {'\0'};
    sprintf(s, "Label: %d | %10.3f", box.label, box.score);
    cv::putText(convert_mat, s, cv::Point(50, pos_y += 20),
                cv::FONT_HERSHEY_PLAIN, 1.0, cv::Scalar(255, 0, 0));
    cv::rectangle(convert_mat, cv::Point(box.x1, box.y1),
                  cv::Point(box.x2, box.y2), cv::Scalar(255, 0, 0));
  }
  char s2[64] = {'\0'};
  sprintf(s2, "Money: %10.4f", amount);
  cv::putText(convert_mat, s2, cv::Point(50, 20), cv::FONT_HERSHEY_PLAIN, 1.0,
              cv::Scalar(0, 255, 0));

  if (!output_image.empty()) {
    cv::imwrite(output_image, convert_mat);
    std::cout << "Write to image: " << output_image << std::endl;
  }

  cv::imshow("predict", convert_mat);
  cv::waitKey(1);
  return 0;
}

std::vector<BoxInfo> PredictionClient::nms(std::vector<BoxInfo> &boxes,
                                           float nms_threshold /* = 0.5 */
) {

  std::vector<BoxInfo> result;
  std::vector<size_t> indices(boxes.size());
  std::iota(indices.begin(), indices.end(), 0);

  std::sort(boxes.begin(), boxes.end(),
            [this](const BoxInfo &lhs, const BoxInfo &rhs) {
              return lhs.score > rhs.score;
            });

  for (auto &box : boxes) {
    while (!indices.empty()) {
      size_t best_idx = indices[0];
      result.push_back(boxes[best_idx]);
      // 移除已选中的框
      indices.erase(indices.begin());
      indices.erase(std::remove_if(indices.begin(), indices.end(),
                                   [&](size_t i) {
                                     return iou(boxes[best_idx], boxes[i]) >
                                            nms_threshold;
                                   }),
                    indices.end());
    }
  }

  return result;
}

std::vector<BoxInfo> PredictionClient::filterBoxByScores(
    const tensorflow::TensorProto &result, float scale, int padding_top,
    int padding_left, float scores /* = 0.5 */) {
  std::vector<BoxInfo> ret;

  const int result_class = tensor_output_.tensor_shape().dim(1).size();
  const int result_num = tensor_output_.tensor_shape().dim(2).size();
  const int offset_cx = result_num * 0;
  const int offset_cy = result_num * 1;
  const int offset_w = result_num * 2;
  const int offset_h = result_num * 3;

  for (int i = 0; i < result_num; ++i) {
    std::vector<float> class_ele;
    class_ele.reserve(32);

    for (int j = 4; j < result_class; ++j) {
      class_ele.push_back(result.float_val(result_num * j + i));
    }

    auto biggest_iter = std::max_element(class_ele.begin(), class_ele.end());

    if (biggest_iter == class_ele.end()) {
      std::cerr << "Can find biggest iterator" << std::endl;
      return {};
    }

    int biggest_pos = std::distance(class_ele.begin(), biggest_iter);
    float biggest_value = class_ele[biggest_pos];

    if (biggest_value > scores) {
      float cx = result.float_val(offset_cx + i);
      float cy = result.float_val(offset_cy + i);
      float w = result.float_val(offset_w + i);
      float h = result.float_val(offset_h + i);
      int x1 = int(cx - w / 2);
      int x2 = int(cx + w / 2);
      int y1 = int(cy - h / 2);
      int y2 = int(cy + h / 2);
      ret.emplace_back(x1, y1, x2, y2, biggest_pos, biggest_value, y2 - y1);
    } else {
      continue;
    }
  }

  return ret;
}

float PredictionClient::iou(const BoxInfo &box1, const BoxInfo &box2) {
  // Calculate intersection area
  float x1 = std::max(box1.x1, box2.x1);
  float y1 = std::max(box1.y1, box2.y1);
  float x2 = std::min(box1.x2, box2.x2);
  float y2 = std::min(box1.y2, box2.y2);

  float intersection_area = std::max(0.0f, x2 - x1) * std::max(0.0f, y2 - y1);

  // Calculate union area
  float box1_area = (box1.x2 - box1.x1) * (box1.y2 - box1.y1);
  float box2_area = (box2.x2 - box2.x1) * (box2.y2 - box2.y1);
  float union_area = box1_area + box2_area - intersection_area;

  // Avoid division by zero
  if (union_area == 0.0f)
    return 0.0f;

  return intersection_area / union_area;
}

std::string PredictionClient::objToDouble(std::vector<BoxInfo> &boxs_info) {
  std::sort(boxs_info.begin(), boxs_info.end(),
            [this](const BoxInfo &l, const BoxInfo &r) {
              return (l.x1 + l.x2) < (r.x1 + r.x2);
            });

  if (boxs_info.size() < 2) {
    std::cerr << "objToDouble boxs_info.size: " << boxs_info.size();
    return "0";
  }

  std::vector<int> part_integer;
  std::vector<int> part_decimal;
  part_integer.reserve(8);
  part_decimal.reserve(4);

  int part_integer_base = boxs_info.begin()->height;
  int part_decimal_base = boxs_info.rbegin()->height;

  for (const auto &ele : boxs_info) {
    if (ele.label > 9) { // 除了0-9, 其他的全部舍弃
      continue;
    }

    float proportion_integer = float(ele.height) / part_integer_base;
    float proportion_decimal = float(ele.height) / part_decimal_base;

    std::cout << ">>> " << ele.label << " " << proportion_integer << " "
              << proportion_decimal << std::endl;

    if (proportion_integer > 0.9 && proportion_integer < 1.2) {
      part_integer.push_back(ele.label);
    }

    if (proportion_decimal > 0.9 && proportion_decimal < 1.2) {
      part_decimal.push_back(ele.label);
    }
  }

  // 组合整数部分
  int sum_integer = 0;
  for (int i = part_integer.size() - 1; i >= 0; --i) {
    sum_integer +=
        part_integer[i] * std::pow<int>(10, part_integer.size() - 1 - i);
  }
  std::cerr << "sum_integer: " << sum_integer << std::endl;

  // 组合小数部分
  int sum_decimal = 0;
  for (int i = part_decimal.size() - 1; i>=0; --i) {
    sum_decimal +=
          part_decimal[i] * std::pow<double>(10, part_decimal.size() - 1 - i);
  }
  std::cerr << "sum_decimal: " << sum_decimal << std::endl;

  std::string ret = std::to_string(sum_integer) + std::to_string(sum_decimal);
  return ret;
}
