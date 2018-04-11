#ifndef CLIENTTCP_H
#define CLIENTTCP_H
#include <QThread>
#include <vector>
#include <string>
using std::vector;
using namespace std;

class ClientTCP : public QThread
{
private:
    void run();
    void reconnect();
};
#endif // CLIENTTCP_H
