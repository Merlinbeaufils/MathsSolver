#include "mainwindow.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include<string>


#include "ImageRecognition/imagePre-processing.hpp"

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    string path= "C:\\Users\\Korisnik\\Desktop\\Ecole Polytechnique\\CSE201 - Final project\\MathsSolver\\sources\\test_image8.jpg";

    display_prepocessing(path);

    return a.exec();
}
