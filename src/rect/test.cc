#include "impls.h"
#include "utils.h"


bool test_get_rect_by_contours() {
    std::string path = "../assets/rect/input.png";
    cv::Mat input = cv::imread(path);

    std::pair<cv::Rect, cv::RotatedRect> output = get_rect_by_contours(input);
    cv::Rect rect = output.first;
    cv::RotatedRect rrect = output.second;

    cv::Mat rect_ans = cv::imread("../assets/rect/answer_rect.jpg");
    cv::imshow("<test_get_rect_by_contours> 正确的答案", rect_ans);
    cv::imshow("<test_get_rect_by_contours> 你的答案", show_rectangle(rect, input.rows, input.cols));
    cv::waitKey(0);
    cv::destroyAllWindows();
    
    cv::Mat rrect_ans = cv::imread("../assets/rect/answer_rrect.jpg");
    cv::imshow("<test_get_rect_by_contours>正确的答案", rrect_ans);
    cv::imshow("<test_get_rect_by_contours> 你的答案", show_rectangle(rrect, input.rows, input.cols));
    cv::waitKey(0);
    cv::destroyAllWindows();

    return true;
}