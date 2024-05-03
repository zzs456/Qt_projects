/********************************************************************************
** Form generated from reading UI file 'functionprowidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUNCTIONPROWIDGET_H
#define UI_FUNCTIONPROWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_FunctionProWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QTreeWidget *functions_treeWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *func_stackedWidget;
    QWidget *powerFuncW;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLabel *powerFuncDomain;
    QLabel *powerFuncAccu;
    QLabel *label_2;
    QLabel *label_1;
    QLabel *label_3;
    QLabel *powerFuncName;
    QCustomPlot *powerFuncPlot;
    QWidget *trigoFuncW;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLabel *trigoFuncName;
    QLabel *label_5;
    QLabel *trigoFuncDomain;
    QLabel *label_6;
    QLabel *trigoFuncAccu;
    QCustomPlot *trigoFuncPlot;
    QWidget *sphereFuncW;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_3;
    QLabel *label_7;
    QLabel *sphereFuncName;
    QLabel *label_8;
    QLabel *sphereFuncDomain;
    QLabel *label_9;
    QLabel *sphereFuncAccu;
    QLabel *label_10;
    QSpinBox *sphereNValueSpin;
    QSpacerItem *verticalSpacer;
    QWidget *GA_IntroW;
    QVBoxLayout *verticalLayout_6;
    QLabel *gaIntroPic;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *startDemo;

    void setupUi(QWidget *FunctionProWidget)
    {
        if (FunctionProWidget->objectName().isEmpty())
            FunctionProWidget->setObjectName("FunctionProWidget");
        FunctionProWidget->resize(900, 589);
        verticalLayout_2 = new QVBoxLayout(FunctionProWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(FunctionProWidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        functions_treeWidget = new QTreeWidget(splitter);
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        QFont font1;
        font1.setPointSize(10);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(functions_treeWidget);
        __qtreewidgetitem->setFont(0, font);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem1->setFont(0, font1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem2->setFont(0, font1);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem3->setFont(0, font1);
        functions_treeWidget->setObjectName("functions_treeWidget");
        functions_treeWidget->setMinimumSize(QSize(300, 0));
        functions_treeWidget->setMaximumSize(QSize(300, 16777215));
        functions_treeWidget->setStyleSheet(QString::fromUtf8("QTreeWidget#functions_treeWidget {\n"
"	border: none;\n"
"}\n"
"QTreeWidget#functions_treeWidget::item{\n"
"	height: 32px;\n"
"}"));
        functions_treeWidget->setAutoExpandDelay(-1);
        functions_treeWidget->setIndentation(25);
        functions_treeWidget->setRootIsDecorated(true);
        functions_treeWidget->setItemsExpandable(true);
        functions_treeWidget->setAnimated(true);
        functions_treeWidget->setAllColumnsShowFocus(false);
        functions_treeWidget->setWordWrap(false);
        functions_treeWidget->setHeaderHidden(true);
        splitter->addWidget(functions_treeWidget);
        functions_treeWidget->header()->setCascadingSectionResizes(false);
        functions_treeWidget->header()->setMinimumSectionSize(31);
        functions_treeWidget->header()->setStretchLastSection(true);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName("layoutWidget");
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        func_stackedWidget = new QStackedWidget(layoutWidget);
        func_stackedWidget->setObjectName("func_stackedWidget");
        powerFuncW = new QWidget();
        powerFuncW->setObjectName("powerFuncW");
        verticalLayout_3 = new QVBoxLayout(powerFuncW);
        verticalLayout_3->setSpacing(20);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 20, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        powerFuncDomain = new QLabel(powerFuncW);
        powerFuncDomain->setObjectName("powerFuncDomain");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font2.setPointSize(12);
        powerFuncDomain->setFont(font2);

        gridLayout->addWidget(powerFuncDomain, 1, 1, 1, 1);

        powerFuncAccu = new QLabel(powerFuncW);
        powerFuncAccu->setObjectName("powerFuncAccu");
        powerFuncAccu->setFont(font2);

        gridLayout->addWidget(powerFuncAccu, 2, 1, 1, 1);

        label_2 = new QLabel(powerFuncW);
        label_2->setObjectName("label_2");
        QFont font3;
        font3.setPointSize(12);
        label_2->setFont(font3);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_1 = new QLabel(powerFuncW);
        label_1->setObjectName("label_1");
        label_1->setFont(font3);
        label_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_1, 0, 0, 1, 1);

        label_3 = new QLabel(powerFuncW);
        label_3->setObjectName("label_3");
        label_3->setFont(font3);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        powerFuncName = new QLabel(powerFuncW);
        powerFuncName->setObjectName("powerFuncName");
        powerFuncName->setFont(font3);

        gridLayout->addWidget(powerFuncName, 0, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        powerFuncPlot = new QCustomPlot(powerFuncW);
        powerFuncPlot->setObjectName("powerFuncPlot");

        verticalLayout_3->addWidget(powerFuncPlot);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 100);
        func_stackedWidget->addWidget(powerFuncW);
        trigoFuncW = new QWidget();
        trigoFuncW->setObjectName("trigoFuncW");
        verticalLayout_4 = new QVBoxLayout(trigoFuncW);
        verticalLayout_4->setSpacing(20);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 20, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        label_4 = new QLabel(trigoFuncW);
        label_4->setObjectName("label_4");
        label_4->setFont(font3);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        trigoFuncName = new QLabel(trigoFuncW);
        trigoFuncName->setObjectName("trigoFuncName");
        trigoFuncName->setFont(font3);

        gridLayout_2->addWidget(trigoFuncName, 0, 1, 1, 1);

        label_5 = new QLabel(trigoFuncW);
        label_5->setObjectName("label_5");
        label_5->setFont(font3);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        trigoFuncDomain = new QLabel(trigoFuncW);
        trigoFuncDomain->setObjectName("trigoFuncDomain");
        trigoFuncDomain->setFont(font2);

        gridLayout_2->addWidget(trigoFuncDomain, 1, 1, 1, 1);

        label_6 = new QLabel(trigoFuncW);
        label_6->setObjectName("label_6");
        label_6->setFont(font3);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        trigoFuncAccu = new QLabel(trigoFuncW);
        trigoFuncAccu->setObjectName("trigoFuncAccu");
        trigoFuncAccu->setFont(font2);

        gridLayout_2->addWidget(trigoFuncAccu, 2, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_2);

        trigoFuncPlot = new QCustomPlot(trigoFuncW);
        trigoFuncPlot->setObjectName("trigoFuncPlot");

        verticalLayout_4->addWidget(trigoFuncPlot);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 100);
        func_stackedWidget->addWidget(trigoFuncW);
        sphereFuncW = new QWidget();
        sphereFuncW->setObjectName("sphereFuncW");
        verticalLayout_5 = new QVBoxLayout(sphereFuncW);
        verticalLayout_5->setSpacing(20);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 20, 0, 0);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        label_7 = new QLabel(sphereFuncW);
        label_7->setObjectName("label_7");
        label_7->setFont(font3);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_7, 0, 0, 1, 1);

        sphereFuncName = new QLabel(sphereFuncW);
        sphereFuncName->setObjectName("sphereFuncName");
        sphereFuncName->setFont(font3);

        gridLayout_3->addWidget(sphereFuncName, 0, 1, 1, 1);

        label_8 = new QLabel(sphereFuncW);
        label_8->setObjectName("label_8");
        label_8->setFont(font3);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_8, 1, 0, 1, 1);

        sphereFuncDomain = new QLabel(sphereFuncW);
        sphereFuncDomain->setObjectName("sphereFuncDomain");
        sphereFuncDomain->setFont(font2);

        gridLayout_3->addWidget(sphereFuncDomain, 1, 1, 1, 1);

        label_9 = new QLabel(sphereFuncW);
        label_9->setObjectName("label_9");
        label_9->setFont(font3);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_9, 2, 0, 1, 1);

        sphereFuncAccu = new QLabel(sphereFuncW);
        sphereFuncAccu->setObjectName("sphereFuncAccu");
        sphereFuncAccu->setFont(font2);

        gridLayout_3->addWidget(sphereFuncAccu, 2, 1, 1, 1);

        label_10 = new QLabel(sphereFuncW);
        label_10->setObjectName("label_10");
        label_10->setFont(font3);
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_10, 3, 0, 1, 1);

        sphereNValueSpin = new QSpinBox(sphereFuncW);
        sphereNValueSpin->setObjectName("sphereNValueSpin");
        sphereNValueSpin->setFocusPolicy(Qt::NoFocus);
        sphereNValueSpin->setReadOnly(false);
        sphereNValueSpin->setMinimum(4);
        sphereNValueSpin->setMaximum(12);

        gridLayout_3->addWidget(sphereNValueSpin, 3, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_3);

        verticalSpacer = new QSpacerItem(20, 376, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 100);
        func_stackedWidget->addWidget(sphereFuncW);
        GA_IntroW = new QWidget();
        GA_IntroW->setObjectName("GA_IntroW");
        verticalLayout_6 = new QVBoxLayout(GA_IntroW);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        gaIntroPic = new QLabel(GA_IntroW);
        gaIntroPic->setObjectName("gaIntroPic");
        QFont font4;
        font4.setPointSize(16);
        gaIntroPic->setFont(font4);
        gaIntroPic->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(gaIntroPic);

        func_stackedWidget->addWidget(GA_IntroW);

        verticalLayout->addWidget(func_stackedWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        startDemo = new QPushButton(layoutWidget);
        startDemo->setObjectName("startDemo");
        startDemo->setFont(font3);

        horizontalLayout->addWidget(startDemo);


        verticalLayout->addLayout(horizontalLayout);

        splitter->addWidget(layoutWidget);

        verticalLayout_2->addWidget(splitter);


        retranslateUi(FunctionProWidget);

        QMetaObject::connectSlotsByName(FunctionProWidget);
    } // setupUi

    void retranslateUi(QWidget *FunctionProWidget)
    {
        FunctionProWidget->setWindowTitle(QCoreApplication::translate("FunctionProWidget", "Form", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = functions_treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("FunctionProWidget", "\345\207\275\346\225\260\350\241\250\350\276\276\345\274\217", nullptr));

        const bool __sortingEnabled = functions_treeWidget->isSortingEnabled();
        functions_treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = functions_treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("FunctionProWidget", "\345\206\205\347\275\256\345\207\275\346\225\260", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("FunctionProWidget", "f(x) = x^2", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("FunctionProWidget", "f(x) = xcos(4x) + xsin(20x) + 2", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("FunctionProWidget", "Sphere \345\207\275\346\225\260", nullptr));
        functions_treeWidget->setSortingEnabled(__sortingEnabled);

        powerFuncDomain->setText(QCoreApplication::translate("FunctionProWidget", "TextLabel", nullptr));
        powerFuncAccu->setText(QCoreApplication::translate("FunctionProWidget", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("FunctionProWidget", "\345\256\232\344\271\211\345\237\237  :", nullptr));
        label_1->setText(QCoreApplication::translate("FunctionProWidget", "\345\207\275\346\225\260  :", nullptr));
        label_3->setText(QCoreApplication::translate("FunctionProWidget", "\347\262\276\345\272\246  :", nullptr));
        powerFuncName->setText(QCoreApplication::translate("FunctionProWidget", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("FunctionProWidget", "\345\207\275\346\225\260  :", nullptr));
        trigoFuncName->setText(QCoreApplication::translate("FunctionProWidget", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("FunctionProWidget", "\345\256\232\344\271\211\345\237\237  :", nullptr));
        trigoFuncDomain->setText(QCoreApplication::translate("FunctionProWidget", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("FunctionProWidget", "\347\262\276\345\272\246  :", nullptr));
        trigoFuncAccu->setText(QCoreApplication::translate("FunctionProWidget", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("FunctionProWidget", "\345\207\275\346\225\260  :", nullptr));
        sphereFuncName->setText(QCoreApplication::translate("FunctionProWidget", "TextLabel", nullptr));
        label_8->setText(QCoreApplication::translate("FunctionProWidget", "\345\256\232\344\271\211\345\237\237  :", nullptr));
        sphereFuncDomain->setText(QCoreApplication::translate("FunctionProWidget", "TextLabel", nullptr));
        label_9->setText(QCoreApplication::translate("FunctionProWidget", "\347\262\276\345\272\246  :", nullptr));
        sphereFuncAccu->setText(QCoreApplication::translate("FunctionProWidget", "TextLabel", nullptr));
        label_10->setText(QCoreApplication::translate("FunctionProWidget", "n \345\200\274  :", nullptr));
        gaIntroPic->setText(QCoreApplication::translate("FunctionProWidget", "\347\202\271\345\207\273\345\255\220\351\241\271\351\200\211\346\213\251\345\206\205\347\275\256\345\207\275\346\225\260", nullptr));
        startDemo->setText(QCoreApplication::translate("FunctionProWidget", "\345\274\200\345\247\213\346\274\224\347\244\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FunctionProWidget: public Ui_FunctionProWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNCTIONPROWIDGET_H
