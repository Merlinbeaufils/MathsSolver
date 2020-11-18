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
    threshold(gray_image, final, 128.0, 255, THRESH_BINARY_INV);

    return final;
}

Mat noise_removal(Mat image){
    Mat final_img;
    Mat ero(3,3,CV_8U,Scalar(1));

    morphologyEx(image,final_img,MORPH_OPEN, ero);

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
    Rect roi;
    roi.x = box.center.x - (box.size.width / 2);
    roi.y = box.center.y - (box.size.height / 2);
    roi.width = box.size.width+10;
    roi.height = box.size.height+10;

    // Crop the original image to the defined ROI
    Mat crop = image(roi);

    return crop;
}

Mat inverse_binarisation(Mat image){
    //clearer lines and background white again
    Mat element = getStructuringElement(MORPH_RECT, Size(4, 4));
    dilate(image, image, element);

    threshold(image, image, 128.0, 255, THRESH_BINARY_INV);

    return image;
}

