#include "client.h"
#include "ui_client.h"
#include "fight_game.h"
#include <QHostAddress>
#include <QMessageBox>
#include <QTime>
#include "lose_pokemon.h"


client::client(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::client)
{
    ui->setupUi(this);
    set_ui();
    //设置ui
    my_socket();
    //网络连接的设定
}

client::~client()
{
    delete ui;
}

//实现socket的连接
void client::my_socket(){

    my_login = new login;
    port = 8888;
    serverIP = new QHostAddress();
    serverIP->setAddress("127.0.0.1");

    tcpsocket = new QTcpSocket(this);
    //创建一个通信套接字，用来和服务器进行通信
    tcpsocket->connectToHost(*serverIP, port);
    //和服务器进行连接

    connect(tcpsocket, &QTcpSocket::connected, this, &client::connect_server_success);
    //连接成功
    connect(tcpsocket, &QTcpSocket::readyRead, this, &client::recieve_data);
    //readyread信号就接收数据

    connect(this, &client::login_success, this, &client::connect_success);
    //登录成功
    connect(my_login, &login::try_login, this, &client::send_msg);
    //登录发送
    connect(my_login, &login::try_login, this, &client::set_username);
    //录入用户名
    connect(my_login, &login::try_register, this, &client::send_msg);
    //注册发送
    connect(my_login, &login::login_disconnect, this, &client::client_disconnect);
    //登录的断开也会导致连接断开

}

//设置ui
void client::set_ui(){

    this->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/Material/client_background.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap.scaled(1024,768)));
    this->setPalette(palette);
    this->setWindowTitle("Pokemon");

    ui->bag_label->setPixmap(QPixmap(":/Material/bag.png").scaled(ui->bag_label->rect().size()));
    ui->set_label->setPixmap(QPixmap(":/Material/set.png").scaled(ui->set_label->rect().size()));
    ui->other_client_label->setPixmap(QPixmap(":/Material/other_client.png").scaled(ui->set_label->rect().size()));
    ui->game_label->setPixmap(QPixmap(":/Material/game.png").scaled(ui->set_label->rect().size()));
    ui->dbg_mode->setIcon(QPixmap(":/Material/dbg_mode.png").scaled(ui->set_label->rect().size()));
    ui->dbg_exp->setIcon(QPixmap(":/Material/exp.png").scaled(ui->set_label->rect().size()));
    ui->dbg_get_pokemon->setIcon(QPixmap(":/Material/pokemon_ball.png").scaled(ui->set_label->rect().size()));
    ui->dbg_fight->setIcon(QPixmap(":/Material/dbg_fight.png").scaled(ui->set_label->rect().size()));
    //设置图片
    ui->bd1->hide();
    ui->bd2->hide();

    ui->dbg_get_pokemon->hide();
    ui->dbg_fight->hide();
    ui->dbg_exp->hide();
    ui->get_pokemon_label->hide();
    ui->exp_label->hide();
    ui->fight_label->hide();
    ui->dbg_log->hide();
    ui->dbg_exit->hide();
    //测试类

    connect(this, &client::my_pokemon_lose, this, &client::choose_a_lose);

    connect(ui->bag_label, &my_Label::clicked, this, &client::bag_on_clicked);
    connect(ui->other_client_label, &my_Label::clicked, this, &client::other_client_on_clicked);
    connect(ui->game_label, &my_Label::clicked, this, &client::game_on_clicked);
    connect(ui->set_label, &my_Label::clicked, this, &client::show_bandge);
    //连接信号槽

}

//点击背包后会召唤出bag-ui
void client::bag_on_clicked(){
    my_bag = new bag;
    //QMessageBox::warning(this, "1", "bag");
    connect(this, &client::load_my_bag, my_bag, &bag::load_bag);
    connect(this, &client::load_my_bag_pokemon, my_bag, &bag::show_pokemon);
    connect(my_bag, &bag::send_pokemon_id, this, &client::get_pokemon_id);
    send_msg(QString::number(BAG) + "//" + QString::number(user_id));
    my_bag->show();
}

