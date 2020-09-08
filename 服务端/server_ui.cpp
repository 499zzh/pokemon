#include "server_ui.h"
#include "ui_server_ui.h"

server_ui::server_ui(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::server_ui)
{
    ui->setupUi(this);
    port = 8888;
    server  = new my_server(this, port);
    connect(server, &my_server::update_ui, this, &server_ui::update_log);
}

server_ui::~server_ui()
{
    delete ui;
}

void server_ui::update_log(QString msg){
    ui->server_log->append(msg);
}
