#include "mail.h"
#include <QSqlQuery>
#include <QDebug>
Mail::Mail()
{
    nom=" "; mail="";
}

Mail::Mail(int id, QString nom,QString mail)
{this->id=id; this->nom=nom; this->mail=mail;}
int Mail::getid(){return id;}
QString Mail::getnom(){return nom;}
QString Mail::getmail(){return mail;}

void Mail::setid(int id){this->id=id;}
void Mail::setnom(QString nom){this->nom=nom;}
void Mail::setmail(QString mail){this->mail=mail;}
bool Mail::ajouter()
{
    QSqlQuery query;
    QString id_string= QString::number(id);
          query.prepare("INSERT INTO mail (id,nom, mail) "
                        "VALUES (:id, :nom, :mail)");
          query.bindValue(0, id);
          query.bindValue(1, nom);
          query.bindValue(2, mail);
          return query.exec();
}
QSqlQueryModel * Mail::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM mail");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("mail"));

    return model;
}

bool Mail::supprimer(int id)
{
    QSqlQuery query;
      QString res =QString::number(id);
    query.prepare(" Delete from mail where id=:id");
    query.bindValue(":id", res);

  return  query.exec();
}
