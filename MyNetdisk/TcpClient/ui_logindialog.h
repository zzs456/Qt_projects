/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QLabel *usernameL;
    QLineEdit *username;
    QLabel *passwordL;
    QLineEdit *password;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *loginButton;
    QPushButton *registerButton;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName("LoginDialog");
        LoginDialog->resize(300, 180);
        verticalLayout = new QVBoxLayout(LoginDialog);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        usernameL = new QLabel(LoginDialog);
        usernameL->setObjectName("usernameL");

        gridLayout->addWidget(usernameL, 0, 0, 1, 1);

        username = new QLineEdit(LoginDialog);
        username->setObjectName("username");
        username->setReadOnly(false);

        gridLayout->addWidget(username, 0, 1, 1, 1);

        passwordL = new QLabel(LoginDialog);
        passwordL->setObjectName("passwordL");

        gridLayout->addWidget(passwordL, 1, 0, 1, 1);

        password = new QLineEdit(LoginDialog);
        password->setObjectName("password");
        password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(password, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        loginButton = new QPushButton(LoginDialog);
        loginButton->setObjectName("loginButton");
        loginButton->setAutoDefault(false);

        horizontalLayout_3->addWidget(loginButton);

        registerButton = new QPushButton(LoginDialog);
        registerButton->setObjectName("registerButton");
        registerButton->setAutoDefault(false);

        horizontalLayout_3->addWidget(registerButton);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        usernameL->setText(QCoreApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        username->setPlaceholderText(QCoreApplication::translate("LoginDialog", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        passwordL->setText(QCoreApplication::translate("LoginDialog", "\345\257\206    \347\240\201\357\274\232", nullptr));
        password->setPlaceholderText(QCoreApplication::translate("LoginDialog", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        registerButton->setText(QCoreApplication::translate("LoginDialog", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
