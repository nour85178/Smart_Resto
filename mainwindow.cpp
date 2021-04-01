#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTimer>
#include<QDateTime>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer_1s = new QTimer(this);
    QObject::connect(timer_1s, SIGNAL(timeout()), this, SLOT(showTime()));
    timer_1s->start(1000);

    listSexe <<"Femme"<<"Homme"<<"Autre";
    ui->sexe_e->clear();
    ui->sexe_e->addItems(listSexe);
    QIntValidator *id_v=new QIntValidator(1,99999);
    ui->id_e->setValidator(id_v);


    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTime()
{

     ui->Digital_clock->setText(QTime::currentTime().toString("hh:mm:ss"));



}

void MainWindow::on_ajoute_e_clicked()
{

    /******************************/
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/chaab/Desktop/button.wav"));
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

void MainWindow::on_pushButton_2_clicked()
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



void MainWindow::on_pushButton_3_clicked()
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

void MainWindow::on_ajout_dep_clicked()
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

/*void MainWindow::on_gestion_currentChanged(int index)
{
    ui->table_e->setModel(tmpemploye.afficher());
    ui->table_depart->setModel(tmpdep.afficher());
    ui->clear();
    ui->addItems(tmpdep.listDepartement());
}*/

void MainWindow::on_supp_dep_clicked()
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

void MainWindow::on_modif_dep_clicked()
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



void MainWindow::on_recherche_employe_textChanged(const QString &arg1)
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

void MainWindow::on_id_e_textChanged(const QString &arg1)
{
    employe e=tmpemploye.trouver(ui->id_e->text().toInt());
    ui->nom_e->setText(e.getnom());
    ui->prenom_e->setText(e.getprenom());
    ui->date_naiss_e->setDate(e.getdate_naiss());

    ui->poste_e->setText(e.getposte());
}

void MainWindow::on_radioButton_clicked()
{
    ui->table_e->setModel(tmpemploye.tridate_naissance());
}

void MainWindow::on_id_ch_textChanged(const QString &arg1)
{
    departement d=tmpdep.trouver(ui->id_ch->text().toInt());
    ui->nom_ch->setText(d.getnom());
    ui->date_ch->setDate(d.getdate_cr());
    ui->nombre_ch->setText(QString::number(d.getnombre_emp()));
}


void MainWindow::on_tick_nom_clicked()
{
  ui->table_e->setModel(tmpemploye.recherche(ui->recherche_employe->text()));
}


void MainWindow::on_tick_prenom_clicked()
{
    ui->table_e->setModel(tmpemploye.recherche_p(ui->recherche_employe->text()));
}


void MainWindow::on_tick_date_clicked()
{
    ui->table_e->setModel(tmpemploye.recherche_d(ui->recherche_employe->text()));
}


void MainWindow::on_prenom_box_clicked()
{
   ui->table_e->setModel(tmpemploye.tri_prenom());
}

void MainWindow::on_radiotri_prenom_clicked()
{
    ui->table_e->setModel(tmpemploye.tri_prenom());
}

void MainWindow::on_radiotri_date_n_clicked()
{
    ui->table_e->setModel(tmpemploye.tridate_naissance());
}

void MainWindow::on_envoyer_mail_clicked()
{

}




void MainWindow::on_radiotri_date_c_2_clicked()
{
    ui->table_depart->setModel(tmpdep.tridate_cr());

}

void MainWindow::on_radiotri_nom_dep_clicked()
{
   ui->table_depart->setModel(tmpdep.trinom());
}

void MainWindow::on_radiotri_id_dep_clicked()
{
  ui->table_depart->setModel(tmpdep.tri_idchef());
}

void MainWindow::on_radiotri_id_emp_clicked()
{
  ui->table_e->setModel(tmpemploye.tri_id());
}

void MainWindow::on_recherche_departement_textChanged(const QString &arg1)
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

void MainWindow::on_checkBox_rech_nom_dep_clicked()
{
ui->table_depart->setModel(tmpdep.recherche_nom(ui->recherche_departement->text()));
}

void MainWindow::on_checkBox_rech_id_chef_clicked()
{
 ui->table_depart->setModel(tmpdep.recherche_id(ui->recherche_departement->text()));
}

void MainWindow::on_checkBox_rech_date_c_clicked()
{
ui->table_depart->setModel(tmpdep.recherche_date(ui->recherche_departement->text()));
}


void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("fahmimankous@gmail.com","Azertyuiop","smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail("", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}
