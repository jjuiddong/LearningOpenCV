
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
	Mat src = imread("../../media/bicycle1.jpg");
	cvtColor(src, src, CV_RGB2GRAY);
	GaussianBlur(src, src, cv::Size(5, 5), 0);
	imshow("src", src);

	float ar[] = { 1.5f, 2.75f, 4.f };
	for (int i = 0; i < 3; ++i)
	{
		const int thr = 100;
		const int thr2 = (int)(thr * ar[i]);

		Mat dst;
		Canny(src, dst, thr, thr2);

		stringstream ss;
		ss << "dst " << i + 1;
		imshow(ss.str().c_str(), dst);
	}

	waitKey();
}
