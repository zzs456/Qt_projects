#ifndef DBINSTANCE_H
#define DBINSTANCE_H

#include <QObject>
#include <QSqlDatabase>


class DBInstance : public QObject
{
    Q_OBJECT
public:
    static DBInstance& GetInstance();
    DBInstance(DBInstance&) = delete;
    DBInstance& operator=(DBInstance&) = delete;
    void Init_DB();
    ~DBInstance();

    bool HandleRegister(const char*,const char*);
    bool HandleLogin(const char*,const char*);
    bool HandleUserExist(const char*,const char*);
    void HandleLogout(const char*);
    bool HandleChangePW(const char*,const char *);
private:
    explicit DBInstance(QObject *parent = nullptr);

private:
    QSqlDatabase m_db;

signals:
};

#endif // DBINSTANCE_H
