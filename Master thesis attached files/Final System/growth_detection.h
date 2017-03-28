#ifndef GROWTH_DETECTION_H
#define GROWTH_DETECTION_H

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

//Finds percentage of foreground pixels
double percentage_foreground(cv::Mat input_image);

//Finds the percentage of growth on a scale from standard growth to 100% growth
double Growth_Detection_algo(double standard_percentage, cv::Mat input_image);



#endif // GROWTH_DETECTION_H
