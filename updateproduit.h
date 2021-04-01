#ifndef UPDATEPRODUIT_H
#define UPDATEPRODUIT_H

#include <QDialog>

namespace Ui {
class UpdateProduit;
}

class UpdateProduit : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateProduit(QWidget *parent = nullptr,QString *refa = nullptr , QString *desa = nullptr,QString *qtea = nullptr,QString *pra = nullptr,QString *monta = nullptr);
    ~UpdateProduit();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::UpdateProduit *ui;
    QString refupdate;
};

#endif // UPDATEPRODUIT_H
