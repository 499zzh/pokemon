#ifndef CLIENT_H
#define CLIENT_H

#include<QList>

class client{
    client();
    ~client();
public:
    int get_id(){ return user_id;};
    QString get_USER_NAME(){ return USER_NAME;};
    //获取用户名
    QString get_PASSWORD(){ return PASSWORD;};
    //获取密码
    QString get_pokemon_id() {
        QString msg;
        for(int i = 0; i < Pokemon_id.count(); i++){
            msg.append(Pokemon_id.at(i));
        }
        return msg;
    }
    //获取所有的精灵的id
private:
    int user_id;
    //用户id
    QString Pokemon_id;
    //所拥有的精灵id
    QString USER_NAME;
    //用户名
    QString PASSWORD;
    //密码
};

#endif // CLIENT_H
