#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include<QSqlQueryModel>

class Employe
{
public:
    Employe();
    Employe(int,QString,QString,QString,QString);
    int getid();
    QString getnom();
    QString getprenom();
    QString getdate_de_naissance();
    QString getfonction();

    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setdate_de_naissance(QString);
    void setfonction(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
     bool supprimer(int);
     bool modifier(int ,QString,QString,QString,QString);
private:
    int id;
    QString nom, prenom , date_de_naissance , fonction;
};

#endif // EMPLOYE_H
