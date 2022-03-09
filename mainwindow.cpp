#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include<QMessageBox>
#include "connection.h"
#include<QIntValidator>
#include"employe.h"
#include"historique.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_id_2->setValidator(new QIntValidator(0, 9999999, this));

ui->tab_e->setModel(E.afficher());
ui->tab_e_2->setModel(h.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ajouter_clicked()
{

    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString fonction=ui->le_fonction->currentText();
    QString date_de_naissance=ui->la_date->text();
    Employe E(id,nom,prenom,fonction,date_de_naissance);
    bool test=E.ajouter();

if (test)
    {
        ui->tab_e->setModel(E.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout"),
                    QObject::tr("ajout avec succes .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("ajout"),
                    QObject::tr("insert failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}






void MainWindow::on_supprimer_clicked()
{

    Employe E1;E1.setid(ui->le_id_supp->text().toInt());
    bool test=E1.supprimer(E1.getid());
            QMessageBox msgBox;
    if(test){
        msgBox.setText("suppression avec succes,");
   ui->tab_e->setModel(E1.afficher());
}

    else
        msgBox.setText("Echec suppriession,");
    msgBox.exec();

      }







void MainWindow::on_modifier_clicked()
{

 int id=ui->le_id2->text().toInt();
 QString nom=ui->le_nom2->text();
 QString prenom=ui->le_prenom2->text();
 QString date_de_naissance=ui->la_date2->text();
 QString fonction=ui->le_fonction2->currentText();

 Employe E1(id,nom,prenom,fonction,date_de_naissance);
 //bool test= E.modifier(id,nom,prenom,fonction,date_naissance);

 bool test= E1.modifier( id , nom, prenom, fonction, date_de_naissance);
 if (test)

    {
     ui->tab_e->setModel(E.afficher());
     QMessageBox::information(nullptr, QObject::tr("MODIFIER"),
                                   QObject::tr("MODIFICATION avec succes .\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

     }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("MODIFIER"),
                                   QObject::tr("UPDATE failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_ajouter_pk_clicked()
{
    int id=ui->le_id_2->text().toInt();
    QString date_emb=ui->la_dateemb->text();
    QString date_fc=ui->la_datefc->text();

    historique h(id,date_emb,date_fc);
    bool test=h.ajouter_pk();

if (test)
    {
        ui->tab_e_2->setModel(h.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout"),
                    QObject::tr("ajout avec succes .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("ajout"),
                    QObject::tr("insert failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_modifier_pk_clicked()
{
    int id=ui->le_id3->text().toInt();
    QString date_emb=ui->la_dateemb2->text();
    QString date_fc=ui->la_datefc2->text();

    historique h1(id,date_emb,date_fc);


    bool test= h1.modifier_pk( id , date_emb, date_fc);
    if (test)

       {
        ui->tab_e_2->setModel(h.afficher());
        QMessageBox::information(nullptr, QObject::tr("MODIFIER"),
                                      QObject::tr("MODIFICATION avec succes .\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);

        }
                      else
                          QMessageBox::critical(nullptr, QObject::tr("MODIFIER"),
                                      QObject::tr("UPDATE failed.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_supprimer_pk_clicked()
{
   historique h1;h1.setid(ui->le_id_supp_2->text().toInt());
    bool test=h1.supprimer_pk(h1.getid());
            QMessageBox msgBox;
    if(test){
        msgBox.setText("suppression avec succes,");
   ui->tab_e_2->setModel(h1.afficher());
}

    else
        msgBox.setText("Echec suppression,");
    msgBox.exec();
}
