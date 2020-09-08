#ifndef DB_H
#define DB_H

#ifndef SQLITEDBAOPERATOR_H
#define SQLITEDBAOPERATOR_H
#include"client.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>
class SqliteDBAOperator
{
public:
    SqliteDBAOperator();
    ~SqliteDBAOperator();
public:
    //创建数据库并建立连接
    bool OpenDb(void);
    //创建数据表（student）
    void createTable(void);
    //查询和显示结果
    void queryTable(QString &str);
    //判断数据表是否存在
    bool IsTaBexists(QString &Tabname);
    //插入数据
    void singleinsertdata(client &singledb);//插入单条数据
    void Moreinsertdata(QList<client> &moredb);//插入多条数据
    //删除数据
    void deletedata();
    //修改数据
    void updatedata();
    //关闭数据库
    void closeDb(void);
private:
    QSqlDatabase db;//用于建立和数据库的连接
};

#endif // SQLITEDBAOPERATOR_H

#endif // DB_H
