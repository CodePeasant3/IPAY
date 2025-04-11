// Ref: https://blog.csdn.net/weixin_43236944/article/details/143252666

#pragma comment(lib, "onnxruntime.lib")

#include <onnxruntime_cxx_api.h>
#include <opencv2/opencv.hpp>
#include <string>

using namespace Ort;


int main(int argc, char** argv)
{
    // 处理入参
    std::string filename_model {};
    std::string filename_image {};
    switch(argc) {
    case 1:
        filename_model = "model/model.onnx";
        filename_image = "data/case_1.png";
        break;
    case 3:
        filename_model = argv[1];
        filename_model = argv[2];
        break;
    default:
        std::cerr << "----------------- Usage -----------------" << std::endl
                  << "./test_onnxruntim" << std::endl
                  << "./test_onnxtime ./model/model.onnx ./data/case_1.png" << std::endl;
        return 0;
    }


    // 读取图片
    cv::Mat frame = cv::imread(filename_image, cv::IMREAD_COLOR_BGR);
    if(frame.empty()) {
        std::cerr << "image is empty" << std::endl;
        return 0;
    }


    // 加载模型
    Ort::SessionOptions session_options = Ort::SessionOptions();;
    Ort::Env env = Ort::Env(ORT_LOGGING_LEVEL_ERROR, "yolov11");
    std::cout << "ONNXRUNTIME inference try to use GPU Device" << std::endl;
    std::wstring modelPath = std::wstring(filename_model.begin(), filename_model.end());
    Ort::Session session_(env, modelPath.c_str(), session_options);

    std::vector<std::string> input_node_names;
    std::vector<std::string> output_node_names;
    size_t numInputNodes = session_.GetInputCount();
    size_t numOutputNodes = session_.GetOutputCount();
    Ort::AllocatorWithDefaultOptions allocator;
    input_node_names.reserve(numInputNodes);

    // 获取输入参数
    int64_t input_w = 0;
    int64_t input_h = 0;
    for (int i = 0; i < numInputNodes; i++) {
        auto input_name = session_.GetInputName(i, allocator);
        input_node_names.push_back(input_name);

        Ort::TypeInfo input_type_info = session_.GetInputTypeInfo(i);
        auto input_tensor_info = input_type_info.GetTensorTypeAndShapeInfo();
        auto input_dims = input_tensor_info.GetShape();
        input_w = input_dims[3];
        input_h = input_dims[2];
        std::cout << "input format: NxCxHxW = " << input_dims[0] << "x" << input_dims[1] << "x" << input_dims[2] << "x" << input_dims[3] << std::endl;
    }

    // 获取输出参数
    int64_t output_h = 0;
    int64_t output_w = 0;
    Ort::TypeInfo output_type_info = session_.GetOutputTypeInfo(0);
    auto output_tensor_info = output_type_info.GetTensorTypeAndShapeInfo();
    auto output_dims = output_tensor_info.GetShape();
    output_h = output_dims[1];
    output_w = output_dims[2];
    std::cout << "output format : HxW = " << output_dims[1] << "x" << output_dims[2] << std::endl;
    for (int i = 0; i < numOutputNodes; i++)
    {
        //onnx newest version-1.14
        auto out_name = session_.GetOutputName(i, allocator);
        output_node_names.push_back(out_name);
    }
    std::cout << "input: " << input_node_names[0] << " output: " << output_node_names[0] << std::endl;

    /*
    //step-5:get infer result
    int64 start = cv::getTickCount();
    int w = frame.cols;
    int h = frame.rows;
    int _max = std::max(h, w);
    cv::Mat image = cv::Mat::zeros(cv::Size(_max, _max), CV_8UC3);
    cv::Rect roi(0, 0, w, h);
    frame.copyTo(image(roi));

    // fix bug, boxes consistence!
    float x_factor = image.cols / static_cast<float>(input_w);
    float y_factor = image.rows / static_cast<float>(input_h);

    cv::Mat blob = cv::dnn::blobFromImage(image, 1 / 255.0, cv::Size(input_w, input_h), cv::Scalar(0, 0, 0), true, false);
    size_t tpixels = input_h * input_w * 3;
    std::array<int64_t, 4> input_shape_info{ 1, 3, input_h, input_w };

    // set input data and inference
    auto allocator_info = Ort::MemoryInfo::CreateCpu(OrtDeviceAllocator, OrtMemTypeCPU);
    Ort::Value input_tensor_ = Ort::Value::CreateTensor<float>(allocator_info, blob.ptr<float>(), tpixels, input_shape_info.data(), input_shape_info.size());
    const std::array<const char*, 1> inputNames = { input_node_names[0].c_str() };
    const std::array<const char*, 1> outNames = { output_node_names[0].c_str() };
    std::vector<Ort::Value> ort_outputs;
    try {
        ort_outputs = session_.Run(Ort::RunOptions{ nullptr }, inputNames.data(), &input_tensor_, 1, outNames.data(), outNames.size());
    }
    catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }

    // output data
    const float* pdata = ort_outputs[0].GetTensorMutableData<float>();
    cv::Mat dout(output_h, output_w, CV_32F, (float*)pdata);
    cv::Mat det_output = dout.t(); // 8400x84

    // post-process
    std::vector<cv::Rect> boxes;
    std::vector<int> classIds;
    std::vector<float> confidences;

    for (int i = 0; i < det_output.rows; i++) {
        cv::Mat classes_scores = det_output.row(i).colRange(4, 84);
        cv::Point classIdPoint;
        double score;
        minMaxLoc(classes_scores, 0, &score, 0, &classIdPoint);

        //between 0～1
        if (score > 0.25)
        {
            float cx = det_output.at<float>(i, 0);
            float cy = det_output.at<float>(i, 1);
            float ow = det_output.at<float>(i, 2);
            float oh = det_output.at<float>(i, 3);
            int x = static_cast<int>((cx - 0.5 * ow) * x_factor);
            int y = static_cast<int>((cy - 0.5 * oh) * y_factor);
            int width = static_cast<int>(ow * x_factor);
            int height = static_cast<int>(oh * y_factor);
            cv::Rect box;
            box.x = x;
            box.y = y;
            box.width = width;
            box.height = height;

            boxes.push_back(box);
            classIds.push_back(classIdPoint.x);
            confidences.push_back(score);
        }
    }

    // NMS
    std::vector<int> indexes;
    cv::dnn::NMSBoxes(boxes, confidences, 0.25, 0.45, indexes);
    for (size_t i = 0; i < indexes.size(); i++) {
        int index = indexes[i];
        int idx = classIds[index];
        cv::rectangle(frame, boxes[index], cv::Scalar(0, 0, 255), 2, 8);
        cv::rectangle(frame, cv::Point(boxes[index].tl().x, boxes[index].tl().y - 20),
                      cv::Point(boxes[index].br().x, boxes[index].tl().y), cv::Scalar(0, 255, 255), -1);

        cv::imshow("YOLOv11 onnxrunning", frame);
    }


    //calculate FPS render it
    float t = (cv::getTickCount() - start) / static_cast<float>(cv::getTickFrequency());
    putText(frame, cv::format("FPS: %.2f", 1.0 / t), cv::Point(20, 40), cv::FONT_HERSHEY_PLAIN, 2.0, cv::Scalar(255, 0, 0), 2, 8);
    cv::imshow("YOLOv11 onnxrunning", frame);
    cv::imwrite("result.jpg", frame);
    cv::waitKey(0);

    session_options.release();
    session_.release();
    */
    return 0;
}
