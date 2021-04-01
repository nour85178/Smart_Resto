#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include"admin.h"
#include<QMessageBox>
#include"mainwindow.h"
#include"integration.h"
namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_login_2_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
