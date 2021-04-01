#ifndef UPDATEDEPENSE_H
#define UPDATEDEPENSE_H

#include <QDialog>

namespace Ui {
class updatedepense;
}

class updatedepense : public QDialog
{
    Q_OBJECT

public:
    explicit updatedepense(QWidget *parent = nullptr,QString *ida = nullptr , QString *cata = nullptr,QDate *datea = nullptr,QString *monta = nullptr);
    ~updatedepense();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::updatedepense *ui;
};

#endif // UPDATEDEPENSE_H
