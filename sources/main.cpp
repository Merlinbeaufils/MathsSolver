#include <QApplication>

#include "MainWindow/mainwindow.h"
//#include "Derivatives/derivatives.hpp"
#include "ImageRecognition/imagePreprocessing.hpp"

#include<iostream>
#include<string>
#include<opencv2/opencv.hpp>
//#include<tensorflow/c/c_api.h>


using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    string path= "C:\\Users\\Korisnik\\Desktop\Ecole Polytechnique\\CSE201 - Final project\\MathsSolver\\sources\\ImageRecognition\\Images\\test2.jpg";
    display_prepocessing(path);

    //printf("Hello from TensorFlow C library version %s\n", TF_Version());

    return a.exec();

//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();
}
