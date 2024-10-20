#include "impls.h"


std::vector<std::vector<cv::Point>> find_contours(const cv::Mat& input) {
    /**
     * 要求：
     * 使用cv::findContours函数，从输入图像（3个通道）中找出所有的最内层轮廓。
     * 将它们保存起来作为函数返回值就行。contours的中文意思就是轮廓。
     * 
     * 提示：
     * 1. 使用cv::imshow来查看输入图像。
     * 2. 使用cv::drawContours来在一张图上绘制轮廓。
     * 3. 直接使用原图一般而言不利于轮廓的寻找，可以做一些简单的处理。
     * 4. findContours函数可以返回轮廓的层次结构，理解层次结构的保存方式并使用它（重点）。
     * 
     * 通过条件：
     * 运行测试点，你找到的轮廓与答案的轮廓一样就行。
     */
    std::vector<std::vector<cv::Point>> res;
    // IMPLEMENT YOUR CODE HERE
 
    cv::Mat gray;  
    cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);  
    cv::Mat binary;  
    cv::threshold(gray, binary, 127, 255, cv::THRESH_BINARY);  
    std::vector<std::vector<cv::Point>> contours;  
    std::vector<cv::Vec4i> h;  
    cv::findContours(binary, contours, h, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);  
    for (int i = 0; i < contours.size(); ++i) {  
        if (h[i][3] == -1) {  
            int child = i;  
            while (h[child][3] != -1) { 
                child = h[child][3]; 
            }  
            res.push_back(contours[child]); 
        }  
    }   
    cv::Mat contour_image = cv::Mat::zeros(input.size(), input.type());  
    cv::drawContours(contour_image, res, -1, cv::Scalar(0, 255, 0), 2);  
    cv::imshow("Contours", contour_image);  
    cv::waitKey(0);  
  

    return res;
}