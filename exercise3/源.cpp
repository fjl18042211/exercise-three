#include <iostream>
#include <opencv.hpp>
#include <stdlib.h>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat binaryMat;
	cv::Mat labelMat;
	cv::Mat statsMat;
	cv::Mat centrMat;
	cv::Mat resultMat;
	cv::Mat	M1;
	cv::Mat srcMat = imread("D:\\5.jpg", 0);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	morphologyEx(srcMat, M1, MORPH_OPEN, kernel);
	imshow("M1", M1);
	cv::threshold(M1, binaryMat, 0, 255, THRESH_OTSU);
	int nComp = cv::connectedComponentsWithStats(binaryMat,
		labelMat,
		statsMat,
		centrMat,
		8,
		CV_32S);
	cout << "the total of connected Components = " << nComp - 1 << endl;
	resultMat = cv::Mat::zeros(srcMat.size(), CV_8UC3);
	for (int i = 1; i < nComp; i++)
	{
		char num[10];
		sprintf_s(num, "%d", i);

		Rect bndbox;
		bndbox.x = statsMat.at<int>(i, 0);
		bndbox.y = statsMat.at<int>(i, 1);
		bndbox.width = statsMat.at<int>(i, 2);
		bndbox.height = statsMat.at<int>(i, 3);
		rectangle(resultMat, bndbox, CV_RGB(255, 255, 255), 1, 8, 0);
	}
	imshow("binaryMat", binaryMat);
	imshow("results", resultMat);
	waitKey(0);
	return 0;
}