#include "client.h"
#include <QDebug>
#include <QString>

Client::Client()
{
CIN=0;
prenom="";
nom="";
etat="";
type_de_produit="";
}
Client::Client(int CIN ,QString prenom ,QString nom ,QString  type_de_produit,QString etat )
{

    this->CIN=CIN; this->prenom=prenom; this->nom=nom; this->type_de_produit=type_de_produit; this->etat=etat;
}

QString Client::get_nom(){return  nom;}
QString Client::get_prenom(){return prenom;}
QString Client::get_type_de_produit(){return type_de_produit;}
QString Client::get_etat(){return etat;}
int Client::get_CIN(){return  CIN;}

void Client::set_nom(QString nom){this->nom=nom;}
void Client::set_prenom (QString prenom){this->prenom=prenom;}
void Client::set_etat(QString etat ){this->etat=etat;}
void Client::set_type_de_produit(QString type_de_produit) {this->type_de_produit=type_de_produit;}
void Client::set_CIN(int CIN) {this->CIN=CIN;}

bool Client::ajouter()
{
   QSqlQuery query;
    QString res=QString::number(CIN);

    query.prepare("INSERT INTO CLIENTS (CIN,nom,prenom,type_de_produit,etat) " "VALUES (:CIN,:nom,:prenom,:type_de_produit,:etat);");
           query.bindValue(":CIN",res);
           query.bindValue(":prenom",prenom);
           query.bindValue(":nom",nom);
           query.bindValue(":type_de_produit", type_de_produit);
           query.bindValue(":etat", etat);

          return query.exec();

}

bool Client::supprimer (int CIN)
{
 QSqlQuery query;
 QString res=QString::number(CIN);
 query.prepare("Delete from clients where CIN=:CIN");
  query.bindValue(":CIN",res);

    return query.exec();

}

QSqlQueryModel* Client::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM clients");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type de produit"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));



  return  model;
}
bool Client::modifier(int CIN,QString nom,QString prenom ,QString type_de_produit,QString etat)
{

    QSqlQuery query;
    QString res= QString::number(CIN);
    query.prepare("UPDATE clients SET nom=:nom,prenom=:prenom,type_de_produit=:type_de_produit,etat=:etat WHERE CIN =:CIN");
    query.bindValue(":CIN",res);
    query.bindValue(":prenom",nom);
    query.bindValue(":nom",prenom);
    query.bindValue(":type_de_produit",type_de_produit);
    query.bindValue(":etat",etat);

    return query.exec();



}
 QSqlQueryModel * Client::triclientpartype()

{

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM clients ORDER BY type_de_produit asc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type de produit"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));


    return model ;
}
QSqlQueryModel *Client::triclientparetat()
{

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM clients ORDER BY etat asc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type de produit"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));

    return model;
}
QSqlQueryModel *Client::triclientparnom()
{


    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM clients ORDER BY nom asc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type de produit"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));


return model;
}
QSqlQueryModel *Client::recherchernom(QString nom)
{
    QSqlQueryModel *model = new QSqlQueryModel;
   model->setQuery("SELECT * FROM clients WHERE (nom LIKE '"+nom+"')");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type de produit"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));
    return model;
}
QSqlQueryModel *Client::rechercheretat(QString etat)
{
    QSqlQueryModel *model = new QSqlQueryModel;
   model->setQuery("SELECT * FROM clients WHERE ( etat LIKE '"+etat+"')");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type de produit"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));
    return model;
}
QSqlQueryModel *Client::recherchertype(QString type)
{
    QSqlQueryModel *model = new QSqlQueryModel;
   model->setQuery("SELECT * FROM clients WHERE (type_de_produit LIKE '"+type+"')");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type de produit"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));
    return model;
}


int Client::calcul_client(int min, int max)
{
    QSqlQuery query;
    query.prepare("select *from CLIENTS where CIN between :min and :max");
    query.bindValue(":min",min);
    query.bindValue(":max",max);
    query.exec();

    int total=0;
    while(query.next()){
        total++;
    }
    return total;
}
















