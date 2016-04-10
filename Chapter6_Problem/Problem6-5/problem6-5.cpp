
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
	Mat src = imread("../../media/line45.png");
	cvtColor(src, src, CV_RGB2GRAY);
	//threshold(src, src, 10, 255, CV_THRESH_BINARY_INV);
	imshow("src", src);

	int arr[3] = { 3,5,9};
	for (int i = 0; i < 3; ++i)
	{
		Mat dst1;
		Sobel(src, dst1, CV_16S, 1, 0, arr[i]);
		convertScaleAbs(dst1, dst1);

		Mat dst2;
		Sobel(src, dst2, CV_16S, 0, 1, arr[i]);
		convertScaleAbs(dst2, dst2);

		double angle = 0;
		int cnt = 0;
		for (int y = 0; y < dst1.rows; ++y)
		{
			for (int x = 0; x < dst1.cols; ++x)
			{
				const int xx = dst1.at<unsigned char>(y, x);
				const int yy = dst2.at<unsigned char>(y, x);
				if ((xx > 0) && (yy > 0))
				{
					angle += atan((float)yy / (float)xx);
					++cnt;
				}
			}
		}

		angle = angle / (double)cnt;

		cout << "num = " << i+1 << ", angle = " << angle << ", tan(angle) = " << tan(angle) << ", cnt = " << cnt << endl;
	}

	waitKey();
}
