#include <iomanip>
#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;

void loadImage1()
{
    // load image from file
    cv::Mat img;
    img = cv::imread("../images/img1.png"); //we can load the image from file and assign it to a matrix variable

    // show result
    string windowName = "First steps in OpenCV";
    cv::namedWindow(windowName, 1); // create window
    cv::imshow(windowName, img);
    cv::waitKey(0); // wait for keyboard input before continuing
}

int main()
{
    loadImage1();
    return 0;
}