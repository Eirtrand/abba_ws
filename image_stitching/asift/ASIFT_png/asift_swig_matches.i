%module asift_swig_matches
%include "numpy.i"

%{
#include "compute_asift_matches.cpp"
typedef std::vector<keypointslist> keypointslistlist;
%}

/*%include "carrays.i"
%array_functions(float, float_arr);
*/


%include "std_vector.i"
%include "std_pair.i"
using namespace std;

%include "demo_lib_sift.h"

// Keypoints:
#define OriSize  8
#define IndexSize  4
#define VecLength  IndexSize * IndexSize * OriSize
typedef struct {
	float	x,y,
		scale,
		angle;
	float	vec[VecLength];
} keypoint;
typedef std::vector<keypoint> keypointslist;
typedef std::vector<keypointslist> keypointslistlist;

%template(keypointslist) vector<keypoint>;
%template(keypointslistlist) vector<keypointslist>;
%template(keypointslistlistlist) vector<keypointslistlist>;
%template(vectorf) vector<float>;

typedef std::pair<keypoint, keypoint> matching;
typedef std::vector<matching> matchingslist;

%template(matching) pair<keypoint,keypoint>;
%template(matchingslist) vector<matching>;

int compute_asift_matches(int num_of_tilts1,
                          int num_of_tilts2, 
                          int w1, int h1, 
                          int w2, int h2, 
                          int verb,
                          vector< vector< keypointslist > >& keys1,
                          vector< vector< keypointslist > >& keys2,
                          matchingslist &OUTPUT,
                          siftPar &siftparameters
                          );

