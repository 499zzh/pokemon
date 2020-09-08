#ifndef FIGHT_GAME_H
#define FIGHT_GAME_H

#include <QWidget>
#include <QLabel>
#include <QPropertyAnimation>
#include "my_pokemon.h"

namespace Ui {
class fight_game;
}

class fight_game : public QWidget
{
    Q_OBJECT

public:
    explicit fight_game(QWidget *parent = nullptr);
    ~fight_game();
    void set_ui();
    //设置ui
public slots:
    void show_msg(QString msg);
    //显示战斗实时情况
    void recieve_pokemon(pokemon* red, pokemon* blue);
    //获取战斗双方的情况
    void recieve_fight_log(QString msg);
    //接收战斗日志
private:
    Ui::fight_game *ui;
    /*
    QLabel *mytext = nullptr;
    QPropertyAnimation *textPropertyAnimation = nullptr;
    */
};

#endif // FIGHT_GAME_H
