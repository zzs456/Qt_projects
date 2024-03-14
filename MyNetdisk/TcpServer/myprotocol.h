#ifndef MYPROTOCOL_H
#define MYPROTOCOL_H

typedef unsigned int uint;

#define REGISTER_OK "register ok"
#define REGISTER_FAIL "register fail"
#define LOGIN_OK "login ok"
#define LOGIN_FAIL "login fail"
#define LOGIN_REPEAT "login repeat"
#define FINDUSER_NOT_EXIST "user not exist"
#define FINDUSER_ONLINE "user online"
#define FINDUSER_OFFONLINE "user offline"
#define ADDFRIEND_UNKNOWN_ERROR "add friend unknown error"
#define ADDFRIEND_SELF "add friend self"
#define ADDFRIEND_REPEAT "add friend repeat"
#define ADDFRIEND_OFFLINE "add friend offline"
#define DELFRIEND_SUCCESS "delete friend success"
#define DELFRIEND_FAIL "delete friend fail"
#define PRIVATECHAT_SUCCESS "private user online"
#define PRIVATECHAT_FAIL "private user offline"
#define CREATEDIR_SUCCESS "create dir success"
#define CREATEDIR_FAIL "create dir fail"
#define DELDIR_SUCCESS "delete dir success"
#define DELDIR_FAIL "delete dir fail"
#define DELFILE_SUCCESS "delete file success"
#define DELFILE_FAIL "delete file fail"
#define RENAME_SUCCESS "rename success"
#define RENAME_FAIL "rename fail"
#define ENTERDIR_SUCCESS "enter dir success"
#define ENTERDIR_FAIL "enter dir fail"
#define MOVEFILE_SUCCESS "move file success"
#define MOVEFILE_FAIL "move file fail"
#define DESTDIR_FAIL "dest dir fail"
#define UPLOADFILE_SUCCESS "upload file success"
#define UPLOADFILE_FAIL "upload file fail"
#define DOWNLOADFILE_FAIL_DIR "download dir fail"
#define DOWNLOADFILE_SUCCESS "download file success"
#define DOWNLOADFILE_START "download file start"
#define DOWNLOADFILE_FAIL "download file fail"
#define SHAREFILE_DIR_SUCCESS "share file dir success"
#define SHAREFILE_DIR_FAIL  "share file dir fail"
#define SHAREFILE_SUCCESS "share file success"

enum MSGTYPE{
    MSGTYPE_MIN = 0,
    MSGTYPE_REGISTER_REQUEST,               // 注册请求
    MSGTYPE_REGISTER_RESPOND,               // 注册回复
    MSGTYPE_LOGIN_REQUEST,                  // 登录请求
    MSGTYPE_LOGIN_RESPOND,                  // 登录回复
    MSGTYPE_ALL_ONLINEUSRES_REQUEST,        // 显示在线用户请求
    MSGTYPE_ALL_ONLINEUSRES_RESPOND,        // 显示在线用户回复
    MSGTYPE_FINDUSER_REQUEST,               // 查找用户请求
    MSGTYPE_FINDUSER_RESPOND,               // 查找用户回复
    MSGTYPE_ADD_FRIEND_REQUEST,             // 添加好友请求
    MSGTYPE_ADD_FRIEND_RESPOND,             // 添加好友回复
    MSGTYPE_AGREE_ADDFRIEND,                // 同意添加好友
    MSGTYPE_REFUSE_ADDFRIEND,               // 拒绝添加好友
    MSGTYPE_FLUSHFRIEND_REQUEST,            // 刷新好友请求
    MSGTYPE_FLUSHFRIEND_RESPOND,            // 刷新好友回复
    MSGTYPE_DELFRIEND_REQUEST,              // 删除好友请求
    MSGTYPE_DELFRIEND_RESPOND,              // 删除好友回复
    MSGTYPE_PRIVATECHAT_REQUEST,            // 私聊请求
    MSGTYPE_PRIVATECHAT_RESPOND,            // 私聊回复
    MSGTYPE_PRIVATECHAT_SENDMSG,            // 私聊发送信息
    MSGTYPE_GROUPCHAT_REQUEST,              // 群聊请求

    MSGTYPE_CREATEDIR_REQUEST,              // 创建文件夹请求
    MSGTYPE_CREATEDIR_RESPOND,              // 创建文件夹回复
    MSGTYPE_FLUSHDIR_REQUEST,               // 刷新文件夹请求
    MSGTYPE_FLUSHDIR_RESPOND,               // 刷新文件夹回复
    MSGTYPE_DELDIR_REQUEST,                 // 删除文件夹请求
    MSGTYPE_DELDIR_RESPND,                  // 删除文件夹回复
    MSGTYPE_DELFILE_REQUEST,                // 删除文件请求
    MSGTYPE_DELFILE_RESPND,                 // 删除文件回复
    MSGTYPE_RENAME_REQUEST,                 // 重命名请求
    MSGTYPE_RENAME_RESPOND,                 // 重命名回复
    MSGTYPE_ENTERDIR_REQUEST,               // 进入文件夹请求
    MSGTYPE_ENTERDIR_RESPOND,               // 进入文件夹回复
    MSGTYPE_MOVEFILE_REQUEST,               // 移动文件请求
    MSGTYPE_MOVEFILE_RESPOND,               // 移动文件回复
    MSGTYPE_UPLOADFILE_REQUEST,             // 上传文件请求
    MSGTYPE_UPLOADFILE_RESPOND,             // 上传文件回复
    MSGTYPE_DOWNLOADFILE_REQUEST,           // 下载文件请求
    MSGTYPE_DOWNLOADFILE_RESPOND,           // 下载文件回复
    MSGTYPE_SHAREFILE_REQUEST,              // 分享文件请求
    MSGTYPE_SHAREFILE_RESPOND,              // 分享文件回复
    MSGTYPE_SHAREFILETOFRIEND_REQUEST,      // 向在线好友发送文件请求
    MSGTYPE_SHAREFILETOFRIEND_RESPOND,      // 向在线好友发送文件回复
    MSGTYPE_RECVFILEFROMFRIEND_REQUEST,     // 接受文件请求
    MSGTYPE_RECVFILEFROMFRIEND_RESPOND,     // 接受文件回复

    MSGTYPE_MAX = 0x00ffffff
};

struct FileInfo{
    char fileName[32];
    int fileType;
};

struct PDU{
    uint PDULength;     // PDU 的总长度
    uint MsgType;       // 消息的类型
    char caData[64];    // 附加信息
    uint MsgLength;     // 实际消息的长度
    char msg[];         // 实际消息
};

PDU *mkPDU(uint MsgLength);

#endif // MYPROTOCOL_H
