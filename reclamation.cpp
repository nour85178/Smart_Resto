#include "reclamation.h"
#include "client.h"
#include <QDebug>
#include <QString>
#include <QSqlQuery>
Reclamation::Reclamation()
{
CIN=0;
prenom="";
nom="";
etat="";
type_de_produit="";
date_depot="";
}
Reclamation::Reclamation(int CIN ,QString prenom ,QString nom ,QString type_de_produit ,QString etat,QString date_depot)
{

    this->CIN=CIN; this->prenom=prenom; this->nom=nom; this->type_de_produit=type_de_produit; this->etat=etat; this->date_depot=date_depot;
}

QString Reclamation::get_nom(){return  nom;}
QString Reclamation::get_prenom(){return prenom;}
QString Reclamation::get_type_de_produit(){return type_de_produit;}
QString Reclamation::get_etat(){return etat;}
int Reclamation::get_CIN(){return  CIN;}

bool Reclamation::ajouter()
{
  QSqlQuery query;
   QString res=QString::number(CIN);

   query.prepare("INSERT INTO RECLAMATIONs (CIN,prenom,nom,type_de_produit,etat,date_de_depot) " "VALUES (:CIN,:prenom,:nom,:type_de_produit,:etat,:date_de_depot);");

          query.bindValue(":CIN",res);
          query.bindValue(":prenom",prenom);
          query.bindValue(":nom",nom);
          query.bindValue(":type_de_produit", type_de_produit);
          query.bindValue(":etat", etat);
           query.bindValue(":date_de_depot",date_depot);



         return query.exec();

}
bool Reclamation::modifier(int CIN,QString prenom,QString nom ,QString type_de_produit,QString etat ,QString date_de_depot)
{
    QSqlQuery query;
    QString res= QString::number(CIN);
    query.prepare("UPDATE reclamations SET prenom=:prenom,nom=:nom,type_de_produit=:type_de_produit,etat=:etat,date_de_depot=:date_de_depot WHERE CIN =:CIN");
    query.bindValue(":CIN",res);
    query.bindValue(":prenom",prenom);
    query.bindValue(":nom",nom);
    query.bindValue(":type_de_produit",type_de_produit);
    query.bindValue(":etat",etat);
    query.bindValue(":date_de_depot",date_de_depot);

    return query.exec();
}







QSqlQueryModel* Reclamation::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM Reclamations");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type de produit"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date de depot"));

   return  model;

}
bool Reclamation::supprimer (int CIN)
{
 QSqlQuery query;
 QString res=QString::number(CIN);
 query.prepare("Delete from reclamations where CIN=:CIN");
  query.bindValue(":CIN",res);

    return query.exec();

}
QSqlQueryModel * Reclamation::trireclamationpardate()
{
    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM reclamations ORDER BY date_de_depot ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type de produit"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date de depot"));
        return model ;
    }

}
QSqlQueryModel * Reclamation::trireclamationparnom()
{

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM reclamations ORDER BY prenom asc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type de produit"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date de depot"));
    return model ;



}
QSqlQueryModel * Reclamation::trireclamationparetat()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM reclamations ORDER BY etat asc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type de produit"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date de depot"));
    return model ;



}
QSqlQueryModel * Reclamation::recherchereclamationpardate(QString date)
 {

    QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM reclamations WHERE (date_de_depot LIKE '"+date+"')");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type de produit"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date de depot"));
        return model ;


 }
QSqlQueryModel* Reclamation::recherchereclamationparcin(int CIN)
{
    QSqlQueryModel *model = new QSqlQueryModel;
   QString res=QString::number(CIN);
   model->setQuery("SELECT * FROM reclamations WHERE (CIN LIKE '"+res+"')");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type de produit"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date de depot"));


   return model;
}
QSqlQueryModel* Reclamation::recherchereclamationparetat(QString etat)
{
    QSqlQueryModel *model = new QSqlQueryModel;
   model->setQuery("SELECT * FROM reclamations WHERE (etat LIKE '"+etat+"')");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type de produit"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date de depot"));


   return model;
}













