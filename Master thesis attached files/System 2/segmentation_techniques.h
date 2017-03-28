#ifndef SEGMENTATION_TECHNIQUES_H
#define SEGMENTATION_TECHNIQUES_H

#include "histogram_segmentation.h"

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>


//Segmentation using edge detection, Sobel
cv::Mat Global_Sobel(cv::Mat input_img,int kernel_size,int histogram_percentile, int dx,int dy,bool Otsu);
cv::Mat Local_Sobel(cv::Mat input_img,int sub_images,int kernel_size,int histogram_percentile, int dx,int dy,bool Otsu,double x_weight, double y_weight);

//Segmentation using edge detection, Scharr
cv::Mat Global_Scharr(cv::Mat input_img,int histogram_percentile, bool dx_checked,bool dy_checked,bool Otsu);
cv::Mat Local_Scharr(cv::Mat input_img,int sub_images,bool using_histogram_percentile,int histogram_percentile,bool using_threshold,int threshold, bool dx_checked,bool dy_checked,bool Otsu,double x_weight, double y_weight);

//Segmentation using edge detection, Laplace
cv::Mat Global_Laplace(cv::Mat input_img,int kernel_size,int histogram_percentile);

//Segmentation using Otsu's mehod
cv::Mat Global_Otsu(cv::Mat input_img);
cv::Mat Local_Otsu(cv::Mat input_img, int sub_images);
cv::Mat Local_Otsu_neighbourhood(int x, int y,int width, int height,cv::Mat sub_image,cv::Mat output_image);

//Segmentation using naive or adaptive thresholding
cv::Mat Naive_Thresholding(cv::Mat input_img,int threshold);
cv::Mat Adaptive_Thresholding(cv::Mat input_img,int kernel_size,int C,bool Gaussian);


#endif // SEGMENTATION_TECHNIQUES_H
