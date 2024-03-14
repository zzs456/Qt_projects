#include "filewidget.h"
#include "ui_filewidget.h"
#include "myprotocol.h"

#include <QInputDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>

FileWidget::FileWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FileWidget)
{
    ui->setupUi(this);

    shareFileWidget = new ShareFileWidget;
    shareFileWidget->setWindowTitle("共享文件");
    shareFileWidget->hide();

    connect(shareFileWidget,&ShareFileWidget::ShareFileToFriends,this,&FileWidget::do_ShareFileToFriendSignal);
}

FileWidget::~FileWidget()
{
    delete shareFileWidget;
    delete ui;
}

void FileWidget::HandleCreateDirRespond(bool isOk)
{
    if(isOk){
        QMessageBox::about(this,"创建文件夹","创建文件夹成功");
        emit FlushDirSignal();
    }else{
        QMessageBox::warning(this,"创建文件夹","该文件夹已存在");
    }
}

void FileWidget::HandleFlushDirRespond(PDU *pdu)
{
    ui->m_showList->clear();
    int nums = pdu->MsgLength / sizeof(FileInfo);
    FileInfo* fileInfo = NULL;
    for(int i = 0;i < nums;++ i){
        fileInfo = (FileInfo*)pdu->msg + i;
        QListWidgetItem *temp = new QListWidgetItem;
        if(fileInfo->fileType == 0){
            temp->setIcon(QIcon(":/iconRes/res/dir.jpg"));
        }else{
            temp->setIcon(QIcon(":/iconRes/res/reg.jpg"));
        }
        temp->setText(fileInfo->fileName);
        ui->m_showList->addItem(temp);
    }
}

void FileWidget::HandleDelDirRespond(bool isDir)
{

    if(isDir){
        QMessageBox::about(this,"删除文件夹","删除文件夹成功");
        emit FlushDirSignal();
    }else{
        QMessageBox::warning(this,"删除文件夹","请选择文件夹");
    }
}

void FileWidget::HandleDelFileRespond(bool isOk)
{
    if(isOk){
        QMessageBox::about(this,"删除文件","删除文件成功");
        emit FlushDirSignal();
    }else{
        QMessageBox::warning(this,"删除文件","请选择文件");
    }
}

void FileWidget::HandleRenameRespond(bool isOk)
{
    if(isOk){
        QMessageBox::about(this,"重命名操作","重命名成功");
        emit FlushDirSignal();
    }else{
        QMessageBox::warning(this,"重命名操作","重命名失败: 名字不能重复");
    }
}

void FileWidget::HandleReturn()
{
    QMessageBox::warning(this,"返回上一级目录","当前目录已经是根目录");
}

void FileWidget::HandleMoveFileRespond(int ret)
{
    if(ret == 0){
        QMessageBox::about(this,"移动文件","移动文件成功");
        emit FlushDirSignal();
    }else if(ret == 1){
        QMessageBox::warning(this,"移动文件","请选择文件进行移动");
    }else{
        QMessageBox::warning(this,"移动文件","目标目录不能是文件");
    }
}

void FileWidget::HandleUploadFileRespond(bool isOk)
{
    if(isOk){
        QMessageBox::about(this,"上传文件","上传文件成功");
        emit FlushDirSignal();
    }else{
        QMessageBox::warning(this,"上传文件","上传文件失败");
    }
}

void FileWidget::HandleShareFileWidgetShow(PDU *pdu)
{
    char ret[32];
    strncpy(ret,pdu->caData,32);
    if(strcmp(ret,SHAREFILE_DIR_FAIL) == 0){
        QMessageBox::warning(this,"分享文件","请选择文件进行上传");
    }else{
        shareFileWidget->HandleShareFileWidgetShow(pdu);
    }
}

void FileWidget::on_m_createDir_clicked()
{
    QString newDir = QInputDialog::getText(this,"创建文件夹","请输入文件夹名: ");
    if(!newDir.isEmpty()){
        emit CreateDirSignal(newDir);
    }else{
        QMessageBox::warning(this,"创建文件夹","文件夹名不能为空");
    }
}


