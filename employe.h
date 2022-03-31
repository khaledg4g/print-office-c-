#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QtCharts/QPieSeries>
#include <QtCharts/QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QFrame>
#include <QtCharts/QtCharts>
#include <QtCharts/QChartView>


class Employe
{
public:
    Employe();
    Employe(int,QString,QString,QString,QString);
    int getid();
    QString getnom();
    QString getprenom();
    QString getfonction();
    QString getdate_de_naissance();


    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setdate_de_naissance(QString);
    void setfonction(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
     bool supprimer(int);
     bool modifier(int ,QString,QString,QString,QString);
     QSqlQueryModel* triparAge();


     bool recherche(int);
    QSqlQueryModel * rech(QString);
    bool recherchen(int);
   QSqlQueryModel * rechn(QString);
   bool recherchep(int);
  QSqlQueryModel * rechp(QString);


               void statistique(QWidget * w);
private:
    int id;
    QString nom, prenom , fonction, date_de_naissance ;
};

#endif // EMPLOYE_H
