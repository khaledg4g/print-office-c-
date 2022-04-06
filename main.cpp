#include "mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QDebug>
#include "connection.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnect();
    MainWindow w;
    if (test)
    {
        w.show();
         QMessageBox::information(nullptr, QObject::tr("Database open"),
             QObject::tr("successful"));



    }
        else
        QMessageBox::critical(nullptr, QObject::tr("Database close"),
            QObject::tr("failed"));

    w.show();
    return a.exec();
}
