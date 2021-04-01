#ifndef DIALOGFINANCE_H
#define DIALOGFINANCE_H
#include "revenu.h"
#include "depense.h"
#include <QMainWindow>

namespace Ui {
class dialogfinance;
}

class dialogfinance : public QMainWindow
{
    Q_OBJECT

public:
    explicit dialogfinance(QWidget *parent = nullptr);
    ~dialogfinance();
     void open_chart();
private slots:

    void on_pushButton_ajouter_rev_clicked();
    void on_pushButton_ajouter_dp_clicked();
    void on_pushButton_updaterev_clicked();
    void on_pushButton_sup_rev_clicked();
    void on_pushButton_supp_dp_clicked();
    void on_pushButton_update_dp_clicked();

    void on_pushButton_stat_dp_clicked();

    void on_stat_rev_clicked();

    void on_pushButton_search_rev_clicked();

    void on_pushButton_search_dp_clicked();

    void on_pushButton_fich_rev_clicked();

    void on_pushButton_fich_dp_clicked();

    void on_pushButton_trie_rev_clicked();

    void on_pushButton_trie_dp_clicked();

private:
    Ui::dialogfinance *ui;
    Revenu *rtmp;
    Depense *dtmp;

};

#endif // DIALOGFINANCE_H
