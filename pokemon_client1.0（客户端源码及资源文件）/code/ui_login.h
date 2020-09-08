/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLineEdit *user_name;
    QLineEdit *password;
    QLabel *user_name_label;
    QLabel *password_label;
    QPushButton *loginbtn;
    QPushButton *registerbtn;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(767, 518);
        user_name = new QLineEdit(login);
        user_name->setObjectName(QString::fromUtf8("user_name"));
        user_name->setGeometry(QRect(260, 220, 261, 51));
        password = new QLineEdit(login);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(260, 350, 261, 51));
        user_name_label = new QLabel(login);
        user_name_label->setObjectName(QString::fromUtf8("user_name_label"));
        user_name_label->setGeometry(QRect(130, 220, 71, 41));
        password_label = new QLabel(login);
        password_label->setObjectName(QString::fromUtf8("password_label"));
        password_label->setGeometry(QRect(130, 350, 81, 51));
        loginbtn = new QPushButton(login);
        loginbtn->setObjectName(QString::fromUtf8("loginbtn"));
        loginbtn->setGeometry(QRect(160, 460, 93, 28));
        registerbtn = new QPushButton(login);
        registerbtn->setObjectName(QString::fromUtf8("registerbtn"));
        registerbtn->setGeometry(QRect(490, 460, 93, 28));

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Form", nullptr));
        user_name->setText(QString());
        user_name_label->setText(QApplication::translate("login", "\347\224\250\346\210\267\345\220\215", nullptr));
        password_label->setText(QApplication::translate("login", "\345\257\206\347\240\201", nullptr));
        loginbtn->setText(QString());
        registerbtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
