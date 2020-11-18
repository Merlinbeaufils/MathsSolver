#ifndef IMAGEPREPROCESSING_HPP
#define IMAGEPREPROCESSING_HPP

#include<iostream>
#include<string>

#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>


using namespace std;
using namespace cv;

Mat binarisation(Mat image);

Mat upload_img(string path);

Mat noise_removal(Mat image);

Mat crop(Mat image);

Mat inverse_binarisation(Mat image);

#endif // IMAGEPREPROCESSING_HPP
