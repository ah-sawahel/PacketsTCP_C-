/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QWidget *centralWidget;
    QTableWidget *table;
    QCustomPlot *graph;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QStringLiteral("Client"));
        Client->resize(640, 403);
        centralWidget = new QWidget(Client);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        table = new QTableWidget(centralWidget);
        if (table->columnCount() < 2)
            table->setColumnCount(2);
        table->setObjectName(QStringLiteral("table"));
        table->setGeometry(QRect(440, 10, 181, 331));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(2);
        sizePolicy.setHeightForWidth(table->sizePolicy().hasHeightForWidth());
        table->setSizePolicy(sizePolicy);
        table->setMinimumSize(QSize(2, 0));
        table->setColumnCount(2);
        graph = new QCustomPlot(centralWidget);
        graph->setObjectName(QStringLiteral("graph"));
        graph->setGeometry(QRect(19, 29, 411, 261));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graph->sizePolicy().hasHeightForWidth());
        graph->setSizePolicy(sizePolicy1);
        Client->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Client);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 22));
        Client->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Client);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Client->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Client);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Client->setStatusBar(statusBar);

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QMainWindow *Client)
    {
        Client->setWindowTitle(QApplication::translate("Client", "Client", 0));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
