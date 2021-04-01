#include "dialogfinance.h"
#include "ui_dialogfinance.h"
#include "revenu.h"
#include "depense.h"
#include<QMessageBox>
#include<iostream>
#include<QTableView>
#include <QLineEdit>
#include "updaterevenu.h"
#include "updatedepense.h"
#include "dialogstat.h"
#include<QFile>
#include<QTextStream>
#include "arduino.h"


dialogfinance::dialogfinance(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dialogfinance)
{
    ui->setupUi(this);
    ui->tableView_rev->setModel(rtmp->afficher());
    ui->tableView_dp->setModel(dtmp->afficher());

    ui->lineEdit_id->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
    ui->lineEdit_id_dp->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
    ui->lineEdit_montant_rev->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
    ui->lineEdit_montant_dp->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));

}

dialogfinance::~dialogfinance()
{
    delete ui;
}


void dialogfinance::on_pushButton_ajouter_rev_clicked()
{
    QString type=ui->lineEdit_type->text();
    int id=ui->lineEdit_id->text().toInt();
    QString date= ui->dateEdit_rev->date().toString("dd/MM/yyyy");
    int montant=ui->lineEdit_montant_rev->text().toInt();
    std::string aaa = date.toStdString();
    if(ui->lineEdit_type->text().isEmpty() || ui->lineEdit_id->text().isEmpty() || ui->dateEdit_rev->text().isEmpty() || ui->lineEdit_montant_rev->text().isEmpty()){
           QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Veuillez remplir tout les champs"),QMessageBox::Ok); }
        else{
    Revenu rev(type,id,date,montant);
    bool test1=rev.ajouter_revenu();
    if(test1)
    {
        ui->tableView_rev->setModel(rtmp->afficher());
           QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué"),QMessageBox::Ok);
           foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
              le->clear();

           }}
           else
          { QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Ajout non effectué"),QMessageBox::Cancel);}}
}


void dialogfinance::on_pushButton_ajouter_dp_clicked()
{
    QString categorie=ui->lineEdit_categorie->text();
    int id=ui->lineEdit_id_dp->text().toInt();
    QString date= ui->dateEdit_dp->date().toString("dd/MM/yyyy");
    int montant=ui->lineEdit_montant_dp->text().toInt();
    std::string aaa = date.toStdString();
    if(ui->lineEdit_categorie->text().isEmpty() || ui->lineEdit_id_dp->text().isEmpty() || ui->dateEdit_dp->text().isEmpty() || ui->lineEdit_montant_dp->text().isEmpty()){
           QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Veuillez remplir tout les champs"),QMessageBox::Ok); }
        else{
    Depense dp(categorie,id,date,montant);
    bool test1=dp.ajouter_depense();
    if(test1)
    {
        ui->tableView_dp->setModel(dtmp->afficher());
           QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué"),QMessageBox::Ok);
           foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
              le->clear();

           }}
           else
          { QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Ajout non effectué"),QMessageBox::Cancel);}}
}

void dialogfinance::on_pushButton_sup_rev_clicked()
{
    QItemSelectionModel *select = ui->tableView_rev->selectionModel();
    QString readid = select->selectedRows(1).value(0).data().toString();
    QSqlQuery query;
    query.prepare("Delete from revenu where id= :id");
    query.bindValue(":id",readid);
    if(!(readid==NULL))
    {
     QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("suppression effectué"),QMessageBox::Ok);}
    else
      { QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("suppression non effectué"),QMessageBox::Cancel);}
     query.exec();
     ui->tableView_rev->setModel(rtmp->afficher());
}

void dialogfinance::on_pushButton_updaterev_clicked()
{
    QItemSelectionModel *select = ui->tableView_rev->selectionModel();
    QString readtype= select->selectedRows(0).value(0).data().toString();
    QString readid = select->selectedRows(1).value(0).data().toString();
    QString readdate= select->selectedRows(2).value(0).data().toString();
    QString readmont= select->selectedRows(3).value(0).data().toString();

    QSqlQuery query;
    QDate read_date;
    read_date.fromString(readdate,"dd/MM/yyyy");
  // std::string aaa = readid.toStdString();
    if(!(readid==NULL))
    {updaterevenu updaterevenu(nullptr, &readtype, &readid,&read_date,&readmont);
        updaterevenu.setModal(true);
        updaterevenu.exec();
     }
    else
      { QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Selectionner un element de tableau"),QMessageBox::Cancel);}
      query.exec();
       ui->tableView_rev->setModel(rtmp->afficher());
}



void dialogfinance::on_pushButton_supp_dp_clicked()
{
    QItemSelectionModel *select = ui->tableView_dp->selectionModel();
    QString readid = select->selectedRows(1).value(0).data().toString();
    QSqlQuery query;
    query.prepare("Delete from depense where id= :id");
    query.bindValue(":id",readid);
    if(!(readid==NULL))
    {
     QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("suppression effectué"),QMessageBox::Ok);}
    else
      { QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Selectionner un element de tableau"),QMessageBox::Cancel);}
     query.exec();
     ui->tableView_dp->setModel(dtmp->afficher());
}

void dialogfinance::on_pushButton_update_dp_clicked()
{
    QItemSelectionModel *select = ui->tableView_dp->selectionModel();
    QString readcat= select->selectedRows(0).value(0).data().toString();
    QString readid = select->selectedRows(1).value(0).data().toString();
    QString readdate= select->selectedRows(2).value(0).data().toString();
    QString readmont= select->selectedRows(3).value(0).data().toString();

    QSqlQuery query;
    QDate read_date;
    read_date.fromString(readdate,"dd/MM/yyyy");
    if(!(readid==NULL))
    {updatedepense updatedepense(nullptr, &readcat, &readid,&read_date,&readmont);
        updatedepense.setModal(true);
        updatedepense.exec();
     }
    else
      { QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Selectionner un element de tableau"),QMessageBox::Cancel);}
      query.exec();
       ui->tableView_dp->setModel(dtmp->afficher());
}



void dialogfinance::on_pushButton_stat_dp_clicked()
{
          Dialogstat dialogstat(nullptr);
          dialogstat.setModal(true);
          dialogstat.exec();
}

void dialogfinance::on_stat_rev_clicked()
{
    Dialogstat dialogstat(nullptr);
    dialogstat.setModal(true);
    dialogstat.exec();
}

void dialogfinance::on_pushButton_search_rev_clicked()
{
    if(ui->lineEdit_supp_rev->text().isEmpty()){
           QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Veuillez remplir le champ ID"),QMessageBox::Ok);
    }
    else{
    int res = ui->lineEdit_supp_rev->text().toInt();
    ui->tableView_rev->setModel(rtmp->rechercher(res));}
    foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
       le->clear();

    }
}

void dialogfinance::on_pushButton_search_dp_clicked()
{
    if(ui->lineEdit_supp_dp->text().isEmpty()){
           QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Veuillez remplir le champ ID"),QMessageBox::Ok);
    }
    else{
    int res = ui->lineEdit_supp_dp->text().toInt();
    ui->tableView_dp->setModel(dtmp->rechercher(res));}
    foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
       le->clear();

    }
}




void dialogfinance::on_pushButton_fich_rev_clicked()
{
    QFile file("fiche revenu.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    return;
    QSqlQuery query;
    query.exec("select * from revenu");
    QTextStream out(&file);
    out << "type" << "\t";
    out << "id" << "\t";
    out << "date" << "\t";
    out << "montant"<< "\n";
    while(query.next())
    {
        QString type = query.value(0).toString();
        QString id = query.value(1).toString();
        QString date = query.value(2).toString();
        QString mont = query.value(3).toString();

         out << type << "\t";
         out << "\t" <<id << "\t";
         out << "\t"<< date << "\t";
         out << "\t"<< mont<< "\n";

    }
}

void dialogfinance::on_pushButton_fich_dp_clicked()
{
    QFile file("fiche depense.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    return;
    QSqlQuery query;
    query.exec("select * from depense");
    QTextStream out(&file);
    out << "categorie" << "\t";
    out << "id" << "\t";
    out << "date" << "\t";
    out << "montant"<< "\n";
    while(query.next())
    {
        QString cate = query.value(0).toString();
        QString id = query.value(1).toString();
        QString date = query.value(2).toString();
        QString mont = query.value(3).toString();

         out << cate << "\t";
         out << "\t" <<id << "\t";
         out << "\t"<< date << "\t";
         out << "\t"<< mont<< "\n";

    }
}

void dialogfinance::on_pushButton_trie_rev_clicked()
{
    if(ui->radioButton_az_rev->isChecked()){
        ui->tableView_rev->setModel(rtmp->trie_az());}
    if(ui->radioButton_date_rev->isChecked()){
        ui->tableView_rev->setModel(rtmp->trie_date());}
    if(ui->radioButton_montant_rev->isChecked()){
       ui->tableView_rev->setModel(rtmp->trie_mont());}
}

void dialogfinance::on_pushButton_trie_dp_clicked()
{
    if(ui->radioButton_az_dp->isChecked()){
        ui->tableView_dp->setModel(dtmp->trie_az());}
    if(ui->radioButton_date_dp->isChecked()){
        ui->tableView_dp->setModel(dtmp->trie_date());}
    if(ui->radioButton_montant_dp->isChecked()){
       ui->tableView_dp->setModel(dtmp->trie_mont());}
}
