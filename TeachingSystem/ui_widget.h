/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rootWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *rootWidget)
    {
        if (rootWidget->objectName().isEmpty())
            rootWidget->setObjectName("rootWidget");
        rootWidget->resize(1108, 730);
        rootWidget->setMinimumSize(QSize(1000, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/res/icons/window_icon.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        rootWidget->setWindowIcon(icon);
        rootWidget->setStyleSheet(QString::fromUtf8("QWidget#rootWidget{\n"
"	padding:0px;\n"
"}"));
        horizontalLayout = new QHBoxLayout(rootWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 2, 0, 0);
        stackedWidget = new QStackedWidget(rootWidget);
        stackedWidget->setObjectName("stackedWidget");

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(rootWidget);

        QMetaObject::connectSlotsByName(rootWidget);
    } // setupUi

    void retranslateUi(QWidget *rootWidget)
    {
        rootWidget->setWindowTitle(QCoreApplication::translate("rootWidget", "Widget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rootWidget: public Ui_rootWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
