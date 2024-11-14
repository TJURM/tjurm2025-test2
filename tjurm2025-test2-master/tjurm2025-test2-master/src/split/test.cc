#include "impls.h"

using namespace cv;

bool test_split() {
    cv::Mat b_img = cv::imread("../assets/split/b.jpg", cv::IMREAD_GRAYSCALE);
    cv::Mat g_img = cv::imread("../assets/split/g.jpg", cv::IMREAD_GRAYSCALE);
    cv::Mat r_img = cv::imread("../assets/split/r.jpg", cv::IMREAD_GRAYSCALE);
    std::vector<cv::Mat> key = {b_img, g_img, r_img};

    cv::Mat rgb_image = cv::imread("../assets/split/rgb_image.jpg");
    std::vector<cv::Mat> results = split(rgb_image);

    // 分别显示三个通道的图像
    for (int i = 0; i < results.size(); i++) {
        cv::imshow("channel" + std::to_string(i), results[i]);
    }
    std::cout << "输入任意键继续(此题目将自动检查实现正确性)" << std::endl;
    cv::waitKey(0);
    cv::destroyAllWindows();

    // 比较每个通道的像素值是否和 b_img, g_img, r_img 相同
    for (int c = 0; c < results.size(); c++) {
        for (int x = 0; x < results[c].rows; x++) {
            for (int y = 0; y < results[c].cols; y++) {
                uint32_t diff = abs(results[c].at<uchar>(x, y) - key[c].at<uchar>(x, y));
                if (diff > 10) {
                    std::cout << "通道 " << c << " 像素值不同: "
                              << static_cast<int>(results[c].at<uchar>(x, y)) << " != " << static_cast<int>(key[c].at<uchar>(x, y)) << std::endl;
                    return false;
                }
            }
        }
    }

    return true;
}
