#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    set_ui();
}

login::~login()
{
    delete ui;
}
//关闭登录窗口会产生登录端的断开信号
void login::closeEvent(QCloseEvent *event){

    emit login_disconnect();
}

//点击登录后 如果都有就发送过去 否则跳出警告
void login::on_loginbtn_clicked()
{

    if(ui->user_name->text() != "" && ui->password->text() != ""){
        QString msg = "0//" + ui->user_name->text() + "//" + ui->password->text();
        emit try_login(msg);
    }
    else{
       QMessageBox::warning(this, "warning", "please input username and password!");
    }
}

//点击注册后 根据输入先进行本地判断，无误后发送信号
void login::on_registerbtn_clicked()
{
    if(ui->user_name->text() != "" && ui->password->text() != ""){
        QString msg = "1//" + ui->user_name->text() + "//" + ui->password->text();
        emit try_register(msg);
    }
    else{
       QMessageBox::warning(this, "warning", "please input username and password!");
    }
}

//设置背景图片
void login::set_ui(){

    this->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/Material/login_background.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap.scaled(767,510)));
    this->setPalette(palette);
    this->setWindowTitle("login");
    QSize size1(120,100);
    QSize size2(81,51);
    pixmap.load(":/Material/login.png");
    pixmap = pixmap.scaled(size1);
    ui->loginbtn->setIcon(pixmap);
    pixmap.load(":/Material/register.png");
    pixmap = pixmap.scaled(size1);
    ui->registerbtn->setIcon(pixmap);
    pixmap.load(":/Material/username.png");
    pixmap =  pixmap.scaled(size2);
    ui->user_name_label->setPixmap(pixmap);
    pixmap.load(":/Material/password.png");
    pixmap = pixmap.scaled(size2);
    ui->password_label->setPixmap(pixmap);
    ui->password->setEchoMode(QLineEdit::Password);
}
