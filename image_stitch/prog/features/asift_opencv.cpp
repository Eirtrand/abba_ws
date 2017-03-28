#include "asift_opencv.h"
#include "asift.h"
#include "common.h"

AsiftFeatureDetector::AsiftFeatureDetector() {};

AsiftKeyPoint::AsiftKeyPoint(const keypoint& kp): cv::KeyPoint(cv::Point2d(kp.x, kp.y), kp.scale, kp.angle) {
    setDescriptor(kp.vec);
};


void AsiftFeatureDetector::detectImpl(const cv::Mat& image, vector<cv::KeyPoint>& keypoints,
                                      const cv::Mat& mask) const {
    keypoints.resize(5);
    return ;
}


void AsiftDescriptorExtractor::computeImpl(const cv::Mat& image, vector<cv::KeyPoint>& keypoints,
                                           cv::Mat& descriptors) const{
    vector<vector<keypointslist> > keys;
    int num_kp = asiftDetect(image, keys);
    AsiftKeyPoint akp;
    
    keypoints.resize(0);
    descriptors.create(num_kp, descriptorSize(), CV_32F);
    
    vector<AsiftKeyPoint> akps;
    flatten_kps<AsiftKeyPoint>(keys, akps);
    
    for (int i = 0; i < num_kp; i++) {
        keypoints.push_back(akps[i]);
        for (int l = 0; l < descriptorSize(); ++l) {
            ((float*)descriptors.ptr(i))[l] = akps[i].getDescriptor()[l] / 255.0;
        }
    }
}

int AsiftDescriptorExtractor::descriptorSize() const {
    return 128;
}

int AsiftDescriptorExtractor::descriptorType() const {
    return 0;
}


void AsiftDetectorMatcher::train(const cv::Mat& image) {
    train_image = image;
    num_kps = asiftDetect(image, keypoints);
    flatten_kps<cv::KeyPoint>(keypoints, cv_keypoints);
}
vector<cv::KeyPoint>& AsiftDetectorMatcher::getTrainKeypoints() {
    return cv_keypoints;
}


int AsiftDetectorMatcher::matchImage(const cv::Mat& image, vector<cv::KeyPoint>& other_kps, vector<cv::DMatch>& matches) {
    vector<vector<keypointslist> > other_keypoints;
    asiftDetect(image, other_keypoints);
    flatten_kps<cv::KeyPoint>(other_keypoints, other_kps);
    matchingslist matchings;
    int num_matches = asiftMatches(keypoints, other_keypoints, train_image.cols, train_image.rows, image.cols, image.rows, matchings);
    
    matchingslist_to_dmatches(matchings, matches, cv_keypoints, other_kps);
    return num_matches;
}

