#include "opencv2/core/types.hpp"
#include "opencv2/imgcodecs.hpp"
#include "tensorflow_serving/apis/get_model_metadata.pb.h"
#include "tensorflow_serving/apis/predict.pb.h"
#include <PredictionClient.h>
#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv) {
    std::cout << "Hello from client!" << std::endl;
    PredictionClient client;

    ::tensorflow::TensorProto tensor_input, tensor_output;
    tensor_input.set_dtype(tensorflow::DataType::DT_FLOAT);
    tensor_input.mutable_tensor_shape()->add_dim()->set_size(1);
    tensor_input.mutable_tensor_shape()->add_dim()->set_size(640);
    tensor_input.mutable_tensor_shape()->add_dim()->set_size(640);
    tensor_input.mutable_tensor_shape()->add_dim()->set_size(3);
    tensor_output.set_dtype(tensorflow::DataType::DT_FLOAT);
    tensor_output.mutable_tensor_shape()->add_dim()->set_size(1);
    tensor_output.mutable_tensor_shape()->add_dim()->set_size(15);
    tensor_output.mutable_tensor_shape()->add_dim()->set_size(8400);


    int ret = client.Init("123.138.200.114:8010",
                          std::move(tensor_input),
                          std::move(tensor_output),
                          "num_1-on-featurize");
    if (ret) {
        std::cerr << "client init failed" << std::endl;
        return 0;
    }

    // 测试模型可用性
    ::tensorflow::serving::GetModelMetadataResponse response_meta;
    client.GetModelMetadata(&response_meta);
    std::cerr << "model.name: " << response_meta.model_spec().name().c_str() << std::endl;
    std::cerr << "model.version: " << response_meta.model_spec().version().value() << std::endl;
    std::cerr << "model.signature_name: " << response_meta.model_spec().signature_name().c_str() << std::endl;


    return 0;
}
