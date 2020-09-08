#include "my_server.h"
#include "set.h"
#include <QTime>
#include <QCoreApplication>
//构造函数
my_server::my_server(QObject *parent, int port):QTcpServer(parent){

    listen(QHostAddress::Any, port);
    //监听
    my_database();
    //打开数据库
    QFile file("./data.txt");
    file.open(QIODevice::ReadWrite);
    pokemon_number = file.readAll().toInt();
    //读取当前精灵数量
}

//打开数据库
void my_server::my_database(){
    my_db = new SqliteDBAOperator();
    my_db->OpenDb();
    my_db->createTable();
}

//只要有新的连接就生成一个新的通信套接字
void my_server::incomingConnection(int socketDescriptor){
    new_client *tcpclientsocket = new new_client(this);
    //将新创建的通信套接字描述符指定为参数socketdescriptor
    tcpclientsocket->setSocketDescriptor(socketDescriptor);

    //将这个套接字加入客户端套接字列表中
    client_list.append(tcpclientsocket);

    connect(tcpclientsocket, &new_client::tell_client_disconnect, this, &my_server::client_disconnect);
    connect(tcpclientsocket, &new_client::send_msg_to_server, this, &my_server::recieve_data);
}

//接收数据并根据数据进行回复
void my_server::recieve_data(QString msg, int Descriptor){

    QStringList msg_list = msg.split("//");
    QString send;
    //更新服务器内的数据
    emit update_ui(msg + "re");
    int msg_type = msg_list.at(0).toInt();
    //qDebug() << msg.toUtf8().data();
    if(msg_type == LOGIN){
        QString user_name = msg_list.at(1);
        QString password = msg_list.at(2);
        if(my_db->check_password(user_name, password) > 0){
            int user_id = my_db->check_password(user_name, password);
            //qDebug() << "change";
            my_db->change_online(user_name, 0);
            send = "0//" + QString::number(user_id);
        }
        else if(my_db->check_password(user_name, password) == FAIL){
            send = "0//-1";
        }
        else{
            send = "0//-2";
        }
    }
    else if(msg_type == REGISTER){
        QString user_name = msg_list.at(1);
        QString password = msg_list.at(2);

        if(my_db->register_client(user_name, password) == 0){
            send = "1//" + QString::number(my_db->check_password(user_name, password));
        }
        else{
            send = "1//-1";
        }
        qDebug() << send;
    }
    else if(msg_type== LOGIN_OUT){
        if(msg_list.at(1) == "login_exit"){
            //登录窗口处退出什么都不发送
        }
        else{
            send = msg_list.at(1) + "exit";
            my_db->change_online(msg_list.at(1) + "---online", 1);
            emit update_ui(send);
        }
        return;
    }
    else if(msg_type == BAG){
        int user_id = msg_list.at(1).toInt();
        send = "3//" + my_db->load_client(user_id);
    }
    else if(msg_type == LOAD_BAG){
        int pokemon_id = msg_list.at(1).toInt();
        send = my_db->inquiry_pokemon(pokemon_id);
    }
    else if(msg_type == CLIENT_LIST){
        send = my_db->inquiry_client();
    }
    else if(msg_type == LOAD_CLIENT_LIST){
        QString user_name = msg_list.at(1);
         QStringList temp = user_name.split("   ");
         user_name = temp.at(0);
        qDebug() << user_name;
        send = my_db->inquiry_client_pokemon(user_name);
    }
    else if(msg_type == EXP_FIGHT){
        int user_id = msg_list.at(1).toInt();
        int result = msg_list.at(2).toInt();
        int pokemon_id = msg_list.at(3).toInt();
        int level = msg_list.at(4).toInt();
        qDebug() << level << "==" << pokemon_id;
        my_db->client_update(user_id, result);
        my_db->pokemon_update(pokemon_id, level);
    }
    else if(msg_type == POKEMON_FIGHT){
        int user_id = msg_list.at(1).toInt();
        int pokemon_id = msg_list.at(2).toInt();
        int result = msg_list.at(3).toInt();
        int get_type = msg_list.at(4).toInt();
        my_db->client_update(user_id, result);
    }
    else if(msg_type == LOAD_CLIENT){
        int user_id = msg_list.at(1).toInt();
        send = "9//" + my_db->load_client(user_id);
    }
    else if(msg_type == LOAD_POKEMON){
        QStringList my_split  = msg.split("fk");
        for(int i = 0; i < my_split.count() - 1; i++){
            QStringList new_msg = my_split.at(i).split("//");
            //qDebug() << new_msg << "new_msg";
            int pokemon_id = new_msg.at(1).toInt();
            send = my_db->inquiry_pokemon(pokemon_id);
            for(int i = 0; i < client_list.count(); i++){
                QTcpSocket* item= client_list.at(i);
                if(item->socketDescriptor() == Descriptor){
                    item->write(send.toUtf8().data());
                    break;
                }
            }
            QTime dieTime = QTime::currentTime().addMSecs(50);
            while( QTime::currentTime() < dieTime )
                QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
        emit update_ui(send);
        }
        return;
    }
    else if(msg_type == NEW_POKEMON){
        //qDebug() << "rec new";
        int user_id = msg_list.at(1).toInt();
        int pokemon_id = msg_list.at(2).toInt();
        int pokemon_type = msg_list.at(3).toInt();
        my_db->new_pokemon(user_id, pokemon_type, pokemon_number);
        qDebug() << pokemon_number;
        pokemon_number++;
        QFile file("./data.txt");
        file.open(QIODevice::ReadWrite);
        file.write(QByteArray::number(pokemon_number));
    }
    else if(msg_type == LOSE_POKEMON){
        int user_id = msg_list.at(1).toInt();
        int pokemon_id = msg_list.at(2).toInt();
        my_db->lose_pokemon(user_id, pokemon_id);
    }
    for(int i = 0; i < client_list.count(); i++){
        QTcpSocket* item= client_list.at(i);
        if(item->socketDescriptor() == Descriptor){
            item->write(send.toUtf8().data());
            break;
        }
    }
    emit update_ui(send);
}

//断开某用户的tcp连接
void my_server::client_disconnect(int descriptor){
    for(int i = 0; i < client_list.count(); i++){
        QTcpSocket *item = client_list.at(i);
        if(item->socketDescriptor() == descriptor){
            client_list.removeAt(i);//如果有客户端断开连接， 就将列表中的套接字删除
            return;
        }
    }
    return;
}
