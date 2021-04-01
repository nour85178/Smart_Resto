#ifndef RECLAMATION_H
#define RECLAMATION_H
#include <QString>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
class Reclamation
{
 private:
    int  CIN;
    QString prenom,nom,type_de_produit,etat,date_depot;


public:
    Reclamation();
    Reclamation(int,QString,QString,QString,QString,QString);
    QSqlQueryModel*afficher();
    bool ajouter();
    bool supprimer(int);
    bool modifier(int,QString,QString,QString,QString,QString);
    int get_CIN();
    QString get_prenom();
    QString get_nom();
    QString get_type_de_produit();
    QString get_etat();
    QString get_date_depot();
  QSqlQueryModel* trireclamationpardate();
   QSqlQueryModel* trireclamationparnom();
   QSqlQueryModel* trireclamationparetat();
QSqlQueryModel * recherchereclamationpardate(QString);
QSqlQueryModel * recherchereclamationparcin(int);
QSqlQueryModel* recherchereclamationparetat(QString);


};

#endif // RECLAMATION_H
