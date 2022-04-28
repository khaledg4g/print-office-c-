#ifndef MAINWINDOWC_H
#define MAINWINDOWC_H

#include <QDialog>
#include <QMainWindow>
#include <commande.h>
//#include "arduino.h"
namespace Ui {
class mainwindowc;
}

class mainwindowc : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainwindowc(QWidget *parent = nullptr);
    ~mainwindowc();

private slots:
    void on_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_update_clicked();


    void on_pushButton_trie_clicked();

    void on_pushButton_update_2_clicked();

    void on_pushButton_supprimer_2_clicked();

    void on_ajouter_2_clicked();

    void on_pdf_clicked();

    void on_radioButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_exel_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::mainwindowc *ui;
    mainwindowc *MainMenuWin;
// Arduino A;
    commande C;
    QByteArray data; // variable contenant les données reçues

};

#endif // MAINWINDOWC_H