//点击用户列表后会召唤出用户列表ui
void client::other_client_on_clicked(){
    my_client_list = new client_list;
    my_client_list->show();
    connect(this, &client::inquiry_client, my_client_list, &client_list::show_client);
    //显示所有用户
    connect(my_client_list, &client_list::send_user_id, this, &client::inquiry_client_pokemon);
    //查询
    connect(this, &client::inquiry_client_pokemon_result, my_client_list, &client_list::show_pokemon);
    //结果传递
    QString msg = "5";
    send_msg(msg);
}

//点击后会召唤出游戏界面
void client::game_on_clicked(){
    my_game =new game;
    connect(this, &client::load_game_pokemon, my_game, &game::get_my_pokemon);
    connect(my_game, &game::game_send_fight_result, this, &client::send_fight_result);
    emit load_game_pokemon(pokemon_list);
    my_game->show();
}

//点击后会召唤出徽章
void client::show_bandge(){
    int max = 0;
    for(int i =0 ; i < pokemon_list.count(); i++){
        if(pokemon_list.at(i)->get_level() == 15)
            max++;
        if(i < 5)
            ui->bd1->setPixmap(QPixmap(":/Material/bd1.png").scaled(ui->bd1->rect().size()));
        else if(i < 10)
            ui->bd1->setPixmap(QPixmap(":/Material/bd2.png").scaled(ui->bd1->rect().size()));
        else
            ui->bd1->setPixmap(QPixmap(":/Material/bd3.png").scaled(ui->bd1->rect().size()));
    }
    if(max == 0)
        ui->bd2->setPixmap(QPixmap(":/Material/bd1.png").scaled(ui->bd1->rect().size()));
    else if(max == 1)
        ui->bd2->setPixmap(QPixmap(":/Material/bd2.png").scaled(ui->bd1->rect().size()));
    else
        ui->bd2->setPixmap(QPixmap(":/Material/bd3.png").scaled(ui->bd1->rect().size()));
    ui->bd1->show();
    ui->bd2->show();
}

//接收数据，并根据报文类型执行下一步的操作
void client::recieve_data(){
    QByteArray array = tcpsocket->readAll();
    QString msg = array;
    QStringList msg_list = msg.split("//");
    int msg_type = msg_list.at(0).toInt();
    //拆解整体的报文，之后根据不同的情况进行不同的处理
    if(msg_type == LOGIN){
        if(msg_list.at(1).toInt() > 0){
            //登录成功
            user_id = msg_list.at(1).toInt();
            //获取用户id
            emit login_success();

        }
        else if(msg_list.at(1) == "-1"){
            //登录失败
            QMessageBox::warning(this, "warning", "username or password error");
        }
        else{
            QMessageBox::warning(this, "warning", "user not exist");
        }
    }
    else if(msg_type == REGISTER){
        if(msg_list.at(1).toInt() > 0){
            //注册成功
            QMessageBox::warning(this, "welcome", "register success");
            user_id = msg_list.at(1).toInt();
            srand(time(NULL));
            int random = rand()%31 + 1;
            get_a_pokemon(random, 1, 1);
            random = rand()%31 + 1;
            QTime dieTime = QTime::currentTime().addMSecs(50);
            while( QTime::currentTime() < dieTime )
                QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
            get_a_pokemon(random, 2, 1);
            dieTime = QTime::currentTime().addMSecs(50);
            while( QTime::currentTime() < dieTime )
                QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
            random = rand()%31 + 1;
            get_a_pokemon(random, 3, 1);
            //分配三个精灵
        }
        else if(msg_list.at(1) == "-1"){
            //注册失败
            QMessageBox::warning(this, "warning", "register fail");
        }
    }
    else if(msg_type == BAG){
        msg_list.removeAt(0);
        my_pokemon_number = msg_list.count();

        emit load_my_bag(msg_list);
    }
    else if(msg_type == CLIENT_LIST){
        msg_list.removeAt(0);
        emit inquiry_client(msg_list);
    }
    else if(msg_type == LOAD_CLIENT_LIST){
        emit inquiry_client_pokemon_result(msg_list);
    }
    else if(msg_type == EXP_FIGHT){

    }
    else if(msg_type == POKEMON_FIGHT){

    }
    else if(msg_type == LOAD_CLIENT){
        msg_list.removeAt(0);
        for(int i = 0; i < msg_list.count() - 1; i++){
                pokemon_Slist.append(msg_list.at(i));
                QString msg;
                msg = QString::number(LOAD_POKEMON) + "//" + pokemon_Slist.at(i) + "//-1" + "fk";
                send_msg(msg);
        }
    }
    else if(msg_type == LOAD_POKEMON){
        int level = msg_list.at(1).toInt();
        int type = msg_list.at(2).toInt();
        int id = msg_list.at(3).toInt();
        //qDebug() << msg;
        this->recover_pokemon(type, id, level);
        //qDebug() << "load error";
    }
}

