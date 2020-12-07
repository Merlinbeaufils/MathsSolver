#ifndef INPUTBOX_H
#define INPUTBOX_H
#include <QWidget>
#include <QInputDialog>

class InputBox:public QWidget
{
public:
    InputBox();
private:
    QInputDialog input_dialog;
};

#endif // INPUTBOX_H
