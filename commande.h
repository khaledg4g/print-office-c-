#ifndef COMMANDE_H
#define COMMANDE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class commande
{
public:
    commande();
    commande(int, QString, QString, QString);
        commande(int);
        //getters
        int getid();
        QString getnom();
        QString getdescri();
        QString getdispo();

        //setters
        void setid(int);
        void setnom(QString);
        void setdescri(QString);
        void setdispo(QString n);

        bool ajouter();
        bool ajouterp();
        QSqlQueryModel * afficher();
        QSqlQueryModel * afficher_des();
        QSqlQueryModel * afficher_produit();
        bool supprimer(int);
        bool modifier();
        int export2Excel();
        QSqlQueryModel * trie_NOM();
    QSqlQueryModel* trier();
    bool recherche(int);
        QSqlQueryModel * rech(QString);
        bool recherchen(int);
       QSqlQueryModel * rechn(QString);
       bool recherchep(int);
      QSqlQueryModel * rechp(QString);
    private:
        int id;
        QString nom, descri, dispo;

};

#endif // COMMANDE_H
