#pragma once

#include "tensorflow_serving/apis/get_model_metadata.pb.h"
#include <array>
#include <cstddef>
//#include <grpc++/grpc++.h>

// #include <grpcpp/channel.h>
#include <memory>
#include <tensorflow_serving/apis/prediction_service.grpc.pb.h>
#include <tensorflow_serving/apis/prediction_service.pb.h>

#include <opencv2/opencv.hpp>
#include <vector>

using tensorflow::serving::GetModelMetadataRequest;
using tensorflow::serving::GetModelMetadataResponse;
using tensorflow::serving::PredictionService;
using tensorflow::serving::PredictRequest;
using tensorflow::serving::PredictResponse;

struct BoxInfo {
  BoxInfo(int x1_, int y1_, int x2_, int y2_, int label_, float score_,
          int height_)
      : x1(x1_), y1(y1_), x2(x2_), y2(y2_), label(label_), score(score_),
        height(height_) {}
  int x1 = 0;
  int y1 = 0;
  int x2 = 0;
  int y2 = 0;
  int label = -1;    // 分类
  float score = 0.0; // label对应的分数, 为最大值
  int height = 0;    // 高度
};

class PredictionClient {
public:
  int Init(const std::string &target,
           const ::tensorflow::TensorProto &&tensor_input,
           const ::tensorflow::TensorProto &&tensor_output,
           const std::string &model_name = "dogcat");

  void Final();

public:
  int GetModelMetadata(GetModelMetadataResponse *response);
  int Predict(cv::Mat &&image, float score = 0.5,
              const std::string &save_path = {});

private:
  std::unique_ptr<PredictionService::Stub> stub_{};
  std::shared_ptr<::grpc::Channel> channel_;
  std::string model_name_;

private:
  void letterbox_preprocess(const cv::Mat &src, cv::Mat &dest, float *scale,
                            int *padding_top, int *padding_left,
                            int target_size = 640, bool normalization = true);

  int drawResult(std::vector<BoxInfo> &boxs_info, cv::Mat &origin_image,
                 const std::string &output_image = {}, double amount = 0.0f);

  std::vector<BoxInfo> filterBoxByScores(const tensorflow::TensorProto &result,
                                         float scale, int padding_top,
                                         int padding_left, float scores = 0.5);

  std::vector<BoxInfo> nms(std::vector<BoxInfo> &boxes,
                           float nms_threshold = 0.5);

  float iou(const BoxInfo &box1, const BoxInfo &box2);

  double objToDouble(std::vector<BoxInfo> &boxes);

private:
  ::tensorflow::TensorProto tensor_input_;
  ::tensorflow::TensorProto tensor_output_;
};
