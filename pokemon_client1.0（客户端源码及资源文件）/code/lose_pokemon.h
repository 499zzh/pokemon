#ifndef LOSE_POKEMON_H
#define LOSE_POKEMON_H

#include <QWidget>

namespace Ui {
class lose_pokemon;
}

class lose_pokemon : public QWidget
{
    Q_OBJECT

public:
    explicit lose_pokemon(QWidget *parent = nullptr);
    ~lose_pokemon();

public slots:
    void recieve(int,int,int);
    //接收随机过来的自己的精灵序号
private slots:
    void on_lose_1_clicked();
    void on_lose_2_clicked();
    void on_lose_3_clicked();
    //上述三个函数用来选择自己失去的精灵
    void on_pushButton_4_clicked();
    //确认自己的选择
private:
    Ui::lose_pokemon *ui;
    QString lose_num;
    //失去精灵的序号
signals:
    void choose_lose(QString);
    //告知上层你选择失去的精灵
};


#endif // LOSE_POKEMON_H
