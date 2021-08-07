#include <iostream>
#include <numeric>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>

using namespace std;

void cornernessHarris()
{
    // load image from file
    cv::Mat img;
    img = cv::imread("../images/img1.png");
    cv::cvtColor(img, img, cv::COLOR_BGR2GRAY); // convert to grayscale

    // Detector parameters
    int blockSize = 2;     // for every pixel, a blockSize × blockSize neighborhood is considered
    int apertureSize = 3;  // aperture parameter for Sobel operator (must be odd)
    int minResponse = 100; // minimum value for a corner in the 8bit scaled response matrix
    double k = 0.04;       // Harris parameter (see equation for details)

    // Detect Harris corners and normalize output
    cv::Mat dst, dst_norm, dst_norm_scaled;
    dst = cv::Mat::zeros(img.size(), CV_32FC1);
    cv::cornerHarris(img, dst, blockSize, apertureSize, k, cv::BORDER_DEFAULT);
    cv::normalize(dst, dst_norm, 0, 255, cv::NORM_MINMAX, CV_32FC1, cv::Mat());
    cv::convertScaleAbs(dst_norm, dst_norm_scaled);

    cout << "OpenCV version : " << CV_VERSION << endl;
    cout << "Major version : " << CV_MAJOR_VERSION << endl;
    cout << "Minor version : " << CV_MINOR_VERSION << endl;
    cout << "Subminor version : " << CV_SUBMINOR_VERSION << endl;

    string windowName = "Harris Corner Detector Response Matrix";
    cv::namedWindow(windowName, 4);
    cv::imshow(windowName, dst_norm_scaled);
    cv::waitKey(0);
}

    // TODO: Your task is to locate local maxima in the Harris response matrix 
    // and perform a non-maximum suppression (NMS) in a local neighborhood around 
    // each maximum. The resulting coordinates shall be stored in a list of keypoints 
    // of the type `vector<cv::KeyPoint>`.
/*
cv::Mat PerfromNMS(cv::Mat corner_img){
    int sw_size = 7; // Odd number because of uniform distribution 
    int sw_dist = floor(sw_size/2);

    cv::Mat result_img = cv::Mat::zeros(corner_img.rows,corner_img.cols,CV_8U);


    for(int r = sw_dist; r<corner_img.rows-sw_dist; r++ ){
        for(int c = sw_dist; c<corner_img.cols-sw_dist; c++){

            unsigned int max_value{0};
            for(int rs = r - sw_dist; rs = r+sw_dist; rs++){
                for(int cs = c-sw_dist;cs = c+sw_dist;cs++){

                    unsigned int new_value = corner_img.at<unsigned int>(rs,cs);
                    max_value = max_value < new_value ? new_value:max_value;
                }
            }

        if(corner_img.at<unsigned int>(r,c) = max_value)
        result_img.at<unsigned int>(r,c) = max_value;
        }
    }



    // visualize results
    string windowName = "Harris Corner Detector Response Matrix";
    cv::namedWindow(windowName, 4);
    cv::imshow(windowName, dst_norm_scaled);
    cv::waitKey(0);
    return result_img;
    }
*/

int main()
{
    cornernessHarris();
}