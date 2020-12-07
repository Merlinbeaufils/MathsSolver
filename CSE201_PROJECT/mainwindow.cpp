#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QFileDialog>
#include <iostream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    upload_file = new QPushButton(this);
    upload_file->move(100,500);
    //QGroupBox *group_box = new QGroupBox(tr("Echo"));

    QLabel *question = new QLabel(this);
    question->setText("Your equation");
    question->show();

    equation_input = new QLineEdit(this);
    equation_input-> setPlaceholderText("ce que tu veux");
    equation_input->move(100, 0);

    input_file = new QFileDialog(this);

    QHBoxLayout *inputLayout = new QHBoxLayout;
    inputLayout->addWidget(question);
    inputLayout->addWidget(equation_input);
    setLayout(inputLayout);

    connect(upload_file, &QAbstractButton::clicked, this, &MainWindow::find_file);


}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::find_file(){
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog:: AnyFile);
    dialog.exec();
    QStringList paths = dialog.selectedFiles();
    for(int i=0 ; i < paths.length() ; i++)
    {
         std::cout<<paths.at(i).toStdString().c_str()<<std::endl;
    }
}

