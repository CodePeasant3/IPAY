#include "PredictionClient.h"
#include "opencv2/core/types.hpp"
#include "opencv2/opencv.hpp"
#include "tensorflow/core/framework/tensor.pb.h"
#include "tensorflow/core/framework/types.pb.h"
#include "tensorflow_serving/apis/get_model_metadata.pb.h"
#include "tensorflow_serving/apis/predict.pb.h"
#include "tensorflow_serving/apis/prediction_service.grpc.pb.h"
#include <cassert>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/support/status.h>

int PredictionClient::Init(const std::string &target,
                           const std::string &model_name /* = "dogcat" */) {

  // Step.0: Assign to value
  model_name_ = model_name;

  // Step.1: Create channel
  channel_ = ::grpc::CreateChannel(target, grpc::InsecureChannelCredentials());
  if (!channel_) {
    std::cerr << "Channel create failed" << std::endl;
    return -1;
  }

  // Step.2: Create stub
  stub_ = ::tensorflow::serving::PredictionService::NewStub(channel_);

  return 0;
}

bool PredictionClient::GetModelMetadata(GetModelMetadataResponse *response) {

  // Step.1: 构建必要上下文
  ::grpc::ClientContext context;
  ::tensorflow::serving::GetModelMetadataRequest request;
  request.mutable_model_spec()->set_name(model_name_);
  request.mutable_metadata_field()->Add("signature_def");

  // Step.2: 调用stub函数
  auto status = stub_->GetModelMetadata(&context, request, response);
  if (!status.ok()) {
    std::cerr << "GetModelMetadata failed" << std::endl;
    return false;
  }

  // Step.3: 输出模型信息
  std::cout << "model.name: " << response->model_spec().name() << std::endl
            << "model.version: " << response->model_spec().version().value()
            << std::endl
            << "model.signature_name: "
            << response->model_spec().signature_name() << std::endl;

  for (const auto &data : response->metadata()) {
    std::cout << "key: " << data.first << std::endl;
  }
  return true;
}

bool PredictionClient::Predict(cv::Mat &&image, PredictResponse *response) {
  // Step.1: 构造必要上下文
  ::grpc::ClientContext context;
  PredictRequest request;

  // Step.2: 构造请求数据
  request.mutable_model_spec()->set_name(model_name_);
  request.mutable_model_spec()->set_signature_name("serving_default");

  // Step.3 处理输入图像
  std::cout << "image.dims: " << image.dims << std::endl
            << "image.channels: " << image.channels() << std::endl
            << "image.cols|width: " << image.cols << std::endl
            << "image.rows|height: " << image.rows << std::endl
            << "image.depth: " << image.depth() << std::endl
            << "image.elemSize: " << image.elemSize() << std::endl;
  assert(image.dims == 2);       // 维度为二维
  assert(image.channels() == 3); // 通道为3

  // Step.3.1 尺寸调整
  cv::resize(image, image, cv::Size(640, 640));
  // Step.3.2 图像通道变换
  cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
  // Step.3.3 归一化
  cv::Mat convert_mat(640, 640, CV_32FC3);
  image.convertTo(convert_mat, CV_32FC3, 1.0f / 255.0);

  std::cout << "convert_mat.dims: " << convert_mat.dims << std::endl
            << "convert_mat.channels: " << convert_mat.channels() << std::endl
            << "convert_mat.cols|width: " << convert_mat.cols << std::endl
            << "convert_mat.rows|height: " << convert_mat.rows << std::endl
            << "convert_mat.depth: " << convert_mat.depth() << std::endl
            << "convert_mat.total: " << convert_mat.total() << std::endl
            << "convert_mat.elemSize: " << convert_mat.elemSize() << std::endl;

  // Step.4: 填充数据
  ::tensorflow::TensorProto tensor_proto;
  //tensor_proto.CopyFrom(tensor_input_);
  tensor_proto.MergeFrom(tensor_input_);

  const size_t data_size = convert_mat.total() * convert_mat.elemSize();
  tensor_proto.set_tensor_content((char *)(convert_mat.data), data_size);

  auto &inputs = *request.mutable_inputs();
  inputs["images"].CopyFrom(tensor_proto);

  auto status = stub_->Predict(&context, request, response);

  return status.ok();
}

void PredictionClient::Final() {}

int PredictionClient::setModelParams() {
  this->tensor_input_.set_dtype(::tensorflow::DataType::DT_FLOAT);
  this->tensor_input_.mutable_tensor_shape()->add_dim()->set_size(1);
  this->tensor_input_.mutable_tensor_shape()->add_dim()->set_size(640);
  this->tensor_input_.mutable_tensor_shape()->add_dim()->set_size(640);
  this->tensor_input_.mutable_tensor_shape()->add_dim()->set_size(3);

  this->tensor_output_.set_dtype(::tensorflow::DataType::DT_FLOAT);
  this->tensor_output_.mutable_tensor_shape()->add_dim()->set_size(1);
  this->tensor_output_.mutable_tensor_shape()->add_dim()->set_size(6);
  this->tensor_output_.mutable_tensor_shape()->add_dim()->set_size(8400);

  return 0;
}
