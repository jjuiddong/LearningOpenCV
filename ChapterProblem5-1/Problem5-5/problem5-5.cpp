
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
	Mat img1 = imread("tsukuba_l.png");
	Mat img2 = imread("tsukuba_r.png");

	Mat img12;
	absdiff(img1, img2, img12);

	imshow("diff", img12);

	Mat clean_diff = img12.clone();
	erode(clean_diff, clean_diff, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)));
	dilate(clean_diff, clean_diff, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)));
	imshow("clean_diff erode dilate", clean_diff);

	Mat dirty_diff = img12.clone();
	dilate(dirty_diff, dirty_diff, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)));
	erode(dirty_diff, dirty_diff, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)));
	imshow("dirty_diff dilate erode", dirty_diff);

	Mat mop_diff = dirty_diff.clone();
	morphologyEx(mop_diff, mop_diff, CV_MOP_OPEN, 
		getStructuringElement(cv::MORPH_RECT, cv::Size(9, 9)));
	imshow("morpohlogy dirty_diff ", mop_diff);

	Mat thresh_diff = mop_diff.clone();
	dilate(thresh_diff, thresh_diff, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)));
	erode(thresh_diff, thresh_diff, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)));
	threshold(thresh_diff, thresh_diff, 1, 255, THRESH_BINARY);
	imshow("threshold dirty_diff ", thresh_diff);

	waitKey();
}
