#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowState(Qt::WindowMaximized);
    w.setWindowTitle("Handwritten Math Solver");
    w.setWindowIcon(QIcon("iconcse201.png"));
    w.show();
    return a.exec();
}
