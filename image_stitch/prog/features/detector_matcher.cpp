#include "detector_matcher.h"
#include "asift.h"


int SiftDetectorAsiftMatcher::matchImage(const cv::Mat& image, vector<cv::KeyPoint>& other_keypoints, vector<cv::DMatch>& matches) {
    cv::Mat other_descriptors;
    detector->detect(image, other_keypoints);
    extractor->compute(image, other_keypoints, other_descriptors);
    return match_cv_sift_kps(keypoints, other_keypoints,
                             descriptors, other_descriptors,
                             train_image.cols, train_image.rows,
                             image.cols, image.rows, matches);
}
void SiftDetectorAsiftMatcher::train(const cv::Mat& image) {
    SiftDetectorMatcher::train(image);
    train_image = image;
}

int SurfDetectorAsiftMatcher::matchImage(const cv::Mat& image, vector<cv::KeyPoint>& other_keypoints, vector<cv::DMatch>& matches) {
    cv::Mat other_descriptors;
    detector->detect(image, other_keypoints);
    extractor->compute(image, other_keypoints, other_descriptors);
    return match_cv_sift_kps(keypoints, other_keypoints,
                             descriptors, other_descriptors,
                             train_image.cols, train_image.rows,
                             image.cols, image.rows, matches);
}
void SurfDetectorAsiftMatcher::train(const cv::Mat& image) {
    SurfDetectorMatcher::train(image);
    train_image = image;
}

