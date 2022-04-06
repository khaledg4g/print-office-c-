#ifndef MAIL_H
#define MAIL_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class Mail
{

public:

    Mail();
    Mail(QString,QString);

    QString getnom();
    QString getmail();

    void setnom(QString);
    void setmail(QString);

   bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * rechercher(QString a);
    QSqlQueryModel * trie_matricule();
    QSqlQueryModel * trie_nom();
    QSqlQueryModel * trier_mail();


private:
    QString nom,mail;
};

#endif // mail_H
