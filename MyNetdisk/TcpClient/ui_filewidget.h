/********************************************************************************
** Form generated from reading UI file 'filewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEWIDGET_H
#define UI_FILEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QListWidget *m_showList;
    QVBoxLayout *verticalLayout;
    QPushButton *m_return;
    QPushButton *m_createDir;
    QPushButton *m_deleteDir;
    QPushButton *m_renameDir;
    QPushButton *m_flushFile;
    QVBoxLayout *verticalLayout_2;
    QPushButton *m_uploadFile;
    QPushButton *m_downloadFile;
    QPushButton *m_deleteFile;
    QPushButton *m_shareFile;
    QPushButton *m_moveFile;
    QPushButton *m_selectFile;

    void setupUi(QWidget *FileWidget)
    {
        if (FileWidget->objectName().isEmpty())
            FileWidget->setObjectName("FileWidget");
        FileWidget->resize(833, 525);
        horizontalLayout = new QHBoxLayout(FileWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        m_showList = new QListWidget(FileWidget);
        m_showList->setObjectName("m_showList");

        horizontalLayout->addWidget(m_showList);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        m_return = new QPushButton(FileWidget);
        m_return->setObjectName("m_return");

        verticalLayout->addWidget(m_return);

        m_createDir = new QPushButton(FileWidget);
        m_createDir->setObjectName("m_createDir");

        verticalLayout->addWidget(m_createDir);

        m_deleteDir = new QPushButton(FileWidget);
        m_deleteDir->setObjectName("m_deleteDir");

        verticalLayout->addWidget(m_deleteDir);

        m_renameDir = new QPushButton(FileWidget);
        m_renameDir->setObjectName("m_renameDir");

        verticalLayout->addWidget(m_renameDir);

        m_flushFile = new QPushButton(FileWidget);
        m_flushFile->setObjectName("m_flushFile");

        verticalLayout->addWidget(m_flushFile);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        m_uploadFile = new QPushButton(FileWidget);
        m_uploadFile->setObjectName("m_uploadFile");

        verticalLayout_2->addWidget(m_uploadFile);

        m_downloadFile = new QPushButton(FileWidget);
        m_downloadFile->setObjectName("m_downloadFile");

        verticalLayout_2->addWidget(m_downloadFile);

        m_deleteFile = new QPushButton(FileWidget);
        m_deleteFile->setObjectName("m_deleteFile");

        verticalLayout_2->addWidget(m_deleteFile);

        m_shareFile = new QPushButton(FileWidget);
        m_shareFile->setObjectName("m_shareFile");

        verticalLayout_2->addWidget(m_shareFile);

        m_moveFile = new QPushButton(FileWidget);
        m_moveFile->setObjectName("m_moveFile");

        verticalLayout_2->addWidget(m_moveFile);

        m_selectFile = new QPushButton(FileWidget);
        m_selectFile->setObjectName("m_selectFile");
        m_selectFile->setEnabled(false);

        verticalLayout_2->addWidget(m_selectFile);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(FileWidget);

        QMetaObject::connectSlotsByName(FileWidget);
    } // setupUi

    void retranslateUi(QWidget *FileWidget)
    {
        FileWidget->setWindowTitle(QCoreApplication::translate("FileWidget", "\346\226\207\344\273\266\347\263\273\347\273\237", nullptr));
        m_return->setText(QCoreApplication::translate("FileWidget", "\350\277\224\345\233\236\344\270\212\344\270\200\347\272\247", nullptr));
        m_createDir->setText(QCoreApplication::translate("FileWidget", "\345\210\233\345\273\272\346\226\207\344\273\266\345\244\271", nullptr));
        m_deleteDir->setText(QCoreApplication::translate("FileWidget", "\345\210\240\351\231\244\346\226\207\344\273\266\345\244\271", nullptr));
        m_renameDir->setText(QCoreApplication::translate("FileWidget", "\351\207\215\345\221\275\345\220\215", nullptr));
        m_flushFile->setText(QCoreApplication::translate("FileWidget", "\345\210\267\346\226\260\346\226\207\344\273\266\345\244\271", nullptr));
        m_uploadFile->setText(QCoreApplication::translate("FileWidget", "\344\270\212\344\274\240\346\226\207\344\273\266", nullptr));
        m_downloadFile->setText(QCoreApplication::translate("FileWidget", "\344\270\213\350\275\275\346\226\207\344\273\266", nullptr));
        m_deleteFile->setText(QCoreApplication::translate("FileWidget", "\345\210\240\351\231\244\346\226\207\344\273\266", nullptr));
        m_shareFile->setText(QCoreApplication::translate("FileWidget", "\345\210\206\344\272\253\346\226\207\344\273\266", nullptr));
        m_moveFile->setText(QCoreApplication::translate("FileWidget", "\347\247\273\345\212\250\346\226\207\344\273\266", nullptr));
        m_selectFile->setText(QCoreApplication::translate("FileWidget", "\347\233\256\346\240\207\347\233\256\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileWidget: public Ui_FileWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEWIDGET_H
