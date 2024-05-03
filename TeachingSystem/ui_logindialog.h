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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QStackedWidget *stackedWidget;
    QWidget *loginPage;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *m_luserLabel;
    QLineEdit *m_luser;
    QLabel *m_luserTip;
    QHBoxLayout *horizontalLayout_3;
    QLabel *m_lpwLabel;
    QLineEdit *m_lpw;
    QLabel *m_lpwTip;
    QHBoxLayout *horizontalLayout;
    QPushButton *m_loginButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_registerButton;
    QSpacerItem *verticalSpacer_2;
    QWidget *registerPage;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *m_ruserLabel;
    QLineEdit *m_ruser;
    QLabel *m_ruserTip;
    QHBoxLayout *horizontalLayout_6;
    QLabel *m_rpwLabel;
    QLineEdit *m_rpw;
    QLabel *m_rpwTip;
    QHBoxLayout *horizontalLayout_7;
    QLabel *m_rewriteLabel;
    QLineEdit *m_rewrite;
    QLabel *m_rewriteTip;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *m_confirmRegister;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *m_returnLogin;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName("LoginDialog");
        LoginDialog->resize(324, 331);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/res/icons/login_icon.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        LoginDialog->setWindowIcon(icon);
        verticalLayout_3 = new QVBoxLayout(LoginDialog);
        verticalLayout_3->setObjectName("verticalLayout_3");
        stackedWidget = new QStackedWidget(LoginDialog);
        stackedWidget->setObjectName("stackedWidget");
        loginPage = new QWidget();
        loginPage->setObjectName("loginPage");
        verticalLayout = new QVBoxLayout(loginPage);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 104, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        m_luserLabel = new QLabel(loginPage);
        m_luserLabel->setObjectName("m_luserLabel");
        QFont font;
        font.setPointSize(12);
        m_luserLabel->setFont(font);

        horizontalLayout_2->addWidget(m_luserLabel);

        m_luser = new QLineEdit(loginPage);
        m_luser->setObjectName("m_luser");
        m_luser->setFont(font);

        horizontalLayout_2->addWidget(m_luser);


        verticalLayout->addLayout(horizontalLayout_2);

        m_luserTip = new QLabel(loginPage);
        m_luserTip->setObjectName("m_luserTip");

        verticalLayout->addWidget(m_luserTip);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        m_lpwLabel = new QLabel(loginPage);
        m_lpwLabel->setObjectName("m_lpwLabel");
        m_lpwLabel->setFont(font);

        horizontalLayout_3->addWidget(m_lpwLabel);

        m_lpw = new QLineEdit(loginPage);
        m_lpw->setObjectName("m_lpw");
        m_lpw->setFont(font);
        m_lpw->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(m_lpw);


        verticalLayout->addLayout(horizontalLayout_3);

        m_lpwTip = new QLabel(loginPage);
        m_lpwTip->setObjectName("m_lpwTip");

        verticalLayout->addWidget(m_lpwTip);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        m_loginButton = new QPushButton(loginPage);
        m_loginButton->setObjectName("m_loginButton");
        m_loginButton->setFont(font);

        horizontalLayout->addWidget(m_loginButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_registerButton = new QPushButton(loginPage);
        m_registerButton->setObjectName("m_registerButton");
        m_registerButton->setFont(font);

        horizontalLayout->addWidget(m_registerButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 103, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        stackedWidget->addWidget(loginPage);
        registerPage = new QWidget();
        registerPage->setObjectName("registerPage");
        verticalLayout_2 = new QVBoxLayout(registerPage);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        m_ruserLabel = new QLabel(registerPage);
        m_ruserLabel->setObjectName("m_ruserLabel");
        m_ruserLabel->setFont(font);

        horizontalLayout_5->addWidget(m_ruserLabel);

        m_ruser = new QLineEdit(registerPage);
        m_ruser->setObjectName("m_ruser");
        m_ruser->setFont(font);

        horizontalLayout_5->addWidget(m_ruser);


        verticalLayout_2->addLayout(horizontalLayout_5);

        m_ruserTip = new QLabel(registerPage);
        m_ruserTip->setObjectName("m_ruserTip");

        verticalLayout_2->addWidget(m_ruserTip);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        m_rpwLabel = new QLabel(registerPage);
        m_rpwLabel->setObjectName("m_rpwLabel");
        m_rpwLabel->setFont(font);

        horizontalLayout_6->addWidget(m_rpwLabel);

        m_rpw = new QLineEdit(registerPage);
        m_rpw->setObjectName("m_rpw");
        m_rpw->setFont(font);
        m_rpw->setEchoMode(QLineEdit::Password);

        horizontalLayout_6->addWidget(m_rpw);


        verticalLayout_2->addLayout(horizontalLayout_6);

        m_rpwTip = new QLabel(registerPage);
        m_rpwTip->setObjectName("m_rpwTip");

        verticalLayout_2->addWidget(m_rpwTip);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        m_rewriteLabel = new QLabel(registerPage);
        m_rewriteLabel->setObjectName("m_rewriteLabel");
        m_rewriteLabel->setFont(font);

        horizontalLayout_7->addWidget(m_rewriteLabel);

        m_rewrite = new QLineEdit(registerPage);
        m_rewrite->setObjectName("m_rewrite");
        m_rewrite->setFont(font);
        m_rewrite->setEchoMode(QLineEdit::Password);

        horizontalLayout_7->addWidget(m_rewrite);


        verticalLayout_2->addLayout(horizontalLayout_7);

        m_rewriteTip = new QLabel(registerPage);
        m_rewriteTip->setObjectName("m_rewriteTip");

        verticalLayout_2->addWidget(m_rewriteTip);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        m_confirmRegister = new QPushButton(registerPage);
        m_confirmRegister->setObjectName("m_confirmRegister");
        m_confirmRegister->setFont(font);

        horizontalLayout_4->addWidget(m_confirmRegister);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        m_returnLogin = new QPushButton(registerPage);
        m_returnLogin->setObjectName("m_returnLogin");
        m_returnLogin->setFont(font);

        horizontalLayout_4->addWidget(m_returnLogin);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalSpacer_4 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        stackedWidget->addWidget(registerPage);

        verticalLayout_3->addWidget(stackedWidget);


        retranslateUi(LoginDialog);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        m_luserLabel->setText(QCoreApplication::translate("LoginDialog", "\350\264\246\345\217\267  :", nullptr));
        m_luser->setPlaceholderText(QCoreApplication::translate("LoginDialog", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", nullptr));
        m_luserTip->setText(QString());
        m_lpwLabel->setText(QCoreApplication::translate("LoginDialog", "\345\257\206\347\240\201  :", nullptr));
        m_lpw->setPlaceholderText(QCoreApplication::translate("LoginDialog", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        m_lpwTip->setText(QString());
        m_loginButton->setText(QCoreApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        m_registerButton->setText(QCoreApplication::translate("LoginDialog", "\346\263\250\345\206\214", nullptr));
        m_ruserLabel->setText(QCoreApplication::translate("LoginDialog", "\350\264\246       \345\217\267  :", nullptr));
        m_ruserTip->setText(QString());
        m_rpwLabel->setText(QCoreApplication::translate("LoginDialog", "\345\257\206       \347\240\201  :", nullptr));
        m_rpwTip->setText(QString());
        m_rewriteLabel->setText(QCoreApplication::translate("LoginDialog", "\347\241\256\350\256\244\345\257\206\347\240\201  :", nullptr));
        m_rewriteTip->setText(QString());
        m_confirmRegister->setText(QCoreApplication::translate("LoginDialog", "\347\241\256\350\256\244\346\263\250\345\206\214", nullptr));
        m_returnLogin->setText(QCoreApplication::translate("LoginDialog", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