//更新胜场情况
void client::update_win(int res){
    if(res == 0) win++;
    else lose++;
}

//连接成功就跳出登录窗口
void client::connect_server_success(){
    my_login->show();
}

//登录成功后会提示
void client::connect_success(){

    QMessageBox::warning(this, "welcome", "欢迎");
    online = true;
    //登录成功
    my_login->close();
    //关闭登录界面
    this->show();
    //显示客户端
    ui->dbg_mode->hide();
    //隐藏测试按钮
    send_msg(QString::number(LOAD_CLIENT) + "//" + QString::number(user_id));
    //发出加载请求

    //也许还需要加载数据
}

//根据服务器内的信息加载精灵
void client::recover_pokemon(int type, int id, int level){
        switch (type) {
        case 1:{
            pokemon_list.append((new strong_fire_pokemon(id))->recover(level));
            break;
        }
        case 2:
            pokemon_list.append((new shield_fire_pokemon(id))->recover(level));
            break;
        case 3:
            pokemon_list.append((new tank_fire_pokemon(id))->recover(level));
            break;
        case 4:
            pokemon_list.append((new swift_fire_pokemon(id))->recover(level));
            break;
        case 5:
            pokemon_list.append((new strong_water_pokemon(id))->recover(level));
            break;
        case 6:
            pokemon_list.append((new shield_water_pokemon(id))->recover(level));
            break;
        case 7:
            pokemon_list.append((new tank_water_pokemon(id))->recover(level));
            break;
        case 8:
            pokemon_list.append((new swift_water_pokemon(id))->recover(level));
            break;
        case 9:
            pokemon_list.append((new strong_plant_pokemon(id))->recover(level));
            break;
        case 10:
            pokemon_list.append((new shield_plant_pokemon(id))->recover(level));
            break;
        case 11:
            pokemon_list.append((new tank_plant_pokemon(id))->recover(level));
            break;
        case 12:
            pokemon_list.append((new swift_plant_pokemon(id))->recover(level));
            break;
        case 13:
            pokemon_list.append((new strong_dark_pokemon(id))->recover(level));
            break;
        case 14:
            pokemon_list.append((new tank_dark_pokemon(id))->recover(level));
            break;
        case 15:
            pokemon_list.append((new swift_dark_pokemon(id))->recover(level));
            break;
        case 16:
            pokemon_list.append((new strong_bright_pokemon(id))->recover(level));
            break;
        case 17:
            pokemon_list.append((new swift_bright_pokemon(id))->recover(level));
            break;
        case 18:
            pokemon_list.append((new strong_wind_pokemon(id))->recover(level));
            break;
        case 19:
            pokemon_list.append((new shield_wind_pokemon(id))->recover(level));
            break;
        case 20:
            pokemon_list.append((new tank_wind_pokemon(id))->recover(level));
            break;
        case 21:
            pokemon_list.append((new swift_wind_pokemon(id))->recover(level));
            break;
        case 22:
            pokemon_list.append((new strong_earth_pokemon(id))->recover(level));
            break;
        case 23:
            pokemon_list.append((new shield_earth_pokemon(id))->recover(level));
            break;
        case 24:
            pokemon_list.append((new tank_earth_pokemon(id))->recover(level));
            break;
        case 25:
            pokemon_list.append((new swift_earth_pokemon(id))->recover(level));
            break;
        case 26:
            pokemon_list.append((new strong_machinery_pokemon(id))->recover(level));
            break;
        case 27:
            pokemon_list.append((new shield_machinery_pokemon(id))->recover(level));
            break;
        case 28:
            pokemon_list.append((new tank_machinery_pokemon(id))->recover(level));
            break;
        case 29:
            pokemon_list.append((new strong_thunder_pokemon(id))->recover(level));
            break;
        case 39:
            pokemon_list.append((new tank_thunder_pokemon(id))->recover(level));
            break;
        case 31:
            pokemon_list.append((new swift_thunder_pokemon(id))->recover(level));
            break;
        }
}

