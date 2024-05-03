/********************************************************************************
** Form generated from reading UI file 'mwsettingwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MWSETTINGWIDGET_H
#define UI_MWSETTINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MWSettingWidget
{
public:
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *m_changePW;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *m_oldPW_l;
    QLineEdit *m_oldPW;
    QLabel *m_oldPW_Info;
    QHBoxLayout *horizontalLayout_3;
    QLabel *m_newPW_l;
    QLineEdit *m_newPW;
    QLabel *m_newPW_Info;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *m_changeOK;
    QPushButton *m_changeCancel;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *MWSettingWidget)
    {
        if (MWSettingWidget->objectName().isEmpty())
            MWSettingWidget->setObjectName("MWSettingWidget");
        MWSettingWidget->resize(759, 600);
        horizontalLayout_6 = new QHBoxLayout(MWSettingWidget);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        m_changePW = new QPushButton(MWSettingWidget);
        m_changePW->setObjectName("m_changePW");
        QFont font;
        font.setPointSize(12);
        m_changePW->setFont(font);

        horizontalLayout->addWidget(m_changePW);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        groupBox = new QGroupBox(MWSettingWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox#groupBox{\n"
"	border:none;\n"
"}"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(15);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        m_oldPW_l = new QLabel(groupBox);
        m_oldPW_l->setObjectName("m_oldPW_l");
        m_oldPW_l->setFont(font);

        horizontalLayout_2->addWidget(m_oldPW_l);

        m_oldPW = new QLineEdit(groupBox);
        m_oldPW->setObjectName("m_oldPW");
        m_oldPW->setFont(font);
        m_oldPW->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(m_oldPW);


        verticalLayout->addLayout(horizontalLayout_2);

        m_oldPW_Info = new QLabel(groupBox);
        m_oldPW_Info->setObjectName("m_oldPW_Info");
        QFont font1;
        font1.setPointSize(10);
        m_oldPW_Info->setFont(font1);

        verticalLayout->addWidget(m_oldPW_Info);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(15);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        m_newPW_l = new QLabel(groupBox);
        m_newPW_l->setObjectName("m_newPW_l");
        m_newPW_l->setFont(font);

        horizontalLayout_3->addWidget(m_newPW_l);

        m_newPW = new QLineEdit(groupBox);
        m_newPW->setObjectName("m_newPW");
        m_newPW->setFont(font);
        m_newPW->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(m_newPW);


        verticalLayout->addLayout(horizontalLayout_3);

        m_newPW_Info = new QLabel(groupBox);
        m_newPW_Info->setObjectName("m_newPW_Info");
        m_newPW_Info->setFont(font1);

        verticalLayout->addWidget(m_newPW_Info);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(15);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        m_changeOK = new QPushButton(groupBox);
        m_changeOK->setObjectName("m_changeOK");
        m_changeOK->setFont(font);

        horizontalLayout_4->addWidget(m_changeOK);

        m_changeCancel = new QPushButton(groupBox);
        m_changeCancel->setObjectName("m_changeCancel");
        m_changeCancel->setFont(font);

        horizontalLayout_4->addWidget(m_changeCancel);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 2);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 2);

        horizontalLayout_5->addWidget(groupBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 5);
        verticalLayout_3->setStretch(2, 100);

        horizontalLayout_6->addLayout(verticalLayout_3);


        retranslateUi(MWSettingWidget);

        QMetaObject::connectSlotsByName(MWSettingWidget);
    } // setupUi

    void retranslateUi(QWidget *MWSettingWidget)
    {
        MWSettingWidget->setWindowTitle(QCoreApplication::translate("MWSettingWidget", "Form", nullptr));
        m_changePW->setText(QCoreApplication::translate("MWSettingWidget", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        groupBox->setTitle(QString());
        m_oldPW_l->setText(QCoreApplication::translate("MWSettingWidget", "\345\216\237\345\257\206\347\240\201:", nullptr));
        m_oldPW_Info->setText(QString());
        m_newPW_l->setText(QCoreApplication::translate("MWSettingWidget", "\346\226\260\345\257\206\347\240\201:", nullptr));
        m_newPW_Info->setText(QString());
        m_changeOK->setText(QCoreApplication::translate("MWSettingWidget", "\347\241\256\345\256\232", nullptr));
        m_changeCancel->setText(QCoreApplication::translate("MWSettingWidget", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MWSettingWidget: public Ui_MWSettingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MWSETTINGWIDGET_H
