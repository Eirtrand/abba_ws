#ifndef DETECTOR_MATCHER_H
#define DETECTOR_MATCHER_H
#include "opencv2/opencv.hpp"


class DetectorMatcher {
public:
	DetectorMatcher() {};
	virtual void train(const cv::Mat&) = 0;
	virtual vector<cv::KeyPoint>& getTrainKeypoints() = 0;
	virtual int matchImage(const cv::Mat&, vector<cv::KeyPoint>&, vector<cv::DMatch>&) = 0;
	virtual ~DetectorMatcher() {};
};


template<class FD, class DE> class UsualDetectorMatcher : public DetectorMatcher {
public:
	UsualDetectorMatcher() {
		detector = new FD();
		extractor = new DE();
//        matcher = new cv::BruteForceMatcher< cv::L2<float> >;
        matcher = new cv::FlannBasedMatcher();
	}
	
	virtual void train(const cv::Mat& image) {	
		detector->detect(image, keypoints);
		extractor->compute(image, keypoints, descriptors);	
        matcher->clear();
		matcher->add(vector<cv::Mat>(1, descriptors));
        this->descriptors = descriptors;
	}
	
	virtual vector<cv::KeyPoint>& getTrainKeypoints() {
		return keypoints;
	}
	
	virtual int matchImage(const cv::Mat& image, vector<cv::KeyPoint>& other_keypoints, vector<cv::DMatch>& matches)  {
		cv::Mat other_descriptors;
		detector->detect(image, other_keypoints);
        extractor->compute(image, other_keypoints, other_descriptors);
        matcher->match(other_descriptors, matches);
		return matches.size();
	}
    
	virtual ~UsualDetectorMatcher() {
		delete detector;
		delete extractor;
		delete matcher;
	}
    
    vector<cv::KeyPoint> keypoints;
protected:
	cv::FeatureDetector* detector;
	cv::DescriptorExtractor* extractor;
	cv::DescriptorMatcher* matcher;
    cv::Mat descriptors;
};

typedef UsualDetectorMatcher<cv::SurfFeatureDetector, cv::SurfDescriptorExtractor> SurfDetectorMatcher;
typedef UsualDetectorMatcher<cv::SiftFeatureDetector, cv::SiftDescriptorExtractor> SiftDetectorMatcher;


class SiftDetectorAsiftMatcher : public SiftDetectorMatcher {
    virtual void train(const cv::Mat& image);
    virtual int matchImage(const cv::Mat& image, 
                           vector<cv::KeyPoint>& other_keypoints, 
                           vector<cv::DMatch>& matches);
private:
    cv::Mat train_image;
};

class SurfDetectorAsiftMatcher : public SurfDetectorMatcher {
    virtual void train(const cv::Mat& image);
    virtual int matchImage(const cv::Mat& image, 
                           vector<cv::KeyPoint>& other_keypoints, 
                           vector<cv::DMatch>& matches);
private:
    cv::Mat train_image;
};

#endif
