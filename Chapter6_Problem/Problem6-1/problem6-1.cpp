
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
	Mat src = imread("../../media/lines.png");
	cvtColor(src, src, CV_RGB2GRAY);
	threshold(src, src, 10, 255, CV_THRESH_BINARY_INV);
	imshow("src", src);

	float ar1[] = {
// 		1,-2,1,
// 		2,-4,2,
// 		1,-2,1,

// 		1,-2,1,
// 		1,-4,1,
// 		1,-2,1,

		// horizontal change
		-1, 0, 1,
		-2, 0, 2,
		-1, 0, 1,

		// vertical change
// 		-1, -2, -1,
// 		0, 0, 0,
// 		1, 2, 1,


// 		-2,-1, -2,
// 		0, 0, 0,
// 		-2,-1, -2,

// 		1,0,1,
// 		1,0,1,
// 		1,0,1
	};

	float ar2[] = {
		// vertical change
		-1, -2, -1,
		0, 0, 0,
		1, 2, 1,
	};

	Mat dst;
	Mat kernel1(3,3, CV_32FC1);
	Mat kernel2(3, 3, CV_32FC1);

	for (int i = 0; i < 9; ++i)
	{
		kernel1.at<float>(i / 3, i % 3) = ar1[i];
		kernel2.at<float>(i / 3, i % 3) = ar2[i];
	}

	cv::filter2D(src, dst, CV_32F, kernel1);
	cv::filter2D(dst, dst, CV_32F, kernel2);
	convertScaleAbs(dst, dst);
	erode(dst, dst, Mat(5,5, CV_32FC1));
	dilate(dst, dst, Mat(5, 5, CV_32FC1));

	imshow("dst", dst);


// 	Mat dstx;
// 	Sobel(src, dstx, CV_16S, 1, 0, 3);
// 	convertScaleAbs(dstx, dstx);
// 	imshow("gradx", dstx);
// 
// 	Mat dsty;
// 	Sobel(src, dsty, CV_16S, 0, 1, 3);
// 	convertScaleAbs(dsty, dsty);
// 	imshow("grady", dsty);
// 
// 	Mat dst;
// 	addWeighted(dstx, 0.5, dsty, 0.5, 0, dst);
// 
// 	imshow("sobel", dst);

	waitKey();
}
