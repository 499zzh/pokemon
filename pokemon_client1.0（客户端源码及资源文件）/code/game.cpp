#include "game.h"
#include "ui_game.h"
#include "qdebug.h"
#include "QTime"
#include "my_Label.h"

game::game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    set_ui();
    fight_type = 0;
}

game::~game()
{
    delete ui;
}

//设置ui
void game::set_ui(){
    this->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/Material/game_backgrount.jfif");
    palette.setBrush(QPalette::Window, QBrush(pixmap.scaled(1024,768)));
    this->setPalette(palette);
    this->setWindowTitle("game");
    //qDebug() << "set_success";
    this->random_pokemon();
    ui->fight->setPixmap(QPixmap(":/Material/fight.jfif").scaled(ui->fight->rect().size()));
    //生成本次的随机列表
    connect(ui->fight, &my_Label::clicked, this, &game::fight);

}

//根据选择的情况进行战斗
void game::fight(){
    int result =  my_pokemon.at(ui->my_pokemon->currentRow())->fight(temp.at(ui->opponent_pokemon->currentRow()));
    qDebug() << result;
    if(fight_type == 0){//升级赛
        emit game_send_fight_result(my_pokemon.at(ui->my_pokemon->currentRow())->get_id(), result, fight_type, my_pokemon.at(ui->my_pokemon->currentRow())->get_level());
        //qDebug() << my_pokemon.at(ui->my_pokemon->currentRow())->get_level();
    }
    else{
        emit  game_send_fight_result(my_pokemon.at(ui->my_pokemon->currentRow())->get_id(), result, fight_type, temp.at(ui->opponent_pokemon->currentRow())->get_type_id());
    }

    qDebug() << "msgok";
}

//调整战斗类型参数
void game::on_exp_fight_clicked()
{
    fight_type = 0;
}
//同上
void game::on_pokemon_fight_clicked()
{
    fight_type = 1;
}

//随机生成系统精灵列表
void game::random_pokemon(){

    for(int i = 0; i < 10 ;i++){

        QTime time= QTime::currentTime();
        qsrand(time.msec()+time.second()*1000);
        int type = qrand()%31 + 1;
        int id = -1;
        int level = qrand()%15 + 1;
        if(i < 3)
            level = qrand()%3 + 1;
        //qDebug() << type << id << level;
        switch (type) {
        case 1:{
            temp.append((new strong_fire_pokemon(id))->recover(level));
            break;
        }
        case 2:
            temp.append((new shield_fire_pokemon(id))->recover(level));
            break;
        case 3:
            temp.append((new tank_fire_pokemon(id))->recover(level));
            break;
        case 4:
            temp.append((new swift_fire_pokemon(id))->recover(level));
            break;
        case 5:
            temp.append((new strong_water_pokemon(id))->recover(level));
            break;
        case 6:
            temp.append((new shield_water_pokemon(id))->recover(level));
            break;
        case 7:
            temp.append((new tank_water_pokemon(id))->recover(level));
            break;
        case 8:
            temp.append((new swift_water_pokemon(id))->recover(level));
            break;
        case 9:
            temp.append((new strong_plant_pokemon(id))->recover(level));
            break;
        case 10:
            temp.append((new shield_plant_pokemon(id))->recover(level));
            break;
        case 11:
            temp.append((new tank_plant_pokemon(id))->recover(level));
            break;
        case 12:
            temp.append((new swift_plant_pokemon(id))->recover(level));
            break;
        case 13:
            temp.append((new strong_dark_pokemon(id))->recover(level));
            break;
        case 14:
            temp.append((new tank_dark_pokemon(id))->recover(level));
            break;
        case 15:
            temp.append((new swift_dark_pokemon(id))->recover(level));
            break;
        case 16:
            temp.append((new strong_bright_pokemon(id))->recover(level));
            break;
        case 17:
            temp.append((new swift_bright_pokemon(id))->recover(level));
            break;
        case 18:
            temp.append((new strong_wind_pokemon(id))->recover(level));
            break;
        case 19:
            temp.append((new shield_wind_pokemon(id))->recover(level));
            break;
        case 20:
            temp.append((new tank_wind_pokemon(id))->recover(level));
            break;
        case 21:
            temp.append((new swift_wind_pokemon(id))->recover(level));
            break;
        case 22:
            temp.append((new strong_earth_pokemon(id))->recover(level));
            break;
        case 23:
            temp.append((new shield_earth_pokemon(id))->recover(level));
            break;
        case 24:
            temp.append((new tank_earth_pokemon(id))->recover(level));
            break;
        case 25:
            temp.append((new swift_earth_pokemon(id))->recover(level));
            break;
        case 26:
            temp.append((new strong_machinery_pokemon(id))->recover(level));
            break;
        case 27:
            temp.append((new shield_machinery_pokemon(id))->recover(level));
            break;
        case 28:
            temp.append((new tank_machinery_pokemon(id))->recover(level));
            break;
        case 29:
            temp.append((new strong_thunder_pokemon(id))->recover(level));
            break;
        case 30:
            temp.append((new tank_thunder_pokemon(id))->recover(level));
            break;
        case 31:
            temp.append((new swift_thunder_pokemon(id))->recover(level));
            break;
        }

        QListWidgetItem* item = new QListWidgetItem();
        if(level < 3)
            item->setText(QString::fromLocal8Bit("新手级") + QString::fromLocal8Bit(temp.at(i)->get_name()));
        else if(level > 12)
            item->setText(QString::fromLocal8Bit("精英级") + QString::fromLocal8Bit(temp.at(i)->get_name()));
        else
            item->setText(QString::fromLocal8Bit(temp.at(i)->get_name()));
        //qDebug() << QString::fromLocal8Bit(temp.at(i)->get_name());
        ui->opponent_pokemon->addItem(item);
        //qDebug() << "load opp success";
    }
    show_opp_pokemon(temp.at(0));
}

