/********************************************************************************
** Form generated from reading UI file 'mymessagebox.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMESSAGEBOX_H
#define UI_MYMESSAGEBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MyMessageBox
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *myMB_picLabel;
    QLabel *myMB_textLabel;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *myMB_OK;
    QPushButton *myMB_Cancel;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *MyMessageBox)
    {
        if (MyMessageBox->objectName().isEmpty())
            MyMessageBox->setObjectName("MyMessageBox");
        MyMessageBox->resize(473, 208);
        verticalLayout = new QVBoxLayout(MyMessageBox);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        myMB_picLabel = new QLabel(MyMessageBox);
        myMB_picLabel->setObjectName("myMB_picLabel");

        horizontalLayout_2->addWidget(myMB_picLabel);

        myMB_textLabel = new QLabel(MyMessageBox);
        myMB_textLabel->setObjectName("myMB_textLabel");

        horizontalLayout_2->addWidget(myMB_textLabel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        myMB_OK = new QPushButton(MyMessageBox);
        myMB_OK->setObjectName("myMB_OK");
        QFont font;
        font.setPointSize(12);
        myMB_OK->setFont(font);

        horizontalLayout->addWidget(myMB_OK);

        myMB_Cancel = new QPushButton(MyMessageBox);
        myMB_Cancel->setObjectName("myMB_Cancel");
        myMB_Cancel->setFont(font);

        horizontalLayout->addWidget(myMB_Cancel);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(MyMessageBox);

        QMetaObject::connectSlotsByName(MyMessageBox);
    } // setupUi

    void retranslateUi(QDialog *MyMessageBox)
    {
        MyMessageBox->setWindowTitle(QCoreApplication::translate("MyMessageBox", "Dialog", nullptr));
        myMB_picLabel->setText(QString());
        myMB_textLabel->setText(QCoreApplication::translate("MyMessageBox", "\346\202\250\345\245\275", nullptr));
        myMB_OK->setText(QCoreApplication::translate("MyMessageBox", "\347\241\256\345\256\232", nullptr));
        myMB_Cancel->setText(QCoreApplication::translate("MyMessageBox", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyMessageBox: public Ui_MyMessageBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMESSAGEBOX_H
