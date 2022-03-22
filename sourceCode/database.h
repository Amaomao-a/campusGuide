#ifndef DATABASE_H
#define DATABASE_H


#include <QSqlDatabase> //用于创建连接并打开数据库
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>    //执行查询操作
#include <QObject>
#include <QMessageBox>
#include <QDateTime>

class database:public QObject{
    Q_OBJECT
public:
    explicit database(QObject *parent=nullptr);
    ~database();
    static database *getDatabase();
    bool userRegister(const QString &userName, const QString &passwd, const QString &notes);  // 用户注册
    bool queryNotes(const QString &userName, const QString &notes);   // 查询关键字用于验证重置密码
    bool queryUserName(const QString &userName);    // 登录时的用户名验证
    bool queryPasswd(const QString &userName, const QString &passwd);  // 登录时的密码验证
    void updatePasswd(const QString &userName, const QString &passwd, const QString &notes); //重置密码时更新密码
    static void updateCommonPath(const QString userName); // 更新常用路径
    static void updateLastPath(const QString userName, QString src, QString trans, QString dst, QString strategy); // 更新最近使用的路径

    // 插入一条操作记录日志
    static bool msgLogInsert(const QString logTime, const QString userName, const QString userState, const QString logMsg);
    // 插入一条已经完成的路径日志，用于偏好设置
    static bool pathLogInsert(const QString userName, const QString timeStart, const QString from, const QString trans, const QString to, const QString strategy, const QString pathMsg, const QString timecost);
    // 获取日志记录，用于偏好设置
    static void getPreferredPath(const QString userName, QList<QString> &commonPath);

private:
    static   database *userDb;

};

#endif // DATABASE_H
