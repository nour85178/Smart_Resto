#include "updaterevenu.h"
#include "ui_updaterevenu.h"
#include "revenu.h"
#include<QMessageBox>

updaterevenu::updaterevenu(QWidget *parent,QString *typea,QString *ida,QDate *datea,QString *monta) :
    QDialog(parent),
    ui(new Ui::updaterevenu)
{
    ui->setupUi(this);
    ui->lineEdit_type_up->setText(*typea);
    ui->lineEdit_id_rev_up->setText(*ida);
    ui->dateEdit_rev_up->setDate(*datea);
    ui->lineEdit_montant_rev_up->setText(*monta);
    ui->lineEdit_id_rev_up->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
    ui->lineEdit_montant_rev_up->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
}

updaterevenu::~updaterevenu()
{
    delete ui;
}

void updaterevenu::on_buttonBox_accepted()
{
    QString type=ui->lineEdit_type_up->text();
    int id=ui->lineEdit_id_rev_up->text().toInt();
    QString date= ui->dateEdit_rev_up->date().toString("dd/MM/yyyy");
    int montant=ui->lineEdit_montant_rev_up->text().toInt();
    std::string aaa = date.toStdString();
    if(ui->lineEdit_type_up->text().isEmpty() || ui->lineEdit_id_rev_up->text().isEmpty() || ui->dateEdit_rev_up->text().isEmpty() || ui->dateEdit_rev_up->text().isEmpty()){
           QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Veuillez remplir tout les champs"),QMessageBox::Ok); }
        else{

    Revenu rev(type,id,date,montant);
    bool test1=rev.update_revenu();
    if(test1)
    {
           QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Modification effectué"),QMessageBox::Ok);
    }
           else
          { QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Modification non effectué"),QMessageBox::Cancel);}}
}
