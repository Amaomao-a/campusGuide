#include "database.h"

database* database::userDb=nullptr;

database::database(QObject *parent) : QObject(parent)
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("10.128.206.75");
    db.setPort(3306);
    db.setDatabaseName("campus_prj");
    db.setUserName("root");
    db.setPassword("123456");

    if (!db.open())
    {
        QMessageBox::information(nullptr, "数据库连接", "数据库连接失败!", QMessageBox::Ok);
        qDebug()<<"error open database because"<<db.lastError().text();
    }
}

database::~database(){
    QSqlDatabase db = QSqlDatabase::database("campus_prj");
    db.close();
    db.removeDatabase("campus_prj");
}

database *database::getDatabase(){
    if(!userDb) userDb = new database;
    return userDb;
}

//注册功能
bool database::userRegister(const QString &userName, const QString &passwd, const QString &notes)
{
    QSqlDatabase db = QSqlDatabase::database("campus_prj");

    QSqlQuery   query(db);    // 创建一个关联的QSqlQuery对象，由QSqlQuery来实现查询工作
    query.prepare("INSERT INTO user(userName, passwd, notes) "
                          "VALUES (?, ?, ?)");
    query.addBindValue(userName);
    query.addBindValue(passwd);
    query.addBindValue(notes);
    bool ok = query.exec();     // 判断打开数据库是否成功
    if(!ok)     qDebug() << "用户注册失败: " << query.lastError().text();

    return ok;
}

//插入用户日志
bool database::msgLogInsert(const QString logTime, const QString userName, const QString userState, const QString logMsg)
{
    QSqlDatabase db = QSqlDatabase::database("campus_prj");
    QSqlQuery   query(db);    // 创建一个关联的QSqlQuery对象，由QSqlQuery来实现查询工作

    query.prepare("INSERT INTO msg_log(logTime, userName, userState, logMsg) "
                        "VALUES(?, ?, ?, ?)");
    query.addBindValue(logTime);
    query.addBindValue(userName);
    query.addBindValue(userState);
    query.addBindValue(logMsg);

    qDebug() << QString("[%1]插入了一条操作记录: [%2]").arg(logTime).arg(logMsg);
    return query.exec();
}

