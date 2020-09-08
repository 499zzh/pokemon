#include "lose_pokemon.h"
#include "ui_lose_pokemon.h"

lose_pokemon::lose_pokemon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lose_pokemon)
{
    ui->setupUi(this);
    lose_num = 1;
}

lose_pokemon::~lose_pokemon()
{
    delete ui;
}
//选择失去的精灵
void lose_pokemon::on_lose_1_clicked()
{
    lose_num = ui->lose_1->text();
}
void lose_pokemon::on_lose_2_clicked()
{
    lose_num = ui->lose_2->text();
}
void lose_pokemon::on_lose_3_clicked()
{
    lose_num = ui->lose_3->text();
}

//发送选择好的精灵，并关闭窗口
void lose_pokemon::on_pushButton_4_clicked()
{
    emit choose_lose(lose_num);
    this->close();
}

//接收可供选择的选项
void lose_pokemon::recieve(int l1, int l2, int l3){
   ui->lose_1->setText(QString::number(l1));
   ui->lose_2->setText(QString::number(l2));
   ui->lose_3->setText(QString::number(l3));
}