void FileWidget::on_m_flushFile_clicked()
{
    emit FlushDirSignal();
}


void FileWidget::on_m_deleteDir_clicked()
{
    QListWidgetItem *currentItem = ui->m_showList->currentItem();
    if(!currentItem){
        QMessageBox::warning(this,"删除文件夹","请选择要删除的文件夹");
    }else{
        emit DelDirSignal(currentItem->text());
    }
}


void FileWidget::on_m_renameDir_clicked()
{
    QListWidgetItem *currentItem = ui->m_showList->currentItem();
    if(!currentItem){
        QMessageBox::warning(this,"重命名操作","请选择要重命名的文件或文件夹");
    }else{
        QString newName = QInputDialog::getText(this,"重命名操作","请输入新名: ");
        if(!newName.isEmpty()){
            emit RenameSignal(currentItem->text(),newName);
        }else{
            QMessageBox::warning(this,"重命名操作","新名不能为空");
        }
    }
}


void FileWidget::on_m_showList_itemDoubleClicked(QListWidgetItem *item)
{
    emit EnterDir(item->text());
}


void FileWidget::on_m_return_clicked()
{
    emit ReturnFatherDir();
}


void FileWidget::on_m_deleteFile_clicked()
{
    QListWidgetItem *currentItem = ui->m_showList->currentItem();
    if(!currentItem){
        QMessageBox::warning(this,"删除文件","请选择要删除的文件");
    }else{
        emit DelFileSignal(currentItem->text());
    }
}


void FileWidget::on_m_moveFile_clicked()
{
    QListWidgetItem *currentItem = ui->m_showList->currentItem();
    if(!currentItem){
        QMessageBox::warning(this,"移动文件","请选择要移动的文件");
    }else{
        ui->m_selectFile->setEnabled(true);
        emit MoveFileSignal(currentItem->text());
    }
}


void FileWidget::on_m_selectFile_clicked()
{
    QListWidgetItem *currentItem = ui->m_showList->currentItem();
    ui->m_selectFile->setEnabled(false);
    if(!currentItem){
        emit SelectDestFileSignal("");
    }else{
        emit SelectDestFileSignal(currentItem->text());
    }
}


void FileWidget::on_m_uploadFile_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,"选择文件");
    if(!filePath.isEmpty()){
        QFileInfo fileInfo(filePath);
        if(fileInfo.isDir()){
            QMessageBox::warning(this,"选择文件","请选择文件");
            return;
        }
        QFile file(filePath);
        emit UploadFileSignal(filePath,file.size());
    }else{
        QMessageBox::warning(this,"选择文件","请选择要上传的文件");
    }
}


void FileWidget::on_m_downloadFile_clicked()
{
    QListWidgetItem *currentItem = ui->m_showList->currentItem();
    if(!currentItem){
        QMessageBox::warning(this,"下载文件","请选择要下载的文件");
    }else{
        QString destFile = QFileDialog::getSaveFileName(this,"下载文件","请指定保存路径");
        if(destFile.isEmpty()){
            QMessageBox::warning(this,"下载文件","请指定保存路径");
            return;
        }
        // qDebug() << destFile;
        emit DownloadFileSignal(currentItem->text(),destFile);
    }
}


void FileWidget::on_m_shareFile_clicked()
{
    QListWidgetItem *currentItem = ui->m_showList->currentItem();
    if(!currentItem){
        QMessageBox::warning(this,"分享文件","请选择要分享的文件");
        return;
    }else{
        m_shareFile.clear();
        m_shareFile = currentItem->text();
        emit ShareFileSignal(currentItem->text());
    }
}

void FileWidget::do_ShareFileToFriendSignal(QStringList &users)
{
    emit ShareFileToFriendsSignal(users,m_shareFile);
}