//插入路径日志
bool database::pathLogInsert(const QString userName, const QString timeStart, const QString from, const QString trans, const QString to, const QString strategy, const QString pathMsg, const QString timecost)
{
    QSqlDatabase db = QSqlDatabase::database("campus_prj");
    QSqlQuery   query(db);    // 创建一个关联的QSqlQuery对象，由QSqlQuery来实现查询工作

    query.prepare("INSERT INTO path_log(userName, timeStart, src, trans, dst, strategy, pathMsg, timecost) "
                        "VALUES(?, ?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(userName);
    query.addBindValue(timeStart);
    query.addBindValue(from);
    query.addBindValue(trans);
    query.addBindValue(to);
    query.addBindValue(strategy);
    query.addBindValue(pathMsg);
    query.addBindValue(timecost);

    qDebug() << QString("插入了一条路径日志: [%1]").arg(pathMsg);
    bool isOk = query.exec();

    // 每插入一条路径日志则更新偏好设置
    updateLastPath(userName, from, trans, to, strategy);
    updateCommonPath(userName);

    return isOk;
}

//重置密码时查询用户名及关键字
bool database::queryNotes(const QString &userName, const QString &notes)
{
    QSqlDatabase    db = QSqlDatabase::database("campus_prj");
    QSqlQuery   query(db);

    //判断数据库中是否存在notes
    query.prepare("select* from user where userName=? and notes=?");
    query.addBindValue(userName);
    query.addBindValue(notes);

    bool ok = query.exec();
    if(!ok){
        qDebug() << "提示信息错误: " << db.lastError().text();
        return false;
    }
    if(query.next())    return true;
    else    return false;

}

//登陆的用户名检测
bool database::queryUserName(const QString &userName)
{
    QSqlDatabase db = QSqlDatabase::database("campus_prj");
    QSqlQuery query(db);
    query.prepare("select *from user where userName=?");
    query.addBindValue(userName);
    bool ok = query.exec();
    if(!ok){
        qDebug() << "[登录]用户名不存在!" << db.lastError().text();
        return false;
    }
    if(query.next())    return true;
    else    return false;

}

//登陆的密码检测
bool database::queryPasswd(const QString &userName, const QString &passwd)
{
    QSqlDatabase db = QSqlDatabase::database("campus_prj");
    QSqlQuery query(db);
    query.prepare("select *from user where userName=? and passwd=?");
    query.addBindValue(userName);
    query.addBindValue(passwd);
    bool ok = query.exec();
    if(!ok){
        qDebug() << "[登录]密码错误!" << db.lastError().text();
        return false;
    }
    if(query.next()){
        return true;
    }
    else{
        return false;
    }
}

//重置密码时的更新
void database::updatePasswd(const QString &userName, const QString &passwd, const QString &notes)
{
    QSqlDatabase db = QSqlDatabase::database("campus_prj");
    QSqlQuery query(db);
    query.prepare("update user set passwd=? where userName=? and notes=?");
    query.addBindValue(passwd);
    query.addBindValue(userName);
    query.addBindValue(notes);

    query.exec();
}

//更新常用路径
void database::updateCommonPath(const QString userName)
{
    QSqlDatabase db = QSqlDatabase::database("campus_prj");
    QSqlQuery query(db);

    query.prepare("select * from ( "
                            "select src, trans, dst, strategy, count(*) as times "
                            "from path_log "
                            "where userName=? "
                            "group by src, trans, dst, strategy "
                            "having count(*) ) as result(src, trans, dst, strategy, times) "
                         "order by result.times desc;");
    query.addBindValue(userName);
    if(!query.exec())
    {
        qDebug() <<__FUNCTION__ <<__LINE__ << "获取常用路径失败" << db.lastError().text();
        return;
    }

    // 获取最常用的三条路径
    for(int i=1; i<=3 && query.next(); i++)
    {
        QSqlQuery queryUpdate(db);
        QString lastPath = QString("(%1, %2, %3, %4)")
                                            .arg(query.value(0).toString())
                                            .arg(query.value(1).toString())
                                            .arg(query.value(2).toString())
                                            .arg(query.value(3).toString());
        switch(i)
        {
            case 1: queryUpdate.prepare("update user set commonPath_1 = ? where userName = ?;");    break;
            case 2: queryUpdate.prepare("update user set commonPath_2 = ? where userName = ?;");    break;
            case 3: queryUpdate.prepare("update user set commonPath_3 = ? where userName = ?;");    break;
        }
        queryUpdate.addBindValue(lastPath);
        queryUpdate.addBindValue(userName);
        queryUpdate.exec();
//        qDebug() << __FUNCTION__ << __LINE__ << queryUpdate.exec();
    }// end of for
}

//更新最近使用路径
void database::updateLastPath(const QString userName, QString src, QString trans, QString dst, QString strategy)
{
    QSqlDatabase db = QSqlDatabase::database("campus_prj");
    QSqlQuery queryUpdate(db);

    queryUpdate.prepare("update user set lastPath = ? where userName = ?;");
    QString lastPath = QString("(%1, %2, %3, %4)").arg(src).arg(trans).arg(dst).arg(strategy);
    queryUpdate.addBindValue(lastPath);
    queryUpdate.addBindValue(userName);  // userName
    queryUpdate.exec();
//    qDebug() <<__FUNCTION__ <<__LINE__ <<QString( "插入了一条路径日志: [%1]").arg(lastPath);
}

void database::getPreferredPath(const QString userName, QList<QString> &commonPath)
{
    QSqlDatabase db = QSqlDatabase::database("campus_prj");
    QSqlQuery query(db);
    query.prepare("select * from user where userName=?");
    query.addBindValue(userName);
    query.exec();
    query.next();

    commonPath.clear();
    commonPath << "上次: " + query.value(3).toString();
    commonPath << "常用1: " + query.value(4).toString();
    commonPath << "常用2: " + query.value(5).toString();
    commonPath << "常用3: " + query.value(6).toString();
}
