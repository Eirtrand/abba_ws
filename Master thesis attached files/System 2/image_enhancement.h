#ifndef IMAGE_ENHANCEMENT_H
#define IMAGE_ENHANCEMENT_H

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

/*using sub_images of a twentieth of the original rowsize
 *equalize so that each sub image gets the same average intensity
 *as the first row.
 *Then does the same with sub_images a fourtieth of the original
 *colsize.
 *Needs an image size with rowsize that divides with 20 and colsize
 *that divides with 40*/
cv::Mat Light_gradient_equalizer(cv::Mat input_img);

/* Taking the top hat of the input image and subtracting that from the
 * input image to reduce light effects from the sun*/
cv::Mat Morpological_light_gradient_equalizer(cv::Mat input_image);

//Using morpological top hat and bottom hat transform to sharpen image
cv::Mat Morpological_contrast_enhancement(cv::Mat input_image);

#endif // IMAGE_ENHANCEMENT_H
