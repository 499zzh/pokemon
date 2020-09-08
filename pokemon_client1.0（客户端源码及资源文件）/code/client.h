#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include "login.h"
#include "my_Label.h"
#include "bag.h"
#include "my_pokemon.h"
#include <QCloseEvent>
#include <QList>
#include "client_list.h"
#include "set.h"
#include "game.h"
QT_BEGIN_NAMESPACE
namespace Ui { class client; }
QT_END_NAMESPACE

class client : public QWidget
{
    Q_OBJECT

public:
    client(QWidget *parent = nullptr);
    ~client();
    login *my_login;
    //登录窗口
    bag *my_bag;
    //背包界面
    client_list *my_client_list;
    //用户列表界面
    game* my_game;
    //游戏界面
    int win = 0;
    //胜场
    int lose = 0;
    //负场
    int my_pokemon_number = 0;
    //我当前的精灵数
    int my_max_number = 0;
    //我满级的精灵数
    void my_socket();
    //socket连接
    void set_ui();
    //设置ui
    int get_id(){ return user_id;};
    //返回用户id
    void set_id(int id){ user_id = id;};
    //设置用户id
protected slots:
    //socket部分
    void recieve_data();
    //接收服务器端的信息
    void connect_server_success();
    //接收登录成功的信号
    void connect_success();
    //接收连接服务器成功的信号
    void client_disconnect();
    //接收断开连接的信号
    void send_msg(QString msg);
    //接收要发送信息的信号
    void set_username(QString msg);
    //接收username

    //ui部分
    void bag_on_clicked();
    //接收背包界面打开的信号
    void other_client_on_clicked();
    //接收查询用户的信号
    void game_on_clicked();
    //接收打开战斗画面的信号
    void dbg_update_ui(QString msg);
    //接收打开调试模式下信息输出的信号
    void show_bandge();
    //接收显示徽章的信号

    //服务器交互
    void inquiry_client_pokemon(QString user_name);   //查询精灵
    //接收想要查询的用户的精灵列表的信号
    void recover_pokemon(int type, int id, int level);
    //根据服务器信息加载精灵
    void get_a_pokemon(int type, int id, int level);
    //得到一个新精灵
    void update_win(int res);
    //更新胜场情况
    void get_pokemon_id(QString id);
    //获取精灵id
    void send_fight_result(int pokemon_id, int result, int fight_type, int get);
    //接收战斗端的信号，来向服务器发送结果
    void choose_a_lose();
    //接收战斗端的失败信号，调用选择精灵失去的信号
    void slot_lose_pokemon(QString);
    //接收失去某精灵的信号
protected:
     void closeEvent(QCloseEvent *event);
     //关闭=登出
private:
    Ui::client *ui;

    bool online = false;
    //判断是否在线
    int port;
    //端口号
    QHostAddress *serverIP;
    //ip
    QString username;
    //用户名
    QString password;
    //密码
    QTcpSocket *tcpsocket;
    //socket通信
    QList<pokemon*> pokemon_list;
    //精灵列表
    QStringList pokemon_Slist;
    //名称列表
    int user_id;
    //用户id
signals:
    void login_success();
    //信号用于判断登录情况
    void inquiry_client(QStringList all_client);
    //发出查询信号
    void inquiry_client_pokemon_result(QStringList all_pokemon);
    //查询精灵
    void load_my_bag(QStringList pokemon_List);
    //加载背包
    void load_my_bag_pokemon(pokemon* my_pokemon);
    //发送加载背包的信号
    void load_game_pokemon(QList<pokemon*>);
    //发送加载对战精灵的信号
    void my_pokemon_lose();
    //发送用户失去精灵的信号（用于发送给服务端）
    void signal_my_pokemon_lose(int, int, int);
    //发送用户失去精灵的信号（发送给选择失去精灵端）
private slots:
    void on_dbg_mode_clicked();
    //接收测试模式的按钮clicked信号
    void on_dbg_get_pokemon_clicked();
    //接收测试模式下得到一个精灵的信号
    void on_dbg_fight_clicked();
    //接收测试模式下，战斗的信号
    void on_dbg_exp_clicked();
    //接收测试模式下，增长经验值的信号
    void on_dbg_exit_clicked();
    //接收退出测试模式的信号
};
#endif // CLIENT_H
