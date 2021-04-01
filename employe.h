#ifndef EMPLOYE_H
#define EMPLOYE_H
#include<QString>
#include<QDate>
#include<QSqlQuery>
#include<QVariant>
#include<QSqlQueryModel>

class employe
{
    int id;
    QString prenom;
    QString nom;
    QDate date_naiss;
    QString sexe;
    QString poste;
    int id_departement;

public:
    employe();
    ~employe();
    employe(int,QString,QString,QDate,QString,QString,int);

    int getid();
    QString getprenom();
    QString getnom();
    QString getsexe();
    QDate getdate_naiss();
    QString getposte();
    int getid_departement();



    void setid(int);
    void setprenom(QString);
    void setnom(QString);
    void setdate_naiss(QDate);
    void setsexe(QString);
    void setposte(QString);
    void setid_departement(int);

    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    employe trouver(int);
    bool trouverId(int);
    QSqlQueryModel * afficher();

    QSqlQueryModel * recherche(const QString&);
    QSqlQueryModel * recherche_n_p(const QString&);
    QSqlQueryModel * recherche_n_d(const QString&);
    QSqlQueryModel * recherche_p_d(const QString&);
    QSqlQueryModel * recherche_n(const QString&);
    QSqlQueryModel * recherche_p(const QString&);
    QSqlQueryModel * recherche_d(const QString&);

    QSqlQueryModel * tridate_naissance();
    QSqlQueryModel * tri_prenom();
    QSqlQueryModel * tri_id();




};

#endif // EMPLOYE_H
