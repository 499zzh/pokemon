/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>
#include <my_Label.h>

QT_BEGIN_NAMESPACE

class Ui_game
{
public:
    QListWidget *my_pokemon;
    QListWidget *opponent_pokemon;
    QRadioButton *exp_fight;
    QRadioButton *pokemon_fight;
    QLabel *pro_label;
    QLabel *my_icon;
    QLabel *my_pro;
    QLabel *type_label;
    QLabel *my_type;
    QLabel *att_label;
    QLabel *my_att;
    QLabel *def_label;
    QLabel *spe_label;
    QLabel *HP_label;
    QLabel *exp_label;
    QLabel *my_def;
    QLabel *my_spe;
    QLabel *my_hp;
    QLabel *my_level;
    QLabel *my_name;
    QLabel *opp_icon;
    QLabel *opp_name;
    QLabel *def_label_2;
    QLabel *spe_label_2;
    QLabel *exp_label_2;
    QLabel *opp_def;
    QLabel *opp_hp;
    QLabel *opp_pro;
    QLabel *opp_att;
    QLabel *opp_spe;
    QLabel *opp_type;
    QLabel *HP_label_2;
    QLabel *pro_label_2;
    QLabel *att_label_2;
    QLabel *opp_level;
    QLabel *type_label_2;
    my_Label *fight;

