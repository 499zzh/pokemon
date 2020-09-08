#include "client_list.h"
#include "ui_client_list.h"

client_list::client_list(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::client_list)
{
    ui->setupUi(this);
    set_ui();
}

client_list::~client_list()
{
    delete ui;
}

//设置ui
void client_list::set_ui(){
    this->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/Material/clientl_list_background.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap.scaled(309,409)));
    this->setPalette(palette);
    this->setWindowTitle("show client");
}

//显示所有用户
void client_list::show_client(QStringList all_client){;
    for(int i = 0;i < all_client.count(); i++){
        QString text = all_client.at(i).toUtf8().data();
        QListWidgetItem* item = new QListWidgetItem;
        item->setText(text);
        ui->all_client->addItem(item);
    }
}

//发送被选中的用户item
void client_list::on_all_client_itemDoubleClicked(QListWidgetItem *item)
{
    emit send_user_id(item->text());
}

//展示选择用户的精灵
void client_list::show_pokemon(QStringList msg){
    ui->all_pokemon->clear();
    for(int i = 1; i < msg.count(); i++){
        ui->all_pokemon->append(msg.at(i));
    }
}
