/********************************************************************************
** Form generated from reading UI file 'bag.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BAG_H
#define UI_BAG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bag
{
public:
    QLabel *pokemon_icon;
    QListWidget *pokemon_list;
    QLabel *att_label;
    QLabel *prolabel;
    QLabel *type_label;
    QLabel *den_label;
    QLabel *speed_label;
    QLabel *level_label;
    QLabel *exp_label;
    QLabel *hp_label;
    QLabel *name_label;
    QLabel *pro;
    QLabel *type;
    QLabel *att;
    QLabel *den;
    QLabel *spe;
    QLabel *hp;
    QLabel *level;
    QLabel *exp;

    void setupUi(QWidget *bag)
    {
        if (bag->objectName().isEmpty())
            bag->setObjectName(QString::fromUtf8("bag"));
        bag->resize(447, 329);
        pokemon_icon = new QLabel(bag);
        pokemon_icon->setObjectName(QString::fromUtf8("pokemon_icon"));
        pokemon_icon->setGeometry(QRect(250, 20, 101, 91));
        pokemon_list = new QListWidget(bag);
        pokemon_list->setObjectName(QString::fromUtf8("pokemon_list"));
        pokemon_list->setGeometry(QRect(10, 10, 171, 311));
        att_label = new QLabel(bag);
        att_label->setObjectName(QString::fromUtf8("att_label"));
        att_label->setGeometry(QRect(200, 210, 61, 21));
        prolabel = new QLabel(bag);
        prolabel->setObjectName(QString::fromUtf8("prolabel"));
        prolabel->setGeometry(QRect(200, 170, 61, 16));
        type_label = new QLabel(bag);
        type_label->setObjectName(QString::fromUtf8("type_label"));
        type_label->setGeometry(QRect(330, 170, 61, 16));
        den_label = new QLabel(bag);
        den_label->setObjectName(QString::fromUtf8("den_label"));
        den_label->setGeometry(QRect(330, 210, 51, 16));
        speed_label = new QLabel(bag);
        speed_label->setObjectName(QString::fromUtf8("speed_label"));
        speed_label->setGeometry(QRect(200, 250, 61, 16));
        level_label = new QLabel(bag);
        level_label->setObjectName(QString::fromUtf8("level_label"));
        level_label->setGeometry(QRect(200, 290, 61, 16));
        exp_label = new QLabel(bag);
        exp_label->setObjectName(QString::fromUtf8("exp_label"));
        exp_label->setGeometry(QRect(330, 290, 51, 16));
        hp_label = new QLabel(bag);
        hp_label->setObjectName(QString::fromUtf8("hp_label"));
        hp_label->setGeometry(QRect(330, 250, 61, 16));
        name_label = new QLabel(bag);
        name_label->setObjectName(QString::fromUtf8("name_label"));
        name_label->setGeometry(QRect(260, 130, 72, 15));
        pro = new QLabel(bag);
        pro->setObjectName(QString::fromUtf8("pro"));
        pro->setGeometry(QRect(270, 170, 41, 16));
        type = new QLabel(bag);
        type->setObjectName(QString::fromUtf8("type"));
        type->setGeometry(QRect(400, 170, 72, 15));
        att = new QLabel(bag);
        att->setObjectName(QString::fromUtf8("att"));
        att->setGeometry(QRect(270, 210, 72, 15));
        den = new QLabel(bag);
        den->setObjectName(QString::fromUtf8("den"));
        den->setGeometry(QRect(400, 210, 72, 15));
        spe = new QLabel(bag);
        spe->setObjectName(QString::fromUtf8("spe"));
        spe->setGeometry(QRect(270, 250, 72, 15));
        hp = new QLabel(bag);
        hp->setObjectName(QString::fromUtf8("hp"));
        hp->setGeometry(QRect(400, 250, 72, 15));
        level = new QLabel(bag);
        level->setObjectName(QString::fromUtf8("level"));
        level->setGeometry(QRect(270, 290, 72, 15));
        exp = new QLabel(bag);
        exp->setObjectName(QString::fromUtf8("exp"));
        exp->setGeometry(QRect(400, 290, 72, 15));

        retranslateUi(bag);

        QMetaObject::connectSlotsByName(bag);
    } // setupUi

    void retranslateUi(QWidget *bag)
    {
        bag->setWindowTitle(QApplication::translate("bag", "Form", nullptr));
        pokemon_icon->setText(QApplication::translate("bag", "pokemon_icon", nullptr));
        att_label->setText(QApplication::translate("bag", "\346\224\273\345\207\273\345\212\233\357\274\232", nullptr));
        prolabel->setText(QApplication::translate("bag", "\345\261\236\346\200\247  \357\274\232", nullptr));
        type_label->setText(QApplication::translate("bag", "\347\261\273\345\236\213  \357\274\232", nullptr));
        den_label->setText(QApplication::translate("bag", "\351\230\262\345\276\241\345\212\233\357\274\232", nullptr));
        speed_label->setText(QApplication::translate("bag", "\351\200\237\345\272\246  \357\274\232", nullptr));
        level_label->setText(QApplication::translate("bag", "\347\255\211\347\272\247  \357\274\232", nullptr));
        exp_label->setText(QApplication::translate("bag", "\347\273\217\351\252\214\345\200\274\357\274\232", nullptr));
        hp_label->setText(QApplication::translate("bag", "HP    :", nullptr));
        name_label->setText(QApplication::translate("bag", "\347\262\276\347\201\265\345\220\215\345\255\227", nullptr));
        pro->setText(QApplication::translate("bag", "pro", nullptr));
        type->setText(QApplication::translate("bag", "type", nullptr));
        att->setText(QApplication::translate("bag", "att", nullptr));
        den->setText(QApplication::translate("bag", "den", nullptr));
        spe->setText(QApplication::translate("bag", "spe", nullptr));
        hp->setText(QApplication::translate("bag", "hp", nullptr));
        level->setText(QApplication::translate("bag", "level", nullptr));
        exp->setText(QApplication::translate("bag", "exp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bag: public Ui_bag {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BAG_H
