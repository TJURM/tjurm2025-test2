#include "impls.h"


std::pair<cv::Rect, cv::RotatedRect> get_rect_by_contours(const cv::Mat& input) {
    /**
     * 要求：
     * 使用findCountours函数找出输入图像（彩色图像）中的矩形轮廓，并且返回它的外接矩形，以及
     * 最小面积外接矩形。所需要的函数自行查找。
     * 
     * 通过条件：
     * 运行测试点，你找到的矩形跟答案一样就行。
    */
    std::pair<cv::Rect, cv::RotatedRect> res;
    // IMPLEMENT YOUR CODE HERE
    cv::Mat gray;  
    cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);  
    cv::Mat binary;  
    cv::threshold(gray, binary, 127, 255, cv::THRESH_BINARY);  
    std::vector<std::vector<cv::Point>> contours;  
    std::vector<cv::Vec4i> hierarchy;  
    cv::findContours(binary, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);  
    // 这里我默认最大的轮廓就是要找的矩形了（其实是偷懒）  
    int maxContourIndex = -1;  
    double maxContourArea = 0.0;  
    for (size_t i = 0; i < contours.size(); ++i) {  
        double area = cv::contourArea(contours[i]);  
        if (area > maxContourArea) {  
            maxContourArea = area;  
            maxContourIndex = i;  
        }  
    }   
    if (maxContourIndex == -1) {  
        return res;  
    }  
    cv::Rect boundingRect = cv::boundingRect(contours[maxContourIndex]);  
    cv::RotatedRect minAreaRect = cv::minAreaRect(contours[maxContourIndex]);  
    res.first = boundingRect;  
    res.second = minAreaRect;  
    return res;
}