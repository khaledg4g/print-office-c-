#include "mail.h"
#include <QSqlQuery>
#include <QDebug>
Mail::Mail()
{
    nom=" "; mail="";
}

Mail::Mail(QString nom,QString mail)
{this->nom=nom; this->mail=mail;}
QString Mail::getnom(){return nom;}
QString Mail::getmail(){return mail;}


void Mail::setnom(QString nom){this->nom=nom;}
void Mail::setmail(QString mail){this->mail=mail;}
bool Mail::ajouter()
{
    QSqlQuery query;
          query.prepare("INSERT INTO mail (NOM, MAIL) "
                        "VALUES (:nom, :mail)");
          query.bindValue(0, nom);
          query.bindValue(1, mail);
          return query.exec();
}
QSqlQueryModel * Mail::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM mail");
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("mail"));

    return model;
}







/*bool Mail::supprimer(string nomsupp)
{
    QSqlQuery query;
      QString res =QString::number(mat);
    query.prepare(" Delete from mail where nom=:nom");
    query.bindValue(":nom", res);

  return  query.exec();
}




QSqlQueryModel * Mail::trier_mail()

{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM mail ORDER BY nom ");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("maila"));
    return model;

}*/
