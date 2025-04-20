#include <opencv2/opencv.hpp>

//#pragma comment(lib, "opencv_world4110.lib")

int main(int argc, char** argv) {
    std::cout << "Hello opencv on windows" << std::endl;
    std::string image_filename {};
    if(argc != 2) {
        image_filename = "data/opencv_logo.png";
    }
    else {
        image_filename = argv[1];
    }

    cv::Mat img = cv::imread(image_filename);
    if(img.empty()){
        cv::imshow("1.jpg",img);
        std::cout << "Is empty" << std::endl;
    }
    cv::resize(img, img, cv::Size(540, 360));
    cv::imshow("Logo", img);
    cv::waitKey(-1);
}
