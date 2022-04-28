#include "mainwindow.h"
#include "mainwindowp.h"
#include "dialog.h"
#include "login.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include<QDebug>
#include<QFile>
#include <QtWidgets/QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //set the app style sheet
    QFile styleSheetFile("C:/Users/Asus/Pictures/Saved Pictures/integration/Chatbee.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);
    Connection c;
    bool test=c.createconnect();
    //MainWindow w;
    login l;
    l.show();
    Dialog x;
    if(test)
    /*{w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);*/



    return a.exec();
}
