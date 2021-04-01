#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H

#include<QString>
#include<QDate>
#include<QSqlQuery>
#include<QVariant>
#include<QSqlQueryModel>
#include "employe.h"

class departement
{
    int id_chef;
    QString nom;
    QDate date_cr;
    int nombre_emp;

    employe e;
public:
    departement();
    ~departement();
    departement(int,QString,QDate,int);

    int getid_chef();
    QString getnom();
    QDate getdate_cr();
    int getnombre_emp();



    void setid_chef(int);
    void setnom(QString);
    void setdate_cr(QDate);
    void setnombre_emp(int);


    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    departement trouver(int);
    QSqlQueryModel * afficher();
    QSqlQueryModel * tridate_cr();
    QSqlQueryModel * trinom();
    QSqlQueryModel * tri_idchef();
    QSqlQueryModel * recherche_dep(const QString&);
    QSqlQueryModel * recherche_nom_id(const QString&);
    QSqlQueryModel * recherche_nom_date(const QString&);
    QSqlQueryModel * recherche_id_date(const QString&);
    QSqlQueryModel * recherche_nom(const QString&);
    QSqlQueryModel * recherche_id(const QString&);
    QSqlQueryModel * recherche_date(const QString&);

    QStringList listDepartement();


};

#endif // DEPARTEMENT_H
