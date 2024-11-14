#include "impls.h"


bool test_threshold() {
    cv::Mat src = cv::imread("../assets/threshold/rgb_image.jpg");
    std::vector<cv::Mat> results = threshold(src, 50);
    cv::Mat gray = results[0];
    cv::Mat dst = results[1];
    if (gray.empty() || dst.empty()) {
        std::cout << "threshold检查点1. 你的实现有误，返回的图像为空" << std::endl;
        return false;
    }
    cv::imshow("gray", gray);
    cv::imshow("dst", dst);

    cv::Mat key_gray = cv::imread("../assets/threshold/threshold_gray.jpg", cv::IMREAD_GRAYSCALE);
    cv::Mat key_dst = cv::imread("../assets/threshold/threshold_dst.jpg", cv::IMREAD_GRAYSCALE);
    cv::imshow("key_gray", key_gray);
    cv::imshow("key_dst", key_dst);

    std::cout << "自行检查是否与答案(key_gray和key_dst)是否一致" << std::endl;
    std::cout << "一致则输入 p 通过, 否则输入 f 表示不通过" << std::endl;

    int key;
    while (key = cv::waitKey(0)) {
        if (key == 'p') {
            cv::destroyAllWindows();
            return true;
        } else if (key == 'f') {
            cv::destroyAllWindows();
            return false;
        }
    }
}
