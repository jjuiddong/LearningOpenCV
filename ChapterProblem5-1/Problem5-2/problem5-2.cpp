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
	Mat img(Size(100, 100), CV_32F, Scalar(0));
	int n = img.step;
	*(float*)(img.data + (img.step * 50) + (img.elemSize()*50)) = 255;

	imshow("src", img);

 	Mat gau55 = img.clone();
 	GaussianBlur(gau55, gau55, Size(5, 5), -1, -1, 4);
	imshow("gaussian5x5", gau55);

	Mat gau552 = gau55.clone();
	GaussianBlur(gau552, gau552, Size(5, 5), -1, -1, 4);
	imshow("gaussian5x52", gau552);

	Mat gau99 = img.clone();
	GaussianBlur(gau99, gau99, Size(9, 9), -1, -1, 4);
	imshow("gaussian9x9", gau99);

	waitKey();
}
