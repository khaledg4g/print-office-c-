#include "fidelite.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
#include<QMessageBox>
Fidelite::Fidelite()
{
    cinf=0; nom=""; prenom="" ;
    tel=0; region="";
    nb_commande=0;
}

Fidelite::Fidelite(int cinf, QString nom, QString prenom, int tel, QString region, int nb_commande)
{this->cinf=cinf; this->nom=nom; this->prenom=prenom; this->tel=tel; this->region=region; this->nb_commande=nb_commande;}
int Fidelite:: getcinf() {return cinf;}
QString Fidelite::getnom() {return nom;}
QString Fidelite::getprenom(){return prenom;}
int Fidelite:: gettel() {return tel;}
QString Fidelite::getregion() {return region;}
int Fidelite:: getnbcommande() {return nb_commande;}
void Fidelite::setcinf (int cinf) {this->cinf=cinf;}
void Fidelite::setnom (QString nom) {this->nom=nom;}
void Fidelite::setprenom(QString prenom) {this->prenom=prenom;}
void Fidelite::settel (int tel) {this->tel=tel;}
void Fidelite::setregion (QString region) {this->region=region;}
void Fidelite::setnbcommande (int nb_commande) {this->nb_commande=nb_commande;}



bool Fidelite::ajouter()
{
    QSqlQuery query;
    QString cinf_string= QString::number (cinf) ;
    QString tel_string= QString::number (tel) ;
    QString nb_commande_string= QString::number (nb_commande) ;
    query.prepare ("INSERT INTO fidelite (cinf, nom, prenom, tel, region, nb_commande) "
                   "VALUES (:cinf, :nom, :prenom, :tel, :region, :nb_commande)");
    query.bindValue(0,cinf_string);
    query.bindValue(1,nom);
    query.bindValue(2,prenom);
    query.bindValue(3,tel_string);
    query.bindValue(4,region);
    query.bindValue(5,nb_commande_string);
    return query.exec () ;

}
QSqlQueryModel *Fidelite::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM fidelite");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cinf"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("region"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("nb_commande"));

    return model;
}

bool Fidelite::supprimer(int cinf)
{
    QSqlQuery query;
      QString res =QString::number(cinf);
    query.prepare(" Delete from fidelite where cinf=:cinf");
    query.bindValue(":cinf", res);

  return  query.exec();
}

bool Fidelite::modifier()
{
QSqlQuery query;
QString res= QString::number(cinf);
query.prepare("update fidelite set cinf= :cinf, nom= :nom, prenom= :prenom, tel= :tel, region= :region, nb_commande= :nb_commande where cinf = :cinf ");
query.bindValue(":cinf", res);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom );
query.bindValue(":tel",tel);
query.bindValue(":region",region);
query.bindValue(":nb_commande",nb_commande);
return    query.exec();
}


