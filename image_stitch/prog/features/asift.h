#ifndef ASIFT_H
#define ASIFT_H

#include "opencv2/opencv.hpp"
#include "asift_opencv.h"

vector<float> MatToFloatVec(const cv::Mat& mat);

int asiftDetect(const cv::Mat& image, vector<vector<keypointslist> >& keypoints);
int asiftMatches(vector<vector<keypointslist> >& keypoints1, vector<vector<keypointslist> >& keypoints2, int w1, int h1, int w2, int h2,
                 matchingslist& matchings, int num_of_tilts1=7, int num_of_tilts2=7, const int verb = 0);



template<class T> int get_index(vector<T> v, T elem) {
    typename vector<T>::const_iterator it = v.begin();
    for (int i = 0; it != v.end(); it++, i++) {
        if (*it == elem) return i;
    }
    assert(false);
}
void matchingslist_to_dmatches(const matchingslist matchings, vector<cv::DMatch>& matches, const vector<cv::KeyPoint> trainKps,
                               const vector<cv::KeyPoint> queryKps);


template<class KP> void flatten_kps(vector<vector<keypointslist> >& keys, vector<KP> &res) {
    res.resize(0);
    
    AsiftKeyPoint akp;
    
    for (unsigned int i = 0; i < keys.size(); ++i) {
        for (unsigned int j = 0; j < keys[i].size(); ++j) {
            for (unsigned int k = 0; k < keys[i][j].size(); ++k) {
                akp = AsiftKeyPoint(keys[i][j][k]);
                res.push_back(akp);
            }
        }
    }
}


vector<vector<keypointslist> > unflatten_kps(const vector<cv::KeyPoint>& keypoints, const cv::Mat& descriptors);

int match_cv_sift_kps(const vector<cv::KeyPoint> & kps1, const vector<cv::KeyPoint>& kps2,
                      cv::Mat& descriptors1, const cv::Mat& descriptors2, int w1, int h1, int w2, int h2,
                      vector<cv::DMatch> &matches);


#endif
