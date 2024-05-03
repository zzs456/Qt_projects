#ifndef MYMESSAGEBOX_H
#define MYMESSAGEBOX_H

#include <QDialog>
#include <QString>

enum MyMessageBoxType{
    MyMessageBoxType_Min = 0,
    MyMessageBoxType_Question,
    MyMessageBoxType_Success,
    MyMessageBoxType_Fail,
    MyMessageBoxType_Info,
    MyMessageBoxType_Max = 0xffffff
};

namespace Ui {
class MyMessageBox;
}

class MyMessageBox : public QDialog
{
    Q_OBJECT

public:
    explicit MyMessageBox(MyMessageBoxType,QString,QWidget *parent = nullptr);
    ~MyMessageBox();

private:
    void Init(MyMessageBoxType,QString);
    void setQuestion(QString);
    void setSuccess(QString);
    void setFail(QString);
    void setInfo(QString);

private slots:
    void on_myMB_OK_clicked();

    void on_myMB_Cancel_clicked();

private:
    Ui::MyMessageBox *ui;
};

#endif // MYMESSAGEBOX_H
