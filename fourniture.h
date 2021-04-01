#ifndef FOURNITURE_H
#define FOURNITURE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fourniture
{
public:
     fourniture(QString type ,QString code ,int prix );
    void settype(QString t);
    void setcodeabarre(QString m);
    void setprix(int p);
    QString gettype();
    QString getcodeabarre();
    int getprix();
    fourniture();
    bool ajouterfourniture();
    QSqlQueryModel *afficherfourniture();
    bool suprimerfourniture(QString code);
    QSqlQueryModel * chercherfourniture(QString  type);
    QSqlQueryModel * chercherfourniturec(QString  code);
    QSqlQueryModel * chercherfourniturprix(QString prix);
    bool  modifierfourniture(QString type , QString code, QString prix );
    QSqlQueryModel * trifourniturepartype();
    QSqlQueryModel * trifournitureparcode();
    QSqlQueryModel * trifournitureparprix();
    //int calculer(int prix);
private:
    QString type , code ;
    int prix;


};

#endif // FOURNITURE_H
