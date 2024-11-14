#include "impls.h"


bool test_my_resize() {
    cv::Mat input = cv::imread("../assets/resize/input.jpg");
    cv::resize(input, input, cv::Size(input.cols / 3, input.rows / 3));

    std::vector<float> scales{1.5f, 0.5f};
    cv::Mat res;

    for (const auto& s : scales) {
        std::string title = "scale = " + std::to_string(s);

        cv::imshow("原图", input);

        cv::Mat resized = my_resize(input, s);
        cv::imshow(title + "(你的答案)", resized);

        cv::resize(input, res, cv::Size((int)(input.cols * s), (int)(input.rows * s)));
        cv::imshow(title + "(正确答案)", res);
        cv::waitKey(0);
        cv::destroyAllWindows();
    }

    return true;
}