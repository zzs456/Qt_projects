#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include "myprotocol.h"
#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT
public:
    static LoginDialog& GetInstance();
    ~LoginDialog();
private:
    explicit LoginDialog(QWidget *parent = nullptr);

private slots:
    void on_registerButton_clicked();

    void on_loginButton_clicked();
public slots:
    void DoRegisterRespond(PDU*);
    void DoLoginRespond(PDU*);

private:
    Ui::LoginDialog *ui;

signals:
    void RegisterSignal(QString,QString);
    void LoginSignal(QString,QString);
    void UpdateShow();

};

#endif // LOGINDIALOG_H
