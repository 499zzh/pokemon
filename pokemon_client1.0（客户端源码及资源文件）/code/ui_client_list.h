/********************************************************************************
** Form generated from reading UI file 'client_list.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_LIST_H
#define UI_CLIENT_LIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_client_list
{
public:
    QListWidget *all_client;
    QTextEdit *all_pokemon;

    void setupUi(QWidget *client_list)
    {
        if (client_list->objectName().isEmpty())
            client_list->setObjectName(QString::fromUtf8("client_list"));
        client_list->resize(309, 409);
        all_client = new QListWidget(client_list);
        all_client->setObjectName(QString::fromUtf8("all_client"));
        all_client->setGeometry(QRect(10, 10, 291, 191));
        all_pokemon = new QTextEdit(client_list);
        all_pokemon->setObjectName(QString::fromUtf8("all_pokemon"));
        all_pokemon->setGeometry(QRect(10, 220, 291, 171));

        retranslateUi(client_list);

        QMetaObject::connectSlotsByName(client_list);
    } // setupUi

    void retranslateUi(QWidget *client_list)
    {
        client_list->setWindowTitle(QApplication::translate("client_list", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class client_list: public Ui_client_list {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_LIST_H
