#include "server_ui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    server_ui w;
    w.show();
    return a.exec();
}
