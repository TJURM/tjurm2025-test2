#include "impls.h"
#include "utils.h"

using std::vector;
using std::cout;
using std::endl;

bool test_find_contours() {
    cv::Mat input = cv::imread("../assets/find_contours/input.png");
    cv::Mat ans = cv::imread("../assets/find_contours/answer.jpg");
    
    vector<vector<cv::Point>> output = find_contours(input);
    cv::Mat res = show_contours(output, input.rows, input.cols);

    cv::imshow("<test_find_contours> 正确的答案", ans);
    cv::imshow("<test_find_contours> 你的答案", res);
    cv::waitKey(0);
    cv::destroyAllWindows();
    
    if (output.size() != 3) {
        cout << "轮廓的个数不对，正确的个数应当为3个，你找到了" << output.size()
             << "个。" << endl;
        return false;
    }

    return true;
}