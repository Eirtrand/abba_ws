#include "settings.h"
#include <cstdlib>

struct InputSetting {
	string capture_fname;
	int skip_frames;
	string reference_fname;
    int skip_ref_frames;
    int prev_frame;
};

InputSetting settings[] = {
	{DATADIR "/IMG_0007.mp4", 75, DATADIR "/20092010094.jpg", 0, 1},
	{DATADIR "/IMG_0008.mp4", 360, DATADIR "/27112010097.jpg", 0, 0},
    {DATADIR "/pisa1.jpg", 0, DATADIR "/pisa2.jpg", 0, 0},
    {DATADIR "/hryvnas.png", 0, DATADIR "/1_hryvnia_2006_front.png", 0, 0},
    {DATADIR "/IMG_0014.mp4", 100, DATADIR "/24042011150.jpg", 0, 0},
    {DATADIR "/24042011152.png", 0, DATADIR "/24042011153.png", 0, 0},
    {DATADIR "/24042011155.png", 0, DATADIR "/24042011153.png", 0, 0},
	{"CAM", 0, DATADIR "/1_hryvnia_2006_front.jpg", 0, 0},
    {DATADIR "/panoram/03052011004.mp4", 170 + 10, DATADIR "/panoram/IMG_0015.mp4", 130 + 10, 0}
};
InputSetting setting = settings[8];
//InputSetting setting = settings[0];

/*InputData::InputData(){
 InputData(cvCaptureFromFile(setting.capture_fname.c_str()), setting.skip_frames, setting.reference_fname);
 };*/
InputData::InputData() {
    capture = (cv::VideoCapture**) malloc(sizeof(cv::VideoCapture*) * 2);
    capture[0] = (setting.capture_fname == "CAM" ? new cv::VideoCapture(0) : new cv::VideoCapture(setting.capture_fname.c_str()));
    capture[1] = new cv::VideoCapture(setting.reference_fname.c_str());
    skipFrames[0] = setting.skip_frames;
    skipFrames[1] = setting.skip_ref_frames;
    match_seq_frames = setting.prev_frame;
}


InputData::~InputData() {
    delete capture[0];
    delete capture[1];
    free(capture);
    capture = NULL;
}
