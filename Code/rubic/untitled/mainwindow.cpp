#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <time.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
   ui->tableWidget->setRowCount(arg1);
}

void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
   ui->tableWidget->setColumnCount(arg1);
}

void MainWindow::on_pushButton_clicked()
{
    srand(time(NULL));
    for(int i=0;i<ui->tableWidget->rowCount();i++)
    {
        for (int j=0;j<ui->tableWidget->columnCount();j++)
        {
            QTableWidgetItem *r;
            r = new QTableWidgetItem;
            r->setText(QString::number(rand()%100+1));
            ui->tableWidget->setItem(i,j,r);
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QTableWidgetItem *r;
    r = new QTableWidgetItem;
    if (ui->tableWidget->columnCount() == ui->tableWidget->rowCount())
    {
        for(int i=0;i<ui->tableWidget->rowCount();i++)
        {
          for (int j=0;j<ui->tableWidget->columnCount();j++)
            {
              if (i<j)
              {
              int a,b;
              r=ui->tableWidget->item(i,j);
              a=r->text().toInt();
              r=ui->tableWidget->item(j,i);
              b=r->text().toInt();
              r->setText(QString::number(a));
              ui->tableWidget->setItem(j,i,r);
              r=ui->tableWidget->item(i,j);
              r->setText(QString::number(b));
              ui->tableWidget->setItem(i,j,r);
              }
            }
       }
   }
}
