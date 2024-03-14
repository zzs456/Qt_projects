/********************************************************************************
** Form generated from reading UI file 'privatechat.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRIVATECHAT_H
#define UI_PRIVATECHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrivateChat
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *m_privateMsgs;
    QHBoxLayout *horizontalLayout;
    QLineEdit *m_privateLineMsg;
    QPushButton *m_privateSend;

    void setupUi(QWidget *PrivateChat)
    {
        if (PrivateChat->objectName().isEmpty())
            PrivateChat->setObjectName("PrivateChat");
        PrivateChat->resize(438, 303);
        verticalLayout = new QVBoxLayout(PrivateChat);
        verticalLayout->setObjectName("verticalLayout");
        m_privateMsgs = new QTextEdit(PrivateChat);
        m_privateMsgs->setObjectName("m_privateMsgs");
        m_privateMsgs->setReadOnly(true);

        verticalLayout->addWidget(m_privateMsgs);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        m_privateLineMsg = new QLineEdit(PrivateChat);
        m_privateLineMsg->setObjectName("m_privateLineMsg");

        horizontalLayout->addWidget(m_privateLineMsg);

        m_privateSend = new QPushButton(PrivateChat);
        m_privateSend->setObjectName("m_privateSend");

        horizontalLayout->addWidget(m_privateSend);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(PrivateChat);

        QMetaObject::connectSlotsByName(PrivateChat);
    } // setupUi

    void retranslateUi(QWidget *PrivateChat)
    {
        PrivateChat->setWindowTitle(QCoreApplication::translate("PrivateChat", "Form", nullptr));
        m_privateSend->setText(QCoreApplication::translate("PrivateChat", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PrivateChat: public Ui_PrivateChat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIVATECHAT_H
