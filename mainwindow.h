#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<employe.h>
#include<historique.h>
#include<arduino.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
   void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_ajouter_pk_clicked();

    void on_modifier_pk_clicked();

    void on_supprimer_pk_clicked();

    void on_trie_par_age_clicked();



   void on_pushButton_recherchee_clicked();

   void on_PDF_clicked();





   void on_tabWidget_tabBarClicked(int index);

   void on_CSV_clicked();
   void update_label();


private:
    Ui::MainWindow *ui;
    Employe E;
    historique h;
    QByteArray data; // variable contenant les données reçues

        Arduino A; // objet temporaire
};
#endif // MAINWINDOW_H
