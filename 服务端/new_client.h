#ifndef NEW_CLIENT_H
#define NEW_CLIENT_H

#include <QTcpSocket>
class new_client:public QTcpSocket
{
    Q_OBJECT
public:
    new_client(QObject *parent = 0);
protected slots:
    void recieve_data();
    //接受数据
    void client_disconnect();
    //接收断开连接请求

signals:
    void send_msg_to_server(QString msg, int Descriptor);
    //向服务器发送信息
    void tell_client_disconnect(int Descriptor);
    //告知服务器某用户断开连接
};


#endif // NEW_CLIENT_H
