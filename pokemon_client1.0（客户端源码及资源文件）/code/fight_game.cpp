#include "fight_game.h"
#include "ui_fight_game.h"
#include <QPixmap>

fight_game::fight_game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fight_game)
{
    ui->setupUi(this);
    set_ui();
}

fight_game::~fight_game()
{
    delete ui;
}
//设置ui
void fight_game::set_ui(){
    this->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/Material/fight_background.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap.scaled(400,300)));
    this->setPalette(palette);
    this->setWindowTitle("fight");
    ui->red_label->setPixmap(QPixmap(":/Material/blue.png").scaled(ui->red_label->rect().size()));
    ui->blue_label->setPixmap(QPixmap(":/Material/red.png").scaled(ui->red_label->rect().size()));
    ui->battle_label->setPixmap(QPixmap(":/Material/battle.png").scaled(ui->red_label->rect().size()));
    ui->vs->setPixmap(QPixmap(":/Material/VS.png").scaled(100,100));
    this->show();
}

//测试用途的传递信息，如果不进入测试模式则需要注释掉
void fight_game::show_msg(QString msg){
    /*mytext = new QLabel(this);
    textPropertyAnimation = new QPropertyAnimation(this);
    textPropertyAnimation->setTargetObject(mytext);
    textPropertyAnimation->setPropertyName("geometry");
    textPropertyAnimation->setDuration(700);
    mytext->setText(msg);*/
    //ui->log->setText(msg);
}

//接收对战精灵的信息，并进一步设置ui
void fight_game::recieve_pokemon(pokemon* red, pokemon* blue){
    ui->red_pokemon_label->setPixmap(QPixmap(red->get_QPixmap()).scaled(200,200));
    ui->blue_pokemon_label->setPixmap(QPixmap(blue->get_QPixmap()).scaled(200,200));
    QFont font;
    font.setBold(true);
    font.setPointSize(10);
    font.setFamily("幼圆");
    font.setPixelSize(30);
    ui->red_name->setText(QString::fromLocal8Bit(red->get_name()));
    ui->red_name->setFont(font);
    ui->blue_name->setText(QString::fromLocal8Bit(blue->get_name()));
    ui->blue_name->setFont(font);
}

//接收战斗日志，并输出显示
void fight_game::recieve_fight_log(QString msg){
    ui->log->append(msg);
}
