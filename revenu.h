#ifndef REVENU_H
#define REVENU_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>
namespace Ui {
class revenu;
}
class Revenu
{
     QString type;
     int id,montant;
     QString date;
public:
    Revenu();
    Revenu(QString,int,QString,int);

    QString get_type(){return type;}
    int get_id(){return id;}
    QString get_date(){return date;}
    int get_montant(){return montant;}

    void set_type(QString type){this->type=type;}
    void set_id(int id){this->id=id;}
    void set_date(QString date){this->date=date;}
    void set_montant(int montant){this->montant=montant;}

    bool ajouter_revenu();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool update_revenu();
    QSqlQueryModel * rechercher(int);
    QSqlQueryModel * trie_az();
    QSqlQueryModel * trie_date();
    QSqlQueryModel * trie_mont();
};

#endif // REVENU_H
