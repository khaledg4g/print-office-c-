#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLCDNumber>
#include "client.h"
#include "fidelite.h"
#include "arduino.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_update_clicked();

    void on_pushButton_trie_clicked();

    void on_pb_ajouterf_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void on_pushButton_imprimer_clicked();

    void on_supprimerf_clicked();

    void on_pushButton_updatef_clicked();

    void on_pushButton_PDF_clicked();
    void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino

private:
    Ui::MainWindow *ui;
    Client C;
    Fidelite F;
    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire
};

#endif // MAINWINDOW_H
