
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
	Mat src = imread("../../media/baboon.jpg");

	Mat dst2;
	cv::resize(src, dst2, Size(src.rows/2, src.cols/2));
	Mat dst4;
	cv::resize(dst2, dst4, Size(dst2.rows / 2, dst2.cols / 2));
	Mat dst8;
	cv::resize(dst4, dst8, Size(dst4.rows / 2, dst4.cols / 2));

	imshow("src", src);
	imshow("dst2", dst2);
	imshow("dst4", dst4);
	imshow("dst8", dst8);


	Mat dstP2;
	cv::pyrDown(src, dstP2, Size(src.rows / 2, src.cols / 2));
	Mat dstP4;
	cv::pyrDown(dstP2, dstP4, Size(dstP2.rows / 2, dstP2.cols / 2));
	Mat dstP8;
	cv::pyrDown(dstP4, dstP8, Size(dstP4.rows / 2, dstP4.cols / 2));

	imshow("dstP2", dstP2);
	imshow("dstP4", dstP4);
	imshow("dstP8", dstP8);

	waitKey();
}
