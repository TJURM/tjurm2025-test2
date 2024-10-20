#include "tests.h"
#include "impls.h"
#include "log.h"


std::string to_string(int i) {
    std::string color = "None";
    switch (i) {
        case 0: color = "blue";     break;
        case 1: color = "green";    break;
        case 2: color = "red";      break;
        default:break;
    }
    return color;
}


bool check_force(std::unordered_map<int, cv::Rect> res) {
    LOG_MSG("开始暴力检查（强行答案对比）");
    // std::cout << "你的答案: " << std::endl;
    // for (auto& [color, rect] : res) {
    //     std::cout << to_string(color) << ": " << rect << std::endl;
    // }

    std::unordered_map<int, cv::Rect> answer = {
        {0, cv::Rect(43, 100, 94, 62)},
        {1, cv::Rect(167, 33, 53, 106)},
        {2, cv::Rect(41, 32, 100, 49)}
    };

    for (int i = 0; i < 3; i++) {
        if (res[i] != answer[i]) {
            std::cout << "与答案不一样: " << to_string(i) << ": " << res[i] << " (答案: " << answer[i] << ")" << std::endl;
            return false;
        }
    }

    return true;
}


bool check_self(cv::Mat &input, std::unordered_map<int, cv::Rect> res) {
    LOG_MSG("check_force 未通过，请根据后续提示自行检查，满足要求此题仍算通过");
    for (auto& [color, rect] : res) {
        cv::rectangle(input, rect, cv::Scalar(0, 0, 0), 2);
        cv::putText(input, to_string(color), cv::Point(rect.x, rect.y - 5), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 0, 0), 2);
    }
    cv::imshow("result", input);
    std::cout << "自行检查:" << std::endl;
    std::cout << "  1. 矩形区域 (黑色画出) 的位置大致ok " << std::endl;
    std::cout << "  2. 三处矩形的颜色标的正确 " << std::endl;
    std::cout << "根据检查结果:" << std::endl;
    std::cout << "  1. 满足就输入 p" << std::endl;
    std::cout << "  2. 不满足就输入 f" << std::endl;

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


bool test_roi_color() {
    cv::Mat input = cv::imread("../assets/roi_color/input.png");

    std::unordered_map<int, cv::Rect> res = roi_color(input);

    if (res.size() != 3) {
        std::cout << "wrong: 找到的轮廓个数不是 3 个" << std::endl;
        return false;
    }

    if (check_force(res)) {
        return true;
    } else if (check_self(input, res)) {
        return true;
    } else {
        return false;
    }
}
