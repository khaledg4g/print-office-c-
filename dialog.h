#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include "mainwindow.h"
#include "mainwindowp.h"
#include "mainwindowe.h"
#include "mainwindowc.h"
#include "mainwindowf.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_btn_client_clicked();

    void on_btn_produit_clicked();

    void on_btn_employe_clicked();

    void on_btn_commande_clicked();

    void on_btn_fournisseur_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
