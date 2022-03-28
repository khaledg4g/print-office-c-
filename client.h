#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QFrame>
#include <QtCharts/QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
class Client
{
public:
    //constructeurs
    Client();
    Client(int, QString, QString, int, QString, QDate);

    //getters
    int getcin();
    QString getnom();
    QString getprenom();
    int gettel();
    QString getregion();
    QDate getdate_ajout();

    //setters
    void setcin(int);
    void setnom(QString);
    void setprenom(QString);
    void settel(int n);
    void setregion(QString n);
    void setdate_ajout(QDate d);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * trie_nom();
    QSqlQueryModel * trie_cin();
    QSqlQueryModel * trie_region();
    QSqlQueryModel * trie_date_ajout();
    void statistique(QWidget * w);
    int notification();
private:
    int cin, tel;
    QString nom, prenom, region;
    QDate date_ajout;
};

#endif // CLIENT_H
