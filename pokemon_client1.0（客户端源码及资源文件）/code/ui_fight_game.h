/********************************************************************************
** Form generated from reading UI file 'fight_game.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIGHT_GAME_H
#define UI_FIGHT_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fight_game
{
public:
    QLabel *red_label;
    QLabel *blue_label;
    QLabel *battle_label;
    QLabel *red_pokemon_label;
    QLabel *blue_pokemon_label;
    QLabel *vs;
    QLabel *red_name;
    QLabel *blue_name;
    QTextEdit *log;

    void setupUi(QWidget *fight_game)
    {
        if (fight_game->objectName().isEmpty())
            fight_game->setObjectName(QString::fromUtf8("fight_game"));
        fight_game->resize(400, 300);
        red_label = new QLabel(fight_game);
        red_label->setObjectName(QString::fromUtf8("red_label"));
        red_label->setGeometry(QRect(10, 10, 51, 51));
        blue_label = new QLabel(fight_game);
        blue_label->setObjectName(QString::fromUtf8("blue_label"));
        blue_label->setGeometry(QRect(340, 10, 51, 51));
        battle_label = new QLabel(fight_game);
        battle_label->setObjectName(QString::fromUtf8("battle_label"));
        battle_label->setGeometry(QRect(170, 20, 72, 31));
        red_pokemon_label = new QLabel(fight_game);
        red_pokemon_label->setObjectName(QString::fromUtf8("red_pokemon_label"));
        red_pokemon_label->setGeometry(QRect(10, 60, 171, 181));
        blue_pokemon_label = new QLabel(fight_game);
        blue_pokemon_label->setObjectName(QString::fromUtf8("blue_pokemon_label"));
        blue_pokemon_label->setGeometry(QRect(200, 60, 161, 181));
        vs = new QLabel(fight_game);
        vs->setObjectName(QString::fromUtf8("vs"));
        vs->setGeometry(QRect(150, 130, 111, 61));
        red_name = new QLabel(fight_game);
        red_name->setObjectName(QString::fromUtf8("red_name"));
        red_name->setGeometry(QRect(60, 20, 91, 41));
        blue_name = new QLabel(fight_game);
        blue_name->setObjectName(QString::fromUtf8("blue_name"));
        blue_name->setGeometry(QRect(240, 20, 91, 41));
        log = new QTextEdit(fight_game);
        log->setObjectName(QString::fromUtf8("log"));
        log->setGeometry(QRect(110, 216, 181, 81));

        retranslateUi(fight_game);

        QMetaObject::connectSlotsByName(fight_game);
    } // setupUi

    void retranslateUi(QWidget *fight_game)
    {
        fight_game->setWindowTitle(QApplication::translate("fight_game", "Form", nullptr));
        red_label->setText(QApplication::translate("fight_game", "\347\272\242\351\230\237", nullptr));
        blue_label->setText(QApplication::translate("fight_game", "\350\223\235\351\230\237", nullptr));
        battle_label->setText(QApplication::translate("fight_game", "battle", nullptr));
        red_pokemon_label->setText(QApplication::translate("fight_game", "red_pokemon", nullptr));
        blue_pokemon_label->setText(QApplication::translate("fight_game", "blue_pokemon", nullptr));
        vs->setText(QApplication::translate("fight_game", "TextLabel", nullptr));
        red_name->setText(QApplication::translate("fight_game", "TextLabel", nullptr));
        blue_name->setText(QApplication::translate("fight_game", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fight_game: public Ui_fight_game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIGHT_GAME_H
