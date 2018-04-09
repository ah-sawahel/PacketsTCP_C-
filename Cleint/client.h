#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <string>
#include <chrono>
#include <thread>
#include <functional>
#include "qcustomplot.h"

namespace Ui {
class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();
    void updateTable(char* packet, char* size);

private slots:
    void on_table_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_button_clicked();

    void setupGraph();

private:
    Ui::Client *ui;
    QTimer *timer;
};

#endif // CLIENT_H
