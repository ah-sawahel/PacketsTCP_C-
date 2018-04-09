#include <QtWidgets>

#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton
{
private:
    /* Here will be the instance stored. */
    static Singleton* instance;

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

#endif // SINGLETON_H
