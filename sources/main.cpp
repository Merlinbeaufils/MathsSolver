#include "mainwindow.h"
#include <QApplication>
#include <opencv2/opencv.hpp>

#include "ImageRecognition/imagePre-processing.hpp"

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Mat image = imread("C:\\Users\\Korisnik\\Desktop\\Ecole Polytechnique\\CSE201 - Final project\\MathsSolver\\sources\\test_image.jpg", IMREAD_COLOR);

    image = binarisation(image);
    image = noise_removal(image);
    image = crop(image);
    image = inverse_binarisation(image);

    const char* source_window = "Source";
    namedWindow( source_window, WINDOW_NORMAL );
    resizeWindow(source_window, 1000, 800);
    imshow( source_window, image );

    waitKey(0);
    return a.exec();
}
