#include "mainwindowc.h"
#include "ui_mainwindowc.h"
#include "commande.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include <QString>
#include <QIntValidator>
#include <QPixmap>
#include<QPainter>
#include<QtPrintSupport/QPrinter>
#include "QFileDialog"
#include "QTextStream"
#include<QtPrintSupport/QPrintDialog>
#include <QTextDocument>
#include <QMessageBox>
#include <QtGlobal>
#include <QDebug>
//#include "login.h"
//#include "arduino.h"
mainwindowc::mainwindowc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainwindowc)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/rania/OneDrive/Bureau/logo.png");
    ui->image->setPixmap(pix);
    ui->le_id->setValidator(new QIntValidator(0, 99999999, this));
        //ui->le_nom;
       // ui->le_descri;
        //ui->le_dispo;
        ui->tab_commande->setModel(C.afficher());
        ui->tab_commande_2->setModel(C.afficher_produit());
        ui->tab_commande->setModel(C.afficher());
}

mainwindowc::~mainwindowc()
{
    delete ui;
}
void mainwindowc::on_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString descri=ui->le_descri->text();
    QString dispo=ui->le_dispo->text();
    commande C(id,nom,descri,dispo);

    bool test=C.ajouter();
    if (test)
    {
        //actualiser pour l'affichage
        ui->tab_commande->setModel(C.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK") , QObject::tr("Ajout effectué\n"
                                                                     "Click Cancel to exit"), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"), QObject::tr("Ajout non effectué\n"
                                                                           "Click Cancel to exit"), QMessageBox::Cancel);

}



void mainwindowc::on_pushButton_supprimer_clicked()
{

    commande C;
    int id =ui->le_id_supp->text().toInt();
    bool test=C.supprimer(id);
            QMessageBox msgBox;

        if(test){
            //actualiser pour l'affichage
            ui->tab_commande->setModel(C.afficher());
                 msgBox.setText("suppression reussit");
                    ui->tab_commande->setModel(C.afficher());
                }
                else
                    msgBox.setText("echec de suppression");
                    msgBox.exec();

}

void mainwindowc::on_pushButton_update_clicked()
{
    int id=ui->lineEdit_id_2->text().toInt();

    QString nom=ui->lineEdit_nom_2->text();

    QString descri=ui->lineEdit_descri_2->text();

   QString dispo=ui->lineEdit_dispo_2->text();

    commande C1(id,nom,descri,dispo);

    bool test=C1.modifier();
    if(test)
    {
        //actualiser pour l'affichage
        ui->tab_commande->setModel(C.afficher());
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("modification effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("modification non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void mainwindowc::on_pushButton_trie_clicked()
{
    commande C;
    bool test=C.trie_NOM();
            QMessageBox msgBox;

        if(test){
            //actualiser pour l'affichage
            ui->tab_commande->setModel(C.afficher());
                 msgBox.setText("trie reussit");
                    ui->tab_commande->setModel(C.afficher());
                }
                else
                    msgBox.setText("echec de suppression");
                    msgBox.exec();
}

void mainwindowc::on_pushButton_update_2_clicked()
{

    int id=ui->lineEdit_id_3->text().toInt();

    QString nom=ui->lineEdit_nom_3->text();

    QString descri=ui->lineEdit_descri_3->text();

   QString dispo=ui->lineEdit_dispo_3->text();

    commande C1(id,nom,descri,dispo);

    bool test=C1.modifier();
    if(test)
    {
        //actualiser pour l'affichage
        ui->tab_commande->setModel(C.afficher());
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("modification effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("modification non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void mainwindowc::on_pushButton_supprimer_2_clicked()

    {

        commande C;
        int id =ui->le_id_supp_2->text().toInt();
        bool test=C.supprimer(id);
                QMessageBox msgBox;

            if(test){
                //actualiser pour l'affichage
                ui->tab_commande->setModel(C.afficher());
                     msgBox.setText("suppression reussit");
                        ui->tab_commande->setModel(C.afficher());
                    }
                    else
                        msgBox.setText("echec de suppression");
                        msgBox.exec();

    }


void mainwindowc::on_ajouter_2_clicked()
{
    int id=ui->le_id_2->text().toInt();

    QString nom=ui->le_nom->text();
    QString descri=ui->le_descri->text();
    QString dispo=ui->le_dispo->text();
    commande C(id,nom,descri,dispo);




    bool test=C.ajouter();
    if (test )
    {
  //ui->label_pp->setText("ssayyee ssehbi");
        //A.write_to_arduino("7");




        //actualiser pour l'affichage
        ui->tab_commande->setModel(C.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK") , QObject::tr("Ajout effectué\n"
                                                                     "Click Cancel to exit"), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"), QObject::tr("Ajout non effectué\n"), QMessageBox::Cancel);

}

void mainwindowc::on_pdf_clicked()


    {QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tab_commande->model()->rowCount();
        const int columnCount = ui->tab_commande->model()->columnCount();
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
                               if (!ui->tab_commande->isColumnHidden(column))
                                   out << QString("<th>%1</th>").arg(ui->tab_commande->model()->headerData(column, Qt::Horizontal).toString());
                           out << "</tr></thead>\n";

                           // data table
                           for (int row = 0; row < rowCount; row++) {
                               out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                               for (int column = 0; column < columnCount; column++) {
                                   if (!ui->tab_commande->isColumnHidden(column)) {
                                       QString data = ui->tab_commande->model()->data(ui->tab_commande->model()->index(row, column)).toString().simplified();
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



void mainwindowc::on_radioButton_clicked()
{
    ui->tab_commande->setModel(C.trier());
}



void mainwindowc::on_pushButton_clicked()
{

    commande c1;

            QString choix=ui->valeur->currentText();

                if (choix=="id")
                {
                    QString id = ui->rech->text();
                    ui->tab_commande->setModel(c1.rech(id));
                }
                if (choix=="nom")
                {
                    QString nom = ui->rech->text();
                    ui->tab_commande->setModel(c1.rechn(nom));
                }
}

void mainwindowc::on_pushButton_2_clicked()
{
     ui->tab_commande->setModel(C.afficher_des());
}

void mainwindowc::on_exel_clicked()
{


}

void mainwindowc::on_pushButton_3_clicked()
{
    QTableView *table= new QTableView;
                                       table = ui->tab_commande;

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
                                           data << strList.join("     ") << "\n";
                                           for (int i = 0; i < model->rowCount(); i++) {
                                               strList.clear();
                                               for (int j = 0; j < model->columnCount(); j++) {

                                                   if (model->data(model->index(i, j)).toString().length() > 0)
                                                       strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                                                   else
                                                       strList.append("");
                                               }
                                               data << strList.join("   ") + "\n";
                                           }
                                           file.close();
                                           QMessageBox::information(nullptr, QObject::tr("Export pdf"),
                                                                     QObject::tr("Export avec succes .\n"
                                                                                 "Click OK to exit."), QMessageBox::Ok);
}
}
