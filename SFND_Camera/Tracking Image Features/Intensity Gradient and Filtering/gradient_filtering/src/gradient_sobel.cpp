#include <iostream>
#include <numeric>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;

void gradientSobel()
{
    // Based on the image gradients in both x and y, compute an image 
    // which contains the gradient magnitude according to the equation at the 
    // beginning of this leesson (refer to the equations for gradient direction and magnitude) 
    // for every pixel position. Also, apply different 
    // levels of Gaussian blurring before applying the Sobel operator and compare the results.
  
  	// Step 1 - load image from file
    cv::Mat img;
    img = cv::imread("../images/img1.png");
    //  Step 2 - convert image to grayscale
    cv::Mat imgGray;
    cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);

    //  Step 3 - create filter kernel for calculating intensity gradient in x
    float sobel_x[9] = {-1, 0, +1,
                        -2, 0, +2, 
                        -1, 0, +1};
    //  Step 3 - create filter kernel for calculating intensity gradient in y
    /*float sobel_y[9] = {-1, -2, -1,
                         0, 0, 0, 
                        +1, +2, +1};*/

    cv::Mat kernel_y = cv::Mat(3, 3, CV_32F, sobel_x);

    //  Step 4 - apply filter
    cv::Mat result_x;
    cv::filter2D(imgGray, result_x, -1, kernel_y, cv::Point(-1, -1), 0, cv::BORDER_DEFAULT);

    //  Step 5 - show result
    string windowName = "Sobel operator (x-direction)";
    cv::namedWindow( windowName, 1 ); // create window 
    cv::imshow(windowName, result_x);
    cv::waitKey(0); // wait for keyboard input before continuing
  
}

int main()
{
    gradientSobel();
}