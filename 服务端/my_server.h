#ifndef MY_SERVER_H
#define MY_SERVER_H

#include <QTcpServer>
#include <QObject>
#include <QList>
#include "new_client.h"
#include "db.h"
#include "msg.h"

class my_server:public QTcpServer{
    Q_OBJECT
public:
    my_server(QObject *parent = 0, int port = 0);
    void my_database();

protected:
    void incomingConnection(int socketDescriptor);
    //只要出现一个新的连接，就会自动调用这个函数
protected slots:
    void recieve_data(QString msg, int Descriptor);
    //接收信息
    void client_disconnect(int);
    //接收客户端断开连接的信号
signals:
    void update_ui(QString msg);
    //更新日志区输出
private:
    SqliteDBAOperator* my_db;
    //指向数据库的指针
    QList<new_client*> client_list;
    //用户列表
    int pokemon_number;
    //服务器内精灵总数
};


#endif // MY_SERVER_H