//发送查询精灵的报文
void client::inquiry_client_pokemon(QString user_name){
    QString msg = "6//" + user_name;
    send_msg(msg);
}

//发送获取精灵的报文，并在本地精灵列表中增加精灵
void client::get_a_pokemon(int type, int id, int level){
    switch (type) {
    case 1:{
        pokemon_list.append((new strong_fire_pokemon(id))->recover(level));
        break;
    }
    case 2:
        pokemon_list.append((new shield_fire_pokemon(id))->recover(level));
        break;
    case 3:
        pokemon_list.append((new tank_fire_pokemon(id))->recover(level));
        break;
    case 4:
        pokemon_list.append((new swift_fire_pokemon(id))->recover(level));
        break;
    case 5:
        pokemon_list.append((new strong_water_pokemon(id))->recover(level));
        break;
    case 6:
        pokemon_list.append((new shield_water_pokemon(id))->recover(level));
        break;
    case 7:
        pokemon_list.append((new tank_water_pokemon(id))->recover(level));
        break;
    case 8:
        pokemon_list.append((new swift_water_pokemon(id))->recover(level));
        break;
    case 9:
        pokemon_list.append((new strong_plant_pokemon(id))->recover(level));
        break;
    case 10:
        pokemon_list.append((new shield_plant_pokemon(id))->recover(level));
        break;
    case 11:
        pokemon_list.append((new tank_plant_pokemon(id))->recover(level));
        break;
    case 12:
        pokemon_list.append((new swift_plant_pokemon(id))->recover(level));
        break;
    case 13:
        pokemon_list.append((new strong_dark_pokemon(id))->recover(level));
        break;
    case 14:
        pokemon_list.append((new tank_dark_pokemon(id))->recover(level));
        break;
    case 15:
        pokemon_list.append((new swift_dark_pokemon(id))->recover(level));
        break;
    case 16:
        pokemon_list.append((new strong_bright_pokemon(id))->recover(level));
        break;
    case 17:
        pokemon_list.append((new swift_bright_pokemon(id))->recover(level));
        break;
    case 18:
        pokemon_list.append((new strong_wind_pokemon(id))->recover(level));
        break;
    case 19:
        pokemon_list.append((new shield_wind_pokemon(id))->recover(level));
        break;
    case 20:
        pokemon_list.append((new tank_wind_pokemon(id))->recover(level));
        break;
    case 21:
        pokemon_list.append((new swift_wind_pokemon(id))->recover(level));
        break;
    case 22:
        pokemon_list.append((new strong_earth_pokemon(id))->recover(level));
        break;
    case 23:
        pokemon_list.append((new shield_earth_pokemon(id))->recover(level));
        break;
    case 24:
        pokemon_list.append((new tank_earth_pokemon(id))->recover(level));
        break;
    case 25:
        pokemon_list.append((new swift_earth_pokemon(id))->recover(level));
        break;
    case 26:
        pokemon_list.append((new strong_machinery_pokemon(id))->recover(level));
        break;
    case 27:
        pokemon_list.append((new shield_machinery_pokemon(id))->recover(level));
        break;
    case 28:
        pokemon_list.append((new tank_machinery_pokemon(id))->recover(level));
        break;
    case 29:
        pokemon_list.append((new strong_thunder_pokemon(id))->recover(level));
        break;
    case 39:
        pokemon_list.append((new tank_thunder_pokemon(id))->recover(level));
        break;
    case 31:
        pokemon_list.append((new swift_thunder_pokemon(id))->recover(level));
        break;
    }

    connect(pokemon_list.at(pokemon_list.count() - 1), &pokemon::finish_fight, this, &client::update_win);
    send_msg("11//" + QString::number(user_id) + "//" + QString::number(id) +
             "//" + QString::number(type) + "//");
    QTime dieTime = QTime::currentTime().addMSecs(200);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    send_msg(QString::number(LOAD_CLIENT) + "//" + QString::number(user_id));
    //发出加载请求
}

