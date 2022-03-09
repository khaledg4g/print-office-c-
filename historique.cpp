#include "historique.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QString>
historique::historique()
{
id=0; date_emb=" "; date_fc=" ";

}
historique::historique(int id ,QString date_emb,QString date_fc)
{
    this->id=id; this->date_emb=date_emb;
    this->date_fc=date_fc;


}
int historique::getid()
{return id;}
QString historique::getdate_emb()
{return date_emb;}
QString historique::getdate_fc()
{return date_fc;}

void historique::setid(int id)
{this->id=id;}
void historique::setdate_emb(QString date_emb)
{this->date_emb=date_emb;}
void historique::setdate_fc(QString date_fc)
{this->date_fc=date_fc;}


bool historique::ajouter_pk()
{

    QSqlQuery query;
   QString id_string= QString::number(id);
         query.prepare("INSERT INTO HISTORIQUE (id, date_emb, date_fc) "
                       "VALUES (:id, :date_emb, :date_fc )");
         query.bindValue(":id", id_string);
         query.bindValue(":date_emb", date_emb);
         query.bindValue(":date_fc", date_fc);


        return query.exec();



}



QSqlQueryModel* historique::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();


          model->setQuery("SELECT * FROM HISTORIQUE");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_emb"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_fc"));


return model;}


bool historique::supprimer_pk(int id)
{
QSqlQuery query ;

query.prepare("Delete from HISTORIQUE where id= :id");
query.bindValue(":id",id);
return query.exec();
}

bool historique::modifier_pk(int id ,QString date_emb,QString date_fc )
 {
     QSqlQuery query ;
     QString id_string = QString::number(id);
     query.prepare("update HISTORIQUE set id= :id, date_emb=:date_emb,date_fc=:date_fc where id=:id");
     query.bindValue(":id", id_string);
     query.bindValue(":date_emb", date_emb);
     query.bindValue(":date_fc", date_fc);

     return query.exec();
}

