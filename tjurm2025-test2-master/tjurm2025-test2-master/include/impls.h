#ifndef TJURM_TUTORIAL_INCLUDE_IMPL_H_
#define TJURM_TUTORIAL_INCLUDE_IMPL_H_

#include <opencv2/opencv.hpp>
#include <vector>

// 练习 (1)
std::vector<cv::Mat> split(const cv::Mat& rgb_image);

// 练习 (2)
std::vector<cv::Mat> threshold(const cv::Mat& src, int threshold_value);

// 练习 (3)
std::vector<cv::Mat> erode(const cv::Mat& src_erode, const cv::Mat& src_dilate);

// 练习 (4)
std::vector<std::vector<cv::Point>> find_contours(const cv::Mat& input);

// 练习 (5)
std::pair<cv::Rect, cv::RotatedRect> get_rect_by_contours(const cv::Mat& input);

// 练习 (6)
float compute_iou(const cv::Rect& a, const cv::Rect& b);

// 练习 (7)
float compute_area_ratio(const std::vector<cv::Point>& contour);

// 练习 (8)
std::unordered_map<int, cv::Rect> roi_color(const cv::Mat& input);

// 练习 (9)
cv::Mat my_resize(const cv::Mat& input, float scale);

#endif
