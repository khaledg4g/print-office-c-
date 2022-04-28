#ifndef MAINWINDOWP_H
#define MAINWINDOWP_H
#include <QMainWindow>
#include "produit.h"
#include "mail.h"
#include <QDesktopServices>
#include <QUrl>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowp; }
QT_END_NAMESPACE

class MainWindowp : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowp(QWidget *parent = nullptr);
    ~MainWindowp();

private slots:
    void on_submit_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pdf_clicked();

    void on_trier_clicked();

    void on_rechercher_clicked();

    void on_submitmail_clicked();



    void on_mailling_clicked();

    void on_pushButton_14_clicked();


private:
    Ui::MainWindowp *ui;
    Produit P;
    Mail M;

/*signals:
    void setCenter(QVariant, QVariant);
    void addMarker(QVariant, QVariant);*/
};
#endif // MAINWINDOWP_H

