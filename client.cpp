#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
#include<QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

Client::Client()
{
    cin=0; nom=""; prenom="" ;
    tel=0; region="";
}
Client::Client(int cin, QString nom, QString prenom, int tel, QString region, QDate date_ajout)
{this->cin=cin; this->nom=nom; this->prenom=prenom; this->tel=tel; this->region=region; this->date_ajout=date_ajout;}
int Client:: getcin() {return cin;}
QString Client::getnom() {return nom;}
QString Client::getprenom(){return prenom;}
int Client:: gettel() {return tel;}
QString Client::getregion() {return region;}
QDate Client::getdate_ajout() {return date_ajout;}
void Client::setcin (int cin) {this->cin=cin;}
void Client::setnom (QString nom) {this->nom=nom;}
void Client::setprenom(QString prenom) {this->prenom=prenom;}
void Client::settel (int tel) {this->tel=tel;}
void Client::setregion (QString region) {this->region=region;}
void Client::setdate_ajout (QDate date_ajout) {this->date_ajout=date_ajout;}


bool Client::ajouter()
{
    QSqlQuery query;
    QString cin_string= QString::number (cin) ;
    QString tel_string= QString::number (tel) ;
    query.prepare ("INSERT INTO client (cin, nom, prenom, tel, region, date_ajout) "
                   "VALUES (:cin, :nom, :prenom, :tel, :region, :date_ajout)");
    query.bindValue(0,cin_string);
    query.bindValue(1,nom);
    query.bindValue(2,prenom);
    query.bindValue(3,tel_string);
    query.bindValue(4,region);
    query.bindValue(5,date_ajout);
    return query.exec () ;

}
QSqlQueryModel * Client::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM client");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("region"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("date d'ajout"));

    return model;
}




bool Client::supprimer(int cin)
{
    QSqlQuery query;
      QString res =QString::number(cin);
    query.prepare(" Delete from client where cin=:cin");
    query.bindValue(":cin", res);

  return  query.exec();
}


bool Client::modifier()
{
QSqlQuery query;
QString res= QString::number(cin);
query.prepare("update Client set cin= :cin, nom= :nom, prenom= :prenom, tel= :tel, region= :region, date_ajout= :date_ajout where cin = :cin ");
query.bindValue(":cin", res);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom );
query.bindValue(":tel",tel);
query.bindValue(":region",region);
query.bindValue(":date_ajout",date_ajout);
return    query.exec();
}


QSqlQueryModel * Client::trie_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM client ORDER BY nom ");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("numero de telephone"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("region"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("date_ajout"));
    return model;
}

QSqlQueryModel * Client::trie_cin()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM client ORDER BY cin ");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("numero de telephone"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("region"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("date_ajout"));
    return model;
}
QSqlQueryModel * Client::trie_region()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM client ORDER BY region ");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("numero de telephone"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("region"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("date_ajout"));
    return model;
}
QSqlQueryModel * Client::trie_date_ajout()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM client ORDER BY date_ajout ");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("numero de telephone"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("region"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("date_ajout"));
    return model;
}

void Client::statistique(QWidget * w)
{
        int nbm = 0,nbsr=0,nbr =0,nb =0;
            QSqlQuery query("SELECT COUNT(*) FROM client WHERE region='tunis'");
            while(query.next())
            {
                nbm = query.value(0).toInt();
            }
            QSqlQuery query2("SELECT COUNT(*) FROM client WHERE region='sfax'");
            while(query2.next())
            {
               nbsr= query2.value(0).toInt();
            }
            QSqlQuery query3("SELECT COUNT(*) FROM client WHERE region='sousse'");
            while(query3.next())
            {
               nbr= query3.value(0).toInt();
            }
            QSqlQuery query4("SELECT COUNT(*) FROM client WHERE region='nabeul'");
            while(query4.next())
            {
               nb= query4.value(0).toInt();
            }
        QPieSeries *series = new QPieSeries();

        series->append("tunis",nbm);
        series->append("sfax",nbsr);
series->append("sousse",nbr);
series->append("nabeul",nb);
        series->setHoleSize(0.0);
        series->setPieSize(1.0);
        series->setPieSize(2.0);
 series->setPieSize(3.0);
        QPieSlice * M = series->slices().at(0);
        QPieSlice * SR = series->slices().at(1);
QPieSlice * R = series->slices().at(2);
QPieSlice * n = series->slices().at(3);
        M->setLabelVisible(true);
        SR->setLabelVisible(true);
R->setLabelVisible(true);
n->setLabelVisible(true);
        M->setBrush(QColor::fromRgb(255, 125, 127));
        SR->setBrush(QColor::fromRgb(100, 0, 100));
R->setBrush(QColor::fromRgb(160, 205, 120));
n->setBrush(QColor::fromRgb(240, 100, 20));
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Statistiques des clients par region");
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
        chart->setAnimationOptions(QChart::AllAnimations);

        QChartView * chartview = new QChartView(chart);
        chartview->resize(w->width(),w->height());
        chartview->setParent(w);


}

int Client::notification()
{
    int i=0;
    QSqlQuery query("SELECT date_ajout FROM client");
    while (query.next())
    {
        QDate date=query.value(0).toDate();
        if (date.addDays(7)<QDate::currentDate())
        {
            i++;
        }

    }
    return i;
}