//接收登录断开
void client::client_disconnect(){

    if(online == false){
        tcpsocket->write((QString::number(2) + "//" + "login_exit").toUtf8().data());
        //离开类型的消息
        tcpsocket->disconnectFromHost();
    }

}

//接收关闭断开 = 登出功能
void client::closeEvent(QCloseEvent *event){

    if(online){
        tcpsocket->write((QString::number(2) + "//" + username).toUtf8().data());
        //离开类型的消息
        tcpsocket->disconnectFromHost();
        online = false;
    }
}

//设置用户名
void client::set_username(QString msg){
    QStringList msg_list = msg.split("//");
    username = msg_list.at(1);
}

//发送消息通信
void client::send_msg(QString msg){

    tcpsocket->write(msg.toUtf8().data());
}

//获取精灵id
void client::get_pokemon_id(QString id){
    //qDebug() << id;
    //qDebug() << pokemon_list.count();
    for(int i = 0; i < pokemon_list.count(); i++){

        if(pokemon_Slist.at(i) == id){
            emit load_my_bag_pokemon(pokemon_list.at(i));
            break;
        }

    }
}

//发送战斗结果
void client::send_fight_result(int pokemon_id, int result, int fight_type, int get){
    QString msg;

    if(fight_type == 0){
        msg.append(QString::number(EXP_FIGHT)  + "//" + QString::number(user_id) + "//"
                   + QString::number(result) + "//" + QString::number(pokemon_id) + "//" + QString::number(get));
    }
    else{
        if(result == 0){

            get_a_pokemon(get, 0, 1);
        }
        else{
            emit my_pokemon_lose();
        }
        msg.append(QString::number(POKEMON_FIGHT) + "//" + QString::number(user_id) + "//"
                   + QString::number(result) + "//" + QString::number(pokemon_id) + "//"
                   + QString::number(get));
    }
    send_msg(msg);
}

//随机三个精灵选择失去一个精灵
void client::choose_a_lose(){
    srand(time(0));
    int max = pokemon_list.count();
    int lose[3] = {-1, -1, -1};
    if(max == 1){
        lose[0] = 0;
        lose[1] = 0;
        lose[2] = 0;
    }
    else if(max == 2){
        lose[0] = 0;
        lose[1] = 1;
        lose[0] = 0;
    }
    else if(max == 3){
        lose[0] = 0;
        lose[1] = 1;
        lose[2] = 2;
    }
    else{
        int random = rand()%max + 1;
        lose[0] = random;
        random = rand()%max + 1;
        lose[1] = random;
        while(lose[1] == lose[2]){
            lose[1] = rand()%max + 1;
        }
        lose[2] = rand()%max + 1;
        while(lose[2] == lose[1] || lose[2] == lose[0]){
            lose[2] = rand()%max + 1;
        }
    }
    qDebug() << "randok";
    lose_pokemon* my_lose = new lose_pokemon;
    connect(this, &client::signal_my_pokemon_lose, my_lose, &lose_pokemon::recieve);
    emit signal_my_pokemon_lose(lose[0], lose[1], lose[2]);
    connect(my_lose, &lose_pokemon::choose_lose, this, &client::slot_lose_pokemon);
    my_lose->show();
}

