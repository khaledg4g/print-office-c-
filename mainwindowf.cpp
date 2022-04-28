#include "mainwindowf.h"
#include "ui_mainwindowf.h"
#include "fournisseur.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QString>
#include <QApplication>
#include<QPainter>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include "QFileDialog"
#include "QTextStream"
#include <QTextDocument>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
MainWindowf::MainWindowf(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowf)

{
    ui->setupUi(this);
    QPixmap pix("C:/Users/rania/OneDrive/Bureau/logo.png");
    ui->image->setPixmap(pix);
    ui->image_2->setPixmap(pix);
    ui->LE_ID->setValidator(new QIntValidator(0, 99999999, this));
 ui->table1->setModel(t.afficher());

}
/*
{
    ui->setupUi(this);
    ui->LE_ID->setValidator(new QIntValidator(0, 99999999, this));
    ui->LE_ID_supp_2->setValidator(new QIntValidator(0,99999999,this));
    ui->le_PRODUIT->setValidator(new QIntValidator(0, 99999999, this));
    ui->le_TARIF->setValidator(new QIntValidator(0,99999999,this));
    ui->table1->setModel(t.afficher());
}*/


MainWindowf::~MainWindowf()
{
    delete ui;
}




void MainWindowf::on_on_pushButton_clicked()
{
    int ID=ui->LE_ID->text().toInt();
    QString PRODUIT=ui->le_PRODUIT->text();
  int TARIF=ui->le_TARIF->text().toInt();
table1 t(ID,PRODUIT,TARIF);
bool test=t.ajouter();
    if (test)
    {
        //actualiser pour l'affichage
        ui->table1->setModel(t.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajouter") , QObject::tr("Ajout effectué\n"
                                                                     "Click Cancel to exit"), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"), QObject::tr("Ajout non effectué\n"
                                                                           "Click Cancel to exit"), QMessageBox::Cancel);

}


void MainWindowf::on_pb_supprimer_clicked()
{
  table1 t; t.setID(ui->LE_ID_supp_2->text().toInt());
  bool test=t.supprimer(t.getID());
  if (test)
  {
      //actualiser pour l'affichage
      ui->table1->setModel(t.afficher());
      QMessageBox::information(nullptr, QObject::tr("ajouter") , QObject::tr("suppression effectué\n"
                                                                   "Click Cancel to exit"), QMessageBox::Cancel);
  }
  else
      QMessageBox::critical(nullptr, QObject::tr("NOT OK"), QObject::tr("suppression non effectué\n"
                                                                         "Click Cancel to exit"), QMessageBox::Cancel);

}


void MainWindowf::on_pb_modifier_clicked()
{
    int ID=ui->LE_ID_2->text().toInt();

        QString PRODUIT=ui->le_PRODUIT_2->text();



        int TARIF=ui->le_TARIF_2->text().toInt();



       table1 t(ID,PRODUIT,TARIF);

        bool test=t.modifier();
        if(test)
        {
            //actualiser pour l'affichage
            ui->table1->setModel(t.afficher());
                    QMessageBox::information(nullptr, QObject::tr("database is open"),
                                QObject::tr("modification effectué.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);}
        else
            QMessageBox::critical(nullptr, QObject::tr("database is open"),
                        QObject::tr("modification non effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindowf::on_radioButton_clicked()
{
    ui->table1->setModel(t.trier());
}

void MainWindowf::on_pb_recherche_clicked()
{
    ui->table1->setModel(t.afficher());
                QString PRODUIT = ui->LE_recherche->text();
               ui->table1_2->setModel(t.recherche(PRODUIT));
}


void MainWindowf::on_pb_pdf_clicked()
{
    QString strStream;

                        QTextStream out(&strStream);



                        const int rowCount = ui->table1->model()->rowCount();

                        const int columnCount = ui->table1->model()->columnCount();

                        out <<  "<html>\n"

                                               "<head>\n"

                                               "<meta Content=\"Text/html; charset=Windows-1251\">\n"

                                               <<  QString("<title>%1</title>\n").arg("strTitle")

                                               <<  "</head>\n"

                                               "<body bgcolor=#ffffff link=#5000A0>\n"



                                              //     "<align='right'> " << datefich << "</align>"

                                               "<center> <H1>Liste Des fournisseurs </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";



                                           // headers

                                           out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";

                                           for (int column = 0; column < columnCount; column++)

                                               if (!ui->table1->isColumnHidden(column))

                                                   out << QString("<th>%1</th>").arg(ui->table1->model()->headerData(column, Qt::Horizontal).toString());

                                           out << "</tr></thead>\n";



                                           // data table

                                           for (int row = 0; row < rowCount; row++) {

                                               out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";

                                               for (int column = 0; column < columnCount; column++) {

                                                   if (!ui->table1->isColumnHidden(column)) {

                                                       QString data = ui->table1->model()->data(ui->table1->model()->index(row, column)).toString().simplified();

                                                       out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));

                                                   }

                                               }

                                               out << "</tr>\n";

                                           }

                                           out <<  "</table> </center>\n"

                                               "</body>\n"

                                               "</html>\n";

      QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");

                    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }



                   QPrinter printer (QPrinter::PrinterResolution);

                    printer.setOutputFormat(QPrinter::PdfFormat);

                   printer.setPaperSize(QPrinter::A4);

                  printer.setOutputFileName(fileName);



                   QTextDocument doc;

                    doc.setHtml(strStream);

                    doc.setPageSize(printer.pageRect().size());

                    doc.print(&printer);
}

void MainWindowf::on_pb_text_clicked()
{
    bool test=t.exporter();
        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("Succés"), QObject::tr("Export effectué\n""Click Ok to exit."), QMessageBox::Ok);
        }
        else QMessageBox::warning(nullptr, QObject::tr("Erreur"),QObject::tr("Export non effectué. \n""Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindowf::on_tabWidget_tabBarClicked(int index)
{
    t.statistique(ui->widget);
}

void MainWindowf::on_pb_excel_clicked()
{
    QTableView *table= new QTableView;
                                       table = ui->table1;

                                       QString filters("CSV files (.csv);;All files (.*)");
                                       QString defaultFilter("CSV files (*.csv)");
                                       QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                                          filters, &defaultFilter);
                                       QFile file(fileName);

                                       QAbstractItemModel *model =  table->model();
                                       if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                                           QTextStream data(&file);
                                           QStringList strList;
                                           for (int i = 0; i < model->columnCount(); i++) {
                                               if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                                                   strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                                               else
                                                   strList.append("");
                                           }
                                           data << strList.join(";") << "\n";
                                           for (int i = 0; i < model->rowCount(); i++) {
                                               strList.clear();
                                               for (int j = 0; j < model->columnCount(); j++) {

                                                   if (model->data(model->index(i, j)).toString().length() > 0)
                                                       strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                                                   else
                                                       strList.append("");
                                               }
                                               data << strList.join(";") + "\n";
                                           }
                                           file.close();
                                           QMessageBox::information(nullptr, QObject::tr("Export pdf"),
                                                                     QObject::tr("Export avec succes .\n"
                                                                                 "Click OK to exit."), QMessageBox::Ok);
}
}
