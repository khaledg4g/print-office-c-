#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "connection.h"
#include "fidelite.h"
#include <QApplication>
#include <QMessageBox>
#include <QString>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_cin->setValidator(new QIntValidator(0, 99999999, this));
    ui->le_cin_supp->setValidator(new QIntValidator(0,99999999,this));
    //ui->le_tel->setValidator(new QIntValidator(0, 99999999, this));
    //ui->lineEdit_tel_2->setValidator(new QIntValidator(0,99999999,this));
    ui->tab_client->setModel(C.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int cin=ui->le_cin->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    int tel=ui->le_tel->text().toInt();
    //QString region=ui->le_region->text();
    QString region=ui->le_region->currentText();
    Client C(cin,nom,prenom,tel,region);

    bool test=C.ajouter();
    if (test)
    {
        //actualiser pour l'affichage
        ui->tab_client->setModel(C.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK") , QObject::tr("Ajout effectué\n"
                                                                     "Click Cancel to exit"), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"), QObject::tr("Ajout non effectué\n"
                                                                           "Click Cancel to exit"), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_supprimer_clicked()
{

    Client C;
    int cin =ui->le_cin_supp->text().toInt();
    bool test=C.supprimer(cin);
            QMessageBox msgBox;

        if(test){
            //actualiser pour l'affichage
            ui->tab_client->setModel(C.afficher());
                 msgBox.setText("suppression reussite");
                    ui->tab_client->setModel(C.afficher());
                }
                else
                    msgBox.setText("echec de suppression");
                    msgBox.exec();

}

void MainWindow::on_pushButton_update_clicked()
{
    int cin=ui->lineEdit_cin_2->text().toInt();

    QString nom=ui->lineEdit_nom_2->text();

    QString prenom=ui->lineEdit_prenom_2->text();

    int tel=ui->lineEdit_tel_2->text().toInt();

   //QString region=ui->lineEdit_region_2->text();
   QString region=ui->lineEdit_region_2->currentText();

    Client C1(cin,nom,prenom,tel,region);

    bool test=C1.modifier();
    if(test)
    {
        //actualiser pour l'affichage
        ui->tab_client->setModel(C.afficher());
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("modification effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("modification non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_trie_clicked()
{
    Client C;
        QString choix=ui->comboBox_trid->currentText();
        if (choix=="nom")
        {
            ui->tab_client->setModel(C.trie_nom());
            ui->tab_client->setModel(C.afficher());
            bool test=C.trie_nom();
            if (test)
            {

        ui->tab_client->setModel(C.trie_nom());
                QMessageBox::information(nullptr,QObject::tr("ok"),
                                         QObject::tr("tri nom effectué \n"
                                                     "Click Cancel to exist ."),QMessageBox::Cancel);

            }
            else
                  QMessageBox::critical(nullptr, QObject::tr("erreur"),
                              QObject::tr("tri  failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        if (choix=="region")
        {
            ui->tab_client->setModel(C.trie_region());
            ui->tab_client->setModel(C.afficher());
            bool test=C.trie_region();
            if (test)
            {

        ui->tab_client->setModel(C.trie_region());
                QMessageBox::information(nullptr,QObject::tr("ok"),
                                         QObject::tr("tri region effectué \n"
                                                     "Click Cancel to exist ."),QMessageBox::Cancel);

            }
            else
                  QMessageBox::critical(nullptr, QObject::tr("erreur"),
                              QObject::tr("tri  failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        if (choix=="cin")
        {
            ui->tab_client->setModel(C.trie_cin());
            ui->tab_client->setModel(C.afficher());
            bool test=C.trie_cin();//tri produit
            if (test)
            {

        ui->tab_client->setModel(C.trie_cin());
                QMessageBox::information(nullptr,QObject::tr("ok"),
                                         QObject::tr("tri cin effectué \n"
                                                     "Click Cancel to exist ."),QMessageBox::Cancel);

            }
            else
                  QMessageBox::critical(nullptr, QObject::tr("erreur"),
                              QObject::tr("tri  failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void MainWindow::on_pb_ajouterf_clicked()
{
    int cinf=ui->le_cinf->text().toInt();
    QString nom=ui->le_nomf->text();
    QString prenom=ui->le_prenomf->text();
    int tel=ui->le_tel->text().toInt();
    //QString region=ui->le_regionf->text();
    QString region=ui->le_regionf->currentText();
    int nb_commande=ui->le_nbcf->text().toInt();
    Fidelite F(cinf,nom,prenom,tel,region,nb_commande);

    bool test=F.ajouter();
    if (test)
    {
        //actualiser pour l'affichage
        ui->tab_fidelite->setModel(F.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK") , QObject::tr("Ajout effectué\n"
                                                                     "Click Cancel to exit"), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"), QObject::tr("Ajout non effectué\n"
                                                                           "Click Cancel to exit"), QMessageBox::Cancel);
}
void MainWindow::on_supprimerf_clicked()
{
    Fidelite F1;F1.setcinf(ui->le_cin_suppf->text().toInt());
        bool test=F1.supprimer(F1.getcinf());
                QMessageBox msgBox;
        if(test){
            msgBox.setText("suppression avec succes,");
       ui->tab_fidelite->setModel(F1.afficher());
    }

        else
            msgBox.setText("Echec suppression,");
        msgBox.exec();
}


void MainWindow::on_pushButton_updatef_clicked()
{
    int cinf=ui->le_cinf_2->text().toInt();

    QString nom=ui->le_nomf_2->text();

    QString prenom=ui->le_prenomf_2->text();

    int tel=ui->le_telf_2->text().toInt();

   //QString region=ui->lineEdit_region_2->text();
   QString region=ui->le_regionf_2->currentText();
   int nb_commande=ui->le_nbcf_2->text().toInt();

    Fidelite F1(cinf,nom,prenom,tel,region,nb_commande);

    bool test=F1.modifier();
    if(test)
    {
        //actualiser pour l'affichage
        ui->tab_fidelite->setModel(F.afficher());
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("modification effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("modification non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


