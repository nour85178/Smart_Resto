#include "dialogproduit.h"
#include "ui_dialogproduit.h"
#include "produit.h"
#include<QMessageBox>
#include<iostream>
#include<QTableView>
#include "updateproduit.h"
#include<QModelIndex>
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QAbstractItemModel>
#include<QFile>
#include <QSortFilterProxyModel>
#include<QRegExpValidator>
#include <QDoubleValidator>
#include<QTextStream>
#include<QSqlRecord>
#include<QSqlField>
#include <stdio.h>
#include <string.h>
#include <QPrinter>
#include<QFileDialog>
#include <QPainter>
#include <QPrintDialog>
#include <QPrinterInfo>
#include <QTextDocument>

dialogproduit::dialogproduit(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dialogproduit)
{
    ui->setupUi(this);
    ui->tableView->setModel(ptmp->afficher());
    ui->lineEdit_ref->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
    ui->lineEdit_qte->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
    ui->lineEdit_pr->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
    ui->lineEdit_montant->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
}

dialogproduit::~dialogproduit()
{
    delete ui;
}

void dialogproduit::on_pushButton_ajouter_clicked()
{
  QString designation=ui->lineEdit_des->text();
  int ref=ui->lineEdit_ref->text().toInt();
  int qte=ui->lineEdit_qte->text().toInt();
  int PrixUnit=ui->lineEdit_pr->text().toInt();
 /* int mon=0;
  mon=qte*PrixUnit;
  QString montant = QString::number(mon);
  ui->lineEdit_montant->setText(montant);*/
  int montant=ui->lineEdit_montant->text().toInt();


   if(ui->lineEdit_ref->text().isEmpty() || ui->lineEdit_des->text().isEmpty() || ui->lineEdit_qte->text().isEmpty() || ui->lineEdit_montant->text().isEmpty()|| ui->lineEdit_pr->text().isEmpty()){
          QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Veuillez remplir tout les champs"),QMessageBox::Ok); }
       else{

       produit p(designation,ref,qte,PrixUnit,montant);
       bool test1=p.ajouter_produit();
  if(test1)
  {
       ui->tableView->setModel(ptmp->afficher());
         QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué"),QMessageBox::Ok);
         foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
            le->clear();

         }}

         else
        { QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Ajout non effectué"),QMessageBox::Cancel);}}

}

void dialogproduit::on_pushButton_supp_clicked()
{
    QItemSelectionModel *select = ui->tableView->selectionModel();
    QString readref = select->selectedRows(1).value(0).data().toString();
    QSqlQuery query;
    query.prepare("Delete from produit where ref= :ref");
    query.bindValue(":ref",readref);
    if(!(readref==NULL))
    {
     QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("suppression effectué"),QMessageBox::Ok);}
    else
      { QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Selectionner un element de tableau"),QMessageBox::Cancel);}
      query.exec();
       ui->tableView->setModel(ptmp->afficher());
}

void dialogproduit::on_pushButton_edit_clicked()
{
    QItemSelectionModel *select = ui->tableView->selectionModel();
    QString readdes= select->selectedRows(0).value(0).data().toString();
    QString readref = select->selectedRows(1).value(0).data().toString();
    QString readqte= select->selectedRows(2).value(0).data().toString();
    QString readpr= select->selectedRows(3).value(0).data().toString();
    QString readmont= select->selectedRows(4).value(0).data().toString();

    QSqlQuery query;
   std::string aaa = readref.toStdString();
    if(!(readref==NULL))
    {UpdateProduit UpdateProduit(nullptr, &readref, &readdes,&readqte,&readpr,&readmont);
        UpdateProduit.setModal(true);
        UpdateProduit.exec();
     }
    else
      { QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Selectionner un element de tableau"),QMessageBox::Cancel);}
      query.exec();
       ui->tableView->setModel(ptmp->afficher());
}


void dialogproduit::on_pushButton_7_clicked()
{
    QFile file("fiche produit.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    return;
    QSqlQuery query;
    query.exec("select * from produit");
    QTextStream out(&file);
    out << "desination" << "\t";
    out << "reference" << "\t";
    out << "quantite" << "\t";
    out <<"prix unit" << "\t";
    out << "montant"<< "\n";
    while(query.next())
    {
        QString des = query.value(0).toString();
        QString ref = query.value(1).toString();
        QString qte = query.value(2).toString();
        QString pr = query.value(3).toString();
        QString mont = query.value(4).toString();

         out << des << "\t";
         out << "\t" <<ref << "\t";
         out << "\t"<< qte << "\t";
         out << "\t" << pr << "\t";
         out << "\t"<< mont<< "\n";

    }

}

void dialogproduit::on_pushButton_trie_clicked()
{
   if(ui->radioButton_az->isChecked()){
       ui->tableView->setModel(ptmp->trie_az());}
   if(ui->radioButton_qte->isChecked()){
       ui->tableView->setModel(ptmp->trie_qte());}
   if(ui->radioButton_montant->isChecked()){
      ui->tableView->setModel(ptmp->trie_mont());}
}


void dialogproduit::on_pushButton_rech_clicked()
{
    if(ui->lineEdit_search->text().isEmpty()){
           QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Veuillez remplir le champ ref"),QMessageBox::Ok); }
    else{
    int res = ui->lineEdit_search->text().toInt();
    ui->tableView->setModel(ptmp->rechercher(res));}
    foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
       le->clear();

    }
}

void dialogproduit::on_pushButton_pdf_produit_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Open PDF", QString(), "*.pdf");
            if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append("Exporter tableau.pdf"); }

            QPrinter printer(QPrinter::PrinterResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setPaperSize(QPrinter::A4);
            printer.setOutputFileName(fileName);

            QTextDocument doc;
            QSqlQuery q;
            q.prepare("SELECT * from produit");
            q.exec();
    QString pdf="<br> < img src='C:/Users/asus/Desktop/projetintgre/Smart_Home_Delivery_2A7/moto.jpg' height='42' width='144'/> <h1  style='color:blue'>   Les produits de notre societé :  <br></h1>\n <br>  <table>  <tr>  <th> DESIGNATION </th> <th> REF </th> <th> QTE </th> <th> PRIXUNIT </th>  <th> MONTANT </th>  </tr>" ;


            while ( q.next()) {

                pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"    </td>  <td>   " + q.value(1).toString()+" </td>  <td>  "+q.value(2).toString() +"   </td>  <td>    "+q.value(3).toString()+"</td>       <td>"+q.value(4).toString()+"    <td>  <td>"+q.value(5).toString()+"            </td>" ;

            }
            doc.setHtml(pdf);
            doc.setPageSize(printer.pageRect().size());
            doc.print(&printer);
}
