#include "departement.h"

departement::departement()
{
    this->id_chef=0;
    this->nom="";
    this->date_cr=date_cr.currentDate();
    this->nombre_emp=0;
}
departement::departement(int id_chef,QString nom,QDate date_cr,int nombre_emp){
    this->id_chef=id_chef;
    this->nom=nom;
    this->date_cr=date_cr;
    this->nombre_emp=nombre_emp;

}
departement::~departement()
{

}
int departement::getid_chef(){
    return id_chef;
}

QString departement::getnom(){
    return nom;
}
QDate departement::getdate_cr(){
    return date_cr;
}

int departement::getnombre_emp(){
    return nombre_emp;
}

void departement::setid_chef(int id_chef){
    this->id_chef=id_chef;
}
void departement::setnom(QString nom){
    this->nom=nom;
}

void departement::setdate_cr(QDate date_cr){
    this->date_cr=date_cr;
}


void departement::setnombre_emp(int nombre_emp){
    this->nombre_emp=nombre_emp;
}

bool departement::ajouter(){
    QSqlQuery query;
    query.prepare("insert into departement (id_chef,nom,nombre_emp,date_cr) values (:id,:nom,:nombre_emp,:date_cr)");
    query.bindValue(":id",id_chef);
    query.bindValue(":nom",nom);
    query.bindValue(":nombre_emp",nombre_emp);
    query.bindValue(":date_cr",date_cr);

    return query.exec();
}


QSqlQueryModel * departement::afficher(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from departement");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_DEPARTEMENTs"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("DATE_CR"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("NOMBRE_EMP"));
    return model;
}

bool departement::supprimer(int id_chef){
    QSqlQuery q;
    q.prepare("select * from departement where id_chef=:id_chef");
    q.bindValue(":id_chef",id_chef);
    q.exec();
    int total=0;
    while(q.next()){
        total++;
    }
    if(total==1){
        QSqlQuery qu;
        qu.prepare("select * from employe where id_departement=:id_chef");
        qu.bindValue(":id_chef",id_chef);
        qu.exec();
        while(qu.next()){
            e.supprimer(qu.value(0).toInt());
        }

        QSqlQuery query;
        query.prepare("delete from departement where id_chef=:id_chef");
        query.bindValue(":id_chef",id_chef);
        return query.exec();
    }
    else{
        return false;
    }

}

departement departement::trouver(int id_chef){
    QSqlQuery query;
    query.prepare("select * from departement where id_chef=:id_chef");
    query.bindValue(":id_chef",id_chef);
    query.exec();
    departement e;
    while(query.next()){
        e.setid_chef(query.value(0).toInt());
        e.setnom(query.value(1).toString());
        e.setdate_cr(query.value(2).toDate());
        e.setnombre_emp(query.value(3).toInt());

    }
    return e;
}


bool departement::modifier(int idr){
    QSqlQuery query;
    query.prepare("update departement set id_chef=:id_chef,nom=:nom,date_cr=:date_cr,nombre_emp=:nombre_emp where id_chef=:idr");
    query.bindValue(":idr",idr);
    query.bindValue(":id_chef",id_chef);
    query.bindValue(":nom",nom);
    query.bindValue(":date_cr",date_cr);
    query.bindValue(":nombre_emp",nombre_emp);
    return query.exec();
}
QSqlQueryModel * departement::tridate_cr(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from departement order by date_cr ");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_DEPARTEMENTs"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("NOMBRE_EMP"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("DATE_CR"));


    return model;
}
QSqlQueryModel * departement::trinom(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from departement order by nombre_emp ");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_DEPARTEMENTs"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("NOMBRE_EMP"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("DATE_CR"));


    return model;
}
QSqlQueryModel * departement::tri_idchef(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from departement order by id_chef ");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_DEPARTEMENTs"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("NOMBRE_EMP"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("DATE_CR"));


    return model;
}
QSqlQueryModel * departement::recherche_dep(const QString &str){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from departement where nom like '"+str+"%' or id_chef like '"+str+"%' or Extract(year from date_cr) like '"+str+"%'");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_DEPARTEMENTs"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("NOMBRE_EMP"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("DATE_CR"));


    return model;
}

QSqlQueryModel * departement::recherche_nom_id(const QString &str){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from departement where nom like '"+str+"%' or id_chef like '"+str+"%'");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_DEPARTEMENTs"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("NOMBRE_EMP"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("DATE_CR"));


    return model;
}
QSqlQueryModel * departement::recherche_nom_date(const QString &str){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from departement where nom like '"+str+"%' or Extract(year from date_cr) like '"+str+"%'" );
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_DEPARTEMENTs"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("NOMBRE_EMP"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("DATE_CR"));


    return model;
}
QSqlQueryModel * departement::recherche_id_date(const QString &str){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from departement where id_chef like '"+str+"%' or Extract(year from date_cr) like '"+str+"%'" );
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_DEPARTEMENTs"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("NOMBRE_EMP"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("DATE_CR"));


    return model;
}
QSqlQueryModel * departement::recherche_nom(const QString &str){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from departement where nom like '"+str+"%'" );
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_DEPARTEMENTs"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("NOMBRE_EMP"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("DATE_CR"));


    return model;
}
QSqlQueryModel * departement::recherche_id(const QString &str){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from departement where id_chef like '"+str+"%'" );
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_DEPARTEMENTs"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("NOMBRE_EMP"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("DATE_CR"));


    return model;
}
QSqlQueryModel * departement::recherche_date(const QString &str){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from departement where Extract(year from date_cr) like '"+str+"%'" );
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_DEPARTEMENTs"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("NOMBRE_EMP"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("DATE_CR"));


    return model;
}


QStringList departement::listDepartement(){
    QSqlQuery query;
    query.prepare("select id_chef from departement");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }
    return list;

}
