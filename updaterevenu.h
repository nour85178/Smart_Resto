#ifndef UPDATEREVENU_H
#define UPDATEREVENU_H

#include <QDialog>

namespace Ui {
class updaterevenu;
}

class updaterevenu : public QDialog
{
    Q_OBJECT

public:
    explicit updaterevenu(QWidget *parent = nullptr,QString *ida = nullptr , QString *typea = nullptr,QDate *datea = nullptr,QString *monta = nullptr);
    ~updaterevenu();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::updaterevenu *ui;
};

#endif // UPDATEREVENU_H
