#ifndef DEPENSE_H
#define DEPENSE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
namespace Ui {
class Depense;
}
class Depense
{
    QString categorie;
    int id,montant;
    QString date;
public:
   Depense();
   Depense(QString,int,QString,int);

   QString get_categorie(){return categorie;}
   int get_id(){return id;}
   QString get_date(){return date;}
   int get_montant(){return montant;}

   void set_categorie(QString categorie){this->categorie=categorie;}
   void set_id(int id){this->id=id;}
   void set_date(QString date){this->date=date;}
   void set_montant(int montant){this->montant=montant;}

   bool ajouter_depense();
   QSqlQueryModel * afficher();
   bool supprimer(int);
   bool update_depense();
   QSqlQueryModel * rechercher(int);
   QSqlQueryModel * trie_az();
   QSqlQueryModel * trie_date();
   QSqlQueryModel * trie_mont();
};

#endif // DEPENSE_H
