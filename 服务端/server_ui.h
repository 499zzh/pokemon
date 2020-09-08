#ifndef SERVER_UI_H
#define SERVER_UI_H

#include <QWidget>
#include "my_server.h"
#include "db.h"

QT_BEGIN_NAMESPACE
namespace Ui { class server_ui; }
QT_END_NAMESPACE

class server_ui : public QWidget
{
    Q_OBJECT

public:
    server_ui(QWidget *parent = nullptr);
    ~server_ui();
    int port;
    //端口号
    my_server* server;
    //服务器
protected slots:
    void update_log(QString msg);
    //更新服务器端日志显示区
private:
    Ui::server_ui *ui;
};

#endif // SERVER_UI_H