//接收失去精灵的信号，并真正失去精灵，如果精灵数量为0则再发一个
void client::slot_lose_pokemon(QString id){
    int pokemon = pokemon_list.at(id.toInt() - 1)->get_id();
    pokemon_list.removeAt(id.toInt() - 1);
    QString msg;
    msg.append(QString::number(LOSE_POKEMON) + "//" + QString::number(user_id) + "//" + QString::number(pokemon));
    qDebug() <<msg;
    send_msg(msg);
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 50);
    if(pokemon_list.count() == 0)
           get_a_pokemon(rand()%3 + 1,0,1);
}

//打开测试模式
void client::on_dbg_mode_clicked(){
    //测试模式
    ui->bag_label->hide();
    ui->set_label->hide();
    ui->other_client_label->hide();
    ui->game_label->hide();
    //隐藏这些按钮
    ui->dbg_get_pokemon->show();
    ui->dbg_fight->show();
    ui->dbg_exp->show();
    ui->get_pokemon_label->show();
    ui->exp_label->show();
    ui->fight_label->show();
    ui->dbg_log->show();
    ui->dbg_exit->show();
}

//测试获取精灵
void client::on_dbg_get_pokemon_clicked()
{
    int random = rand() % 3 + 1 ;
    if(random == 1){
        strong_fire_pokemon* dbg_pokemon = new strong_fire_pokemon(0);
        connect(dbg_pokemon, &pokemon::update, this, &client::dbg_update_ui);
        if(!pokemon_list.count())
            pokemon_list.append(dbg_pokemon);
        else{
            pokemon_list.replace(0, dbg_pokemon);
        }
    }
    else if(random == 2){
        strong_water_pokemon* dbg_pokemon = new strong_water_pokemon(0);
        connect(dbg_pokemon, &pokemon::update, this, &client::dbg_update_ui);
        if(!pokemon_list.count())
            pokemon_list.append(dbg_pokemon);
        else{
            pokemon_list.replace(0, dbg_pokemon);
        }
    }
    else{
        shield_plant_pokemon* dbg_pokemon = new shield_plant_pokemon(0);
        connect(dbg_pokemon, &pokemon::update, this, &client::dbg_update_ui);
        if(!pokemon_list.count())
            pokemon_list.append(dbg_pokemon);
        else{
            pokemon_list.replace(0, dbg_pokemon);
        }
    }
    dbg_update_ui(QString::fromLocal8Bit("你获得了 ") + QString::fromLocal8Bit(this->pokemon_list.at(0)->get_name()));
}

//测试战斗
void client::on_dbg_fight_clicked()
{
    if(this->pokemon_list.count() == 1){
        shield_water_pokemon* dbg_keda = new shield_water_pokemon(-1);
        dbg_keda->exp_level(200);
        connect(dbg_keda, &pokemon::update, this, &client::dbg_update_ui);
        this->pokemon_list.at(0)->fight(dbg_keda);
    }
    else if(this->pokemon_list.count() == 0){
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("请先获取测试精灵"));
    }
}

//测试分配经验值
void client::on_dbg_exp_clicked()
{
    pokemon_list.at(0)->exp_level(200);
}

//测试界面信息输出
void client::dbg_update_ui(QString msg){
    ui->dbg_log->append(msg);
}

//退出测试模式
void client::on_dbg_exit_clicked()
{
    ui->dbg_get_pokemon->hide();
    ui->dbg_fight->hide();
    ui->dbg_exp->hide();
    ui->get_pokemon_label->hide();
    ui->exp_label->hide();
    ui->fight_label->hide();
    ui->dbg_log->hide();
    ui->dbg_exit->hide();
    //隐藏dbg选项
    ui->bag_label->show();
    ui->set_label->show();
    ui->other_client_label->show();
    ui->game_label->show();
}
