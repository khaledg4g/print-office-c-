#include "fournisseur.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
#include<QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QtCharts/QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
table1::table1()
{
    ID=0;PRODUIT=""; TARIF=0;
}

table1::table1(int ID,QString PRODUIT,int TARIF)
{this->ID=ID; this->PRODUIT=PRODUIT; this->TARIF=TARIF;}
int table1:: getID(){return ID;}

QString table1:: getPRODUIT(){return PRODUIT;}
int table1::getTARIF(){return TARIF;}
void table1::setID(int ID) {this->ID=ID;}
void table1:: setPRODUIT(QString PRODUIT){this->PRODUIT=PRODUIT;}
void table1::setTARIF(int TARIF){this->TARIF=TARIF;}
bool table1::ajouter()
{
    QSqlQuery query;
    QString ID_string= QString::number(ID);
     QString TARIF_string= QString::number(TARIF);
          query.prepare("INSERT INTO fournisseur (ID, PRODUIT, TARIF )"
                        "VALUES (:id, :forename, :surname)");
          query.bindValue(0, ID_string);
          query.bindValue(1, PRODUIT);
          query.bindValue(2, TARIF_string);
          return query.exec();

}
bool table1::supprimer(int ID)
{
    QSqlQuery query;
    query.prepare("delete from fournisseur where ID=:ID");
    query.bindValue(0, ID);

    return query.exec();

}
QSqlQueryModel* table1::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();


          model->setQuery("SELECT * FROM frounissseur");
          model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
          model->setHeaderData(1, Qt::Horizontal,QObject::tr("PRODUIT"));
          model->setHeaderData(2, Qt::Horizontal,QObject::tr("TARIF"));



    return model;
}
///
bool table1::modifier()
{
QSqlQuery query;
QString res = QString::number(ID);

query.prepare("update fournisseur set ID= :ID, PRODUIT= :PRODUIT, TARIF= :TARIF  where ID = :ID ");
query.bindValue(":ID",res);
query.bindValue(":PRODUIT",PRODUIT);
query.bindValue(":TARIF",TARIF);

return    query.exec();
}
QSqlQueryModel *table1::trier()
{

    QSqlQuery *q = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel();
    q->prepare("SELECT * FROM  fournisseur ORDER BY ID ");
    q->exec();
    model->setQuery(*q);
    return model;
}

QSqlQueryModel * table1::recherche(QString PRODUIT)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from fournisseur WHERE ID = '"+PRODUIT+"'");
    model->setHeaderData(0,Qt::Horizontal,"ID");
    model->setHeaderData(1,Qt::Horizontal,"PRODUIT");
    model->setHeaderData(2,Qt::Horizontal,"TARIF");

    return model ;
}

bool table1::exporter()
{
    bool test=false;
    QSqlQueryModel * model=afficher();
    QString textData;
    int rows = model->rowCount();
    int columns = model->columnCount();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
                textData += model->data(model->index(i,j)).toString();
                textData += " || " ;
        }
        textData += "\n";
    }
    QFile txtFile("test.txt");
    if(txtFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
        {
            test=true;
            QTextStream out(&txtFile);
            out << "ID ||      PRODUIT      ||  TARIF \n";
            out << textData;
            txtFile.close();
        }
        return test;
    }
/*void table1::exportFichier(QString fichier)
 {


     QFile file(fichier);  //on lie le save avec la fenetre qdialog
     if(file.open(QIODevice::WriteOnly | QIODevice::Text))
     {
         QTextStream ecriture(&file);
     QSqlQuery query;  // pour gerer la recherche

      QString ID,PRODUIT,TARIF; //creation des variable qui vont prendre les valeurs trouvé

         query.prepare("SELECT* FROM equipement");

         int compte=0;
         query.exec();  // lancement de l'excution de la recherche
           while(query.next())
           {
               ID= query.value(0).toString();
               PRODUIT= query.value(1).toString();

                TARIF=query.value(1).toString();
            ecriture << ID << "\t"<< PRODUIT << "\t"<< TARIF<<  "\n";
               compte++;
            }
           file.close();

     }
     else
        { QMessageBox::information(nullptr, QObject::tr("erreur"),
                                                    QObject::tr("erreur douverture fichier. \n click here to exit."),QMessageBox::Cancel);

     }

 }*/
void table1::statistique(QWidget * w)

{

    int tarifa=0,tarifb=0;

                QSqlQuery query("SELECT COUNT(*) FROM fournisseur WHERE TARIF>'100'");

                while(query.next())

                {

                    tarifa = query.value(0).toInt();

                                    }

                                    QSqlQuery query2("SELECT COUNT(*) FROM fournisseur WHERE TARIF<'100'");

                                    while(query2.next())

                                    {

                                       tarifb= query2.value(0).toInt();

                                    }
                                    QPieSeries *series = new QPieSeries();



                                                series->append("tarif>100",tarifa);

                                                series->append("tarif<100",tarifb);



                                                series->setHoleSize(0.0);

                                                series->setPieSize(1.0);



                                                QPieSlice * I = series->slices().at(0);

                                                QPieSlice * C = series->slices().at(1);



                                                I->setLabelVisible(true);

                                                C->setLabelVisible(true);



                                                I->setBrush(QColor::fromRgb(255, 0, 0));
                                                C->setBrush(QColor::fromRgb(0, 0, 255));



                                                            QChart *chart = new QChart();

                                                            chart->addSeries(series);

                                                            chart->setTitle("stat selon tarif");

                                                            chart->legend()->setVisible(true);

                                                            chart->legend()->setAlignment(Qt::AlignBottom);

                                                            chart->setAnimationOptions(QChart::AllAnimations);
                                                            QChartView * chartview = new QChartView(chart);

                                                                        chartview->resize(w->width(),w->height());

                                                                        chartview->setParent(w);
}


