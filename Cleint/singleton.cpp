
#include <iostream>
#include <string>
#include "client.h"
#include <vector>
#include <QtWidgets>
using namespace std;

class Singleton
{
    private:
        /* Here will be the instance stored. */
        static Singleton* instance;
        vector <QPushButton * > clients;

        /* Private constructor to prevent instancing. */
        Singleton();

    public:
        /* Static access method. */
        static Singleton* getInstance();
        vector<string> packetSizes;
        vector<string> stringLengthes;
        void registerUI(QPushButton *client);
        void updateTables(string packetSize, string stringLength);
};

/* Null, because instance will be initialized on demand. */
Singleton* Singleton::instance = 0;

/* Get single instance */
Singleton* Singleton::getInstance()
{
    if (instance == 0)
    {
        instance = new Singleton();
    }

    return instance;
}

Singleton::Singleton()
{}
