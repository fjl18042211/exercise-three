#include <iostream>
#include <opencv.hpp>
#include <stdlib.h>
using namespace cv;
using namespace std;
int main()
{
	cv::Mat canny;
	cv::Mat srcMat = cv::imread("D:\\metal-part-distorted-03.png", 1);
	if (srcMat.empty()) return-1;
	Canny(srcMat, canny, 60, 180);
	cv::imshow("canny", canny);
	std::vector<cv::Vec4i>lines;
	cv::HoughLinesP(canny, lines, 1, CV_PI / 180, 50,20,10);
	std::vector<cv::Vec4i>::iterator it = lines.begin();
	for (size_t i = 0; i < lines.size(); i++)
	{
		Vec4i l = lines[i];
		line(srcMat, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 1, CV_AA);
	}
	imshow("src", srcMat);
	cv::waitKey(0);

}