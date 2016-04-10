
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
	Mat src = imread("../../media/lena.jpg");
	cvtColor(src, src, CV_RGB2GRAY);
	imshow("src", src);

	float ar1[] = {
		1.f/16.f, 2.f/16.f, 1.f/16.f,
		2.f/16.f, 4.f/16.f, 2.f/16.f,
		1.f/16.f, 2.f/16.f, 1.f/16.f,
	};

	Mat dst;
	Mat kernel1(3, 3, CV_32FC1);
	for (int i = 0; i < 9; ++i)
	{
		kernel1.at<float>(i / 3, i % 3) = ar1[i];
	}

	cv::filter2D(src, dst, CV_32F, kernel1);
	convertScaleAbs(dst, dst);
	imshow("dst", dst);


	float ar2[] = { 1.f/4.f, 2.f/4.f, 1.f/4.f };
	Mat kernel2(1, 3, CV_32FC1);
	for (int i = 0; i < 3; ++i)
	{
		kernel2.at<float>(i / 3, i % 3) = ar2[i];
	}
	cv::filter2D(src, dst, CV_32F, kernel2);
	convertScaleAbs(dst, dst);
	imshow("dst 1x3 1,2,1", dst);


	Mat kernel3(3, 1, CV_32FC1);
	for (int i = 0; i < 3; ++i)
	{
		kernel3.at<float>(i % 3, i / 3) = ar2[i];
	}
	cv::filter2D(dst, dst, CV_32F, kernel3);
	convertScaleAbs(dst, dst);
	imshow("dst 1x3 - 3x1", dst);

	waitKey();
}
