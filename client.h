#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Client
{
public:
    //constructeurs
    Client();
    Client(int, QString, QString, int, QString);

    //getters
    int getcin();
    QString getnom();
    QString getprenom();
    int gettel();
    QString getregion();

    //setters
    void setcin(int);
    void setnom(QString);
    void setprenom(QString);
    void settel(int n);
    void setregion(QString n);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * trie_nom();
    QSqlQueryModel * trie_cin();
    QSqlQueryModel * trie_region();
private:
    int cin, tel;
    QString nom, prenom, region;
};

#endif // CLIENT_H
