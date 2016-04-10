
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
	Mat src = imread("../../media/face3.jpg");
	cvtColor(src, src, CV_RGB2GRAY);
	GaussianBlur(src, src, cv::Size(5, 5), 0);
	imshow("src", src);

	int arr[3] = { 3,5,9 };
	for (int i = 0; i < 3; ++i)
	{
		Mat dst1;
		Laplacian(src, dst1, CV_16S, arr[i], 1);
		convertScaleAbs(dst1, dst1);
		threshold(dst1, dst1, 30, 255, CV_THRESH_BINARY);
 		dilate(dst1, dst1, Mat());
 		erode(dst1, dst1, Mat(), Point(-1,-1), 3);

		stringstream ss;
		ss << "raplacian " << i + 1;
		imshow(ss.str().c_str(), dst1);
	}

	waitKey();
}
