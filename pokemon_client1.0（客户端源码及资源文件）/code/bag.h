#ifndef BAG_H
#define BAG_H

#include <QWidget>
#include <QListWidgetItem>
#include "my_pokemon.h"
namespace Ui {
class bag;
}

class bag : public QWidget
{
    Q_OBJECT

public:
    explicit bag(QWidget *parent = nullptr);
    ~bag();

private:
    Ui::bag *ui;
public slots:
    void load_bag(QStringList pokemon_list);
    //接收加载背包的信号
    void show_pokemon(pokemon* pl);
    //接收展示精灵的信号
signals:
    void inquiry_pokemon(QString msg);
    //发送一个查询精灵的信号
    void send_pokemon_id(QString id);
    //发送精灵id的信号
private slots:
    void on_pokemon_list_itemDoubleClicked(QListWidgetItem *item);
    //接收被点击的item的信息
};

#endif // BAG_H
