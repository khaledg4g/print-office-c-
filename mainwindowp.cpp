#include "mainwindowp.h"
#include "ui_mainwindowp.h"
#include "produit.h"
#include "mail.h"
#include <QIntValidator>
#include <QMessageBox>
#include<QPainter>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include "QFileDialog"
#include "QTextStream"
#include <QTextDocument>
MainWindowp::MainWindowp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowp)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/rania/OneDrive/Bureau/logo.png");
    ui->image_2->setPixmap(pix);
    ui->image_3->setPixmap(pix);
    ui->le_mat->setValidator(new QIntValidator(0, 99999999, this));
    ui->tabp->setModel(P.afficher());
    ui->tabm->setModel(M.afficher());


    /*ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
       ui->quickWidget->show();

       auto obj = ui->quickWidget->rootObject();
       connect(this, SIGNAL(setCenter(QVariant, QVariant)), obj, SLOT(setCenter(QVariant, QVariant)));
       connect(this, SIGNAL(addMarker(QVariant, QVariant)), obj, SLOT(addMarker(QVariant, QVariant)));

       emit setCenter(25.000, 50.000);
       emit addMarker(25.000, 50.000);*/



}
MainWindowp::~MainWindowp()
{
    delete ui;
}

void MainWindowp::on_submit_clicked()
{
    int mat=ui->le_mat->text().toInt();
    QString nom=ui->le_nom->text();
    QString desc=ui->le_desc->text();
Produit P(mat,nom,desc);
bool test=P.ajouter();
if (test)
{
    //actualiser pour l'affichage
    ui->tabp->setModel(P.afficher());
    QMessageBox::information(nullptr, QObject::tr("OK") , QObject::tr("Ajout effectué\n"
                                                                 "Click Cancel to exit"), QMessageBox::Cancel);
}
else
    QMessageBox::critical(nullptr, QObject::tr("NOT OK"), QObject::tr("Ajout non effectué\n"
                                                                       "Click Cancel to exit"), QMessageBox::Cancel);



}


void MainWindowp::on_pushButton_11_clicked()
{
    {
        int mat=ui->matm->text().toInt();

        QString nom=ui->nomm->text();

        QString desc=ui->descm->text();


        Produit P(mat,nom,desc);

        bool test=P.modifier();
        if(test)
        {
            //actualiser pour l'affichage
           ui->tabp->setModel(P.afficher());
                    QMessageBox::information(nullptr, QObject::tr("database is open"),
                                QObject::tr("modification effectué.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);}
       else
           QMessageBox::critical(nullptr, QObject::tr("database is open"),
                       QObject::tr("modification non effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void MainWindowp::on_pushButton_13_clicked()
{
    Produit P;
        int mat =ui->mats->text().toInt();
        bool test=P.supprimer(mat);
                QMessageBox msgBox;

            if(test){
                ui->tabp->setModel(P.afficher());
                     msgBox.setText("suppression reussit");
                    }
                    else
                        msgBox.setText("echec de suppression");
                        msgBox.exec();

    }



void MainWindowp::on_pdf_clicked()
{
    QString strStream;
                        QTextStream out(&strStream);

                        const int rowCount = ui->tabp->model()->rowCount();
                        const int columnCount = ui->tabp->model()->columnCount();
                        out <<  "<html>\n"
                                               "<head>\n"
                                               "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                               <<  QString("<title>%1</title>\n").arg("strTitle")
                                               <<  "</head>\n"
                                               "<body bgcolor=#ffffff link=#5000A0>\n"

                                              //     "<align='right'> " << datefich << "</align>"
                                               "<center> <H1>Liste des produits</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                           // headers
                                           out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                           for (int column = 0; column < columnCount; column++)
                                               if (!ui->tabp->isColumnHidden(column))
                                                   out << QString("<th>%1</th>").arg(ui->tabp->model()->headerData(column, Qt::Horizontal).toString());
                                           out << "</tr></thead>\n";

                                           // data table
                                           for (int row = 0; row < rowCount; row++) {
                                               out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                               for (int column = 0; column < columnCount; column++) {
                                                   if (!ui->tabp->isColumnHidden(column)) {
                                                       QString data = ui->tabp->model()->data(ui->tabp->model()->index(row, column)).toString().simplified();
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

void MainWindowp::on_trier_clicked()
{
    Produit P;
        QString choix=ui->comboBox_5->currentText();
        if (choix=="matricule")
        {
            ui->tabp->setModel(P.trie_matricule());
            ui->tabp->setModel(P.afficher());
            bool test=P.trie_matricule();
            if (test)
            {

        ui->tabp->setModel(P.trie_matricule());
                QMessageBox::information(nullptr,QObject::tr("ok"),
                                         QObject::tr("tri nom effectué \n"
                                                     "Click Cancel to exist ."),QMessageBox::Cancel);

            }
            else
                  QMessageBox::critical(nullptr, QObject::tr("erreur"),
                              QObject::tr("tri  failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }

        if (choix=="nom")
        {
            ui->tabp->setModel(P.trie_nom());
            ui->tabp->setModel(P.afficher());
            bool test=P.trie_nom();
            if (test)
            {

        ui->tabp->setModel(P.trie_nom());
                QMessageBox::information(nullptr,QObject::tr("ok"),
                                         QObject::tr("tri nom effectué \n"
                                                     "Click Cancel to exist ."),QMessageBox::Cancel);

            }
            else
                  QMessageBox::critical(nullptr, QObject::tr("erreur"),
                              QObject::tr("tri  failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }

}

void MainWindowp::on_rechercher_clicked()
{
    Produit p;
    QString  matricule=ui->matricule_rechercher->text();
     ui->tab_rechercher->setModel(p.rechercher(matricule));
}

void MainWindowp::on_submitmail_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->nommail->text();
    QString mail=ui->maila->text();
Mail M(id,nom,mail);
bool test=M.ajouter();
if (test)
{
    //actualiser pour l'affichage
    ui->tabm->setModel(M.afficher());
    QMessageBox::information(nullptr, QObject::tr("OK") , QObject::tr("Ajout effectué\n"
                                                                 "Click Cancel to exit"), QMessageBox::Cancel);
}
else
    QMessageBox::critical(nullptr, QObject::tr("NOT OK"), QObject::tr("Ajout non effectué\n"
                                                                       "Click Cancel to exit"), QMessageBox::Cancel);

}



void MainWindowp::on_mailling_clicked()
{
    QString link="https://mail.google.com/mail/u/0/#inbox?compose=new";
        QDesktopServices::openUrl(link);
}

void MainWindowp::on_pushButton_14_clicked()
{
    Mail M;
        int id =ui->idsupp->text().toInt();
        bool test=M.supprimer(id);
                QMessageBox msgBox;

            if(test){
                ui->tabm->setModel(M.afficher());
                     msgBox.setText("suppression reussit");
                    }
                    else
                        msgBox.setText("echec de suppression");
                        msgBox.exec();
}

