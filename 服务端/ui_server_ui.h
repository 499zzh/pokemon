/********************************************************************************
** Form generated from reading UI file 'server_ui.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_UI_H
#define UI_SERVER_UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_server_ui
{
public:
    QTextEdit *server_log;

    void setupUi(QWidget *server_ui)
    {
        if (server_ui->objectName().isEmpty())
            server_ui->setObjectName(QString::fromUtf8("server_ui"));
        server_ui->resize(800, 600);
        server_log = new QTextEdit(server_ui);
        server_log->setObjectName(QString::fromUtf8("server_log"));
        server_log->setGeometry(QRect(13, 16, 341, 411));

        retranslateUi(server_ui);

        QMetaObject::connectSlotsByName(server_ui);
    } // setupUi

    void retranslateUi(QWidget *server_ui)
    {
        server_ui->setWindowTitle(QApplication::translate("server_ui", "server_ui", nullptr));
    } // retranslateUi

};

namespace Ui {
    class server_ui: public Ui_server_ui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_UI_H
