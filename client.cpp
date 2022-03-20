#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
#include<QMessageBox>

Client::Client()
{
    cin=0; nom=""; prenom="" ;
    tel=0; region="";
}
Client::Client(int cin, QString nom, QString prenom, int tel, QString region)
{this->cin=cin; this->nom=nom; this->prenom=prenom; this->tel=tel; this->region=region;}
int Client:: getcin() {return cin;}
QString Client::getnom() {return nom;}
QString Client::getprenom(){return prenom;}
int Client:: gettel() {return tel;}
QString Client::getregion() {return region;}
void Client::setcin (int cin) {this->cin=cin;}
void Client::setnom (QString nom) {this->nom=nom;}
void Client::setprenom(QString prenom) {this->prenom=prenom;}
void Client::settel (int tel) {this->tel=tel;}
void Client::setregion (QString region) {this->region=region;}


bool Client::ajouter()
{
    QSqlQuery query;
    QString cin_string= QString::number (cin) ;
    QString tel_string= QString::number (tel) ;
    query.prepare ("INSERT INTO client (cin, nom, prenom, tel, region) "
                   "VALUES (:cin, :nom, :prenom, :tel, :region)");
    query.bindValue(0,cin_string);
    query.bindValue(1,nom);
    query.bindValue(2,prenom);
    query.bindValue(3,tel_string);
    query.bindValue(4,region);
    return query.exec () ;

}
QSqlQueryModel * Client::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM client");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("region"));

    return model;
}




bool Client::supprimer(int cin)
{
    QSqlQuery query;
      QString res =QString::number(cin);
    query.prepare(" Delete from client where cin=:cin");
    query.bindValue(":cin", res);

  return  query.exec();
}


bool Client::modifier()
{
QSqlQuery query;
QString res= QString::number(cin);
query.prepare("update Client set cin= :cin, nom= :nom, prenom= :prenom, tel= :tel, region= :region where cin = :cin ");
query.bindValue(":cin", res);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom );
query.bindValue(":tel",tel);
query.bindValue(":region",region);
return    query.exec();
}


QSqlQueryModel * Client::trie_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM client ORDER BY nom ");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("numero de telephone"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("region"));
    return model;
}

QSqlQueryModel * Client::trie_cin()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM client ORDER BY cin ");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("numero de telephone"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("region"));
    return model;
}
QSqlQueryModel * Client::trie_region()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM client ORDER BY region ");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("numero de telephone"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("region"));
    return model;
}
