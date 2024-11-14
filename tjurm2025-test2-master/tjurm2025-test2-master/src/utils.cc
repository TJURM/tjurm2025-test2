#include "utils.h"
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>

using std::vector;

int get_terminal_width() {
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    return size.ws_col;
}

void print_line(int width, char c) {
    for (int j = 0; j < width / 2; j++)
        std::cout << c << ' ';
    std::cout << std::endl;
}

cv::Mat show_contours(const vector<vector<cv::Point>>& contours,
    int rows, int cols)
{
    cv::Mat empty = cv::Mat::zeros(cv::Size(cols, rows), CV_8UC3);
    for (int i = 0; i < contours.size(); i++) {
        cv::drawContours(empty, contours, i, { 255, 255, 255 });
    }
    return empty;
}

cv::Mat show_rectangle(const cv::Rect& rect, int rows, int cols) {
    cv::Mat empty = cv::Mat::zeros(cv::Size(cols, rows), CV_8UC3);
    cv::Point2f pnts[] = {
        {rect.x, rect.y},
        {rect.x + rect.width, rect.y},
        {rect.x + rect.width, rect.y + rect.height},
        {rect.x, rect.y + rect.height}
    };
    for (int j = 0; j < 4; j++)
        line(empty, pnts[j], pnts[(j + 1) % 4], { 255, 255, 255 });
    return empty;
}

cv::Mat show_rectangle(const cv::RotatedRect& rrect, int rows, int cols) {
    cv::Mat empty = cv::Mat::zeros(cv::Size(cols, rows), CV_8UC3);
    cv::Point2f pnts[4];
    rrect.points(pnts);
    for (int j = 0; j < 4; j++)
        line(empty, pnts[j], pnts[(j + 1) % 4], { 255, 255, 255 });
    return empty;
}

std::vector<cv::Point> make_random_contour(int rows, int cols) {
    // copy from: https://blog.csdn.net/memorynode/article/details/125304555
    cv::RNG& rng = cv::theRNG();
    
    int n = (unsigned)rng % 100 + 13;
    std::vector<cv::Point> points;
    for (int i = 0; i < n; i++) {
        cv::Point point;
        point.x = rng.uniform(cols / 4, cols * 3 / 4);
        point.y = rng.uniform(rows / 4, rows * 3 / 4);
        points.push_back(point);
    }

    std::vector<int> hull;
    cv::convexHull(cv::Mat(points), hull, true);

    std::vector<cv::Point> contour;
    for (const auto& i : hull) {
        contour.push_back(points[i]);
    }

    return contour;
}