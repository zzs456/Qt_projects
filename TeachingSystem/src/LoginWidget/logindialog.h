#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

signals:
    void changeStackedWidget(int);
    void loginSuccess(QString);

private slots:

    void on_m_loginButton_clicked();

    void on_m_registerButton_clicked();

    void on_m_confirmRegister_clicked();
    void on_m_returnLogin_clicked();

private:
    void clearLTips();
    void clearLText();
    void clearRTips();
    void clearRText();
    void setTipsColor();

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
