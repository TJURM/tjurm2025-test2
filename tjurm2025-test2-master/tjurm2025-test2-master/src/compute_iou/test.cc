#include "impls.h"


bool test_compute_iou() {
    std::vector<cv::Rect> as, bs;
    std::vector<float> res;
    
    as.emplace_back(0, 0, 2, 2);
    bs.emplace_back(1, 1, 1, 1);
    res.emplace_back(1.f / 4);

    as.emplace_back(0, 0, 2, 2);
    bs.emplace_back(0, 0, 2, 2);
    res.emplace_back(1.f);

    as.emplace_back(0, 0, 2, 2);
    bs.emplace_back(1, 1, 2, 2);
    res.emplace_back(1.f / 7);

    as.emplace_back(0, 0, 2, 2);
    bs.emplace_back(2, 2, 1, 1);
    res.emplace_back(0.f);
    
    for (int i = 0; i < as.size(); i++) {
        if (std::abs(res[i] - compute_iou(as[i], bs[i])) > 1e-6) {
            std::cout << "失败, "
                      << "a = (" << as[i].x << ", " << as[i].y << ", " << as[i].width << ", " << as[i].height << ")"
                      << " "
                      << "b = (" << bs[i].x << ", " << bs[i].y << ", " << bs[i].width << ", " << bs[i].height << ")"
                      << std::endl;
            return false;
        }
    }
    return true;
}