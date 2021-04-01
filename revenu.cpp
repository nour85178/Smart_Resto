#include "revenu.h"
#include <QDateEdit>
#include <iostream>
#include <string>

Revenu::Revenu(QString type,int id,QString date,int montant)
{

 this->type=type;
 this->id=id;
 this->date=date;
 this->montant=montant;
}

bool Revenu::ajouter_revenu()
{

    QSqlQuery query;
    QString res = QString::number(id);
    QString res2 = QString::number(montant);

    /*std::string aaa = date.toStdString();
    std::cout<<aaa;*/
    query.prepare("insert into REVENU (type,id,date_rev,montant)""values (:type,:id,:date,:montant)");
    query.bindValue(":type",type);
    query.bindValue(":id",res);
    query.bindValue(":date",date);
    query.bindValue(":montant",res2);

    return query.exec();
}
QSqlQueryModel *Revenu::afficher()
{
QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from revenu");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("type"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("id"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("date"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("montant"));
return model;
}
bool Revenu::supprimer(int id)
{
QSqlQuery query;
QString res = QString::number(id);
query.prepare("Delete from revenu where id= :id");
query.bindValue(":id",res);
return query.exec();
}
bool Revenu::update_revenu()
{
  QSqlQuery query;
  QString res = QString::number(id);
  QString res2 = QString::number(montant);

  query.prepare("update REVENU set type='"+type+"',id='"+res+"',date_rev='"+date+"',montant='"+res2+"' where id='"+res+"'");
  query.bindValue(":type",type);
  query.bindValue(":id",res);
  query.bindValue(":date",date);
  query.bindValue(":montant",res2);

  return query.exec();
}
QSqlQueryModel *Revenu::rechercher(int reid)
{
     QString res = QString::number(reid);
QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from revenu where id ='"+res+"'");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("Type"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Montant"));
return model;
}
QSqlQueryModel *Revenu::trie_az()
{
QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from revenu order by type");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("Type"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Montant"));
return model;
}
QSqlQueryModel *Revenu::trie_date()
{
QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from revenu order by date_rev");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("Type"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Montant"));
return model;
}
QSqlQueryModel *Revenu::trie_mont()
{
QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from revenu order by montant");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("Type"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Montant"));
return model;
}
