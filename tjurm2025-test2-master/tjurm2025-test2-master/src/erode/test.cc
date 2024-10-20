#include "impls.h"


bool test_erode() {
    bool flag = true;
    cv::Mat src_erode = cv::imread("../assets/erode/rgb_image.jpg");
    cv::Mat src_dilate = cv::imread("../assets/erode/dilate.jpg");

    std::vector<cv::Mat> dst = erode(src_erode, src_dilate);
    cv::Mat dst_erode = dst[0];
    cv::Mat dst_dilate = dst[1];

    {
        cv::Mat gray;
        cv::cvtColor(src_erode, gray, cv::COLOR_BGR2GRAY);

        cv::Mat binary;
        cv::threshold(gray, binary, 50, 255, cv::THRESH_BINARY);

        if (dst_erode.empty()) {
            std::cout << "erode检查点1. 你的实现有误，返回的图像为空" << std::endl;
            return false;
        }
        cv::imshow("二值化图", binary);
        cv::imshow("erode 你的实现", dst_erode);
        cv::Mat erode_key = cv::imread("../assets/erode/erode_key.jpg", cv::IMREAD_GRAYSCALE);
        cv::imshow("erode 参考答案", erode_key);

        std::cout << "erode检查点1. 自行检查是否满足以下要求：" << std::endl
                << "erode 之后的图像中，图中女孩头发里的白点被消除了(类似答案中的样子)" << std::endl
                << "满足条件 则输入 p 通过, 否则输入 f 表示不通过" << std::endl;

        int key;
        while (key = cv::waitKey(0)) {
            if (key == 'p') {
                break;
            } else if (key == 'f') {
                flag = false;
                break;
            }
        }
        cv::destroyAllWindows();
    }

    {
        cv::Mat gray;
        cv::cvtColor(src_dilate, gray, cv::COLOR_BGR2GRAY);

        cv::Mat binary;
        cv::threshold(gray, binary, 50, 255, cv::THRESH_BINARY);

        if (dst_dilate.empty()) {
            std::cout << "dilate检查点1. 你的实现有误，返回的图像为空" << std::endl;
            return false;
        }

        cv::imshow("二值化图", binary);
        cv::imshow("dilate 你的实现", dst_dilate);
        cv::Mat dilate_key = cv::imread("../assets/erode/dilate_key.jpg", cv::IMREAD_GRAYSCALE);
        cv::imshow("dilate 参考答案", dilate_key);

        std::cout << "erode检查点2. 自行检查是否满足以下要求：" << std::endl
                << "dilate 之后的图像中，图中的小脚被消除了(类似答案中的样子)" << std::endl
                << "满足条件 则输入 p 通过, 否则输入 f 表示不通过" << std::endl;

        int key;
        while (key = cv::waitKey(0)) {
            if (key == 'p') {
                break;
            } else if (key == 'f') {
                flag = false;
                break;
            }
        }
        cv::destroyAllWindows();
    }

    return true;
}
