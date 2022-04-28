#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include<QSqlQuery>
#include <QSqlQueryModel>
#include <QtCharts/QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
class table1
{
public:
    table1();
    table1(int,QString,int);
    int getID();
    QString getPRODUIT();
    int getTARIF();
    void setID(int);
    void setPRODUIT(QString);
    void setTARIF(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
     QSqlQueryModel* trier();
     QSqlQueryModel *recherche(QString);
     bool exporter();
    // void exportFichier(QString);
     void statistique(QWidget * w);
private:
    int ID;
    QString PRODUIT;
    int TARIF;
};
#endif // TABLE1_H
