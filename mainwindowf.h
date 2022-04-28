#ifndef MAINWINDOWF_H
#define MAINWINDOWF_H


#include <QMainWindow>
#include "fournisseur.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowf; }
QT_END_NAMESPACE

class MainWindowf : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowf(QWidget *parent = nullptr);
    ~MainWindowf();

   private slots:
    /*void on_submit_clicked();*/


    /*void  on_on_pushButton_clicked();*/

    void on_on_pushButton_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();


    void on_radioButton_clicked();

    void on_pb_recherche_clicked();
;

    void on_pb_pdf_clicked();

    void on_pb_text_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void on_pb_excel_clicked();

private:
    Ui::MainWindowf *ui;

 table1 t;

};
#endif // MAINWINDOWF_H

