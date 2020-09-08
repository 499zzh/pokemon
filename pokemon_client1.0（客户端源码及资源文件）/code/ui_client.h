/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include <my_Label.h>

QT_BEGIN_NAMESPACE

class Ui_client
{
public:
    my_Label *bag_label;
    my_Label *set_label;
    my_Label *other_client_label;
    QPushButton *dbg_mode;
    my_Label *game_label;
    QPushButton *dbg_exp;
    QPushButton *dbg_fight;
    QPushButton *dbg_get_pokemon;
    QLabel *exp_label;
    QLabel *fight_label;
    QLabel *get_pokemon_label;
    QTextEdit *dbg_log;
    QPushButton *dbg_exit;
    QLabel *bd1;
    QLabel *bd2;

    void setupUi(QWidget *client)
    {
        if (client->objectName().isEmpty())
            client->setObjectName(QString::fromUtf8("client"));
        client->resize(1026, 766);
        bag_label = new my_Label(client);
        bag_label->setObjectName(QString::fromUtf8("bag_label"));
        bag_label->setGeometry(QRect(820, 690, 61, 61));
        set_label = new my_Label(client);
        set_label->setObjectName(QString::fromUtf8("set_label"));
        set_label->setGeometry(QRect(920, 690, 61, 61));
        other_client_label = new my_Label(client);
        other_client_label->setObjectName(QString::fromUtf8("other_client_label"));
        other_client_label->setGeometry(QRect(720, 690, 61, 61));
        dbg_mode = new QPushButton(client);
        dbg_mode->setObjectName(QString::fromUtf8("dbg_mode"));
        dbg_mode->setGeometry(QRect(20, 30, 93, 61));
        game_label = new my_Label(client);
        game_label->setObjectName(QString::fromUtf8("game_label"));
        game_label->setGeometry(QRect(620, 690, 61, 61));
        dbg_exp = new QPushButton(client);
        dbg_exp->setObjectName(QString::fromUtf8("dbg_exp"));
        dbg_exp->setGeometry(QRect(250, 550, 71, 61));
        dbg_fight = new QPushButton(client);
        dbg_fight->setObjectName(QString::fromUtf8("dbg_fight"));
        dbg_fight->setGeometry(QRect(450, 550, 71, 61));
        dbg_get_pokemon = new QPushButton(client);
        dbg_get_pokemon->setObjectName(QString::fromUtf8("dbg_get_pokemon"));
        dbg_get_pokemon->setGeometry(QRect(650, 550, 71, 61));
        exp_label = new QLabel(client);
        exp_label->setObjectName(QString::fromUtf8("exp_label"));
        exp_label->setGeometry(QRect(241, 620, 91, 20));
        fight_label = new QLabel(client);
        fight_label->setObjectName(QString::fromUtf8("fight_label"));
        fight_label->setGeometry(QRect(450, 620, 72, 21));
        get_pokemon_label = new QLabel(client);
        get_pokemon_label->setObjectName(QString::fromUtf8("get_pokemon_label"));
        get_pokemon_label->setGeometry(QRect(640, 620, 101, 21));
        dbg_log = new QTextEdit(client);
        dbg_log->setObjectName(QString::fromUtf8("dbg_log"));
        dbg_log->setGeometry(QRect(370, 70, 241, 391));
        dbg_exit = new QPushButton(client);
        dbg_exit->setObjectName(QString::fromUtf8("dbg_exit"));
        dbg_exit->setGeometry(QRect(150, 30, 91, 61));
        bd1 = new QLabel(client);
        bd1->setObjectName(QString::fromUtf8("bd1"));
        bd1->setGeometry(QRect(801, 64, 71, 71));
        bd2 = new QLabel(client);
        bd2->setObjectName(QString::fromUtf8("bd2"));
        bd2->setGeometry(QRect(810, 230, 71, 71));

        retranslateUi(client);

        QMetaObject::connectSlotsByName(client);
    } // setupUi

    void retranslateUi(QWidget *client)
    {
        client->setWindowTitle(QApplication::translate("client", "client", nullptr));
        bag_label->setText(QApplication::translate("client", "\350\203\214\345\214\205", nullptr));
        set_label->setText(QApplication::translate("client", "\350\256\276\347\275\256", nullptr));
        other_client_label->setText(QApplication::translate("client", "\347\224\250\346\210\267", nullptr));
        dbg_mode->setText(QApplication::translate("client", "\346\265\213\350\257\225", nullptr));
        game_label->setText(QApplication::translate("client", "\346\210\230\346\226\227", nullptr));
        dbg_exp->setText(QString());
        dbg_fight->setText(QString());
        dbg_get_pokemon->setText(QString());
        exp_label->setText(QApplication::translate("client", " \345\210\206\351\205\215\347\273\217\351\252\214\345\200\274", nullptr));
        fight_label->setText(QApplication::translate("client", "  \346\210\230\346\226\227", nullptr));
        get_pokemon_label->setText(QApplication::translate("client", "\350\216\267\345\217\226\346\265\213\350\257\225\347\262\276\347\201\265", nullptr));
        dbg_exit->setText(QApplication::translate("client", "\351\200\200\345\207\272\346\265\213\350\257\225", nullptr));
        bd1->setText(QApplication::translate("client", "TextLabel", nullptr));
        bd2->setText(QApplication::translate("client", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class client: public Ui_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
