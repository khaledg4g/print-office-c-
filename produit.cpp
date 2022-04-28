#include "produit.h"
#include <QSqlQuery>
#include <QDebug>
Produit::Produit()
{
    mat=0; nom=" "; desc="";
}

Produit::Produit(int mat,QString nom,QString desc)
{this->mat=mat; this->nom=nom; this->desc=desc;}
int Produit::getMat(){return mat;}
QString Produit::getnom(){return nom;}
QString Produit::getdesc(){return desc;}


void Produit::setMat(int mat){this->mat=mat;}
void Produit::setNom(QString nom){this->nom=nom;}
void Produit::setDesc(QString desc){this->desc=desc;}
bool Produit::ajouter()
{
    QSqlQuery query;
    QString mat_string= QString::number(mat);
          query.prepare("INSERT INTO produit (MAT, NOM, DESCR) "
                        "VALUES (:mat, :nom, :desc)");
          query.bindValue(0, mat_string);
          query.bindValue(1, nom);
          query.bindValue(2, desc);
          return query.exec();
}
QSqlQueryModel * Produit::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM produit");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("mat"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("desc"));

    return model;
}
bool Produit::supprimer(int mat)
{
    QSqlQuery query;
      QString res =QString::number(mat);
    query.prepare(" Delete from produit where mat=:mat");
    query.bindValue(":mat", res);

  return  query.exec();
}


bool Produit::modifier()
{
QSqlQuery query;
QString res= QString::number(mat);
query.prepare("update produit set mat= :mat, nom= :nom, desc= :desc where mat=:mat ");
query.bindValue(":mat", res);
query.bindValue(":nom",nom);
query.bindValue(":desc",desc );

return    query.exec();
}

QSqlQueryModel* Produit ::rechercher(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from produit where mat ='"+a+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("mat"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("desc"));

        return model;

}

QSqlQueryModel * Produit::trie_matricule()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM produit ORDER BY mat ");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("mat"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("desc"));
    return model;
}

QSqlQueryModel * Produit::trie_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM produit ORDER BY nom ");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("mat"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("desc"));
    return model;
}









