#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    solve_button = new QPushButton("SOLVE", this);
    solve_button -> setGeometry(QRect(QPoint(50,50), QSize(300,100)));
    connect(solve_button, SIGNAL(released()), this, SLOT(handleButton()));
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleButton(){
    solve_button->setText("SOLVED");
    solve_button->resize(100,100);
}
