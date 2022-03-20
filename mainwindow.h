#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <client.h>
#include <fidelite.h>

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
    void on_supprimerf_clicked();

    void on_pushButton_updatef_clicked();





private:
    Ui::MainWindow *ui;
    Client C;
    Fidelite F;
};

#endif // MAINWINDOW_H
