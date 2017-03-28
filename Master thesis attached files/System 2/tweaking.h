#ifndef TWEAKING_H
#define TWEAKING_H

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

//Cutting the video frame to test what is wanted to test
cv::Mat tweak_video_frame(cv::Mat input_image);

#endif // TWEAKING_H
