#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->logologin->setPixmap(QPixmap("C:/Users/asus/Desktop/projetintgre/Smart_Home_Delivery_2A7/moto.jpg"));
}

login::~login()
{
    delete ui;
}

void login::on_login_2_clicked()
{
    admin a;
    bool test=a.login(ui->lineEdit_username->text(),ui->lineEdit_pwd->text());
    if(test){

        /*MainWindow *w=new MainWindow();
        w->show();*/
        integration *i=new integration();
        i->show();
        this->hide();
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Login"),
                    QObject::tr("username ou password invalide!\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
