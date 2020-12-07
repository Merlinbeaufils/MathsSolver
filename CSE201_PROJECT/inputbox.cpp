#include "inputbox.h"
#include <QString>
#include <QInputDialog>
#include <iostream>

InputBox::InputBox()
{
    bool ok;
    QString equation = input_dialog.getText(this, "Your equation","Enter here:", QLineEdit::Normal, QString(), &ok);
    if ( ok && !equation.isEmpty() ) {
        std::cout<<equation.toStdString().c_str()<<std::endl;
    } else {
        // do nothing
    }
}
