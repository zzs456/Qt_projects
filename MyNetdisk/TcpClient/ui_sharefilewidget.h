/********************************************************************************
** Form generated from reading UI file 'sharefilewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHAREFILEWIDGET_H
#define UI_SHAREFILEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShareFileWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *m_selectAll;
    QPushButton *m_cancelAll;
    QListWidget *m_onlineFriend;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *m_ok;
    QPushButton *m_cancel;

    void setupUi(QWidget *ShareFileWidget)
    {
        if (ShareFileWidget->objectName().isEmpty())
            ShareFileWidget->setObjectName("ShareFileWidget");
        ShareFileWidget->resize(262, 399);
        verticalLayout = new QVBoxLayout(ShareFileWidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        m_selectAll = new QPushButton(ShareFileWidget);
        m_selectAll->setObjectName("m_selectAll");

        horizontalLayout->addWidget(m_selectAll);

        m_cancelAll = new QPushButton(ShareFileWidget);
        m_cancelAll->setObjectName("m_cancelAll");

        horizontalLayout->addWidget(m_cancelAll);


        verticalLayout->addLayout(horizontalLayout);

        m_onlineFriend = new QListWidget(ShareFileWidget);
        m_onlineFriend->setObjectName("m_onlineFriend");

        verticalLayout->addWidget(m_onlineFriend);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        m_ok = new QPushButton(ShareFileWidget);
        m_ok->setObjectName("m_ok");

        horizontalLayout_2->addWidget(m_ok);

        m_cancel = new QPushButton(ShareFileWidget);
        m_cancel->setObjectName("m_cancel");

        horizontalLayout_2->addWidget(m_cancel);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(ShareFileWidget);

        QMetaObject::connectSlotsByName(ShareFileWidget);
    } // setupUi

    void retranslateUi(QWidget *ShareFileWidget)
    {
        ShareFileWidget->setWindowTitle(QCoreApplication::translate("ShareFileWidget", "Form", nullptr));
        m_selectAll->setText(QCoreApplication::translate("ShareFileWidget", "\345\205\250\351\200\211", nullptr));
        m_cancelAll->setText(QCoreApplication::translate("ShareFileWidget", "\345\217\226\346\266\210\351\200\211\346\213\251", nullptr));
        m_ok->setText(QCoreApplication::translate("ShareFileWidget", "\347\241\256\345\256\232", nullptr));
        m_cancel->setText(QCoreApplication::translate("ShareFileWidget", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShareFileWidget: public Ui_ShareFileWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHAREFILEWIDGET_H
