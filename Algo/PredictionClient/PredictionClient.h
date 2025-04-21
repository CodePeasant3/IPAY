#pragma once

#include "tensorflow_serving/apis/get_model_metadata.pb.h"
#include <grpc++/grpc++.h>

#include <grpcpp/channel.h>
#include <memory>
#include <tensorflow_serving/apis/prediction_service.grpc.pb.h>
#include <tensorflow_serving/apis/prediction_service.pb.h>

#include <opencv2/opencv.hpp>

using tensorflow::serving::GetModelMetadataRequest;
using tensorflow::serving::GetModelMetadataResponse;
using tensorflow::serving::PredictionService;
using tensorflow::serving::PredictRequest;
using tensorflow::serving::PredictResponse;

class PredictionClient {
public:
  int Init(const std::string &target, const std::string &model_name = "dogcat");
  void Final();

public:
  bool GetModelMetadata(GetModelMetadataResponse *response);
  bool Predict(cv::Mat &&image, PredictResponse *response);

private:
  std::unique_ptr<PredictionService::Stub> stub_{};
  std::shared_ptr<::grpc::Channel> channel_;
  std::string model_name_;

private:
  // 模型参数相关
  tensorflow::TensorProto tensor_input_;  // tensor name: images
  tensorflow::TensorProto tensor_output_; // tensor name: output0
                                        
private:
  int setModelParams();
};
