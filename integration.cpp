#include "integration.h"
#include "ui_integration.h"
#include "integration.h"
#include "ui_integration.h"
#include <QPrinter>
#include<QFileDialog>
#include <QPainter>
#include <QPrintDialog>
#include <QPrinterInfo>
#include <QBarSet>
#include<QtCharts>

integration::integration(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::integration)
{
    ui->setupUi(this);
    timer_1s = new QTimer(this);
    QObject::connect(timer_1s, SIGNAL(timeout()), this, SLOT(showTime()));
    timer_1s->start(1000);

    timer_2s = new QTimer(this);
    QObject::connect(timer_2s, SIGNAL(timeout()), this, SLOT(show+Time()));
    timer_2s->start(1000);



    listSexe <<"Femme"<<"Homme"<<"Autre";
    ui->sexe_e->clear();
    ui->sexe_e->addItems(listSexe);
    QIntValidator *id_v=new QIntValidator(1,99999);
    ui->id_e->setValidator(id_v);


    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));


    ui->moto_emp->setPixmap(QPixmap("C:/Users/asus/Desktop/projetintgre/Smart_Home_Delivery_2A7/moto.jpg"));
    ui->aj_emp->setPixmap(QPixmap("C:/Users/asus/Desktop/projetintgre/Smart_Home_Delivery_2A7/add.png"));
    ui->mod_emp->setPixmap(QPixmap("C:/Users/asus/Desktop/projetintgre/Smart_Home_Delivery_2A7/edit.png"));
    ui->su_emp->setPixmap(QPixmap("C:/Users/asus/Desktop/projetintgre/Smart_Home_Delivery_2A7/delete.png"));
    ui->re_emp->setPixmap(QPixmap("C:/Users/asus/Desktop/projetintgre/Smart_Home_Delivery_2A7/search.png"));
    ui->kamyoun->setPixmap(QPixmap("C:/Users/asus/Desktop/projetintgre/Smart_Home_Delivery_2A7/deliver car.png"));
    ui->moutour_dep->setPixmap(QPixmap("C:/Users/asus/Desktop/projetintgre/Smart_Home_Delivery_2A7/moto.jpg"));
    ui->aj_dep->setPixmap(QPixmap("C:/Users/asus/Desktop/projetintgre/Smart_Home_Delivery_2A7/add.png"));
    ui->mod_dep->setPixmap(QPixmap("C:/Users/asus/Desktop/projetintgre/Smart_Home_Delivery_2A7/edit.png"));
    ui->su_dep->setPixmap(QPixmap("C:/Users/asus/Desktop/projetintgre/Smart_Home_Delivery_2A7/delete.png"));
    ui->re_dep->setPixmap(QPixmap("C:/Users/asus/Desktop/projetintgre/Smart_Home_Delivery_2A7/search.png"));
    ui->kamyounab->setPixmap(QPixmap("C:/Users/asus/Desktop/projetintgre/Smart_Home_Delivery_2A7/deliver car.png"));
    ui->karhabet_malek->setPixmap(QPixmap("C:/Users/asus/Desktop/projetintgre/Smart_Home_Delivery_2A7/deliver car.png"));


    /************************gestion heure et date **********************************/
    /**************heure************************/
    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showtime()));
    timer->start();
    /*************************date*****************/
    QDate date = QDate ::currentDate();
    QString datee=date.toString();
    ui->date->setText(datee);
    ui->date_2->setText(datee);

    ui->atype1->setValidator(new QRegExpValidator( QRegExp("[A-Za-z ]*"), this ));
    ui->lineEdit_modtype->setValidator(new QRegExpValidator( QRegExp("[A-Za-z ]*"), this ));
    ui->atype2->setValidator(new QRegExpValidator( QRegExp("[A-Za-z ]*"), this ));
    ui->lineEdit_modtype_2->setValidator(new QRegExpValidator( QRegExp("[A-Za-z ]*"), this ));
    ui->aprix1->setValidator(new QIntValidator(0,9999999,this));
    ui->aprix2->setValidator(new QIntValidator(0,9999999,this));
    ui->lineEdit_modprix->setValidator(new QIntValidator(0,9999999,this));
    ui->lineEdit_modprix_2->setValidator(new QIntValidator(0,9999999,this));
}
QTranslator* translator = new QTranslator;


integration::~integration()
{
    delete ui;
}