    void setupUi(QWidget *game)
    {
        if (game->objectName().isEmpty())
            game->setObjectName(QString::fromUtf8("game"));
        game->resize(826, 500);
        my_pokemon = new QListWidget(game);
        my_pokemon->setObjectName(QString::fromUtf8("my_pokemon"));
        my_pokemon->setGeometry(QRect(10, 10, 301, 241));
        opponent_pokemon = new QListWidget(game);
        opponent_pokemon->setObjectName(QString::fromUtf8("opponent_pokemon"));
        opponent_pokemon->setGeometry(QRect(510, 10, 301, 241));
        exp_fight = new QRadioButton(game);
        exp_fight->setObjectName(QString::fromUtf8("exp_fight"));
        exp_fight->setGeometry(QRect(350, 80, 115, 19));
        pokemon_fight = new QRadioButton(game);
        pokemon_fight->setObjectName(QString::fromUtf8("pokemon_fight"));
        pokemon_fight->setGeometry(QRect(350, 180, 115, 19));
        pro_label = new QLabel(game);
        pro_label->setObjectName(QString::fromUtf8("pro_label"));
        pro_label->setGeometry(QRect(20, 330, 72, 15));
        my_icon = new QLabel(game);
        my_icon->setObjectName(QString::fromUtf8("my_icon"));
        my_icon->setGeometry(QRect(20, 250, 71, 71));
        my_pro = new QLabel(game);
        my_pro->setObjectName(QString::fromUtf8("my_pro"));
        my_pro->setGeometry(QRect(80, 330, 72, 15));
        type_label = new QLabel(game);
        type_label->setObjectName(QString::fromUtf8("type_label"));
        type_label->setGeometry(QRect(120, 330, 72, 15));
        my_type = new QLabel(game);
        my_type->setObjectName(QString::fromUtf8("my_type"));
        my_type->setGeometry(QRect(180, 330, 72, 15));
        att_label = new QLabel(game);
        att_label->setObjectName(QString::fromUtf8("att_label"));
        att_label->setGeometry(QRect(20, 370, 72, 15));
        my_att = new QLabel(game);
        my_att->setObjectName(QString::fromUtf8("my_att"));
        my_att->setGeometry(QRect(80, 370, 72, 15));
        def_label = new QLabel(game);
        def_label->setObjectName(QString::fromUtf8("def_label"));
        def_label->setGeometry(QRect(120, 370, 72, 15));
        spe_label = new QLabel(game);
        spe_label->setObjectName(QString::fromUtf8("spe_label"));
        spe_label->setGeometry(QRect(20, 410, 72, 15));
        HP_label = new QLabel(game);
        HP_label->setObjectName(QString::fromUtf8("HP_label"));
        HP_label->setGeometry(QRect(120, 410, 72, 15));
        exp_label = new QLabel(game);
        exp_label->setObjectName(QString::fromUtf8("exp_label"));
        exp_label->setGeometry(QRect(20, 450, 72, 15));
        my_def = new QLabel(game);
        my_def->setObjectName(QString::fromUtf8("my_def"));
        my_def->setGeometry(QRect(180, 370, 72, 15));
        my_spe = new QLabel(game);
        my_spe->setObjectName(QString::fromUtf8("my_spe"));
        my_spe->setGeometry(QRect(80, 410, 72, 15));
        my_hp = new QLabel(game);
        my_hp->setObjectName(QString::fromUtf8("my_hp"));
        my_hp->setGeometry(QRect(180, 410, 72, 15));
        my_level = new QLabel(game);
        my_level->setObjectName(QString::fromUtf8("my_level"));
        my_level->setGeometry(QRect(80, 450, 72, 15));
        my_name = new QLabel(game);
        my_name->setObjectName(QString::fromUtf8("my_name"));
        my_name->setGeometry(QRect(120, 280, 72, 15));
        opp_icon = new QLabel(game);
        opp_icon->setObjectName(QString::fromUtf8("opp_icon"));
        opp_icon->setGeometry(QRect(510, 250, 71, 71));
        opp_name = new QLabel(game);
        opp_name->setObjectName(QString::fromUtf8("opp_name"));
        opp_name->setGeometry(QRect(620, 280, 72, 15));
        def_label_2 = new QLabel(game);
        def_label_2->setObjectName(QString::fromUtf8("def_label_2"));
        def_label_2->setGeometry(QRect(610, 370, 72, 15));
        spe_label_2 = new QLabel(game);
        spe_label_2->setObjectName(QString::fromUtf8("spe_label_2"));
        spe_label_2->setGeometry(QRect(510, 410, 72, 15));
        exp_label_2 = new QLabel(game);
        exp_label_2->setObjectName(QString::fromUtf8("exp_label_2"));
        exp_label_2->setGeometry(QRect(510, 450, 72, 15));
        opp_def = new QLabel(game);
        opp_def->setObjectName(QString::fromUtf8("opp_def"));
        opp_def->setGeometry(QRect(670, 370, 72, 15));
        opp_hp = new QLabel(game);
        opp_hp->setObjectName(QString::fromUtf8("opp_hp"));
        opp_hp->setGeometry(QRect(670, 410, 72, 15));
        opp_pro = new QLabel(game);
        opp_pro->setObjectName(QString::fromUtf8("opp_pro"));
        opp_pro->setGeometry(QRect(570, 330, 72, 15));
        opp_att = new QLabel(game);
        opp_att->setObjectName(QString::fromUtf8("opp_att"));
        opp_att->setGeometry(QRect(570, 370, 72, 15));
        opp_spe = new QLabel(game);
        opp_spe->setObjectName(QString::fromUtf8("opp_spe"));
        opp_spe->setGeometry(QRect(570, 410, 72, 15));
        opp_type = new QLabel(game);
        opp_type->setObjectName(QString::fromUtf8("opp_type"));
        opp_type->setGeometry(QRect(670, 330, 72, 15));
        HP_label_2 = new QLabel(game);
        HP_label_2->setObjectName(QString::fromUtf8("HP_label_2"));
        HP_label_2->setGeometry(QRect(610, 410, 72, 15));
        pro_label_2 = new QLabel(game);
        pro_label_2->setObjectName(QString::fromUtf8("pro_label_2"));
        pro_label_2->setGeometry(QRect(510, 330, 72, 15));
        att_label_2 = new QLabel(game);
        att_label_2->setObjectName(QString::fromUtf8("att_label_2"));
        att_label_2->setGeometry(QRect(510, 370, 72, 15));
        opp_level = new QLabel(game);
        opp_level->setObjectName(QString::fromUtf8("opp_level"));
        opp_level->setGeometry(QRect(570, 450, 72, 15));
        type_label_2 = new QLabel(game);
        type_label_2->setObjectName(QString::fromUtf8("type_label_2"));
        type_label_2->setGeometry(QRect(610, 330, 72, 15));
        fight = new my_Label(game);
        fight->setObjectName(QString::fromUtf8("fight"));
        fight->setGeometry(QRect(320, 290, 121, 121));

        retranslateUi(game);

        QMetaObject::connectSlotsByName(game);
    } // setupUi

