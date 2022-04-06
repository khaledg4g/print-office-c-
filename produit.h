#ifndef PRODUIT_H
#define PRODUIT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class Produit
{

public:

    Produit();
    Produit(int,QString,QString);

    int getMat();
    QString getnom();
    QString getdesc();

    void setNom(QString);
    void setDesc(QString);
    void setMat(int);

   bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * rechercher(QString a);
    QSqlQueryModel * trie_matricule();
    QSqlQueryModel * trie_nom();

private:
    QString nom,desc;
    int mat;
};

#endif // PRODUIT_H