void integration::showTime()
{

     ui->Digital_clock->setText(QTime::currentTime().toString("hh:mm:ss"));
     ui->Ctime->setText(QTime::currentTime().toString("hh:mm:ss"));
      ui->Rtime->setText(QTime::currentTime().toString("hh:mm:ss"));



}
void integration::sendMail()
{
    Smtp* smtp = new Smtp("fahmimankous@gmail.com","Azertyuiop","smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail("", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void integration::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void integration::on_ajout_dep_clicked()
{
    departement d(ui->id_ch->text().toInt(),ui->nom_ch->text(),ui->date_ch->date(),ui->nombre_ch->text().toInt());
    bool test=d.ajouter();
    if(test){
        QMessageBox::information(nullptr, QObject::tr("Departement"),
                    QObject::tr("Departement ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->table_depart->setModel(tmpdep.afficher());
        ui->id_ch->setText("");
        ui->nom_ch->setText("");
        ui->date_ch->setDate(QDate(2000,01,01));
        ui->nombre_ch->setText("");

        ui->comboBox_iddepartement->clear();
        ui->comboBox_iddepartement->addItems(tmpdep.listDepartement());

    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Departement"),
                    QObject::tr("Erreur!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void integration::on_supp_dep_clicked()
{
    bool test =tmpdep.supprimer(ui->id_ch->text().toInt());
    if(test){
        QMessageBox::information(nullptr, QObject::tr("Departement"),
                    QObject::tr("departement suppriméé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->table_depart->setModel(tmpdep.afficher());
         ui->id_ch->setText("");
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Departement"),
                    QObject::tr("Erreur!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void integration::on_modif_dep_clicked()
{
    departement d(ui->id_ch->text().toInt(),ui->nom_ch->text(),ui->date_ch->date(),ui->nombre_ch->text().toInt());
    bool test=d.modifier(ui->id_ch->text().toInt());
    if(test){
        QMessageBox::information(nullptr, QObject::tr("Departement"),
                    QObject::tr("departement modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->table_depart->setModel(tmpdep.afficher());
        ui->id_ch->setText("");
        ui->nom_ch->setText("");
        ui->date_ch->setDate(QDate(2000,01,01));
        ui->nombre_ch->setText("");
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Departement "),
                    QObject::tr("Erreur!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void integration::on_id_ch_textChanged(const QString &arg1)
{
    departement d=tmpdep.trouver(ui->id_ch->text().toInt());
    ui->nom_ch->setText(d.getnom());
    ui->date_ch->setDate(d.getdate_cr());
    ui->nombre_ch->setText(QString::number(d.getnombre_emp()));
}


void integration::on_recherche_departement_textChanged(const QString &arg1)
{

    bool nom=ui->checkBox_rech_nom_dep->isChecked();
    bool id=ui->checkBox_rech_id_chef->isChecked();
    bool date_c=ui->checkBox_rech_date_c->isChecked();
    const QString rech=ui->recherche_departement->text();

    if((nom && id && date_c) || (!nom && !id && !date_c)){
        ui->table_depart->setModel(tmpdep.recherche_dep(rech));
        qDebug() <<"3!!";
    }
    else{
        if(nom){
            if(id){
                ui->table_depart->setModel(tmpdep.recherche_nom_id(rech));
                qDebug()<<"nom w id";
            }
            else if(date_c){
                ui->table_depart->setModel(tmpdep.recherche_nom_date(rech));
                qDebug()<<"nom w date";
            }
            else{
                ui->table_depart->setModel(tmpdep.recherche_nom(rech));
            }
        }
        else if(id){
            if(date_c){
                ui->table_depart->setModel(tmpdep.recherche_id_date(rech));
                qDebug()<<"id w date";
            }
            else{
                ui->table_depart->setModel(tmpdep.recherche_id(rech));
            }
        }
        else{
            ui->table_depart->setModel(tmpdep.recherche_date(rech));
        }
    }

}

void integration::on_checkBox_rech_nom_dep_clicked()
{
    ui->table_depart->setModel(tmpdep.recherche_nom(ui->recherche_departement->text()));
}

void integration::on_checkBox_rech_id_chef_clicked()
{

    ui->table_depart->setModel(tmpdep.recherche_id(ui->recherche_departement->text()));
}


void integration::on_checkBox_rech_date_c_clicked()
{
    ui->table_depart->setModel(tmpdep.recherche_date(ui->recherche_departement->text()));
}

void integration::on_radiotri_date_c_2_clicked()
{
    ui->table_depart->setModel(tmpdep.tridate_cr());
}

void integration::on_radiotri_nom_dep_clicked()
{
    ui->table_depart->setModel(tmpdep.trinom());
}

void integration::on_radiotri_id_dep_clicked()
{

    ui->table_depart->setModel(tmpdep.tri_idchef());
}

void integration::on_ajoute_e_clicked()
{

    /******************************/
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/chaab/Desktop/Smart_Home_Delivery_2A7-master/button-10.wav"));
    if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }


    employe e(ui->id_e->text().toInt(),ui->nom_e->text(),ui->prenom_e->text(),ui->date_naiss_e->date(),ui->sexe_e->currentText(),ui->poste_e->text(),ui->comboBox_iddepartement->currentText().toInt());
    bool test=e.ajouter();
    if(test){
        QMessageBox::information(nullptr, QObject::tr("Employe"),
                    QObject::tr("employe ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->table_e->setModel(tmpemploye.afficher());
        ui->id_e->setText("");
        ui->nom_e->setText("");
        ui->prenom_e->setText("");
        ui->date_naiss_e->setDate(QDate(2000,01,01));
        ui->sexe_e->clear();
        ui->sexe_e->addItems(listSexe);
        ui->poste_e->setText("");
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Employe"),
                    QObject::tr("Erreur!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void integration::on_pushButton_2_clicked()
{

    bool test =tmpemploye.supprimer(ui->id_e->text().toInt());
    if(test){
        QMessageBox::information(nullptr, QObject::tr("Employe"),
                    QObject::tr("employe suppriméé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->table_e->setModel(tmpemploye.afficher());
         ui->id_e->setText("");
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Employe"),
                    QObject::tr("Erreur!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void integration::on_pushButton_3_clicked()
{
    employe e(ui->id_e->text().toInt(),ui->nom_e->text(),ui->prenom_e->text(),ui->date_naiss_e->date(),ui->sexe_e->currentText(),ui->poste_e->text(),ui->comboBox_iddepartement->currentText().toInt());
    bool test=e.modifier(ui->id_e->text().toInt());
    if(test){
        QMessageBox::information(nullptr, QObject::tr("Employe"),
                    QObject::tr("employe modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->table_e->setModel(tmpemploye.afficher());
        ui->id_e->setText("");
        ui->nom_e->setText("");
        ui->prenom_e->setText("");
        ui->date_naiss_e->setDate(QDate(2000,01,01));
        ui->sexe_e->clear();
        ui->sexe_e->addItems(listSexe);
        ui->poste_e->setText("");
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Employe"),
                    QObject::tr("Erreur!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void integration::on_id_e_textChanged(const QString &arg1)
{

    employe e=tmpemploye.trouver(ui->id_e->text().toInt());
    ui->nom_e->setText(e.getnom());
    ui->prenom_e->setText(e.getprenom());
    ui->date_naiss_e->setDate(e.getdate_naiss());

    ui->poste_e->setText(e.getposte());
}


void integration::on_recherche_employe_textChanged(const QString &arg1)
{
    bool nom=ui->checkBox_rech_nom->isChecked();
    bool prenom=ui->checkBox_rech_prenom->isChecked();
    bool date_n=ui->checkBox_rech_date_n->isChecked();
    const QString rech=ui->recherche_employe->text();

    if((nom && prenom && date_n) || (!nom && !prenom && !date_n)){
        ui->table_e->setModel(tmpemploye.recherche(rech));
        qDebug() <<"3!!";
    }
    else{
        if(nom){
            if(prenom){
                ui->table_e->setModel(tmpemploye.recherche_n_p(rech));
                qDebug()<<"nom w prenom";
            }
            else if(date_n){
                ui->table_e->setModel(tmpemploye.recherche_n_d(rech));
                qDebug()<<"nom w date";
            }
            else{
                ui->table_e->setModel(tmpemploye.recherche_n(rech));
            }
        }
        else if(prenom){
            if(date_n){
                ui->table_e->setModel(tmpemploye.recherche_p_d(rech));
                qDebug()<<"prenom w date";
            }
            else{
                ui->table_e->setModel(tmpemploye.recherche_p(rech));
            }
        }
        else{
            ui->table_e->setModel(tmpemploye.recherche_d(rech));
        }
    }

}



void integration::on_checkBox_rech_nom_clicked()
{
    ui->table_e->setModel(tmpemploye.recherche(ui->recherche_employe->text()));
}

void integration::on_checkBox_rech_prenom_clicked()
{
    ui->table_e->setModel(tmpemploye.recherche_p(ui->recherche_employe->text()));
}


void integration::on_checkBox_rech_date_n_clicked()
{

    ui->table_e->setModel(tmpemploye.recherche_d(ui->recherche_employe->text()));
}


void integration::on_radiotri_date_n_clicked()
{
     ui->table_e->setModel(tmpemploye.tridate_naissance());
}

void integration::on_radiotri_prenom_clicked()
{
    ui->table_e->setModel(tmpemploye.tri_prenom());
}

void integration::on_radiotri_id_emp_clicked()
{
    ui->table_e->setModel(tmpemploye.tri_id());
}

void integration::on_pushButton_12_clicked()
{
    ui->tabclient->setModel(tmpclient.afficher());


      int CIN=ui->lineEdit_CIN->text().toInt();
        QString prenom=ui->lineEdit_prenom->text();
        QString nom=ui->lineEdit_nom->text();
        QString type_de_produit=ui->comboBox_2->currentText();
      // QString etat=ui->comboBox_etat->currentText();
        QString etat=ui->etat->text();


          if( nom.isEmpty() || prenom.isEmpty() || type_de_produit.isEmpty() || etat.isEmpty()  )
             {
                 QMessageBox::information(0,qApp->tr("erreur"),
                                       qApp->tr("Veuillez remplir tous les champs !"),QMessageBox::Cancel);
             }

       Client C(CIN,nom,prenom,type_de_produit,etat);
       bool test=C.ajouter();
               QMessageBox msgBox;
              // if(test)
                   //ui->tabclient->setModel(tmpclient.afficher());

       if(test)
         {
           ui->tabclient->setModel(tmpclient.afficher());

           msgBox.setText("Client ajouté avec succés");

       }
       else
           msgBox.setText("Echec d'ajout");
           msgBox.exec();
      }


void integration::on_pushButton_11_clicked()
{
    ui->tabclient->setModel(tmpclient.afficher());
        {
            int CIN=ui->lineEdit_supp->text().toInt();
            bool test=tmpclient.supprimer(CIN);
            if(test)
            {
                ui->tabclient->setModel(tmpclient.afficher());

                QMessageBox::information(nullptr, QObject::tr("Produit a supprimer"),
                             QObject::tr("Produit supprimer.\n"
                                         "Click Cancel to exit."), QMessageBox::Ok);
            }
            else {
                            QMessageBox::critical(nullptr, QObject::tr("Produit a supprimer"),
                     QObject::tr("Produit non supprimer.\n"
                                 "Click Cancel to exit."), QMessageBox::Ok);
                   }

        }
}

void integration::on_pushButton_13_clicked()
{

    int CIN=ui->modifcin->text().toInt();
    QString nom=ui->modifnom->text();
    QString prenom=ui->modifprenom->text();
    QString etat=ui->modifetat->text();
    QString type_de_produit=ui->modiftype->currentText();
    Client c(CIN,nom,prenom,etat,type_de_produit);
    bool test=c.modifier(CIN,nom,prenom,type_de_produit,etat);
    if(test)
    {
        ui->tabclient->setModel(tmpclient.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("modifier un Equipe"),
                          QObject::tr("equipe modifié.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        ui->tabreclamation->setModel(tmprecla.afficher());//refresh

}


void integration::on_Load_2_clicked()
{
    ui->tabclient->setModel(tmpclient.afficher());
}


void integration::on_SetatC_clicked()
{
    QString etat=ui->Cinrecherche_2->text();

     ui->tabclient->setModel(tmpclient.rechercheretat(etat));
}


void integration::on_StypeC_clicked()
{
    QString type=ui->Cinrecherche_3->text();

      ui->tabclient->setModel(tmpclient.recherchertype(type));
}


void integration::on_SnomC_clicked()
{
    QString nom=ui->Cinrecherche_4->text();

   ui->tabclient->setModel(tmpclient.recherchernom(nom));
}



void integration::on_checkBox_4_clicked()
{
    ui->tabclient->setModel(tmpclient.triclientpartype());
}


void integration::on_checkBox_5_clicked()
{
    ui->tabclient->setModel(tmpclient.triclientparnom());
}


void integration::on_checkBox_6_clicked()
{
    ui->tabclient->setModel(tmpclient.triclientparetat());
}

void integration::on_pushButton_ajouter_reclamation_clicked()
{
    ui->tabreclamation->setModel(tmprecla.afficher());

       int CIN=ui->lineEdit_CIN_2->text().toInt();

           QString nom=ui->lineEdit_nom_2->text();
           QString prenom=ui->lineEdit_prenom_2->text();
           QString type_de_produit=ui->comboBox_3->currentText();

           QString etat=ui->lineEdit_etat_2->text();
           QString date_depot=ui->dated->text();

           if( nom.isEmpty() || prenom.isEmpty() || type_de_produit.isEmpty() || etat.isEmpty() || date_depot.isEmpty() )
              {
                  QMessageBox::information(0,qApp->tr("erreur"),
                                        qApp->tr("Veuillez remplir tous les champs !"),QMessageBox::Cancel);
              }

        Reclamation R(CIN,nom,prenom,type_de_produit,etat,date_depot);
        bool test=R.ajouter();


                QMessageBox msgBox;
               // if(test)
                    //ui->tabclient->setModel(tmpclient.afficher());

        if(test)
          {  msgBox.setText("Ajout avec succes.");
            ui->tabreclamation->setModel(tmprecla.afficher());


        }
        else
        {
            msgBox.setText("Echec d'ajout");
            msgBox.exec();
       }
   }







void integration::on_pushButton_suppR_clicked()
{
    ui->tabreclamation->setModel(tmprecla.afficher());


            int CIN=ui->lineEdit_supp_2->text().toInt();
            bool test=tmprecla.supprimer(CIN);
            if(test)
            {
                ui->tabclient->setModel(tmprecla.afficher());

                QMessageBox::information(nullptr, QObject::tr("Reclamation a supprimer"),
                             QObject::tr("Reclamation supprimee.\n"
                                         "Click Cancel to exit."), QMessageBox::Ok);
            }
            else {
                            QMessageBox::critical(nullptr, QObject::tr("Reclamation a supprimer"),
                     QObject::tr("Reclamation non supprimee.\n"
                                 "Click Cancel to exit."), QMessageBox::Ok);
                   }


}


void integration::on_modifierR_clicked()
{

    int CIN=ui->cinmodif->text().toInt();
    QString type_de_produit=ui->choixmodif->currentText();
    QString prenom=ui->nommodif->text();
    QString nom=ui->prenommodif->text();
    QString date_depot=ui->dateM->text();
    QString etat=ui->etatmodif->text();


    Reclamation r(CIN,prenom,nom,type_de_produit,etat,date_depot);
           bool test=r.modifier(CIN,prenom,nom,type_de_produit,etat,date_depot);
           if(test)
           {
               ui->tabreclamation->setModel(tmprecla.afficher());//refresh
               QMessageBox::information(nullptr, QObject::tr("modifier un Equipe"),
                                 QObject::tr("equipe modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
           }
           else
               ui->tabreclamation->setModel(tmprecla.afficher());//refresh
           //    QMessageBox::critical(nullptr, QObject::tr("modifier un Equipe"),
                             //    QObject::tr("Erreur !.\n"
                               //              "Click Cancel to exit."), QMessageBox::Cancel);
}



void integration::on_cinchercher_clicked()
{
    int CIN=ui->Cinrecherche->text().toInt();
      ui->tabreclamation->setModel(tmprecla.recherchereclamationparcin(CIN));
}


void integration::on_cinchercher_2_clicked()
{
    QString etat=ui->etatrecherche->text();

    ui->tabreclamation->setModel(tmprecla.recherchereclamationparetat(etat));
}


void integration::on_recherchedate_2_clicked()
{
    QString date=ui->recherchedate->text();

   ui->tabreclamation->setModel(tmprecla.recherchereclamationpardate(date));
}

void integration::on_checkBox_25_clicked()
{
    ui->tabreclamation->setModel(tmprecla.trireclamationpardate());

}


void integration::on_checkBox_26_clicked()
{
    ui->tabreclamation->setModel(tmprecla.trireclamationparnom());

}


void integration::on_checkBox_27_clicked()
{
    ui->tabreclamation->setModel(tmprecla.trireclamationparetat());

}

void integration::on_Load_3_clicked()
{
    ui->tabreclamation->setModel(tmprecla.afficher());
}


void integration::on_sendMail_clicked()
{
    mailing* smtp = new mailing("projet.esprit11@gmail.com","esprit2020", "smtp.gmail.com", 465);

           smtp->sendMail("projet.esprit11@gmail.com", ui->ecrire_mail->text() , ui->ecrire_objet->text() ,ui->ecrire_txt->toPlainText());
}

void integration::on_EnglishON_clicked()
{
    if(translator->load(":/english.qm")){
      qApp->removeTranslator(translator); // Remove the translator if was used before
      qApp->installTranslator(translator); // Install again the translator to force a new translation.
      ui->retranslateUi(this);}
}

void integration::on_FrenchON_clicked()
{
    qApp->removeTranslator(translator); // Remove the translator if was used before
    ui->retranslateUi(this);
}




void integration::on_Load_4_clicked()
{
    ui->tabclient->setModel(tmpclient.afficher());
}

void integration::on_loadC_clicked()
{
    ui->tabclient->setModel(tmpclient.afficher());

}

void integration::on_stat_2_clicked()
{
    ui->tabclient->setModel(tmpclient.afficher());

}

void integration::on_sendMail_2_clicked()
{
    mailing* smtp = new mailing("projet.esprit11@gmail.com","esprit2020", "smtp.gmail.com", 465);

           smtp->sendMail("projet.esprit11@gmail.com", ui->ecrire_mail->text() , ui->ecrire_objet->text() ,ui->ecrire_txt->toPlainText());
}


void integration::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void integration::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void integration::on_gestion_currentChanged(int index)
{
    ui->comboBox_iddepartement->clear();
    ui->comboBox_iddepartement->addItems(tmpdep.listDepartement());
}



void integration::on_print_button_clicked()
{

    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Open PDF", QString(), "*.pdf");
            if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append("Exporter tableau.pdf"); }

            QPrinter printer(QPrinter::PrinterResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setPaperSize(QPrinter::A4);
            printer.setOutputFileName(fileName);

            QTextDocument doc;
            QSqlQuery q;
            q.prepare("SELECT * from employe");
            q.exec();
    QString pdf="<br> < img src='C:/Users/asus/Desktop/projetintgre/Smart_Home_Delivery_2A7/deliver car.png' height='42' width='144'/> <h1  style='color:blue'>   Les employés de notre societé :  <br></h1>\n <br>  <table>  <tr>  <th> ID </th> <th> NOM </th> <th> PRENOM </th> <th> DATE NAISSANCE </th>  <th> SEXE </th>  </tr>" ;


            while ( q.next()) {

                pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"    </td>  <td>   " + q.value(1).toString()+" </td>  <td>  "+q.value(2).toString() +"   </td>  <td>    "+q.value(3).toString()+"</td>       <td>"+q.value(4).toString()+"    <td>  <td>"+q.value(5).toString()+"            </td>" ;

            }
            doc.setHtml(pdf);
            doc.setPageSize(printer.pageRect().size());
            doc.print(&printer);
}

void integration::on_print_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Open PDF", QString(), "*.pdf");
               if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append("Client.pdf"); }

               QPrinter printer(QPrinter::PrinterResolution);
               printer.setOutputFormat(QPrinter::PdfFormat);
               printer.setPaperSize(QPrinter::A4);
               printer.setOutputFileName(fileName);

               QTextDocument doc;
               QSqlQuery q;
               q.prepare("SELECT * from reclamations");
               q.exec();
       QString pdf=" <body style='background-color:powderblue'> <h1  style='color:blue'>   Les clients de notre societé :  <br></h1>\n <br>  <table>  <tr>  <th> ID </th> <th> NOM </th> <th> PRENOM </th> <th> TYPE </th>  <th> ETAT </th>  </tr>" ;


               while ( q.next()) {

                   pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"    </td>  <td>   " + q.value(1).toString()+" </td>  <td>  "+q.value(2).toString() +"   </td>  <td>    "+q.value(3).toString()+"</td>       <td>"+q.value(4).toString()+"    <td>  <td>"+q.value(5).toString()+"            </td>" ;

               }
               doc.setHtml(pdf);
               doc.setPageSize(printer.pageRect().size());
               doc.print(&printer);
}


void integration::on_print_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Open PDF", QString(), "*.pdf");
               if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append("Client.pdf"); }

               QPrinter printer(QPrinter::PrinterResolution);
               printer.setOutputFormat(QPrinter::PdfFormat);
               printer.setPaperSize(QPrinter::A4);
               printer.setOutputFileName(fileName);

               QTextDocument doc;
               QSqlQuery q;
               q.prepare("SELECT * from clients");
               q.exec();
       QString pdf=" <body style='background-color:powderblue'> <h1  style='color:blue'>   Les reclamations de notre societé :  <br></h1>\n <br>  <table>  <tr>  <th> ID </th> <th> NOM </th> <th> PRENOM </th> <th> TYPE </th>  <th> ETAT </th> <th> DATE D'AJOUT </th> </tr>" ;


               while ( q.next()) {

                   pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"    </td>  <td>   " + q.value(1).toString()+" </td>  <td>  "+q.value(2).toString() +"   </td>  <td>    "+q.value(3).toString()+"</td>       <td>"+q.value(4).toString()+"    <td>  <td>"+q.value(5).toString()+"            </td>" ;

               }
               doc.setHtml(pdf);
               doc.setPageSize(printer.pageRect().size());
               doc.print(&printer);
}










void integration::on_ajouter1_clicked()
{
  QString type =ui->atype1->text() ;
  QString mat =ui->amat1->text() ;
  int prix = ui->aprix1->text().toInt();
  vehicule v(type,mat,prix) ;
  bool test = v.ajouetrvehicule();
  if (test)

  {
      ui->tableView->setModel(tmpvehicule.affichervehicule()) ;

      //QMessageBox::information(nullptr, QObject::tr("ajouter un vehicule"),
                           //  QObject::tr("vehicule ajouter.\n"));


}
  else { //QMessageBox::critical(nullptr, QObject::tr("ajouter un vehicule"),
                                 // QObject::tr("vehicule non ajouter.\n"));

  }
}

void integration::on_afficher1_clicked()
{
    ui->tableView->setModel(tmpvehicule.affichervehicule()) ;
}

void integration::on_pushButton_sup1_clicked()
{
    QString mat = ui->lineEdit_sup1->text();
    bool test = tmpvehicule.suprimervehicule(mat);
    if (test)
    {
       ui->tableView->setModel(tmpvehicule.affichervehicule()) ;
      // QMessageBox::information(nullptr, QObject::tr("suprimer un vehicule"),
                           //   QObject::tr("suppression effectué.\n"));
    }
    else
    { //QMessageBox::critical(nullptr, QObject::tr("suprimer un vehicule"),
                            //::tr("suppression non effectué.\n"));
    }
}

void integration::on_pushButton_100_clicked()
{
    QString k = ui->lineEdit_rech1->text();
    QString l = ui->lineEdit_rechm1->text();
    QString m =ui->lineEdit_21->text();
    if (k != ""){
   ui->tableView->setModel(tmpvehicule.cherchervehicule(k)) ;}
    if (l != ""){
   ui->tableView->setModel(tmpvehicule.cherchervehiculem(l)) ;}
    if (m != "")
    ui->tableView->setModel(tmpvehicule.cherchervehiculep(m));


}

void integration::on_pushButton_15_clicked()
{
    QString type =ui->lineEdit_modtype->text();
    QString mat =ui->lineEdit_modmat->text();
    QString prix =ui->lineEdit_modprix->text();

      bool test=tmpvehicule.modifiervehicule(type,mat,prix);

      if(test)
      {
          ui->tableView->setModel(tmpvehicule.affichervehicule());


      }
      else {

      }


  }

void integration::on_pushButton_10_clicked()
{
    QString type =ui->atype2->text() ;
    QString code =ui->acode2->text() ;
    int prix = ui->aprix2->text().toInt();
    fourniture f  (type ,code , prix) ;
    bool test = f.ajouterfourniture();
    if (test)

    {
        ui->tableView_2->setModel(tmpfourniture.afficherfourniture()) ;

        //QMessageBox::information(nullptr, QObject::tr("ajouter un vehicule"),
                             //  QObject::tr("vehicule ajouter.\n"));


  }
    else { //QMessageBox::critical(nullptr, QObject::tr("ajouter un vehicule"),
                                   // QObject::tr("vehicule non ajouter.\n"));

    }
}


void integration::on_afficher1_2_clicked()
{
    ui->tableView_2->setModel(tmpfourniture.afficherfourniture()) ;
}


void integration::on_pushButton_16_clicked()
{
    QString code = ui->lineEdit_code2->text();
    bool test = tmpfourniture.suprimerfourniture(code);
    if (test)
    {
       ui->tableView_2->setModel(tmpfourniture.afficherfourniture()) ;
      // QMessageBox::information(nullptr, QObject::tr("suprimer un vehicule"),
                           //   QObject::tr("suppression effectué.\n"));
    }
    else
    { //QMessageBox::critical(nullptr, QObject::tr("suprimer un vehicule"),
                            //::tr("suppression non effectué.\n"));
    }
}


void integration::on_pushButton_9_clicked()
{
    QString b = ui->lineEdit_recht2->text();
    QString c =ui->lineEdit_rechc2->text();
    QString d = ui->lineEdit_40->text();
    if (b != "")
    {
   ui->tableView_2->setModel(tmpfourniture.chercherfourniture(b)) ;}
    if (c != "")
   ui->tableView_2->setModel(tmpfourniture.chercherfourniturec(c)) ;

    if (d != "")
    ui->tableView_2->setModel(tmpfourniture.chercherfourniturprix(d));
}


void integration::on_pushButton_rech()
{
    QString type =ui->lineEdit_modtype_2->text();
      QString code =ui->lineEdit_modcode_2->text();
      QString prix =ui->lineEdit_modprix_2->text();
      bool test=tmpfourniture.modifierfourniture(type,code,prix);

      if(test)
      {
         ui->tableView->setModel(tmpfourniture.afficherfourniture()) ;


      }



  }










void integration::on_radioButton_7_clicked()
{
    ui->tableView->setModel(tmpvehicule.trivehiculepartype());
}

void integration::on_radioButton_12_clicked()
{
    ui->tableView->setModel(tmpvehicule.trivehiculeparmat());
}


/*void stock::on_pushButton_8_clicked()
{
    QPrinter printer;
            QPrintDialog *printDialog = new QPrintDialog(&printer, this);
            printDialog->setWindowTitle("Imprimer Document");
            printDialog->exec();
}*/

void integration::on_radioButton_clicked()
{
    ui->tableView_2->setModel(tmpfourniture.trifourniturepartype());
}

void integration::on_radioButton_2_clicked()
{
    ui->tableView_2->setModel(tmpfourniture.trifournitureparcode());
}

void integration::on_radioButton_6_clicked()
{
    ui->tableView_2->setModel(tmpfourniture.trifournitureparprix());
}

void integration::on_radioButton_11_clicked()
{
 ui->tableView->setModel(tmpvehicule.trivehiculeparprix());
}


void integration::on_pushButton_14_clicked()
{
    QPrinter printer;
            QPrintDialog *printDialog = new QPrintDialog(&printer, this);
            printDialog->setWindowTitle("Imprimer Document");
            printDialog->exec();
}

/*void stock::on_pushButton_8_clicked()
{
    ui->tabWidget->setCurrentIndex(7);

        QBarSet *set0 = new QBarSet("fourniture");

             QStringList list1;
            QStringList list, list2;
            QVector<fourniture> tab;
            fourniture f;

               ui->tableView_2->setModel(tmpfourniture.afficherfourniture());
               ui->tableView_2->adjustSize();
               QStringList Titres;

                   Titres <<"Identifiant du ramassage" <<"Nombre de poubelle"<<"Duree";
                                    ui->tableWidget->setHorizontalHeaderLabels(Titres);


            for( int row = 0; row < ui->tableView_2->model()->rowCount(); ++row )
                   {   ui->tableWidget->setColumnCount(3);
               ui->tableWidget->insertRow(ui->tableWidget->rowCount());
             for( int col = 0; col < ui->tableView_2->model()->columnCount(); ++col )
                     {
                      QModelIndex index =ui->tableView_2->model()->index(row,0);
                       QModelIndex index2 =ui->tableView_2->model()->index(row,1);
                        QModelIndex index3 =ui->tableView_2->model()->index(row,2);
                        list1.append(index.data().toString());
                       f.settype(index.data().toString());
                       f.setcodeabarre(index2.data().toString());
                      // f.setprix(index3.data());
            ui->tableWidget->hide();
           }
              tab.push_back(f);
            }


            for(int m=0;m<tab.size();m++)
           {
                for(int index=0;index<tab.size();index++)

         {
           if(tab[index].getprix()==tab[m].getprix()&& m!=index)

           {

                  tab[index].settype("");
                  int x=tab[m].getcodeabarre().toInt()+tab[index].getcodeabarre().toInt();
                   QString ch=QVariant(x).toString();
                   tab[m].setcodeabarre(ch);




             }



           }


           for(int k=0;k<tab.size();k++)

            //list.append(tab[k].getprix());

           if(tab[m].gettype()!="")
           {
      qDebug()<<"id= "<<tab[m].gettype();
         qDebug()<<"date= "<<tab[m].getprix();
            qDebug()<<"nb= "<<tab[m].getcodeabarre();
               qDebug()<<" ";
               qDebug()<<" ";
        *set0<<tab[m].getcodeabarre().toInt();


   }
            }



            //ui->tableWidget->setCurrentIndex(7);
                    QBarSeries *series = new QBarSeries();
                         series->append(set0);

                        QChart *chart = new QChart;
                         chart->addSeries(series);
                         chart->setTitle("Le nombre de ramassages effectués par la municipalité en fonction des années");
                    chart->setAnimationOptions(QChart::AllAnimations);

                    QBarCategoryAxis *axis= new QBarCategoryAxis();
                    axis->append(list);

                    chart->createDefaultAxes();

                    chart->setAxisX(axis,series);
                    chart->legend()->setVisible(true);
                    chart->legend()->setAlignment(Qt::AlignBottom);
                    QPalette pal =  ui->graphicsView->palette();
                    pal.setColor(QPalette::Window, QRgb(0x121218));
                    pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));

           ui->graphicsView->show();

         ui->graphicsView->setPalette(pal);
                //ui->graphicsView->setchart(chart);
                ui->graphicsView->setRenderHint(QPainter::Antialiasing);
                ui->graphicsView->setMinimumSize(780,480);


   }
*/

void integration::on_pushButton_8_clicked()
{
    QPieSeries *series = new QPieSeries();
        series->append("stylo",80);
        series->append("papier",70);
        series->append("a",60);
        series->append("b ",50);
        series->append("c",40);
        QPieSlice *slice= series->slices().at(1);
        slice->setExploded(true);
        slice->setLabelVisible(true);
        slice->setPen(QPen(Qt::darkGreen,2));
        slice->setBrush(Qt::green);
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("stat");
        QChartView *chartview=new QChartView(chart);
        //chartview->setParent(ui->horizontalFrame);
        chartview->setParent(ui->horizontalFrame);
        ui->tabWidget ->setCurrentIndex(2);
}
void integration:: showtime()
{
    QTime time = QTime::currentTime();

    QString time_text=time.toString("hh : mm : ss");
    if((time.second() % 2) == 0 )
    {
        time_text[3] = ' ';
        time_text[8] = ' ';
    }
    ui->digitalclock->setText(time_text);
    ui->digitalclock_2->setText(time_text);
    ui->Digital_clock3->setText(time_text);

}


void integration::on_pushButton_ges_produit_clicked()
{
    produitwindow = new dialogproduit(this);
        produitwindow->show();
}

void integration::on_pushButton_ges_finance_clicked()
{
    financewindow = new dialogfinance(this);
        financewindow->show();
}

void integration::on_pushButton_ardomar_clicked()
{
    QSqlQuery query;
    query.exec("select PRIX from VEHICULE");
    int sum=0;
    while(query.next())
    {
        int int_montant = query.value(0).toInt();
        sum=sum+int_montant;
    }
             QByteArray priomar;
              priomar.setNum(sum);
              b.write_to_arduino(priomar);
}
