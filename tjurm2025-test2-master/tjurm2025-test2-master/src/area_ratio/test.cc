#include "impls.h"
#include "utils.h"


bool test_compute_area_ratio() {
    for (int i = 0; i < 10; i++) {
        std::vector<cv::Point> contour = make_random_contour(320, 480);
        float r = compute_area_ratio(contour);
        float ans = cv::contourArea(contour) / cv::minAreaRect(contour).size.area();

        if (std::abs(r - ans) > 1e-6) {
            std::cout << "计算这个轮廓时出错了, 你的答案: " << r
                      << ", 正确答案: " << ans << std::endl;
            cv::imshow("contour", show_contours({contour}, 320, 480));
            cv::waitKey(0);
            cv::destroyAllWindows();
            return false;
        } else {
            std::cout << "contour size " << contour.size()
                      << ", answer " << ans
                      << ", output " << r << std::endl;
        }
    }
    return true;
}