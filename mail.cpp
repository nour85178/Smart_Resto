#include "mail.h"
#include "ui_mail.h"

Mail::Mail(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mail)
{
    ui->setupUi(this);
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
}

Mail::~Mail()
{
    delete ui;
}

void Mail::sendMail()
{
    Smtp* smtp = new Smtp("fahmimankous@gmail.com","Azertyuiop","smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail("", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void Mail::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}
