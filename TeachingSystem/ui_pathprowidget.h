/********************************************************************************
** Form generated from reading UI file 'pathprowidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATHPROWIDGET_H
#define UI_PATHPROWIDGET_H

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

class Ui_PathProWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QTreeWidget *path_treeWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *path_stackedWidget;
    QWidget *GAPathIntroW;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QCustomPlot *FivePathW;
    QCustomPlot *TwentyPathW;
    QCustomPlot *ThirtyPathW;
    QWidget *UserDefPathW;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_2;
    QSpinBox *pathWSpin;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_3;
    QSpinBox *pathHSpin;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *startDemo;

    void setupUi(QWidget *PathProWidget)
    {
        if (PathProWidget->objectName().isEmpty())
            PathProWidget->setObjectName("PathProWidget");
        PathProWidget->resize(800, 531);
        verticalLayout_2 = new QVBoxLayout(PathProWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(PathProWidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        path_treeWidget = new QTreeWidget(splitter);
        QFont font;
        font.setPointSize(12);
        QFont font1;
        font1.setPointSize(10);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(path_treeWidget);
        __qtreewidgetitem->setFont(0, font);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem1->setFont(0, font1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem2->setFont(0, font1);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem3->setFont(0, font1);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(path_treeWidget);
        __qtreewidgetitem4->setFont(0, font);
        path_treeWidget->setObjectName("path_treeWidget");
        path_treeWidget->setMinimumSize(QSize(300, 0));
        path_treeWidget->setMaximumSize(QSize(300, 16777215));
        path_treeWidget->setStyleSheet(QString::fromUtf8("QTreeWidget#path_treeWidget {\n"
"	border: none;\n"
"}\n"
"QTreeWidget#path_treeWidget::item{\n"
"	height: 32px;\n"
"}"));
        path_treeWidget->setHeaderHidden(true);
        splitter->addWidget(path_treeWidget);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName("layoutWidget");
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        path_stackedWidget = new QStackedWidget(layoutWidget);
        path_stackedWidget->setObjectName("path_stackedWidget");
        GAPathIntroW = new QWidget();
        GAPathIntroW->setObjectName("GAPathIntroW");
        verticalLayout_3 = new QVBoxLayout(GAPathIntroW);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label = new QLabel(GAPathIntroW);
        label->setObjectName("label");
        QFont font2;
        font2.setPointSize(16);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        path_stackedWidget->addWidget(GAPathIntroW);
        FivePathW = new QCustomPlot();
        FivePathW->setObjectName("FivePathW");
        path_stackedWidget->addWidget(FivePathW);
        TwentyPathW = new QCustomPlot();
        TwentyPathW->setObjectName("TwentyPathW");
        path_stackedWidget->addWidget(TwentyPathW);
        ThirtyPathW = new QCustomPlot();
        ThirtyPathW->setObjectName("ThirtyPathW");
        path_stackedWidget->addWidget(ThirtyPathW);
        UserDefPathW = new QWidget();
        UserDefPathW->setObjectName("UserDefPathW");
        verticalLayout_4 = new QVBoxLayout(UserDefPathW);
        verticalLayout_4->setSpacing(20);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 20, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(20);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        label_2 = new QLabel(UserDefPathW);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        pathWSpin = new QSpinBox(UserDefPathW);
        pathWSpin->setObjectName("pathWSpin");
        pathWSpin->setFocusPolicy(Qt::NoFocus);
        pathWSpin->setMinimum(5);
        pathWSpin->setMaximum(30);

        gridLayout->addWidget(pathWSpin, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 3, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 1, 0, 1, 1);

        label_3 = new QLabel(UserDefPathW);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        pathHSpin = new QSpinBox(UserDefPathW);
        pathHSpin->setObjectName("pathHSpin");
        pathHSpin->setMinimum(5);
        pathHSpin->setMaximum(30);

        gridLayout->addWidget(pathHSpin, 1, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 3, 1, 1);


        verticalLayout_4->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 371, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 100);
        path_stackedWidget->addWidget(UserDefPathW);

        verticalLayout->addWidget(path_stackedWidget);

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


        retranslateUi(PathProWidget);

        QMetaObject::connectSlotsByName(PathProWidget);
    } // setupUi

    void retranslateUi(QWidget *PathProWidget)
    {
        PathProWidget->setWindowTitle(QCoreApplication::translate("PathProWidget", "Form", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = path_treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("PathProWidget", "\351\227\256\351\242\230\351\200\211\346\213\251", nullptr));

        const bool __sortingEnabled = path_treeWidget->isSortingEnabled();
        path_treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = path_treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("PathProWidget", "\345\206\205\347\275\256\347\244\272\344\276\213", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("PathProWidget", "5 * 5", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("PathProWidget", "20 * 15", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("PathProWidget", "30 * 30", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = path_treeWidget->topLevelItem(1);
        ___qtreewidgetitem5->setText(0, QCoreApplication::translate("PathProWidget", "\350\207\252\345\256\232\344\271\211\347\275\221\346\240\274\345\244\247\345\260\217", nullptr));
        path_treeWidget->setSortingEnabled(__sortingEnabled);

        label->setText(QCoreApplication::translate("PathProWidget", "\347\202\271\345\207\273\345\255\220\351\241\271\351\200\211\346\213\251\345\206\205\347\275\256\347\244\272\344\276\213", nullptr));
        label_2->setText(QCoreApplication::translate("PathProWidget", "\345\256\275\345\272\246:  ", nullptr));
        label_3->setText(QCoreApplication::translate("PathProWidget", "\351\253\230\345\272\246:  ", nullptr));
        startDemo->setText(QCoreApplication::translate("PathProWidget", "\345\274\200\345\247\213\346\274\224\347\244\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PathProWidget: public Ui_PathProWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATHPROWIDGET_H
