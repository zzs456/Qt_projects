#ifndef FILEWIDGET_H
#define FILEWIDGET_H

#include "myprotocol.h"
#include "sharefilewidget.h"

#include <QWidget>
#include <QListWidgetItem>
#include <QStringList>

namespace Ui {
class FileWidget;
}

class FileWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FileWidget(QWidget *parent = nullptr);
    ~FileWidget();

    void HandleCreateDirRespond(bool);
    void HandleFlushDirRespond(PDU*);
    void HandleDelDirRespond(bool);
    void HandleDelFileRespond(bool);
    void HandleRenameRespond(bool);
    void HandleReturn();
    void HandleMoveFileRespond(int);
    void HandleUploadFileRespond(bool);
    void HandleShareFileWidgetShow(PDU*);

private slots:
    void on_m_createDir_clicked();

    void on_m_flushFile_clicked();

    void on_m_deleteDir_clicked();

    void on_m_renameDir_clicked();

    void on_m_showList_itemDoubleClicked(QListWidgetItem *);

    void on_m_return_clicked();

    void on_m_deleteFile_clicked();

    void on_m_moveFile_clicked();

    void on_m_selectFile_clicked();

    void on_m_uploadFile_clicked();

    void on_m_downloadFile_clicked();

    void on_m_shareFile_clicked();

    void do_ShareFileToFriendSignal(QStringList &);

signals:
    void CreateDirSignal(QString);
    void FlushDirSignal();
    void DelDirSignal(QString);
    void RenameSignal(QString,QString);
    void EnterDir(QString);
    void ReturnFatherDir();
    void DelFileSignal(QString);
    void MoveFileSignal(QString);
    void SelectDestFileSignal(QString);
    void UploadFileSignal(QString,qint64);
    void DownloadFileSignal(QString,QString);
    void ShareFileSignal(QString);
    void ShareFileToFriendsSignal(QStringList &,QString);

private:
    Ui::FileWidget *ui;

    ShareFileWidget *shareFileWidget;

    QString m_shareFile;
};

#endif // FILEWIDGET_H
