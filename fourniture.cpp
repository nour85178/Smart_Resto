#include "fourniture.h"

fourniture::fourniture()
{
 type="";
 code="";
 prix=0 ;
}
fourniture::fourniture(QString type , QString code , int prix)
{
    this->type=type ;
    this->code=code ;
    this->prix=prix;
}
void fourniture::settype(QString t) { type = t ;}
void fourniture::setcodeabarre(QString c)
{code=c;}
void fourniture::setprix(int p) {prix =p ;}
QString fourniture::gettype() {return type;}
QString fourniture::getcodeabarre() {return code;}
int fourniture::getprix(){return prix ;}
bool fourniture::ajouterfourniture()
{
QSqlQuery query ;
query.prepare("INSERT INTO FOURNITURE(TYPE,CODE,PRIX)VALUES(:type,:code,:prix)");
query.bindValue(":type",type) ;
query.bindValue(":code",code) ;
query.bindValue(":prix",prix) ;
return query.exec();

}
QSqlQueryModel * fourniture::afficherfourniture()
{
    QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM FOURNITURE ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("CODE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));

return model ;
}
bool fourniture::suprimerfourniture(QString code)
{ QSqlQuery querry ;
    querry.prepare("delete from FOURNITURE where CODE= :code");
    querry.bindValue(":code", code);
    return  querry.exec();

}

QSqlQueryModel * fourniture::chercherfourniture(QString type)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM FOURNITURE WHERE TYPE='"+type+"' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("CODE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
        return model ;
    }

 }
QSqlQueryModel * fourniture::chercherfourniturec(QString code)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM FOURNITURE WHERE CODE='"+code+"' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("CODE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
        return model ;
    }

 }
QSqlQueryModel * fourniture::chercherfourniturprix(QString prix)
{
    QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM FOURNITURE WHERE PRIX='"+prix+"' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("CODE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
        return model ;

}
bool fourniture:: modifierfourniture(QString type , QString code, QString prix)
{
    QSqlQuery query;
    query.prepare("UPDATE  FOURNITURE SET TYPE='"+type+"',CODE='"+code+"',PRIX='"+prix+"'WHERE CODE='"+code+"' ");
    query.bindValue(":type",type);
    query.bindValue(":code",code);
    query.bindValue(":identifiant",prix);
    return  query.exec();
 }
QSqlQueryModel *fourniture:: trifournitureparcode()
{
    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM FOURNITURE ORDER BY CODE ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("CODE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
        return model ;
    }

}
QSqlQueryModel *fourniture:: trifourniturepartype()
{
    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM FOURNITURE ORDER BY TYPE ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("CODE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
        return model ;
    }

}
QSqlQueryModel *fourniture:: trifournitureparprix()
{
    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM FOURNITURE ORDER BY PRIX ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("CODE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
        return model ;
    }

}

