/********************************************************************************
** Form generated from reading UI file 'tspprowidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TSPPROWIDGET_H
#define UI_TSPPROWIDGET_H

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

class Ui_TSPProWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QTreeWidget *tsp_treeWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *tsp_stackedWidget;
    QWidget *GATspIntroW;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QCustomPlot *TenTspW;
    QCustomPlot *ThirtyOneTspW;
    QWidget *UserDefTspW;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSpinBox *pointNums;
    QLabel *label_3;
    QSpinBox *xMin;
    QLabel *label_4;
    QSpinBox *xMax;
    QLabel *label_5;
    QSpinBox *yMin;
    QLabel *label_6;
    QSpinBox *yMax;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *startDemo;

    void setupUi(QWidget *TSPProWidget)
    {
        if (TSPProWidget->objectName().isEmpty())
            TSPProWidget->setObjectName("TSPProWidget");
        TSPProWidget->resize(771, 513);
        verticalLayout_2 = new QVBoxLayout(TSPProWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(TSPProWidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        tsp_treeWidget = new QTreeWidget(splitter);
        QFont font;
        font.setPointSize(12);
        QFont font1;
        font1.setPointSize(10);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(tsp_treeWidget);
        __qtreewidgetitem->setFont(0, font);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem1->setFont(0, font1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem2->setFont(0, font1);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(tsp_treeWidget);
        __qtreewidgetitem3->setFont(0, font);
        tsp_treeWidget->setObjectName("tsp_treeWidget");
        tsp_treeWidget->setMinimumSize(QSize(300, 0));
        tsp_treeWidget->setMaximumSize(QSize(300, 16777215));
        tsp_treeWidget->setStyleSheet(QString::fromUtf8("QTreeWidget#tsp_treeWidget {\n"
"	border: none;\n"
"}\n"
"QTreeWidget#tsp_treeWidget::item{\n"
"	height: 32px;\n"
"}"));
        tsp_treeWidget->setHeaderHidden(true);
        splitter->addWidget(tsp_treeWidget);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName("layoutWidget");
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tsp_stackedWidget = new QStackedWidget(layoutWidget);
        tsp_stackedWidget->setObjectName("tsp_stackedWidget");
        GATspIntroW = new QWidget();
        GATspIntroW->setObjectName("GATspIntroW");
        verticalLayout_4 = new QVBoxLayout(GATspIntroW);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label = new QLabel(GATspIntroW);
        label->setObjectName("label");
        QFont font2;
        font2.setPointSize(16);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label);

        tsp_stackedWidget->addWidget(GATspIntroW);
        TenTspW = new QCustomPlot();
        TenTspW->setObjectName("TenTspW");
        tsp_stackedWidget->addWidget(TenTspW);
        ThirtyOneTspW = new QCustomPlot();
        ThirtyOneTspW->setObjectName("ThirtyOneTspW");
        tsp_stackedWidget->addWidget(ThirtyOneTspW);
        UserDefTspW = new QWidget();
        UserDefTspW->setObjectName("UserDefTspW");
        verticalLayout_3 = new QVBoxLayout(UserDefTspW);
        verticalLayout_3->setSpacing(20);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 20, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(UserDefTspW);
        label_2->setObjectName("label_2");
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        pointNums = new QSpinBox(UserDefTspW);
        pointNums->setObjectName("pointNums");
        pointNums->setFocusPolicy(Qt::NoFocus);
        pointNums->setMinimum(10);
        pointNums->setMaximum(60);

        gridLayout->addWidget(pointNums, 0, 1, 1, 1);

        label_3 = new QLabel(UserDefTspW);
        label_3->setObjectName("label_3");
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        xMin = new QSpinBox(UserDefTspW);
        xMin->setObjectName("xMin");
        xMin->setMinimum(-5000);
        xMin->setMaximum(5000);

        gridLayout->addWidget(xMin, 1, 1, 1, 1);

        label_4 = new QLabel(UserDefTspW);
        label_4->setObjectName("label_4");
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        xMax = new QSpinBox(UserDefTspW);
        xMax->setObjectName("xMax");
        xMax->setMinimum(-5000);
        xMax->setMaximum(5000);

        gridLayout->addWidget(xMax, 2, 1, 1, 1);

        label_5 = new QLabel(UserDefTspW);
        label_5->setObjectName("label_5");
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        yMin = new QSpinBox(UserDefTspW);
        yMin->setObjectName("yMin");
        yMin->setMinimum(-5000);
        yMin->setMaximum(5000);

        gridLayout->addWidget(yMin, 3, 1, 1, 1);

        label_6 = new QLabel(UserDefTspW);
        label_6->setObjectName("label_6");
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        yMax = new QSpinBox(UserDefTspW);
        yMax->setObjectName("yMax");
        yMax->setMinimum(-5000);
        yMax->setMaximum(5000);

        gridLayout->addWidget(yMax, 4, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 270, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        tsp_stackedWidget->addWidget(UserDefTspW);

        verticalLayout->addWidget(tsp_stackedWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        startDemo = new QPushButton(layoutWidget);
        startDemo->setObjectName("startDemo");
        startDemo->setFont(font);

        horizontalLayout->addWidget(startDemo);


        verticalLayout->addLayout(horizontalLayout);

        splitter->addWidget(layoutWidget);

        verticalLayout_2->addWidget(splitter);


        retranslateUi(TSPProWidget);

        QMetaObject::connectSlotsByName(TSPProWidget);
    } // setupUi

    void retranslateUi(QWidget *TSPProWidget)
    {
        TSPProWidget->setWindowTitle(QCoreApplication::translate("TSPProWidget", "Form", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = tsp_treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("TSPProWidget", "\351\227\256\351\242\230\351\200\211\346\213\251", nullptr));

        const bool __sortingEnabled = tsp_treeWidget->isSortingEnabled();
        tsp_treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = tsp_treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("TSPProWidget", "\345\206\205\347\275\256\347\244\272\344\276\213", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("TSPProWidget", "10", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("TSPProWidget", "31", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = tsp_treeWidget->topLevelItem(1);
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("TSPProWidget", "\350\207\252\345\256\232\344\271\211\347\202\271", nullptr));
        tsp_treeWidget->setSortingEnabled(__sortingEnabled);

        label->setText(QCoreApplication::translate("TSPProWidget", "\347\202\271\345\207\273\345\255\220\351\241\271\351\200\211\346\213\251\345\206\205\347\275\256\347\244\272\344\276\213", nullptr));
        label_2->setText(QCoreApplication::translate("TSPProWidget", "\347\202\271\346\225\260:  ", nullptr));
        label_3->setText(QCoreApplication::translate("TSPProWidget", "<html><head/><body><p>x<span style=\" vertical-align:sub;\">min</span>:  </p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("TSPProWidget", "<html><head/><body><p>x<span style=\" vertical-align:sub;\">max</span>:  </p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("TSPProWidget", "<html><head/><body><p>y<span style=\" vertical-align:sub;\">min</span>: </p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("TSPProWidget", "<html><head/><body><p>y<span style=\" vertical-align:sub;\">max</span>:  </p></body></html>", nullptr));
        startDemo->setText(QCoreApplication::translate("TSPProWidget", "\345\274\200\345\247\213\346\274\224\347\244\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TSPProWidget: public Ui_TSPProWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TSPPROWIDGET_H
