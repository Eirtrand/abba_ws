#include "test.h"




using namespace cv;
using namespace std;



int main(){

CvCapture *camera=cvCaptureFromFile("video.mp4");
if (camera==NULL)
    printf("camera is null\n");
else
    printf("camera is not null");

cvNamedWindow("img");

while (cvWaitKey(10)!=atoi("q")){
    double t1=(double)cvGetTickCount();
    IplImage *img=cvQueryFrame(camera);
    Mat mtx = cv::cvarrToMat(img);
    double growth = Growth_Detection_algo(50.0,mtx);


    double t2=(double)cvGetTickCount();


    printf("time: %gms  fps: %.2g\n   growth: %.2g\n",(t2-t1)/(cvGetTickFrequency()*1000.), 1000./((t2-t1)/(cvGetTickFrequency()*1000.)), growth);
    cvShowImage("img",img);

}
cvReleaseCapture(&camera);
}