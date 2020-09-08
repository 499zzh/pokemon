/********************************************************************************
** Form generated from reading UI file 'lose_pokemon.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOSE_POKEMON_H
#define UI_LOSE_POKEMON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lose_pokemon
{
public:
    QPushButton *lose_1;
    QPushButton *lose_2;
    QPushButton *lose_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *lose_pokemon)
    {
        if (lose_pokemon->objectName().isEmpty())
            lose_pokemon->setObjectName(QString::fromUtf8("lose_pokemon"));
        lose_pokemon->resize(399, 186);
        lose_1 = new QPushButton(lose_pokemon);
        lose_1->setObjectName(QString::fromUtf8("lose_1"));
        lose_1->setGeometry(QRect(20, 70, 93, 28));
        lose_2 = new QPushButton(lose_pokemon);
        lose_2->setObjectName(QString::fromUtf8("lose_2"));
        lose_2->setGeometry(QRect(150, 70, 93, 28));
        lose_3 = new QPushButton(lose_pokemon);
        lose_3->setObjectName(QString::fromUtf8("lose_3"));
        lose_3->setGeometry(QRect(280, 70, 93, 28));
        pushButton_4 = new QPushButton(lose_pokemon);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(150, 140, 93, 28));

        retranslateUi(lose_pokemon);

        QMetaObject::connectSlotsByName(lose_pokemon);
    } // setupUi

    void retranslateUi(QWidget *lose_pokemon)
    {
        lose_pokemon->setWindowTitle(QApplication::translate("lose_pokemon", "Form", nullptr));
        lose_1->setText(QApplication::translate("lose_pokemon", "PushButton", nullptr));
        lose_2->setText(QApplication::translate("lose_pokemon", "PushButton", nullptr));
        lose_3->setText(QApplication::translate("lose_pokemon", "PushButton", nullptr));
        pushButton_4->setText(QApplication::translate("lose_pokemon", "\351\200\201\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lose_pokemon: public Ui_lose_pokemon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOSE_POKEMON_H
