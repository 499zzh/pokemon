#include "set.h"
#include "new_client.h"


new_client::new_client(QObject *parent){
    connect(this, &new_client::readyRead, this, &new_client::recieve_data);
    connect(this, &new_client::disconnected, this, &new_client::client_disconnect);
}

//接收信息
void new_client::recieve_data(){
    QByteArray array = readAll();
    QString msg = array;
    int Descriptor = this->socketDescriptor();
    emit send_msg_to_server(msg, Descriptor);
}

//断开连接
void new_client::client_disconnect(){
    emit tell_client_disconnect(this->socketDescriptor());
}
