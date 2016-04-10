
#include <iostream>
#include "opencv/cxcore.h"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/video/background_segm.hpp"
#include "opencv2/highgui/highgui.hpp"

#pragma comment(lib, "opencv_core2411d.lib")
#pragma comment(lib, "opencv_highgui2411d.lib")
#pragma comment(lib, "opencv_imgproc2411d.lib")

using namespace std;
using namespace cv;


void main()
{
	Mat img = imread("../../media/baboon.jpg");
	if (img.empty())
		return;

	imshow("src", img);

	Mat gau33 = img.clone();
	GaussianBlur(gau33, gau33, Size(3, 3), -1, -1, 4);
	imshow("gaussian3x3", gau33);

	Mat gau55 = img.clone();
	GaussianBlur(gau55, gau55, Size(5, 5), -1, -1, 4);
	imshow("gaussian5x5", gau55);

	Mat gau99 = img.clone();
	GaussianBlur(gau99, gau99, Size(5, 5), -1, -1, 4);
	imshow("gaussian9x9", gau99);

	Mat gau11 = img.clone();
	GaussianBlur(gau11, gau11, Size(11, 11), -1, -1, 4);
	imshow("gaussian11x11", gau11);

	waitKey();
}
