#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class login;
}

class login : public QWidget{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    void set_ui();
    //设置ui
protected:
     void closeEvent(QCloseEvent *event);
     //关闭窗口 = 登出
signals:
     void login_disconnect();
     //登录界面关闭
     void try_login(QString msg);
     //登录信号
     void try_register(QString msg);
    //注册信号
private slots:
     void on_loginbtn_clicked();
     //点击登录就发一个登录信号过去

     void on_registerbtn_clicked();
    //点击注册就发送一个注册信号
private:
    Ui::login *ui;
};

#endif // LOGIN_H
