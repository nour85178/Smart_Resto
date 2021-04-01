#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <QMainWindow>
#include "vehicule.h"
#include "fourniture.h"
#include<QMessageBox>
#include"employe.h"
#include "departement.h"
#include<QDebug>
#include<QValidator>
#include"smtp.h"
#include <QtWidgets/QMessageBox>
#include<QMediaPlayer>
#include<QTimer>
#include<QDateTime>
#include <client.h>
#include <reclamation.h>
#include <mailing.h>
#include <QWidget>
#include <QTimer>
#include <QDebug>
#include <QMessageBox>
#include <QIntValidator>
#include "connexion.h"
#include "reclamation.h"
#include <QTranslator>
#include <QInputDialog>
#include <QPrintDialog>
#include <QPrinter>
#include <QTextDocument>
#include <QMediaPlayer>
#include <QSound>
#include "dialogproduit.h"
#include "dialogfinance.h"
#include "arduino.h"

namespace Ui {
class integration;
}

class integration : public QMainWindow
{
    Q_OBJECT

public:
    explicit integration(QWidget *parent = nullptr);
    ~integration();

private slots:
    void on_ajout_dep_clicked();


    void sendMail();
    void mailSent(QString);
    void showTime();

    void on_supp_dep_clicked();

    void on_modif_dep_clicked();

    void on_id_ch_textChanged(const QString &arg1);

    void on_recherche_departement_textChanged(const QString &arg1);

    void on_checkBox_rech_nom_dep_clicked();

    void on_checkBox_rech_id_chef_clicked();

    void on_checkBox_rech_date_c_clicked();

    void on_radiotri_date_c_2_clicked();

    void on_radiotri_nom_dep_clicked();

    void on_radiotri_id_dep_clicked();

    void on_ajoute_e_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_id_e_textChanged(const QString &arg1);

    void on_recherche_employe_textChanged(const QString &arg1);



    void on_checkBox_rech_nom_clicked();

    void on_checkBox_rech_prenom_clicked();

    void on_checkBox_rech_date_n_clicked();

    void on_radiotri_date_n_clicked();

    void on_radiotri_prenom_clicked();

    void on_radiotri_id_emp_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_Load_2_clicked();

    void on_SetatC_clicked();

    void on_StypeC_clicked();

    void on_SnomC_clicked();


    void on_checkBox_4_clicked();

    void on_checkBox_5_clicked();

    void on_checkBox_6_clicked();





    void on_cinchercher_clicked();

    void on_cinchercher_2_clicked();

    void on_recherchedate_2_clicked();

    void on_checkBox_25_clicked();

    void on_checkBox_26_clicked();

    void on_checkBox_27_clicked();

    void on_Load_3_clicked();

    void on_sendMail_clicked();

    void on_EnglishON_clicked();

    void on_FrenchON_clicked();

    void on_pushButton_ajouter_reclamation_clicked();

    void on_pushButton_suppR_clicked();

    void on_modifierR_clicked();

    void on_pushButton_14_clicked();

    void on_Load_4_clicked();

    void on_loadC_clicked();

    void on_stat_2_clicked();

    void on_sendMail_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_gestion_currentChanged(int index);

    void on_print_button_clicked();

    void on_print_clicked();

    void on_print_2_clicked();



    void on_ajouter1_clicked();

    void on_afficher1_clicked();

    void on_pushButton_sup1_clicked();

    void on_pushButton_rech();

    void on_pushButton_15_clicked();

    void on_pushButton_10_clicked();

    void on_afficher1_2_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_100_clicked();

   // void on_radioButton_clicked();



    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_12_clicked();

    void on_radioButton_11_clicked();

    void on_radioButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void showtime();


    void on_pushButton_ges_produit_clicked();

    void on_pushButton_ges_finance_clicked();

    void on_pushButton_ardomar_clicked();

private:
    Ui::integration *ui;
    employe tmpemploye;
    departement tmpdep;
    QStringList listSexe;
    QTimer *timer_1s;
    Client tmpclient;
    Reclamation tmprecla;
    vehicule tmpvehicule ;
    fourniture tmpfourniture;
    QPrinter printer;
    dialogproduit * produitwindow;
     dialogfinance * financewindow;
     QTimer *timer_2s;
     arduino b;
     QByteArray dd;
};

#endif // INTEGRATION_H
