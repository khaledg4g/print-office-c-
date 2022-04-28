#include "login.h"
#include "ui_login.h"
#include <QtDebug>
#include <QObject>
#include <QMessageBox>
#include <QKeyEvent>
#include <QMainWindow>
login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
}

login::~login()
{
    delete ui;
}

void login::update_label()
{
    data=A.read_from_arduino();

        if(data=="1")

            ui->label_7->setText("Connected");


}

void login::on_pushButton_clicked()
{
     A.write_to_arduino("1");
}

void login::on_pushButton_2_clicked()
{

     A.write_to_arduino("0");
}


void login::on_pushButton_5_clicked()
{
    QString username = ui->lineEdit_username_2->text();
    QString password = ui->lineEdit_password_2->text();


    QSqlQuery qry;

    if(qry.exec("select * from EMPLOYE  where NOM='"+username+"' and PRENOM='"+password+"' "))
    {
     int count=0;
     while(qry.next())
     {count++;}

     if(count==1){
       A.write_to_arduino("2");
    QMessageBox::information(this, "login", "welcome "+username+"");

          dialog  = new Dialog();
           dialog -> show();
     }
    else if(count<1)
         A.write_to_arduino("3");
    QMessageBox::critical(this, "login", "incorrect password or username");

    }
}

void login::on_pushButton_6_clicked()
{
    A.write_to_arduino("1");
}

/*QString login::clavier()
{
    QString clv;

    data=A.read_from_arduino();

    if(data=="4")

    ui->lineEdit_username->setText("khaled");

return(data);
}*/

void login::update_label_cnx()
{


}
void login::on_pushButton_3_clicked()
{
 A.write_to_arduino("5");
            ui->lineEdit_username_2->setText("khaled");
}

void login::on_pushButton_4_clicked()
{
    A.write_to_arduino("6");
               ui->lineEdit_password_2->setText("123");
}
