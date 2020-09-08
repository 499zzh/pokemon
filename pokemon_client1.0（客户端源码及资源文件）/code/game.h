#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include "my_pokemon.h"
#include "fight_game.h"
#include "QListWidgetItem"
namespace Ui {
class game;
}

class game : public QWidget
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = nullptr);
    ~game();
    void set_ui();
    //设置ui
    void random_pokemon();
    //生成系统维护的精灵列表
    void show_my_pokemon(pokemon* pokemon);
    //展示我的精灵
    void show_opp_pokemon(pokemon* pokemon);
    //展示对手的精灵
public slots:
    void get_my_pokemon(QList<pokemon*> my_pokemon_list);
    //获取我的精灵的信息
signals:
    void game_send_fight_result(int pokemon_id, int result, int fight_type, int get);
    //发送战斗结果的信号
private slots:
    void on_exp_fight_clicked();
    //选择升级赛
    void on_pokemon_fight_clicked();
    //选择决斗赛
    void on_opponent_pokemon_itemDoubleClicked(QListWidgetItem *item);
    //选择对手出战的精灵
    void on_my_pokemon_itemDoubleClicked(QListWidgetItem *item);
    //选择自己出战的精灵
    void fight();
    //开始战斗
private:
    Ui::game *ui;
    int fight_type;
    //战斗类型
    QList<pokemon*> temp;
    //新生成的精灵列表
    QList<pokemon*> my_pokemon;
    //我的精灵的列表
};

#endif // GAME_H
