#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btn_client_clicked()
{
    MainWindow *dialog= new MainWindow(this);
    dialog->show();
}

void Dialog::on_btn_produit_clicked()
{
    MainWindowp *dialog= new MainWindowp(this);
    dialog->show();
}

void Dialog::on_btn_employe_clicked()
{
    MainWindowe *dialog= new MainWindowe(this);
    dialog->show();
}

void Dialog::on_btn_commande_clicked()
{
    mainwindowc *dialog= new mainwindowc(this);
    dialog->show();
}

void Dialog::on_btn_fournisseur_clicked()
{
    MainWindowf *dialog= new MainWindowf(this);
    dialog->show();
}
