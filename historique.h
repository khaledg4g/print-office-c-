#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include <QString>
#include<QSqlQueryModel>


class historique
{
public:
    historique();
    historique(int,QString,QString);
    int getid();
    QString getdate_emb();

    QString getdate_fc();


    void setid(int);
    void setdate_emb(QString);

    void setdate_fc(QString);

    bool ajouter_pk();
    QSqlQueryModel* afficher();
     bool supprimer_pk(int);
     bool modifier_pk(int ,QString,QString);
private:
    int id;
    QString  date_emb , date_fc;
};

#endif // HISTORIQUE_H
