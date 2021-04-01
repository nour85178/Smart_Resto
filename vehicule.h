#ifndef VEHICULE_H
#define VEHICULE_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtPrintSupport/QPrintDialog>
#include<QtPrintSupport/QPrinter>

class vehicule
{
public:
    vehicule();
    vehicule(QString type ,QString mat ,int prix );
    void settype(QString t);
    void setmatricule(QString m);
    void setprix(int p);
    QString gettype();
    QString getmatricule();
    int getprix();
    bool ajouetrvehicule();
    QSqlQueryModel *affichervehicule();
    bool suprimervehicule(QString mat);
    QSqlQueryModel * cherchervehicule(QString  type);
    QSqlQueryModel * cherchervehiculem(QString  mat);
    QSqlQueryModel * cherchervehiculep(QString prix);
    bool  modifiervehicule(QString type , QString mat, QString prix );
    QSqlQueryModel * trivehiculepartype();
    QSqlQueryModel * trivehiculeparmat();
    QSqlQueryModel * trivehiculeparprix();



private:
    QString type , mat ;
    int prix;


};

#endif // VEHICULE_H

