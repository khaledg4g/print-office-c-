#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include<QMessageBox>
#include "connection.h"
#include<QIntValidator>
#include"employe.h"
#include"historique.h"
#include<QPainter>
#include<QtPrintSupport/QPrinter>
#include "QFileDialog"
#include "QTextStream"
#include<QtPrintSupport/QPrintDialog>
#include <QTextDocument>
#include <QMessageBox>
#include "QFileDialog"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_id_2->setValidator(new QIntValidator(0, 9999999, this));

ui->tab_e->setModel(E.afficher());
ui->tab_e_2->setModel(h.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ajouter_clicked()
{

    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString fonction=ui->le_fonction->currentText();
    QString date_de_naissance=ui->la_date->text();
    Employe E(id,nom,prenom,fonction,date_de_naissance);
    bool test=E.ajouter();

if (test)
    {
        ui->tab_e->setModel(E.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout"),
                    QObject::tr("ajout avec succes .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("ajout"),
                    QObject::tr("insert failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}






void MainWindow::on_supprimer_clicked()
{

    Employe E1;E1.setid(ui->le_id_supp->text().toInt());
    bool test=E1.supprimer(E1.getid());
            QMessageBox msgBox;
    if(test){
        msgBox.setText("suppression avec succes,");
   ui->tab_e->setModel(E1.afficher());
}

    else
        msgBox.setText("Echec suppriession,");
    msgBox.exec();

      }







void MainWindow::on_modifier_clicked()
{

 int id=ui->le_id2->text().toInt();
 QString nom=ui->le_nom2->text();
 QString prenom=ui->le_prenom2->text();
 QString date_de_naissance=ui->la_date2->text();
 QString fonction=ui->le_fonction2->currentText();

 Employe E1(id,nom,prenom,fonction,date_de_naissance);
 //bool test= E.modifier(id,nom,prenom,fonction,date_naissance);

 bool test= E1.modifier( id , nom, prenom, fonction, date_de_naissance);
 if (test)

    {
     ui->tab_e->setModel(E.afficher());
     QMessageBox::information(nullptr, QObject::tr("MODIFIER"),
                                   QObject::tr("MODIFICATION avec succes .\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

     }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("MODIFIER"),
                                   QObject::tr("UPDATE failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}



////////////////////////////////////////////////////////////////
void MainWindow::on_ajouter_pk_clicked()
{
    int id=ui->le_id_2->text().toInt();
    QString date_emb=ui->la_dateemb->text();
    QString date_fc=ui->la_datefc->text();

    historique h(id,date_emb,date_fc);
    bool test=h.ajouter_pk();

if (test)
    {
        ui->tab_e_2->setModel(h.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout"),
                    QObject::tr("ajout avec succes .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("ajout"),
                    QObject::tr("insert failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_modifier_pk_clicked()
{
    int id=ui->le_id3->text().toInt();
    QString date_emb=ui->la_dateemb2->text();
    QString date_fc=ui->la_datefc2->text();

    historique h1(id,date_emb,date_fc);


    bool test= h1.modifier_pk( id , date_emb, date_fc);
    if (test)

       {
        ui->tab_e_2->setModel(h.afficher());
        QMessageBox::information(nullptr, QObject::tr("MODIFIER"),
                                      QObject::tr("MODIFICATION avec succes .\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);

        }
                      else
                          QMessageBox::critical(nullptr, QObject::tr("MODIFIER"),
                                      QObject::tr("UPDATE failed.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_supprimer_pk_clicked()
{
   historique h1;h1.setid(ui->le_id_supp_2->text().toInt());
    bool test=h1.supprimer_pk(h1.getid());
            QMessageBox msgBox;
    if(test){
        msgBox.setText("suppression avec succes,");
   ui->tab_e_2->setModel(h1.afficher());
}

    else
        msgBox.setText("Echec suppression,");
    msgBox.exec();
}
////////////////////////////////trier/////////////////////////////

void MainWindow::on_trie_par_age_clicked()

    {QSqlQueryModel* test=(E.triparAge());
        QMessageBox msgBox;
            if(test){
                msgBox.setText("tri avec succes");
                ui->tab_e->setModel(E.triparAge());
            }
                else
                msgBox.setText(("echec"));

                msgBox.exec();

    }



////////////////////////// recherche////////////////////////////////////////////

void MainWindow::on_pushButton_recherchee_clicked()
{
    Employe E1;

         QString choix=ui->valeur->currentText();

             if (choix=="id")
             {
                 QString id = ui->lineEdit_rech->text();
                 ui->tab_e->setModel(E1.rech(id));
             }
             if (choix=="nom")
             {
                 QString nom = ui->lineEdit_rech->text();
                 ui->tab_e->setModel(E1.rechn(nom));
             }
             if (choix=="prenom")
             {
                 QString prenom = ui->lineEdit_rech->text();
                 ui->tab_e->setModel(E1.rechp(prenom));
             }
}
///////////////////////////////////////////////////pdf//////////////////////////////////////////////
void MainWindow::on_PDF_clicked()
{
    QString strStream;
                            QTextStream out(&strStream);

                            const int rowCount = ui->tab_e->model()->rowCount();
                            const int columnCount = ui->tab_e->model()->columnCount();
                            out <<  "<html>\n"
                                                   "<head>\n"
                                                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                                   <<  QString("<title>%1</title>\n").arg("strTitle")
                                                   <<  "</head>\n"
                                                   "<body bgcolor=#ffffff link=#5000A0>\n"

                                                  //     "<align='right'> " << datefich << "</align>"
                                                   "<center> <H1>Liste Des Employes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                               // headers
                                               out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                               for (int column = 0; column < columnCount; column++)
                                                   if (!ui->tab_e->isColumnHidden(column))
                                                       out << QString("<th>%1</th>").arg(ui->tab_e->model()->headerData(column, Qt::Horizontal).toString());
                                               out << "</tr></thead>\n";

                                               // data table
                                               for (int row = 0; row < rowCount; row++) {
                                                   out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                                   for (int column = 0; column < columnCount; column++) {
                                                       if (!ui->tab_e->isColumnHidden(column)) {
                                                           QString data = ui->tab_e->model()->data(ui->tab_e->model()->index(row, column)).toString().simplified();
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


/////////////////////////////////statistique//////////////////////////////////////////////////////////

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    E.statistique(ui->widget);
}
///////////////////////////////////////////////CSV////////////////////////////////////////////////
void MainWindow::on_CSV_clicked()
{
    QTableView *table= new QTableView;
                                   table = ui->tab_e;

                                   QString filters("PDF files (.pdf);;All files (.*)");
                                   QString defaultFilter("PDF files (*.pdf)");
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
