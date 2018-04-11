#include "client.h"
#include "clienttcp.h"
#include "singleton.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /* Start Client. */
    Client client;
    client.show();

    /* Start Client TCP Connection */
    ClientTCP tcp;
    tcp.start();

    return a.exec();
}
