#include "widget.h"
#include "logindialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog::GetInstance().show();
    Widget w;

    return a.exec();
}
