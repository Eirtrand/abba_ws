#ifndef HOLE_DETECTION_H
#define HOLE_DETECTION_H

#include <QList>
#include <QFile>

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

//Algorithm to detect damaged areas in sea cages
cv::Mat Hole_detection_algo(cv::Mat input_img);

//Grows region from a seed pixel, if the region contains pixels at the top AND bottom border
//or left AND right border the area is set to 0 to exclude the region from further processing
//This to eliminate false areas present during testing.
cv::Vec6i Region_Growing(cv::Mat input_img,int x, int y, int color);


#endif // HOLE_DETECTION_H
