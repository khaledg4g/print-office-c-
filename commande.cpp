#include "commande.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
#include<QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include<QMessageBox>
#include "connection.h"
#include<QIntValidator>
#include<QPainter>
#include<QtPrintSupport/QPrinter>
#include "QFileDialog"
#include "QTextStream"
#include<QtPrintSupport/QPrintDialog>
#include <QTextDocument>
#include <QMessageBox>
#include "QFileDialog"
#include <QTextStream>
#include <QApplication>
#include <QFileDialog>
#include <QSqlQuery>
#include <QVariant>
commande::commande()
{
    id=0; nom=""; descri="" ;
      dispo="";
}
commande::commande(int id, QString nom, QString descri, QString dispo)
{this->id=id; this->nom=nom; this->descri=descri;  this->dispo=dispo;}
int commande:: getid() {return id;}
QString commande::getnom() {return nom;}
QString commande::getdescri(){return descri;}
QString commande::getdispo() {return dispo;}
void commande::setid (int id) {this->id=id;}
void commande::setnom (QString nom) {this->nom=nom;}
void commande::setdescri(QString descri) {this->descri=descri;}
void commande::setdispo (QString dispo) {this->dispo=dispo;}

bool commande::ajouter()


{
    QSqlQuery query;
    QString id_string= QString::number (id) ;
    query.prepare ("INSERT INTO COMMANDE (id, nom, descri, dispo) "
                   "VALUES (:id, :nom, :descri, :dispo)");
    query.bindValue(0,id_string);
    query.bindValue(1,nom);
    query.bindValue(2,descri);
    query.bindValue(3,dispo);
    return query.exec () ;

}
QSqlQueryModel * commande::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM COMMANDE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("descri"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("dispo"));

    return model;
}

QSqlQueryModel * commande::afficher_produit()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM PRODUIT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("mat"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_produit"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("description"));


    return model;
}


bool commande::supprimer(int id)
{
    QSqlQuery query;
      QString res =QString::number(id);
    query.prepare(" Delete from Commande where id=:id");
    query.bindValue(":id", res);

  return  query.exec();
}


bool commande::modifier()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("update Commande set id= :id, nom= :nom, descri= :descri,  dispo= :dispo where id = :id ");
query.bindValue(":id", res);
query.bindValue(":nom",nom);
query.bindValue(":descri",descri );
query.bindValue(":dispo",dispo);
return    query.exec();
}


QSqlQueryModel * commande::trie_NOM()
{
    QSqlQuery query;
    QString nom_string= QString::number (id) ;
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM Commande ORDER BY id ");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("descri"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("dispo"));
    return model;
}

QSqlQueryModel *commande::trier()
{

    QSqlQuery *q = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel();
    q->prepare("SELECT * FROM  Commande ORDER BY ID ");
    q->exec();
    model->setQuery(*q);
    return model;
}

bool commande::recherche(int x)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Commande WHERE id=:id; ");
    query.bindValue(":id",x);

    return query.exec();
}
QSqlQueryModel * commande::rech(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT * FROM Commande WHERE id = '"+a+"'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("descri"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("dispo"));
        return model;


}
bool commande::recherchen(int x)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM commande WHERE nom=:nom;");
    query.bindValue(":nom",x);

    return query.exec();
}
QSqlQueryModel * commande::rechn(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT * FROM commande WHERE nom = '"+a+"'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("descri"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("dispo"));
        return model;


}
QSqlQueryModel * commande::afficher_des()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM COMMANDE where dispo ='o' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("descri"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("dispo"));

    return model;
}

bool commande::ajouterp()
{
    QSqlQuery query;
    QString id_string= QString::number (id) ;
    query.prepare ("INSERT INTO COMMANDE SELECT MAT,NOM,DESCR FROM PRODUIT ");

    query.bindValue(0,id_string);

    return query.exec () ;

}
