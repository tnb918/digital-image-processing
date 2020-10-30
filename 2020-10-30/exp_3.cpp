#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap(0);
	double scale = 0.5;
	while (1)
	{
		Mat frame;
		Mat outFrame;

		cap >> frame;
		Size ResImgSiz = Size(frame.cols * scale, frame.rows * scale);
		Mat rFrame = Mat(ResImgSiz, frame.type());
		resize(frame, rFrame, ResImgSiz, INTER_LINEAR);

		GaussianBlur(rFrame, outFrame, Size(5, 5),1,0, BORDER_DEFAULT);

		imshow("original", rFrame);
		imshow("after_GaussianBlur", outFrame);
		waitKey(30);
	}
}