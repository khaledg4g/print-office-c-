#ifndef FIDELITE_H
#define FIDELITE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Fidelite
{
public:
    //constructeurs
    Fidelite();
    Fidelite(int, QString, QString, int, QString, int);

    //getters
    int getcinf();
    QString getnom();
    QString getprenom();
    int gettel();
    QString getregion();
    int getnbcommande();

    //setters
    void setcinf(int);
    void setnom(QString);
    void setprenom(QString);
    void settel(int n);
    void setregion(QString n);
    void setnbcommande(int);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * trie_nom();
    QSqlQueryModel * trie_cin();
    QSqlQueryModel * trie_region();
private:
    int cinf, tel, nb_commande;
    QString nom, prenom, region;
};

#endif // FIDELITE_H
