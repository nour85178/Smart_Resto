#include "connexion.h"

connexion::connexion()
{

}

bool connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet_2a");//inserer le nom de la source de données ODBC
db.setUserName("malek");//inserer nom de l'utilisateur
db.setPassword("malek");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
