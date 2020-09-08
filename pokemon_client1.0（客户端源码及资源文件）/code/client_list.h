#ifndef CLIENT_LIST_H
#define CLIENT_LIST_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class client_list;
}

class client_list : public QWidget
{
    Q_OBJECT

public:
    explicit client_list(QWidget *parent = nullptr);
    ~client_list();
    void set_ui();
    //设置ui
private:
    Ui::client_list *ui;
public slots:
    void show_client(QStringList all_client);
    void show_pokemon(QStringList all_pokemon);
private slots:
    void on_all_client_itemDoubleClicked(QListWidgetItem *item);
signals:
    void send_user_id(QString user_id);
};

#endif // CLIENT_LIST_H
