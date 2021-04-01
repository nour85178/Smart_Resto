#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMessageBox>
#include <QMainWindow>
#include"employe.h"
#include "departement.h"
#include<QDebug>
#include<QValidator>
#include"smtp.h"
#include <QtWidgets/QMessageBox>
#include<QMediaPlayer>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




private slots:
    void on_ajoute_e_clicked();

    void on_pushButton_2_clicked();

    //void on_trouver_e_clicked();

    void on_pushButton_3_clicked();

    void on_ajout_dep_clicked();



    //void on_gestion_currentChanged(int index);

    void on_supp_dep_clicked();

    void on_modif_dep_clicked();

    //void on_touver_departement_clicked();

    void on_recherche_employe_textChanged(const QString &arg1);

    void on_id_e_textChanged(const QString &arg1);

    void on_radioButton_clicked();

    void on_id_ch_textChanged(const QString &arg1);



    void on_tick_nom_clicked();

    void on_tick_prenom_clicked();

    void on_tick_date_clicked();

    void on_prenom_box_clicked();

    void on_radiotri_date_n_clicked();

    void on_radiotri_prenom_clicked();

    void on_envoyer_mail_clicked();


    void on_radiotri_date_c_2_clicked();

    void on_radiotri_nom_dep_clicked();

    void on_radiotri_id_dep_clicked();

    void on_radiotri_id_emp_clicked();

    void on_recherche_departement_textChanged(const QString &arg1);

    void on_checkBox_rech_nom_dep_clicked();

    void on_checkBox_rech_id_chef_clicked();

    void on_checkBox_rech_date_c_clicked();

    void sendMail();
    void mailSent(QString);
    void showTime();


private:
    Ui::MainWindow *ui;
    employe tmpemploye;
    departement tmpdep;
    QStringList listSexe;
    QTimer *timer_1s;


};
#endif // MAINWINDOW_H
