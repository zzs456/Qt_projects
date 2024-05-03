#include "widget.h"
#include "./LoginWidget/logindialog.h"
#include "./LoginWidget/dbinstance.h"

#include "ProAlgoWidget/problemandalgorithm.h"

#include <QApplication>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // DBInstance::GetInstance().Init_DB();

    // LoginDialog loginDialog;
    // loginDialog.show();

    // Widget w;

    // QObject::connect(&loginDialog,&LoginDialog::loginSuccess,&w,&Widget::MyShow);

    ProblemAndAlgorithm w;
    w.show();

    // FuncMainWidget w;
    // w.show();


    // PathMainWidget w;
    // w.show();

    return a.exec();
}
