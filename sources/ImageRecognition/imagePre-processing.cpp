#include<iostream>
#include<string>
#include<vector>

#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

Mat upload_img(string path){
    Mat image = imread(path, IMREAD_COLOR);

    if(!image.data){
        cout<<"Image path is not valid\n";
    }

    return image;
}

Mat binarisation(Mat image){
    Mat gray_image;
    Mat final;

    if(!image.data){
        cout<<"Image path is not valid\n";
    }

    cvtColor(image, gray_image, COLOR_BGR2GRAY);
    adaptiveThreshold(gray_image, final, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 75, 50);
    bitwise_not(final, final);

    return final;
}

Mat noise_removal(Mat image){
    Mat final_img;

   Size size(3,3);
   GaussianBlur(image,final_img,size,0);

   Mat ero(2,2,CV_8U,Scalar(1));
   morphologyEx(final_img,final_img,MORPH_OPEN, ero);

    return final_img;
}

Mat crop(Mat image){
    if(!image.data){
        cout<<"Image path is not valid\n";
    }

    Mat output;

    Mat element = getStructuringElement(MORPH_RECT, Size(5, 3));
    erode(image, output, element);

    vector<Point> points;
    Mat_<uchar>::iterator it = output.begin<uchar>();
    Mat_<uchar>::iterator end = output.end<uchar>();

    for (; it != end; ++it){
        if (*it) points.push_back(it.pos());
    }

    RotatedRect box = minAreaRect(Mat(points));
    double angle = box.angle;
    if (angle < -45.)
      angle += 90.;

    Mat rot_mat = getRotationMatrix2D(box.center, angle, 1);
    Mat rotated;
    warpAffine(image, rotated, rot_mat, output.size(), INTER_CUBIC);

  /*  Rect roi;
    roi.x = box.center.x - (box.size.width / 2);
    roi.y = box.center.y - (box.size.height / 2);
    roi.width = box.size.width;
    roi.height = box.size.height;
    Mat cropped = image(roi);
*/

    Size box_size = box.size;
    if (box.angle < -45.)
      swap(box_size.width, box_size.height);
    Mat cropped;
    getRectSubPix(rotated, box_size, box.center, cropped);

    return cropped;
}


