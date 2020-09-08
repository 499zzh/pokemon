#include "db.h"
#include <QDir>
#include <QStringList>
#include "set.h"



SqliteDBAOperator::SqliteDBAOperator()
{
    QSqlDatabase database;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        //建立和sqlite数据的连接
        db = QSqlDatabase::addDatabase("QSQLITE");
        //设置数据库文件的名字
        QString dbname = "./user_db.db";
        db.setDatabaseName(dbname);
    }
}

/*析构函数关闭数据库连接*/
SqliteDBAOperator::~SqliteDBAOperator()
{
    db.close();
}

//打开数据库
bool SqliteDBAOperator::OpenDb(void)
{
    //打开数据库
    if(db.open() == false){
        qDebug() << "fail！";
        return false;
    }
    qDebug() << "success!";
    return true;
}

//创建数据表
void SqliteDBAOperator::createTable(void)
{
    //用于执行sql语句的对象
    QSqlQuery query;
    //构建创建数据库的sql语句字符串
    QString str1 = QString("CREATE TABLE USER (\
                          ID INTEGER PRIMARY KEY AUTOINCREMENT,\
                          USER_NAME TEXT,\
                          PASSWORD TEXT,\
                          WIN INTEGER,\
                          LOSE INTEGER,\
                          POKEMON_LIST TEXT)");
    //执行sql语句
    query.exec(str1);
    QString str2 = QString("CREATE TABLE POKEMON(ID INTEGER PRIMARY KEY,\
                            POKEMON_TYPE TEXT,LEVEL INTEGER, CLIENT_ID INTEGER)");
    query.exec(str2);
}

//关闭数据库
void SqliteDBAOperator::closeDb(void)
{
    db.close();
}

//核对密码
int SqliteDBAOperator::check_password(QString user_name, QString password){
    QSqlQuery query;
    QString str1 = "SELECT PASSWORD FROM USER WHERE USER_NAME = " + user_name;
    query.exec(str1);
    query.next();
    if(query.value(0).toByteArray().length() == 0){
        qDebug() << query.value(0).toByteArray();
        return NONEXISTENT;
    }
    if(query.value(0).toString() == password){
        query.exec(QString("select ID from USER where USER_NAME = ") + user_name);
        query.next();
        int id = query.value(0).toInt();
        return id;
    }

    else if(query.value(0).toString() != password)
        return FAIL;
}

//注册
int SqliteDBAOperator::register_client(QString user_name, QString password){
    QSqlQuery query;
    //如果无同名用户
    if(this->check_password(user_name, password) == NONEXISTENT){
        query.prepare("INSERT INTO USER(USER_NAME, PASSWORD, WIN, LOSE,\
                        POKEMON_LIST)\
                        VALUES(:USER_NAME, :PASSWORD, :WIN, :LOSE,\
                        :POKEMON_LIST)");
        query.bindValue(":USER_NAME", user_name);
        query.bindValue(":PASSWORD", password);
        query.bindValue(":WIN", 0);
        query.bindValue(":LOSE", 0);
        query.bindValue(":POKEMON_LIST", "");
        if(!query.exec())
          qDebug() << query.lastError();
        else{
            return SUCCESS;
        }
    }
    else
        return FAIL;
}

//更新精灵列表
void SqliteDBAOperator::pokemon_update(int id, int now_level){
    QSqlQuery query;
    QString str;
    str = QString("update POKEMON set level = '%1' where ID = '%2'").arg(now_level).arg(id);
    query.exec(str);
}

//更新用户信息
void SqliteDBAOperator::client_update(int user_id, int result){
    QSqlQuery query;
    query.exec(QString("select WIN from USER where ID = '%1'").arg(user_id));
    query.next();
    int win = query.value(0).toInt();
    query.exec(QString("select LOSE from USER where ID = '%1'").arg(user_id));
    query.next();
    int lose = query.value(0).toInt();
    if(result == 0){
        query.exec(QString("update USER set WIN = '%1' where ID = '%2'").arg(win+1).arg(user_id));
    }
    else{

        query.exec(QString("update USER set LOSE = '%1' where ID = '%2'").arg(lose+1).arg(user_id));
    }
}

