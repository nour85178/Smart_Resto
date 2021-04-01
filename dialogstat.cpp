#include "dialogstat.h"
#include "ui_dialogstat.h"
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<iostream>
#include "arduino.h"
#include <QDebug>


QT_CHARTS_USE_NAMESPACE

Dialogstat::Dialogstat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogstat)
{
    ui->setupUi(this);
    int ret= A.connect_arduino();
        switch(ret){
        case(0): qDebug() << "arduino is available and connected to :" << A.getarduino_port_name();
            break;
        case(1): qDebug() << "arduino is available and not connected to :" << A.getarduino_port_name();
            break;
        case(-1): qDebug() << "arduino is not available" ;
        }
        QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
                data=A.read_from_arduino();



    QSqlQuery query;
    query.exec("select montant from depense");
    int sum=0;
    while(query.next())
    {
        int int_montant = query.value(0).toInt();
         std::cout<<int_montant;
        sum=sum+int_montant;
    }
    std::cout<<sum;

    QSqlQuery query2;
    query2.exec("select montant from revenu");
    int sum2=0;
    while(query2.next())
    {
        int int_montant2 = query2.value(0).toInt();
         std::cout<<int_montant2;
        sum2=sum2+int_montant2;
    }
     std::cout<<sum2;
     int pdp=((sum+sum2)/sum2);
     int prev((sum+sum2)/sum);

    QPieSeries *series = new QPieSeries();
          series->append("Depenses ",pdp);
          series->append("Revenus ",prev);

          QPieSlice *slice0 = series->slices().at(0);
          slice0->setLabelVisible();

          QPieSlice *slice1 = series->slices().at(1);
          slice1->setExploded();
          slice1->setLabelVisible();
          slice1->setPen(QPen(Qt::darkGreen, 2));
          slice1->setBrush(Qt::green);

          QChart *chart = new QChart();

          chart->addSeries(series);
          chart->setTitle("Statistiquess (Revenus/Depenses): ");
          chart->legend()->hide();

          // Used to display the chart
          QChartView *chartView = new QChartView(chart);
          chartView->setRenderHint(QPainter::Antialiasing);
          ui->chart_dp->addWidget(chartView);

          //send_data(&sum,&sum2);
          QByteArray depenserate;
          depenserate.setNum(123);
          A.write_to_arduino(depenserate);

}

Dialogstat::~Dialogstat()
{
    delete ui;
}
void Dialogstat::update_label()
{
    data=A.read_from_arduino();
     if(data=="1")
         ui->label_update->setText("Sending Revenu data");
     else if(data=="2")
         ui->label_update->setText("Sending Depense data");
}
/*void Dialogstat::send_data(int *rev,int *dep)
{
    data=A.read_from_arduino();
 while(data!="")
 {
     if(data=="1")
        { QByteArray revrate;
         revrate.setNum(*rev);
         A.write_to_arduino(revrate);}
    else if(data=="2")
     { QByteArray depenserate;
      depenserate.setNum(*dep);
      A.write_to_arduino(depenserate);}
 }
}*/
