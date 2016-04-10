
#include <iostream>
#include <sstream>
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
	Mat src = imread("../../media/target.png");
	cvtColor(src, src, CV_RGB2GRAY);
	threshold(src, src, 10, 255, CV_THRESH_BINARY_INV);
	imshow("src", src);

	int arr[4] = { 3,5,9,13 };
	for (int i=0; i < 4; ++i)
	{
		Mat dst1;
		Sobel(src, dst1, CV_16S, 1, 0, arr[i]);
		Mat dst2;
		Sobel(src, dst2, CV_16S, 0, 1, arr[i]);
		Mat dst;
		addWeighted(dst1, 0.5, dst2, 0.5, 0, dst);
		convertScaleAbs(dst, dst);

		stringstream ss;
		ss << "dst " << arr[i];
		imshow(ss.str().c_str(), dst);
	}

	waitKey();
}