    void retranslateUi(QWidget *game)
    {
        game->setWindowTitle(QApplication::translate("game", "Form", nullptr));
        exp_fight->setText(QApplication::translate("game", "\345\215\207\347\272\247\350\265\233", nullptr));
        pokemon_fight->setText(QApplication::translate("game", "\345\206\263\346\226\227\350\265\233", nullptr));
        pro_label->setText(QApplication::translate("game", "\345\261\236\346\200\247  \357\274\232", nullptr));
        my_icon->setText(QApplication::translate("game", "my_icon", nullptr));
        my_pro->setText(QApplication::translate("game", "pro", nullptr));
        type_label->setText(QApplication::translate("game", "\347\261\273\345\236\213  \357\274\232", nullptr));
        my_type->setText(QApplication::translate("game", "type", nullptr));
        att_label->setText(QApplication::translate("game", "\346\224\273\345\207\273\345\212\233\357\274\232", nullptr));
        my_att->setText(QApplication::translate("game", "att", nullptr));
        def_label->setText(QApplication::translate("game", "\351\230\262\345\276\241\345\212\233\357\274\232", nullptr));
        spe_label->setText(QApplication::translate("game", "\351\200\237\345\272\246  \357\274\232", nullptr));
        HP_label->setText(QApplication::translate("game", "HP    :", nullptr));
        exp_label->setText(QApplication::translate("game", "\347\255\211\347\272\247  \357\274\232", nullptr));
        my_def->setText(QApplication::translate("game", "def", nullptr));
        my_spe->setText(QApplication::translate("game", "spe", nullptr));
        my_hp->setText(QApplication::translate("game", "hp", nullptr));
        my_level->setText(QApplication::translate("game", "level", nullptr));
        my_name->setText(QApplication::translate("game", "my_name", nullptr));
        opp_icon->setText(QApplication::translate("game", "opp_icon", nullptr));
        opp_name->setText(QApplication::translate("game", "opponent_name", nullptr));
        def_label_2->setText(QApplication::translate("game", "\351\230\262\345\276\241\345\212\233\357\274\232", nullptr));
        spe_label_2->setText(QApplication::translate("game", "\351\200\237\345\272\246  \357\274\232", nullptr));
        exp_label_2->setText(QApplication::translate("game", "\347\255\211\347\272\247  \357\274\232", nullptr));
        opp_def->setText(QApplication::translate("game", "def", nullptr));
        opp_hp->setText(QApplication::translate("game", "hp", nullptr));
        opp_pro->setText(QApplication::translate("game", "pro", nullptr));
        opp_att->setText(QApplication::translate("game", "att", nullptr));
        opp_spe->setText(QApplication::translate("game", "spe", nullptr));
        opp_type->setText(QApplication::translate("game", "type", nullptr));
        HP_label_2->setText(QApplication::translate("game", "HP    :", nullptr));
        pro_label_2->setText(QApplication::translate("game", "\345\261\236\346\200\247  \357\274\232", nullptr));
        att_label_2->setText(QApplication::translate("game", "\346\224\273\345\207\273\345\212\233\357\274\232", nullptr));
        opp_level->setText(QApplication::translate("game", "level", nullptr));
        type_label_2->setText(QApplication::translate("game", "\347\261\273\345\236\213  \357\274\232", nullptr));
        fight->setText(QApplication::translate("game", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class game: public Ui_game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
