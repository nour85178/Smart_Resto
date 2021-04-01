#include "admin.h"

admin::admin()
{

}

bool admin::login(QString username,QString password){
    QSqlQuery query;
    query.prepare("select * from login where username=:username and password=:password");
    query.bindValue(":username",username);
    query.bindValue(":password",password);
    query.exec();
    int total=0;
    while(query.next()){
        total++;
    }
    if(total==1){
        return true;
    }
    else{
        return false;
    }
    /*ajouter un travail*/

}
