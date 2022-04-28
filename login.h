#ifndef LOGIN_H
#define LOGIN_H
#include "arduino.h"
#include "mainwindow.h"
#include <QMainWindow>
#include "mainwindow.h"
#include <QString>
#include "dialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();
private slots:
    void update_label_cnx();
    void update_label();    // slot permettant la mise à jour du label état du cnx,


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

     void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::login *ui;
    QByteArray data; // variable contenant les données reçues
   // mainwindow *MainMenuWin;
Dialog *dialog;
    QByteArray key;
       Arduino A; // objet temporaire
};
#endif // LOGIN_H
