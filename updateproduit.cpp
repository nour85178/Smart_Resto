#include "updateproduit.h"
#include "ui_updateproduit.h"
#include "produit.h"
#include<QMessageBox>
#include<iostream>
#include<QTableView>

UpdateProduit::UpdateProduit(QWidget *parent, QString *refa,QString *desa,QString *qtea,QString *pra,QString *monta) :
    QDialog(parent),
    ui(new Ui::UpdateProduit)
{
    ui->setupUi(this);
    ui->lineEdit_ref_up->setText(*refa);
    ui->lineEdit_des_up->setText(*desa);
    ui->lineEdit_qte_up->setText(*qtea);
    ui->lineEdit_pr_up->setText(*pra);
    ui->lineEdit_montant_up->setText(*monta);

    ui->lineEdit_ref_up->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
    ui->lineEdit_qte_up->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
    ui->lineEdit_pr_up->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
    ui->lineEdit_montant_up->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));

}

UpdateProduit::~UpdateProduit()
{
    delete ui;
}

void UpdateProduit::on_buttonBox_accepted()
{

    QString designation=ui->lineEdit_des_up->text();
    int ref=ui->lineEdit_ref_up->text().toInt();
    int qte=ui->lineEdit_qte_up->text().toInt();
    int PrixUnit=ui->lineEdit_pr_up->text().toInt();
    int montant=ui->lineEdit_montant_up->text().toInt();
    std::cout<<ref;
    if(ui->lineEdit_des_up->text().isEmpty() || ui->lineEdit_ref_up->text().isEmpty() || ui->lineEdit_qte_up->text().isEmpty() || ui->lineEdit_pr_up->text().isEmpty()|| ui->lineEdit_pr_up->text().isEmpty()){
           QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Veuillez remplir tout les champs"),QMessageBox::Ok); }
        else{


    produit up(designation,ref,qte,PrixUnit,montant);
    bool test1=up.update_produit();
     std::cout<<test1;
    if(test1)
    {
           QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Modification effectué"),QMessageBox::Ok);
         }
           else
          { QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Modification non effectué"),QMessageBox::Cancel);}}
}
