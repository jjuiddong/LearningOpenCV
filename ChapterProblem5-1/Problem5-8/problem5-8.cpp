
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
// 	Mat src(500, 500, CV_8UC1);// CV_32F);
// 	src.setTo(Scalar(0));
// 
// 	for (int x = 0; x < 500; ++x)
// 	{
// 		for (int y = 0; y < 500; ++y)
// 		{
// 			src.at<unsigned char>(x,y) = 100+ (rand()%3);
// 		}
// 	}
// 
// 	imshow("src", src);
// 	imwrite("src.jpg", src);

	Mat src = imread("src1.jpg");
	Mat dst;
	cv::bilateralFilter(src, dst, 9, 18, 2);

	imshow("src", src);
	imshow("dst", dst);
	waitKey();
}