//新建一个精灵
void SqliteDBAOperator::new_pokemon(int user_id, int pokemon_type, int pokemon_id){
    QSqlQuery query;
   // qDebug() << "exe_new";
    query.exec(QString("insert into POKEMON(ID, POKEMON_TYPE, LEVEL, CLIENT_ID)\
                        values('%1', '%2', 1, '%3')").arg(pokemon_id).arg(pokemon_type).arg(user_id));
    //在精灵表中新建一个一级该类型精灵
    qDebug() << query.lastError();
    query.exec(QString("select POKEMON_LIST from USER where ID = '%1'").arg(user_id));
    query.next();
    QString temp = query.value(0).toString().append(QString::number(pokemon_id)) + "//";
    //获取旧的精灵列表,并更新

    query.exec(QString("update USER set POKEMON_LIST = '%1'\
                         where id = '%2'").arg(temp).arg(user_id));
}

//失去一个精灵，直接从数据库中和user的pokemon_list中删除
void SqliteDBAOperator::lose_pokemon(int user_id, int pokemon_id){
    QSqlQuery query;
    qDebug() << "s lose";
    query.exec(QString("select POKEMON_LIST from USER where ID = '%1'").arg(user_id));
    query.next();
    QString temp = query.value(0).toString();
    int index = temp.indexOf(QString::number(pokemon_id));
    qDebug() << temp << "!" << index;
    temp = temp.replace(index, QString::number(pokemon_id).length() + 2, "");
    //qDebug() << temp;
    query.exec(QString("update USER set POKEMON_LIST = '%1' where ID = '%2'").arg(temp).arg(user_id));
    //删除user中pokemon_list的信息
    query.exec(QString("delete from POKEMON where ID = '%2'").arg(pokemon_id));
}

//查询某用户的信息
QString SqliteDBAOperator::inquiry_client(){
    QSqlQuery query2;
    QSqlQuery queryw;
    QSqlQuery queryl;
    QString msg;
    msg.append("5//");
    query2.exec(QString("select USER_NAME from USER"));
    queryw.exec(QString("select WIN FROM USER"));
    queryl.exec(QString("select LOSE from USER"));
    while(query2.next()){
        msg.append(query2.value(0).toString() + "   ");
        queryw.next();
        queryl.next();
        msg.append(QString::number(queryw.value(0).toInt()) + "|");
        msg.append(QString::number(queryl.value(0).toInt()) + "//");
    }
    return msg;
}

//查询某用户的精灵信息
QString SqliteDBAOperator::inquiry_client_pokemon(QString user_name){
    QSqlQuery query;
    query.exec(QString("select POKEMON_LIST from USER where USER_NAME = '%1'").arg(user_name));
    query.next();
    //qDebug(query.value(0).toString());
    QString msg = "6//";
    msg.append(query.value(0).toString());
    return msg;
}

//查询某精灵的信息
QString SqliteDBAOperator::inquiry_pokemon(int pokemon_id){
    QSqlQuery query;
    query.exec(QString("select * from POKEMON where id = '%1'").arg(pokemon_id));
    query.next();
    QString msg = "10//";
    msg.append(query.value(2).toString() + "//" + query.value(1).toString() + "//" + query.value(0).toString());
    return msg;
}

//加载某用户
QString SqliteDBAOperator::load_client(int user_id){
    QSqlQuery query;
    qDebug() << user_id;
    query.exec(QString("select POKEMON_LIST from USER where id = '%1'").arg(user_id));
    query.next();
    QString msg;
    msg = "";
    msg.append(query.value(0).toString().toUtf8().data());
    return msg;
}

//更改在线情况
void SqliteDBAOperator::change_online(QString user_name, int type){

    QSqlQuery query;
    query.exec(QString("select ID from USER where USER_NAME = '%1'").arg(user_name));
    query.next();
    int user_id = query.value(0).toInt();
    if(type == 0){
        QString temp = user_name + "---online";
        query.exec(QString("update USER set USER_NAME = '%1' where ID = '%2'").arg(temp).arg(user_id));
        //qDebug() << query.value(0).toByteArray() << "c";
    }
    else{
        QString temp = user_name.split("---online").at(0);
        qDebug() << temp << "out" << user_id;
        query.exec(QString("update USER set USER_NAME = '%1' where ID = '%2'").arg(temp).arg(user_id));
        qDebug()<< query.lastError();
    }
}
