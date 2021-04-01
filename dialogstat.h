#ifndef DIALOGSTAT_H
#define DIALOGSTAT_H
#include <QDialog>
#include "arduino.h"

namespace Ui {
class Dialogstat;
}

class Dialogstat : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogstat(QWidget *parent = nullptr);
    ~Dialogstat();
    void send_data(int *rev,int *dep);

private slots:
     void update_label();
private:
    Ui::Dialogstat *ui;
    arduino A;
    QByteArray data;
};

#endif // DIALOGSTAT_H
