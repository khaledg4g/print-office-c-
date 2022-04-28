#ifndef MAIL_H
#define MAIL_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class Mail
{

public:

    Mail();
    Mail(int,QString,QString);
    int getid();
    QString getnom();
    QString getmail();

    void setnom(QString);
    void setmail(QString);
    void setid(int);
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
    int id;
};

#endif // mail_H
