#ifndef MAIL_H
#define MAIL_H

#include <QMainWindow>
#include "smtp.h"
#include <QtWidgets/QMessageBox>

namespace Ui {
class Mail;
}

class Mail : public QMainWindow
{
    Q_OBJECT

public:
    explicit Mail(QWidget *parent = nullptr);
    ~Mail();

private slots:
    void sendMail();
    void mailSent(QString);

private:
    Ui::Mail *ui;
};

#endif // MAIL_H
