// 가우시안 필터

#include <iostream>
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

	Mat gau332 = img.clone();
	GaussianBlur(gau332, gau332, Size(3, 3), 2, 3, 4);
	imshow("gaussian3x3 2", gau332);

	waitKey();
}
