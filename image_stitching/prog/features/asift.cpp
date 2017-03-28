#include "compute_asift_keypoints.h"
#include "compute_asift_matches.h"

#include "opencv2/opencv.hpp"
#include "asift_opencv.h"
#include "common.h"
#include "asift.h"

vector<float> MatToFloatVec(const cv::Mat& mat)  {
	return vector<float>(mat.begin<uchar>(), mat.end<uchar>());
}

int asiftDetect(const cv::Mat& image, vector<vector<keypointslist> >& keypoints) {
	vector<float> image_vec = MatToFloatVec(image);
	
	siftPar siftparameters;
	default_sift_parameters(siftparameters);
	int num_kp = compute_asift_keypoints(image_vec, image.cols, image.rows, 7, 0, keypoints, siftparameters);
	return num_kp;
}

int asiftMatches(vector<vector<keypointslist> >& keypoints1, vector<vector<keypointslist> >& keypoints2, int w1, int h1, int w2, int h2,
                 matchingslist& matchings, int num_of_tilts1, int num_of_tilts2, const int verb) {
	siftPar siftparameters;
	default_sift_parameters(siftparameters);
	
	int num_matchings;
	num_matchings = compute_asift_matches(num_of_tilts1, num_of_tilts2, w1, h1, w2, 
                                          h2, verb, keypoints1, keypoints2, matchings, siftparameters);
	return num_matchings;
	
}


void matchingslist_to_dmatches(const matchingslist matchings, vector<cv::DMatch>& matches, const vector<cv::KeyPoint> trainKps,
                               const vector<cv::KeyPoint> queryKps) {
    matches.resize(0);
    cv::DMatch match;
    for(unsigned int i = 0; i < matchings.size(); i++) {
        match.trainIdx = get_index(trainKps, (cv::KeyPoint)AsiftKeyPoint(matchings[i].first));
        match.queryIdx = get_index(queryKps, (cv::KeyPoint)AsiftKeyPoint(matchings[i].second));
        matches.push_back(match);
    }
}

void conv_keypoint(cv::KeyPoint cv_kp, cv::Mat descriptor, keypoint &res) {
    res.x = cv_kp.pt.x;
    res.y = cv_kp.pt.y;
    res.scale = cv_kp.size;
    res.angle = cv_kp.angle;
    
    int i;
    for (i = 0; i < min(VecLength, descriptor.cols); i++) {
        res.vec[i] = (float)descriptor.at<float>(0, i);
    }
    for (; i < VecLength; i++) {
        res.vec[i] = 0;
    }
}

vector<vector<keypointslist> > unflatten_kps(const vector<cv::KeyPoint>& keypoints, const cv::Mat& descriptors) {
    vector<vector<keypointslist> > res(1);
    res[0].push_back(keypointslist(keypoints.size()));
    vector<cv::KeyPoint>::const_iterator it;
    unsigned int i = 0;
    for (it = keypoints.begin(); it != keypoints.end(); i++, it++) {
        conv_keypoint(*it, descriptors.row(i) * 255., res[0][0][i]);
    }
    return res;
}

int match_cv_sift_kps(const vector<cv::KeyPoint> & kps1, const vector<cv::KeyPoint>& kps2,
                      cv::Mat& descriptors1, const cv::Mat& descriptors2,
                      int w1, int h1, int w2, int h2,
                      vector<cv::DMatch> &matches) {
    matchingslist matchings;
    vector<vector<keypointslist> > keypointslist1 = unflatten_kps(kps1, descriptors1);
    vector<vector<keypointslist> > keypointslist2 = unflatten_kps(kps2, descriptors2);
    int num_matches = asiftMatches(keypointslist1, keypointslist2, w1, h1, w2, h2, matchings, 1, 1, 1);
    matchingslist_to_dmatches(matchings, matches, kps1, kps2);
    return num_matches;
}
