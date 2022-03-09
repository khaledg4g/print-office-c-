#include "employe.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QString>
Employe::Employe()
{
id=0; nom=" "; prenom=" "; date_de_naissance=" ";
 fonction="";
}
Employe::Employe(int id ,QString nom,QString prenom,QString date_de_naissance,QString fonction)
{
    this->id=id; this->nom=nom; this->prenom=prenom;
    this->date_de_naissance=date_de_naissance; this->fonction=fonction;


}
int Employe::getid()
{return id;}
QString Employe::getnom()
{return nom;}
QString Employe::getprenom()
{return prenom;}
QString Employe::getdate_de_naissance()
{return date_de_naissance;}
QString Employe::getfonction()
{return fonction;}
void Employe::setid(int id)
{this->id=id;}
void Employe::setnom(QString nom)
{this->nom=nom;}
void Employe::setprenom(QString prenom)
{this->prenom=prenom;}
void Employe::setdate_de_naissance(QString date_de_naissance)
{this->date_de_naissance=date_de_naissance;}
void Employe::setfonction(QString fonction)
{this->fonction=fonction;}

bool Employe::ajouter()
{

    QSqlQuery query;
   QString id_string= QString::number(id);
         query.prepare("INSERT INTO EMPLOYE (id, nom, prenom ,fonction,date_de_naissance) "
                       "VALUES (:id, :nom, :prenom,:fonction, :date_de_naissance )");
         query.bindValue(":id", id_string);
         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":fonction", fonction);
          query.bindValue(":date_de_naissance", date_de_naissance);


        return query.exec();



}



QSqlQueryModel* Employe::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();


          model->setQuery("SELECT * FROM Employe");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("fonction"));


            model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_de_naissance"));

return model;}


bool Employe::supprimer(int id)
{
QSqlQuery query ;

query.prepare("Delete from Employe where id= :id");
query.bindValue(":id",id);
return query.exec();
}

bool Employe::modifier(int id ,QString nom,QString prenom,QString fonction,QString date_de_naissance )
 {
     QSqlQuery query ;
     QString id_string = QString::number(id);
     query.prepare("update EMPLOYE set id= :id, nom=:nom,prenom=:prenom,fonction=:fonction,date_de_naissance=:date_de_naissance where id=:id");
     query.bindValue(":id",id_string);
     query.bindValue(":nom",nom);
     query.bindValue(":prenom",prenom);
     query.bindValue(":fonction",fonction);
     query.bindValue(":date_de_naissance",date_de_naissance);
     return query.exec();
}

