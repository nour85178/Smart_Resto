#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <string>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>



#include <QMainWindow>
using namespace  std;
class Client
{
private:
    int  CIN;
    QString prenom,nom,type_de_produit,etat;

public:
    Client();
    Client(int,QString,QString,QString,QString);
    QSqlQueryModel *  afficher();

    bool ajouter();

    bool supprimer(int);
    bool modifier(int,QString,QString,QString,QString);
    int get_CIN();
    QString get_prenom();
    QString get_nom();
    QString get_type_de_produit();
    QString get_etat();
    void set_prenom(QString);
    void set_nom(QString);
    void set_type_de_produit(QString);
    void set_etat (QString);
    void set_CIN(int);
    QSqlQueryModel* triclientpartype();
     QSqlQueryModel* triclientparnom();
     QSqlQueryModel* triclientparetat();
     QSqlQueryModel *recherchernom(QString);
     QSqlQueryModel *rechercheretat(QString);
     QSqlQueryModel *recherchertype(QString);
     int calcul_client(int,int);







};

#endif // CLIENT_H
