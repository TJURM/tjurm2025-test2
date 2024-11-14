#include "impls.h"


float compute_area_ratio(const std::vector<cv::Point>& contour) {
    /**
     * 要求：
     *      计算输入的轮廓的面积与它的最小外接矩形面积的比例。自行查找
     * 获得轮廓面积的函数。这个量可以用来判断一个轮廓到底有多靠近一个矩形。
     * 
     * 提示：
     * 无。
     * 
     * 通过条件:
     * 运行测试点，通过即可。
     */
  
float compute_area_ratio(const std::vector<cv::Point>& contour) {  
  
    double cArea = cv::contourArea(contour);  
    cv::Rect  s= cv::boundingRect(contour);  
    double rArea = s.area();  
    //if (rArea == 0) {  return 0.f;  } 我不知道这个要不要判断一下分母为零的情况，就注释掉了
    return static_cast<float>(cArea / rArea);  
}
    return 0.f;
}