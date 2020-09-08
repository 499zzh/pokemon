#include "bag.h"
#include "ui_bag.h"
#include<QtDebug>


bag::bag(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bag)
{
    ui->setupUi(this);
}

bag::~bag()
{
    delete ui;
}

void bag::load_bag(QStringList my_list){
    //加载背包
    for(int i = 0; i< my_list.count(); i++){
        QListWidgetItem* item = new QListWidgetItem();
        item->setText(my_list.at(i).toUtf8().data());
        ui->pokemon_list->addItem(item);
    }
}

void bag::show_pokemon(pokemon* pl){
    //显示选中的精灵
    ui->hp->setNum(pl->get_HP());
    ui->pro->setText(QString::fromLocal8Bit(pl->format_output(pl->get_property(), -1)));
    ui->type->setText(QString::fromLocal8Bit(pl->format_output(-1, pl->get_type())));
    ui->att->setNum(pl->get_att());
    ui->den->setNum(pl->get_defense());
    ui->level->setNum(pl->get_level());
    ui->pokemon_icon->setPixmap(pl->get_QPixmap().scaled(100,100));
    ui->spe->setNum(pl->get_speed());
    ui->name_label->setText(QString::fromLocal8Bit(pl->get_name()));
    ui->exp->hide();
    ui->exp_label->hide();
}


void bag::on_pokemon_list_itemDoubleClicked(QListWidgetItem *item)
{
    //发送当前精灵的id
    emit send_pokemon_id(item->text());
}

