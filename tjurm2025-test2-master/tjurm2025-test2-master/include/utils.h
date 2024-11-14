#ifndef TJURM_TUTORIAL_INCLUDE_UTILS_H_
#define TJURM_TUTORIAL_INCLUDE_UTILS_H_

#include <opencv2/opencv.hpp>

#define FORMAT_BLUE(str)      "\033[34m" str "\033[0m"
#define FORMAT_BLUE_BACK(str) "\033[44m" str "\033[0m"
#define FORMAT_RED(str)       "\033[31m" str "\033[0m"

int get_terminal_width();

void print_line(int width, char c);

cv::Mat show_contours(const std::vector<std::vector<cv::Point>>& contours,
                      int rows, int cols);

cv::Mat show_rectangle(const cv::Rect& rect, int rows, int cols);
cv::Mat show_rectangle(const cv::RotatedRect& rrect, int rows, int cols);

std::vector<cv::Point> make_random_contour(int rows, int cols);

#endif
