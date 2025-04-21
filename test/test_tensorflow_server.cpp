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
    int ret = client.Init("123.57.18.145:8500");
    if (ret) {
        std::cerr << "client init failed" << std::endl;
        return 0;
    }

    // 测试模型可用性
    ::tensorflow::serving::GetModelMetadataResponse response_meta;
    client.GetModelMetadata(&response_meta);

    // 读取测试图片
    auto image = cv::imread(argv[1]);
    if (image.empty()) {
        std::cerr << "image is empty" << std::endl;
        return 0;
    }
    auto origin_image = image.clone();

    // 推理图片
    ::tensorflow::serving::PredictResponse response_predict;
    auto status = client.Predict(std::move(image), &response_predict);

    if (status) {
        std::cout << "Predict end, return true" << std::endl;
        const auto &result = response_predict.outputs().at("output0");
        for (int i = 0; i < result.tensor_shape().dim_size(); ++i) {
            std::cout << "name: " << result.tensor_shape().dim(i).name()
            << " | sz: " << result.tensor_shape().dim(i).size()
            << std::endl;
        }

        float scale_x = 1920 / 640.0;
        float scale_y = 1080 / 640.0;
        std::cout << "float_val_size: " << result.float_val_size() << std::endl;

        const int offset_cx = 8400 * 0;
        const int offset_cy = 8400 * 1;
        const int offset_w = 8400 * 2;
        const int offset_h = 8400 * 3;
        const int offset_con_0 = 8400 * 4;
        const int offset_con_1 = 8400 * 5;

        for (int i = 0; i < 8400; ++i) {
            float confidence_0 = result.float_val(offset_con_0 + i);
            float confidence_1 = result.float_val(offset_con_1 + i);
            if (confidence_0 > 0.80) {
                std::cout << "One Cat..." << std::endl;
                float cx = scale_x * result.float_val(offset_cx + i);
                float cy = scale_y * result.float_val(offset_cy + i);
                float w = scale_x * result.float_val(offset_w + i);
                float h = scale_y * result.float_val(offset_h + i);
                int x1 = int(cx - w / 2);
                int x2 = int(cx + w / 2);
                int y1 = int(cy - h / 2);
                int y2 = int(cy + h / 2);
                cv::rectangle(origin_image, cv::Point(x1, y1), cv::Point(x2, y2),
                              cv::Scalar(0, 255, 0));

            } else if (confidence_1 > 0.80) {
                std::cout << "One Dog..." << std::endl;
            } else {
                continue;
            }
        }

        // TODO: NMS算法

        // TODO: 绘制图像
        cv::imwrite("./CPP_result.jpg", origin_image);
    } else {
        std::cout << "Predict end, return false" << std::endl;
    }

    return 0;
}
