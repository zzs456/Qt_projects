/********************************************************************************
** Form generated from reading UI file 'chatwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWIDGET_H
#define UI_CHATWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *sendMsg;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *m_lineMsg;
    QPushButton *m_sendMsg;
    QHBoxLayout *clickOperators;
    QTextEdit *m_showMsgs;
    QListWidget *m_friendList;
    QVBoxLayout *clickButtons;
    QPushButton *m_deleteFriend;
    QPushButton *m_flushFriend;
    QPushButton *m_showOnlineUser;
    QPushButton *m_findUser;
    QPushButton *m_privateChat;
    QGroupBox *onlineUsers;
    QHBoxLayout *horizontalLayout;
    QListWidget *m_onlineUserList;
    QPushButton *m_addFriend;
    QSpacerItem *verticalSpacer_1;

    void setupUi(QWidget *ChatWidget)
    {
        if (ChatWidget->objectName().isEmpty())
            ChatWidget->setObjectName("ChatWidget");
        ChatWidget->resize(1049, 598);
        ChatWidget->setStyleSheet(QString::fromUtf8("QGroupBox#sendMsg{\n"
"border:none;\n"
"}\n"
"QGroupBox#onlineUsers{\n"
"border:none;\n"
"}"));
        gridLayout = new QGridLayout(ChatWidget);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 4, 0, 1, 1);

        sendMsg = new QGroupBox(ChatWidget);
        sendMsg->setObjectName("sendMsg");
        sendMsg->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_3 = new QHBoxLayout(sendMsg);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(6, 10, 6, 10);
        m_lineMsg = new QLineEdit(sendMsg);
        m_lineMsg->setObjectName("m_lineMsg");

        horizontalLayout_3->addWidget(m_lineMsg);

        m_sendMsg = new QPushButton(sendMsg);
        m_sendMsg->setObjectName("m_sendMsg");

        horizontalLayout_3->addWidget(m_sendMsg);


        gridLayout->addWidget(sendMsg, 1, 0, 1, 1);

        clickOperators = new QHBoxLayout();
        clickOperators->setObjectName("clickOperators");
        m_showMsgs = new QTextEdit(ChatWidget);
        m_showMsgs->setObjectName("m_showMsgs");

        clickOperators->addWidget(m_showMsgs);

        m_friendList = new QListWidget(ChatWidget);
        m_friendList->setObjectName("m_friendList");

        clickOperators->addWidget(m_friendList);

        clickButtons = new QVBoxLayout();
        clickButtons->setObjectName("clickButtons");
        m_deleteFriend = new QPushButton(ChatWidget);
        m_deleteFriend->setObjectName("m_deleteFriend");

        clickButtons->addWidget(m_deleteFriend);

        m_flushFriend = new QPushButton(ChatWidget);
        m_flushFriend->setObjectName("m_flushFriend");

        clickButtons->addWidget(m_flushFriend);

        m_showOnlineUser = new QPushButton(ChatWidget);
        m_showOnlineUser->setObjectName("m_showOnlineUser");

        clickButtons->addWidget(m_showOnlineUser);

        m_findUser = new QPushButton(ChatWidget);
        m_findUser->setObjectName("m_findUser");

        clickButtons->addWidget(m_findUser);

        m_privateChat = new QPushButton(ChatWidget);
        m_privateChat->setObjectName("m_privateChat");

        clickButtons->addWidget(m_privateChat);


        clickOperators->addLayout(clickButtons);


        gridLayout->addLayout(clickOperators, 0, 0, 1, 1);

        onlineUsers = new QGroupBox(ChatWidget);
        onlineUsers->setObjectName("onlineUsers");
        horizontalLayout = new QHBoxLayout(onlineUsers);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(6, 10, 6, 10);
        m_onlineUserList = new QListWidget(onlineUsers);
        m_onlineUserList->setObjectName("m_onlineUserList");

        horizontalLayout->addWidget(m_onlineUserList);

        m_addFriend = new QPushButton(onlineUsers);
        m_addFriend->setObjectName("m_addFriend");

        horizontalLayout->addWidget(m_addFriend);


        gridLayout->addWidget(onlineUsers, 3, 0, 1, 1);

        verticalSpacer_1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_1, 2, 0, 1, 1);


        retranslateUi(ChatWidget);

        QMetaObject::connectSlotsByName(ChatWidget);
    } // setupUi

    void retranslateUi(QWidget *ChatWidget)
    {
        ChatWidget->setWindowTitle(QCoreApplication::translate("ChatWidget", "\350\201\212\345\244\251\347\263\273\347\273\237", nullptr));
        sendMsg->setTitle(QString());
        m_sendMsg->setText(QCoreApplication::translate("ChatWidget", "\344\277\241\346\201\257\345\217\221\351\200\201", nullptr));
        m_deleteFriend->setText(QCoreApplication::translate("ChatWidget", "\345\210\240\351\231\244\345\245\275\345\217\213", nullptr));
        m_flushFriend->setText(QCoreApplication::translate("ChatWidget", "\345\210\267\346\226\260\345\245\275\345\217\213", nullptr));
        m_showOnlineUser->setText(QCoreApplication::translate("ChatWidget", "\346\230\276\347\244\272\345\234\250\347\272\277\347\224\250\346\210\267", nullptr));
        m_findUser->setText(QCoreApplication::translate("ChatWidget", "\346\237\245\346\211\276\347\224\250\346\210\267", nullptr));
        m_privateChat->setText(QCoreApplication::translate("ChatWidget", "\347\247\201\350\201\212", nullptr));
        onlineUsers->setTitle(QString());
        m_addFriend->setText(QCoreApplication::translate("ChatWidget", "\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatWidget: public Ui_ChatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIDGET_H
