#ifndef COLORSPACES_H
#define COLORSPACES_H

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

//xyY color space using OpenCV RGB2XYZ
cv::Mat standard_x(cv::Mat input_image);
cv::Mat standard_y(cv::Mat input_image);
cv::Mat standard_Y(cv::Mat input_image);

//xyY color space using custom made RGB2XYZ
cv::Mat custom_x(cv::Mat input_image);
cv::Mat custom_y(cv::Mat input_image);
cv::Mat custom_Y(cv::Mat input_image);

//RGB color space
cv::Mat red_space(cv::Mat input_image);
cv::Mat green_space(cv::Mat input_image);
cv::Mat blue_space(cv::Mat input_image);

//L*a*b* color space
cv::Mat L_space(cv::Mat input_image);
cv::Mat a_space(cv::Mat input_image);
cv::Mat b_space(cv::Mat input_image);


#endif // COLORSPACES_H
