#include "impls.h"
cv::Mat my_resize(const cv::Mat& input, float scale) {
    /**
     * 要求：
     *      实现resize算法，只能使用基础的语法，比如说for循环，Mat的基本操作。不能
     * 用cv::resize。resize算法的内容自行查找学习，不是很难。
     * 
     * 提示：
     * 无。
     * 
     * 通过条件：
     * 运行测试点，你的结果跟答案长的差不多就行。
     */
    int new_rows = input.rows * scale, new_cols = input.cols * scale;
    // IMPLEMENT YOUR CODE
    cv::Mat output( new_rows, new_cols, CV_8UC3);

    for (int i = 0; i < new_rows; i++) 
    {
        for (int j = 0; j < new_cols; j++) 
        {
            double x = j/ scale;
            double y = i/ scale;

            int x1 = floor(x);
            int y1 = floor(y);
            int x2 = ceil(x);
            int y2 = ceil(y);

            if (x2 >= input.cols) {
                x2 = input.cols - 1;
            }
            if (y2 >= input.rows) {
                y2 = input.rows - 1;
            }

            cv::Vec3b x11 = input.at<cv::Vec3b>(y1, x1);
            cv::Vec3b x12 = input.at<cv::Vec3b>(y2, x1);
            cv::Vec3b x21 = input.at<cv::Vec3b>(y1, x2);
            cv::Vec3b x22 = input.at<cv::Vec3b>(y2, x2);

            double dx = x - x1;
            double dy = y - y1;

            cv::Vec3b result;
            for (int k = 0; k < 3; k++) 
            {
                double f =(x11[k] * (1 - dx) + x21[k] * dx )* (1 - dy) + (x12[k] * (1 - dx) + x22[k] * dx) * dy;
                result[k] = static_cast<uchar>(f);
            }

            output.at<cv::Vec3b>(i, j) = result;
        }
    }

    return output;
}
