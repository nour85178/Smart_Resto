#include "vehicule.h"
//#include "ui_stock.h"
//#include "stock.h"
#include <QtPrintSupport/QPrintDialog>
#include<QtPrintSupport/QPrinter>

vehicule::vehicule()
{
 type="";
 mat="";
 prix=0 ;
}
vehicule::vehicule(QString type , QString mat , int prix)
{
    this->type=type ;
    this->mat=mat ;
    this->prix=prix;
}
void vehicule::settype(QString t) { type = t ;}
void vehicule::setmatricule(QString m)
{mat=m;}
void vehicule::setprix(int p) {prix =p ;}
QString vehicule::gettype() {return type;}
QString vehicule::getmatricule() {return mat;}
int vehicule::getprix(){return prix ;}
bool vehicule::ajouetrvehicule()
{
QSqlQuery query ;
query.prepare("INSERT INTO VEHICULE(TYPE,MATRICULE,PRIX)VALUES(:type,:mat,:prix)");
query.bindValue(":type",type) ;
query.bindValue(":mat",mat) ;
query.bindValue(":prix",prix) ;
return query.exec();

}
QSqlQueryModel * vehicule::affichervehicule()
{
    QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM VEHICULE ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("MATRICULE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));

return model ;
}
bool vehicule::suprimervehicule(QString matr)
{ QSqlQuery querry ;
    querry.prepare("delete from VEHICULE where MATRICULE= :mat");
    querry.bindValue(":mat", matr);
    return  querry.exec();

}
/*bool vehicule::cherchervehicule(QString  typee)
 {
    QSqlQuery query;
    query.prepare("SELECT * FROM VEHICULE WHERE TYPE LIKE :type");
     query.bindValue(":type", typee);



    return query.exec();
 }*/
QSqlQueryModel * vehicule::cherchervehicule(QString type)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM VEHICULE WHERE TYPE='"+type+"' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("MATRICULE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
        return model ;
    }

 }
QSqlQueryModel * vehicule::cherchervehiculem(QString mat)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM VEHICULE WHERE MATRICULE='"+mat+"' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("MATRICULE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
        return model ;
    }

 }
QSqlQueryModel * vehicule::cherchervehiculep(QString prix)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM VEHICULE WHERE PRIX ='"+prix+"' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("MATRICULE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
        return model ;
    }

 }

bool vehicule:: modifiervehicule(QString type, QString mat, QString prix)
{
    QSqlQuery query;
    query.prepare("UPDATE  VEHICULE SET TYPE='"+type+"',MATRICULE='"+mat+"',PRIX='"+prix+"'WHERE MATRICULE='"+mat+"' ");
    query.bindValue(":type",type);
    query.bindValue(":matricule",mat);
    query.bindValue(":prix",prix);
    return  query.exec();
 }
QSqlQueryModel *vehicule:: trivehiculepartype()
{
    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM VEHICULE ORDER BY TYPE ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("MATRICULE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
        return model ;
    }

}

QSqlQueryModel *vehicule:: trivehiculeparmat()
{
    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM VEHICULE ORDER BY MATRICULE ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("MATRICULE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
        return model ;
    }

}
QSqlQueryModel *vehicule :: trivehiculeparprix()
{
    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM VEHICULE ORDER BY PRIX ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("MATRICULE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
        return model ;
    }

}



