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
    // IMPLEMENT YOUR CODE HERE
 
    int new_rows = static_cast<int>(input.rows * scale);  
    int new_cols = static_cast<int>(input.cols * scale);  
    cv::Mat output = cv::Mat::zeros(new_rows, new_cols, input.type());  
    for (int y = 0; y < new_rows; ++y) {  
        for (int x = 0; x < new_cols; ++x) {  
  
            int src_x = static_cast<int>(x / scale);  
            int src_y = static_cast<int>(y / scale);  
            src_x = std::min(src_x, input.cols - 1);  
            src_y = std::min(src_y, input.rows - 1);  
            output.at<cv::Vec3b>(y, x) = input.at<cv::Vec3b>(src_y, src_x); 
        }  
    }  
    
    return cv::Mat::zeros(new_rows, new_cols, input.type());
}