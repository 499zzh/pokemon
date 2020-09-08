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
#include<msg.h>
class SqliteDBAOperator
{
public:
    SqliteDBAOperator();
    ~SqliteDBAOperator();
public:
    bool OpenDb(void);
    //创建数据库并建立连接
    void createTable(void);
    //创建数据表
    void closeDb(void);
    //关闭数据库

    int check_password(QString user_name, QString password);
    //核对密码 接应0型消息
    int register_client(QString user_name, QString password);
    //注册新用户 接应1型消息

    void pokemon_update(int id, int now_level);
    //精灵数据修改 接应自产生3型消息 战斗导致的精灵等级变化
    void client_update(int user_id, int result);
    //更新胜场等
    void new_pokemon(int user_id, int pokemon_type, int pokemon_id);
    //新增精灵  接应1型消息
    void lose_pokemon(int user_id, int pokemon_id);
    //失去精灵 接应自产生6型消息 战斗导致精灵主人发生改变
    QString inquiry_client();
    //查询当前所有用户 返回的报文类型为 用户ID
    QString inquiry_client_pokemon(QString user_name);
    //自身全部精灵ID
    QString inquiry_pokemon(int pokemon_id);
    //查询精灵(id需要翻译)
    QString load_client(int user_id);
    //加载某用户，接应0型消息
    void change_online(QString user_id, int type);
    //更改在线情况
private:
    QSqlDatabase db;//用于建立和数据库的连接
};

#endif // SQLITEDBAOPERATOR_H

#endif // DB_H
