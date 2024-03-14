#ifndef DBINSTANCE_H
#define DBINSTANCE_H

#include <QObject>
#include <QSqlDatabase>
#include <QStringList>

class DBInstance : public QObject
{
    Q_OBJECT
public:
    static DBInstance& GetInstance();
    DBInstance(DBInstance&) = delete;
    DBInstance& operator=(DBInstance&) = delete;
    void Init_DB();
    bool HandleRegister(const char*,const char*);
    int HandleLogin(const char*,const char*);
    bool HandleLogout(const char*);
    QStringList HandleAllOnlineUsers();
    int HandleFindUser(const char*);
    int HandleGetUserId(const char*);
    QString HandleGetUsername(int);
    int HandleAddFriend(const char*,const char*);
    void HandleAddUserRelation(const char*,const char*);
    QStringList HandleFlushFriend(const char*);
    bool HandleDelRelation(const char*,const char*);
    bool HandleUserIsOnline(const char*);
    bool HandleUserIsFriend(const char*,const char*);
    QStringList HandleOnlineFriends(const char*);
    ~DBInstance();
private:
    explicit DBInstance(QObject *parent = nullptr);
    QSqlDatabase m_db;
signals:
};

#endif // DBINSTANCE_H
