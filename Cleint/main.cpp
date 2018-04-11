#include "client.h"
#include "clienttcp.h"
#include "singleton.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Client client;
    client.show();

    ClientTCP tcp;
    tcp.start();

    return a.exec();
}
