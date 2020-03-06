#include <iostream>
#include <opencv.hpp>
#include <stdlib.h>
using namespace cv;
int main()
{
	Mat drawImage = Mat::zeros(Size(256, 256), CV_8UC3);
	cv::Point pt;
	pt.x = 10;
	pt.y = 10;
	circle(drawImage, pt, 5, CV_RGB(255, 0, 0), 1, 8, 0);
	line(drawImage, Point(0), Point(256), CV_RGB(255, 0, 0), 1, 8, 0);
	cv::Rect rect;
	rect.x = 10;
	rect.y = 10;
	rect.width;
	rect.height;
	rectangle(drawImage, rect, CV_RGB(255, 0, 0), 1, 8, 0);
	imshow("¡¾Í¼ÐÎ¡¿", drawImage);
	waitKey();
}