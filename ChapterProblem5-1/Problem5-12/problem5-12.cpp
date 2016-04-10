
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
	Mat src = imread("../../media/fruits.jpg");
	cvtColor(src, src, CV_RGB2GRAY);
	imshow("src", src);

	Mat dst;
	threshold(src, dst, 100, 255, CV_THRESH_BINARY);
	imshow("dst", dst);
// 
// 	threshold(src, dst, 100, 255, CV_THRESH_BINARY_INV);
// 	imshow("dst binary inverse", dst);
// 
// 	threshold(src, dst, 100, 255, CV_THRESH_TOZERO);
// 	imshow("dst tozero", dst);
// 
// 	threshold(src, dst, 100, 255, CV_THRESH_TRUNC);
// 	imshow("dst trunc", dst);
// 
// 	threshold(src, dst, 100, 255, CV_THRESH_TOZERO_INV);
// 	imshow("dst tozero inverse", dst);

	Mat adapDst1;
	cv::adaptiveThreshold(src, adapDst1, 255, CV_ADAPTIVE_THRESH_GAUSSIAN_C, CV_THRESH_BINARY, 5, 5);
	imshow("adapDst +5", adapDst1);

	Mat adapDst2;
	cv::adaptiveThreshold(src, adapDst2, 255, CV_ADAPTIVE_THRESH_GAUSSIAN_C, CV_THRESH_BINARY, 5, -5);
	imshow("adapDst -5", adapDst2);

	waitKey();
}
