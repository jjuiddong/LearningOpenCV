
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

	{
		float ar1[] = {
			-3, 0, 3,
			-10, 0, 10,
			-3, 0, 3,
		};

		Mat dst;
		Mat kernel1(3, 3, CV_32FC1);
		for (int i = 0; i < 9; ++i)
		{
			kernel1.at<float>(i / 3, i % 3) = ar1[i];
		}

		cv::filter2D(src, dst, CV_32F, kernel1);
		convertScaleAbs(dst, dst);
		imshow("dst1", dst);

		float ar2[] = { -3, 0, 3 };
		Mat kernel2(1, 3, CV_32FC1);
		for (int i = 0; i < 3; ++i)
		{
			kernel2.at<float>(i / 3, i % 3) = ar2[i];
		}

		float ar3[] = { 1, 10.f / 3.f, 1 };
		Mat kernel3(3, 1, CV_32FC1);
		for (int i = 0; i < 3; ++i)
		{
			kernel3.at<float>(i % 3, i / 3) = ar3[i];
		}

		cv::filter2D(src, dst, CV_32F, kernel2);
		cv::filter2D(dst, dst, CV_32F, kernel3);
		convertScaleAbs(dst, dst);
		imshow("dst 1x3 - 3x1", dst);
	}


	{
		float ar1[] = {
			-3, -10, -3,
			0, 0, 0,
			3, 10, 3,
		};

		Mat dst;
		Mat kernel1(3, 3, CV_32FC1);
		for (int i = 0; i < 9; ++i)
		{
			kernel1.at<float>(i / 3, i % 3) = ar1[i];
		}

		cv::filter2D(src, dst, CV_32F, kernel1);
		convertScaleAbs(dst, dst);
		imshow("dst2", dst);

		float ar2[] = { 3, 10, 3 };
		Mat kernel2(1, 3, CV_32FC1);
		for (int i = 0; i < 3; ++i)
		{
			kernel2.at<float>(i / 3, i % 3) = ar2[i];
		}

		float ar3[] = { -1, 0, 1 };
		Mat kernel3(3, 1, CV_32FC1);
		for (int i = 0; i < 3; ++i)
		{
			kernel3.at<float>(i % 3, i / 3) = ar3[i];
		}

		cv::filter2D(src, dst, CV_32F, kernel2);
		cv::filter2D(dst, dst, CV_32F, kernel3);
		convertScaleAbs(dst, dst);
		imshow("dst2 1x3 - 3x1", dst);
	}


	waitKey();
}
