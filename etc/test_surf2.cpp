#include <stdio.h>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include <math.h>
#include <cv.h>
#include <highgui.h>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <math.h>
#include <fstream>
#include <iostream>
#include <iostream>
#include <ctype.h>

using namespace cv;
using namespace std;



int main( int argc, char** argv ){
Mat img_template = imread("images.jpg"); // read template image
void surf_detection(Mat img_1,Mat img_2)
{ 

if( !img_1.data || !img_2.data )
{ 
    std::cout<< " --(!) Error reading images " << std::endl; 

}
//-- Step 1: Detect the keypoints using SURF Detector
int minHessian = 400;
SurfFeatureDetector detector( minHessian );
std::vector<KeyPoint> keypoints_1, keypoints_2;
std::vector< DMatch > good_matches;

do{ 

detector.detect( img_1, keypoints_1 );
detector.detect( img_2, keypoints_2 );

//-- Draw keypoints

Mat img_keypoints_1; Mat img_keypoints_2;
drawKeypoints( img_1, keypoints_1, img_keypoints_1, Scalar::all(-1), DrawMatchesFlags::DEFAULT );
drawKeypoints( img_2, keypoints_2, img_keypoints_2, Scalar::all(-1), DrawMatchesFlags::DEFAULT );

//-- Step 2: Calculate descriptors (feature vectors)
SurfDescriptorExtractor extractor;
Mat descriptors_1, descriptors_2;
extractor.compute( img_1, keypoints_1, descriptors_1 );
extractor.compute( img_2, keypoints_2, descriptors_2 );


//-- Step 3: Matching descriptor vectors using FLANN matcher
FlannBasedMatcher matcher;
std::vector< DMatch > matches;
matcher.match( descriptors_1, descriptors_2, matches );
double max_dist = 0; 
double min_dist = 100;

//-- Quick calculation of max and min distances between keypoints
for( int i = 0; i < descriptors_1.rows; i++ )
{ 
    double dist = matches[i].distance;
if( dist < min_dist )
    min_dist = dist;
if( dist > max_dist ) 
    max_dist = dist;
}

std::cout("-- Max dist : %f \n", max_dist );
std::cout("-- Min dist : %f \n", min_dist );

//-- Draw only "good" matches (i.e. whose distance is less than 2*min_dist )
//-- PS.- radiusMatch can also be used here.



for( int i = 0; i < descriptors_1.rows; i++ )
{ 
    if( matches[i].distance < 2*min_dist )
        { 
                good_matches.push_back( matches[i]);
        }
}

}while(good_matches.size()<100);

//-- Draw only "good" matches
Mat img_matches;
drawMatches( img_1, keypoints_1, img_2, keypoints_2,good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );

//-- Localize the object
std::vector<Point2f> obj;
std::vector<Point2f> scene;
for( int i = 0; i < good_matches.size(); i++ )
{
//-- Get the keypoints from the good matches
obj.push_back( keypoints_1[ good_matches[i].queryIdx ].pt );
scene.push_back( keypoints_2[ good_matches[i].trainIdx ].pt );
}

// se non trova H....sarebbe da usare la vecchia H e disegnarla con un colore diverso
Mat H = findHomography( obj, scene, CV_RANSAC );


//-- Get the corners from the image_1 ( the object to be "detected" )
std::vector<Point2f> obj_corners(4);
obj_corners[0] = cvPoint(0,0); 
obj_corners[1] = cvPoint( img_1.cols, 0 );
obj_corners[2] = cvPoint( img_1.cols, img_1.rows ); 
obj_corners[3] = cvPoint( 0, img_1.rows );
std::vector<Point2f> scene_corners(4);


perspectiveTransform( obj_corners, scene_corners, H);


//-- Draw lines between the corners (the mapped object in the scene - image_2 )
  line( img_matches, scene_corners[0] + Point2f( img_1.cols, 0), scene_corners[1] + Point2f( img_1.cols, 0), Scalar(0, 255, 0), 4 );
  line( img_matches, scene_corners[1] + Point2f( img_1.cols, 0), scene_corners[2] + Point2f( img_1.cols, 0), Scalar( 0, 255, 0), 4 );
  line( img_matches, scene_corners[2] + Point2f( img_1.cols, 0), scene_corners[3] + Point2f( img_1.cols, 0), Scalar( 0, 255, 0), 4 );
  line( img_matches, scene_corners[3] + Point2f( img_1.cols, 0), scene_corners[0] + Point2f( img_1.cols, 0), Scalar( 0, 255, 0), 4 );
return 0;

}