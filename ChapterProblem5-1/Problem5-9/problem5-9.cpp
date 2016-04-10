
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
	Mat src = imread("../../media/building.jpg");
	Mat mask;
	cv::morphologyEx(src, mask, CV_MOP_TOPHAT, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)));
	threshold(mask, mask, 10, 255, CV_THRESH_BINARY);

	Mat dst;
	src.copyTo(dst, mask);

	imshow("src", src);
	imshow("mask", mask);
	imshow("dst", dst);

	waitKey();
}
