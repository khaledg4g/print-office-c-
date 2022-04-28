#include "employe.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QString>
#include<QSqlQueryModel>
#include<QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

Employe::Employe()
{
id=0; nom=" "; prenom=" ";fonction="";
date_de_naissance=" ";

}
Employe::Employe(int id ,QString nom,QString prenom,QString fonction,QString date_de_naissance)
{
    this->id=id; this->nom=nom; this->prenom=prenom;
   this->fonction=fonction; this->date_de_naissance=date_de_naissance;


}
int Employe::getid()
{return id;}
QString Employe::getnom()
{return nom;}
QString Employe::getprenom()
{return prenom;}
QString Employe::getfonction()
{return fonction;}
QString Employe::getdate_de_naissance()
{return date_de_naissance;}

void Employe::setid(int id)
{this->id=id;}
void Employe::setnom(QString nom)
{this->nom=nom;}
void Employe::setprenom(QString prenom)
{this->prenom=prenom;}
void Employe::setfonction(QString fonction)
{this->fonction=fonction;}
void Employe::setdate_de_naissance(QString date_de_naissance)
{this->date_de_naissance=date_de_naissance;}


bool Employe::ajouter()
{

    QSqlQuery query;
   QString id_string= QString::number(id);
         query.prepare("INSERT INTO EMPLOYE (id, nom, prenom ,fonction,date_de_naissance) "
                       "VALUES (:id, :nom, :prenom,:fonction, :date_de_naissance )");
         query.bindValue(":id", id_string);
         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":fonction", fonction);
          query.bindValue(":date_de_naissance", date_de_naissance);


        return query.exec();



}



QSqlQueryModel* Employe::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();


          model->setQuery("SELECT * FROM Employe");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("fonction"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_de_naissance"));

return model;}


bool Employe::supprimer(int id)
{
QSqlQuery query ;

query.prepare("Delete from Employe where id= :id");
query.bindValue(":id",id);
return query.exec();
}

bool Employe::modifier(int id ,QString nom,QString prenom,QString fonction,QString date_de_naissance )
 {
     QSqlQuery query ;
     QString id_string = QString::number(id);
     query.prepare("update EMPLOYE set id= :id, nom=:nom,prenom=:prenom,fonction=:fonction,date_de_naissance=:date_de_naissance where id=:id");
     query.bindValue(":id",id_string);
     query.bindValue(":nom",nom);
     query.bindValue(":prenom",prenom);
     query.bindValue(":fonction",fonction);
     query.bindValue(":date_de_naissance",date_de_naissance);
     return query.exec();
}

//////tri age//////////

QSqlQueryModel* Employe::triparAge()
  {
  QSqlQuery * q = new  QSqlQuery ();
                   QSqlQueryModel * model = new  QSqlQueryModel ();
                   q->prepare("SELECT * FROM EMPLOYE order by date_de_naissance ASC");
                   q->exec();
                   model->setQuery(*q);
                   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
                   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
                   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
                   model->setHeaderData(3, Qt::Horizontal, QObject::tr("fonction"));
                   model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_de_naissance"));
                   return model;


  }

////////////// recherche nom////////////////

bool Employe::recherche(int x)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Employe WHERE id=:id; ");
    query.bindValue(":id",x);

    return query.exec();
}
QSqlQueryModel * Employe::rech(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT * FROM Employe WHERE id = '"+a+"'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("fonction"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_de_naissance"));
        return model;


}
bool Employe::recherchen(int x)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Employe WHERE nom=:nom;");
    query.bindValue(":nom",x);

    return query.exec();
}
QSqlQueryModel * Employe::rechn(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT * FROM Employe WHERE nom = '"+a+"'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("fonction"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_de_naissance"));
        return model;


}
bool Employe::recherchep(int x)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Employe WHERE prenom=:prenom;");
    query.bindValue(":prenom",x);

    return query.exec();
}
QSqlQueryModel * Employe::rechp(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT * FROM Employe WHERE prenom = '"+a+"'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("fonction"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_de_naissance"));
        return model;


}



    void Employe::statistique(QWidget * w)
    {
            int nbm = 0,nbsr=0,nbr =0,nb =0;

                QSqlQuery query("SELECT COUNT(*) FROM Employe WHERE fonction='Technicien'");
                while(query.next())
                {
                    nbm = query.value(0).toInt();
                }
                QSqlQuery query2("SELECT COUNT(*) FROM Employe WHERE fonction='Ingenieur'");
                while(query2.next())
                {
                   nbsr= query2.value(0).toInt();
                }
                QSqlQuery query3("SELECT COUNT(*) FROM Employe WHERE fonction='PDG'");
                while(query3.next())
                {
                   nbr= query3.value(0).toInt();
                }
                QSqlQuery query4("SELECT COUNT(*) FROM Employe WHERE fonction='Sec'");
                while(query4.next())
                {
                   nb= query4.value(0).toInt();
                }
            QPieSeries *series = new QPieSeries();

            series->append("Technicien",nbm);
            series->append("Ingenieur",nbsr);
    series->append("PDG",nbr);
    series->append("Sec",nb);
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
            M->setBrush(QColor::fromRgb(85, 31, 31));
            SR->setBrush(QColor::fromRgb(205, 0, 0));
    R->setBrush(QColor::fromRgb(160, 205, 120));
    n->setBrush(QColor::fromRgb(100, 100, 20));
            QChart *chart = new QChart();
            chart->addSeries(series);
            chart->setTitle("statistique des employes par poste");
            chart->legend()->setVisible(true);
            chart->legend()->setAlignment(Qt::AlignBottom);
            chart->setAnimationOptions(QChart::AllAnimations);

            QChartView * chartview = new QChartView(chart);
            chartview->resize(w->width(),w->height());
            chartview->setParent(w);


    }