//展示我的精灵
void game::show_my_pokemon(pokemon* pl){
    //
    ui->my_hp->setNum(pl->get_HP());
    ui->my_pro->setText(QString::fromLocal8Bit(pl->format_output(pl->get_property(), -1)));
    ui->my_type->setText(QString::fromLocal8Bit(pl->format_output(-1, pl->get_type())));
    ui->my_att->setNum(pl->get_att());
    ui->my_def->setNum(pl->get_defense());
    ui->my_level->setNum(pl->get_level());
    ui->my_icon->setPixmap(pl->get_QPixmap().scaled(100,100));
    ui->my_spe->setNum(pl->get_speed());
    ui->my_name->setText(QString::fromLocal8Bit(pl->get_name()));
}

//展示对手的精灵
void game::show_opp_pokemon(pokemon *pl){
    ui->opp_hp->setNum(pl->get_HP());
    ui->opp_pro->setText(QString::fromLocal8Bit(pl->format_output(pl->get_property(), -1)));
    ui->opp_type->setText(QString::fromLocal8Bit(pl->format_output(-1, pl->get_type())));
    ui->opp_att->setNum(pl->get_att());
    ui->opp_def->setNum(pl->get_defense());
    ui->opp_level->setNum(pl->get_level());
    ui->opp_icon->setPixmap(pl->get_QPixmap().scaled(100,100));
    ui->opp_spe->setNum(pl->get_speed());
    ui->opp_name->setText(QString::fromLocal8Bit(pl->get_name()));
}

//传递选择精灵的序号
void game::on_opponent_pokemon_itemDoubleClicked(QListWidgetItem *item)
{
    int num = ui->opponent_pokemon->currentRow();
    show_opp_pokemon(temp.at(num));
}
//同上
void game::on_my_pokemon_itemDoubleClicked(QListWidgetItem *item)
{
    int num = ui->my_pokemon->currentRow();
    show_my_pokemon(my_pokemon.at(num));
}

//展示我的精灵列表
void game::get_my_pokemon(QList<pokemon*> my_pokemon_list){
    my_pokemon = my_pokemon_list;
    for(int i = 0; i < my_pokemon.count(); i++){
        QListWidgetItem* item = new QListWidgetItem();
        item->setText(QString::fromLocal8Bit(my_pokemon.at(i)->get_name()));
        ui->my_pokemon->addItem(item);
    }
    show_my_pokemon(my_pokemon.at(0));
}
