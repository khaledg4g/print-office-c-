#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "produit.h"
#include "mail.h"
#include <QDesktopServices>
#include <QUrl>
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
    void on_submit_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pdf_clicked();

    void on_trier_clicked();

    void on_rechercher_clicked();

    void on_submitmail_clicked();



    void on_mailling_clicked();

private:
    Ui::MainWindow *ui;
    Produit P;
    Mail M;
};
#endif // MAINWINDOW_H
