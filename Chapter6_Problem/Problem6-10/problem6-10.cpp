
#include <iostream>
#include <sstream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/video/background_segm.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/contrib/contrib.hpp"

#pragma comment(lib, "opencv_core2411d.lib")
#pragma comment(lib, "opencv_highgui2411d.lib")
#pragma comment(lib, "opencv_imgproc2411d.lib")
#pragma comment(lib, "opencv_contrib2411d.lib")

using namespace std;
using namespace cv;

void main()
{
	Mat source = imread("../../media/rect.png");
	cvtColor(source, source, CV_RGB2GRAY);

	// a
	int R = 300; // radius.
	int sectors = 200; // sectors
	int ro0 = 3; // blind spost
	int w = source.cols;
	int h = source.rows;
	cv::Point2i center(source.cols / 2, source.rows / 2);
	LogPolar_Adjacent adj(w, h, center, R, ro0, 1, sectors);
	Mat logpolar = adj.to_cortical(source);
	//Mat retinal = adj.to_retinal(logpolar);

	imshow("src", source);
	imshow("logpolar", logpolar);

	// b
	Mat source2 = imread("../../media/circle.png");
	cvtColor(source2, source2, CV_RGB2GRAY);
	Mat logpolar2 = adj.to_cortical(source2);
	imshow("logpolar2", logpolar2);

	// c
	cv::Point2i center2(500, 200);
	LogPolar_Adjacent adj2(w, h, center2, R, ro0, 1, sectors);
	Mat logpolar3 = adj2.to_cortical(source2);
	//Mat logpolar3 = adj2.to_cartesian(source2);
	imshow("logpolar3", logpolar3);


	waitKey();
}
