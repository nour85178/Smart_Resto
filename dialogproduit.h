#ifndef DIALOGPRODUIT_H
#define DIALOGPRODUIT_H

#include <QMainWindow>
#include "produit.h"
namespace Ui {
class dialogproduit;
}

class dialogproduit : public QMainWindow
{
    Q_OBJECT

public:
    explicit dialogproduit(QWidget *parent = nullptr);
    ~dialogproduit();

private slots:

   void on_pushButton_ajouter_clicked();
   void on_pushButton_supp_clicked();

   void on_pushButton_edit_clicked();

   void on_pushButton_7_clicked();

   void on_pushButton_trie_clicked();

   void on_pushButton_rech_clicked();

   void on_pushButton_pdf_produit_clicked();

private:
    Ui::dialogproduit *ui;
    produit *ptmp;
};

#endif // DIALOGPRODUIT_H
