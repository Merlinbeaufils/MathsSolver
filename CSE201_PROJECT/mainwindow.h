#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "inputbox.h"
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void find_file();

private:
    Ui::MainWindow *ui;
    QPushButton* upload_file;
//InputBox input_box;
    QLineEdit * equation_input;
    QFileDialog * input_file;
};
#endif // MAINWINDOW_H
