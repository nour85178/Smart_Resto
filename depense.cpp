#include "depense.h"
#include <QDateEdit>
#include <iostream>
#include <string>

Depense::Depense(QString categorie,int id,QString date,int montant)
{

 this->categorie=categorie;
 this->id=id;
 this->date=date;
 this->montant=montant;
}
bool Depense::ajouter_depense()
{

    QSqlQuery query;
    QString res = QString::number(id);
    QString res2 = QString::number(montant);

    std::string aaa = date.toStdString();
    //std::cout<<aaa;
    query.prepare("insert into depense (categorie,id,date_dp,montant)""values (:categorie,:id,:date,:montant)");
    query.bindValue(":categorie",categorie);
    query.bindValue(":id",res);
    query.bindValue(":date",date);
    query.bindValue(":montant",res2);

    return query.exec();
}
QSqlQueryModel *Depense::afficher()
{
QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from depense");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("categorie"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("id"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("date"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("montant"));
return model;
}
bool Depense::supprimer(int id)
{
QSqlQuery query;
QString res = QString::number(id);
query.prepare("Delete from depense where id= :id");
query.bindValue(":id",res);
return query.exec();
}
bool Depense::update_depense()
{
  QSqlQuery query;
  QString res = QString::number(id);
  QString res2 = QString::number(montant);

  query.prepare("update depense set categorie='"+categorie+"',id='"+res+"',date_dp='"+date+"',montant='"+res2+"' where id='"+res+"'");
  query.bindValue(":categorie",categorie);
  query.bindValue(":id",res);
  query.bindValue(":date",date);
  query.bindValue(":montant",res2);

  return query.exec();
}
QSqlQueryModel *Depense::rechercher(int reid)
{
     QString res = QString::number(reid);
QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from depense where id ='"+res+"'");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("Categorie"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Montant"));
return model;
}
QSqlQueryModel *Depense::trie_az()
{
QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from depense order by Categorie");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("Categorie"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Montant"));
return model;
}
QSqlQueryModel *Depense::trie_date()
{
QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from depense order by date_dp");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("Categorie"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Montant"));
return model;
}
QSqlQueryModel *Depense::trie_mont()
{
QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from depense order by montant");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("Categorie"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Montant"));
return model;
}
