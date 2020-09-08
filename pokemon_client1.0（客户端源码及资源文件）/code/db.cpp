#include "db.h"
#include <QDir>


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
        QString dbname = QDir::currentPath() +QString("/")+ QString("MACAddrs.db");
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
        qDebug() << "连接数据失败！";
        return false;
    }
    qDebug() << "连接数据库成功";
    return true;
}

//判断数据库中某个数据表是否存在
bool SqliteDBAOperator::IsTaBexists(QString& Tabname)
{
    QSqlDatabase db = QSqlDatabase::database();
    if(db.tables().contains(Tabname))
    {
        return true;
    }
    return false;
}


//创建数据表
void SqliteDBAOperator::createTable(void)
{
    //用于执行sql语句的对象
    QSqlQuery query;
    //构建创建数据库的sql语句字符串
    QString str = QString("CREATE TABLE MACAddrs (\
                          ID INT PRIMARY KEY NOT NULL,\
                          POKEMON_LIST TEXT NOT NULL)");
    //执行sql语句
    query.exec(str);
}


//查询和显示结果
void SqliteDBAOperator::queryTable(QString& str)
{
    QSqlQuery query;
    //构建创建数据库的sql语句字符串
    str = QString("SELECT ID,MACADDR FROM MACAddrs");
    //执行sql语句,并将结果集保存到model
    query.exec(str);
}


//单条插入
void SqliteDBAOperator::singleinsertdata(client &singledb)
{
    QSqlQuery query;
    query.prepare("INSERT INTO MACAddrs VALUES (:ID,:Type,:ProduceTime)");
    query.bindValue(":ID", singledb.get_id());
    query.bindValue(":Pokemon_count", singledb.get_pokemon_list().count());
    query.exec();
}


//删除一条数据
void SqliteDBAOperator::deletedata()
{
    //比较简单，自行补充
}
//修改
void SqliteDBAOperator::updatedata()
{
    //比较简单，自行补充
}


void SqliteDBAOperator::closeDb(void)
{
    db.close();
}
