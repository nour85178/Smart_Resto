#include "updatedepense.h"
#include "ui_updatedepense.h"
#include "depense.h"
#include<QMessageBox>


updatedepense::updatedepense(QWidget *parent,QString *cata,QString *ida,QDate *datea,QString *monta) :
    QDialog(parent),
    ui(new Ui::updatedepense)
{
    ui->setupUi(this);
    ui->lineEdit_categorie_up->setText(*cata);
    ui->lineEdit_id_dp_up->setText(*ida);
    ui->dateEdit_dp_up->setDate(*datea);
    ui->lineEdit_montant_dp_up->setText(*monta);
    ui->lineEdit_id_dp_up->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
    ui->lineEdit_montant_dp_up->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
}

updatedepense::~updatedepense()
{
    delete ui;
}

void updatedepense::on_buttonBox_accepted()
{
    QString categorie=ui->lineEdit_categorie_up->text();
    int id=ui->lineEdit_id_dp_up->text().toInt();
    QString date= ui->dateEdit_dp_up->date().toString("dd/MM/yyyy");
    int montant=ui->lineEdit_montant_dp_up->text().toInt();
    std::string aaa = date.toStdString();
    if(ui->lineEdit_categorie_up->text().isEmpty() || ui->lineEdit_id_dp_up->text().isEmpty() || ui->dateEdit_dp_up->text().isEmpty() || ui->lineEdit_montant_dp_up->text().isEmpty()){
           QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Veuillez remplir tout les champs"),QMessageBox::Ok); }
        else{
    Depense dp(categorie,id,date,montant);
    bool test1=dp.update_depense();
    if(test1)
    {
           QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Modification effectué"),QMessageBox::Ok);
    }
           else
          { QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Modification non effectué"),QMessageBox::Cancel);}}

}
