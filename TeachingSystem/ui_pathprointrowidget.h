/********************************************************************************
** Form generated from reading UI file 'pathprointrowidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATHPROINTROWIDGET_H
#define UI_PATHPROINTROWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PathProIntroWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QWidget *PathProIntroWidget)
    {
        if (PathProIntroWidget->objectName().isEmpty())
            PathProIntroWidget->setObjectName("PathProIntroWidget");
        PathProIntroWidget->resize(725, 580);
        verticalLayout = new QVBoxLayout(PathProIntroWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(PathProIntroWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        retranslateUi(PathProIntroWidget);

        QMetaObject::connectSlotsByName(PathProIntroWidget);
    } // setupUi

    void retranslateUi(QWidget *PathProIntroWidget)
    {
        PathProIntroWidget->setWindowTitle(QCoreApplication::translate("PathProIntroWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("PathProIntroWidget", "\351\201\227\344\274\240\347\256\227\346\263\225\n"
"\350\267\257\345\276\204\350\247\204\345\210\222\351\227\256\351\242\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PathProIntroWidget: public Ui_PathProIntroWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATHPROINTROWIDGET_H
