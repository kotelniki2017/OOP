#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTableWidgetItem"
#include "qheaderview.h"
#include "qlistwidget.h"
#include "new_matrix.h"
#include <qstring.h>
#include "square_matrix.h"
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
void MainWindow::on_pushButton_clicked()
{
    ui->FORM_MATRIX_A->setRowCount(ui->spinBox->value());
    ui->FORM_MATRIX_A->setColumnCount(ui->spinBox_2->value());
    ui->FORM_MATRIX_B->setRowCount(ui->spinBox_3->value());
    ui->FORM_MATRIX_B->setColumnCount(ui->spinBox_4->value());
    QHeaderView* hheader = ui->FORM_MATRIX_A->horizontalHeader();
    hheader->setSectionResizeMode(QHeaderView::Stretch);
    QHeaderView* vheader = ui->FORM_MATRIX_A->verticalHeader();
    vheader->setSectionResizeMode(QHeaderView::Stretch);
    QHeaderView* Hheader = ui->FORM_MATRIX_B->horizontalHeader();
    Hheader->setSectionResizeMode(QHeaderView::Stretch);
    QHeaderView* Vheader = ui->FORM_MATRIX_B->verticalHeader();
    Vheader->setSectionResizeMode(QHeaderView::Stretch);
    QHeaderView* H_header = ui->FORM_MATRIX_C->horizontalHeader();
    H_header->setSectionResizeMode(QHeaderView::Stretch);
    QHeaderView* V_header = ui->FORM_MATRIX_C->verticalHeader();
    V_header->setSectionResizeMode(QHeaderView::Stretch);
    for (int i=0; i<ui->spinBox->value();i++)
        for (int j=0; j<ui->spinBox_2->value();j++){
            QTableWidgetItem *item;
            item = new QTableWidgetItem;
            item->setText(QString::number (0));
            ui->FORM_MATRIX_A->setItem(i,j,item);
        }
    for (int i=0; i<ui->spinBox_3->value();i++)
        for (int j=0; j<ui->spinBox_4->value();j++){
            QTableWidgetItem *item;
            item = new QTableWidgetItem;
            item->setText(QString::number (0));
            ui->FORM_MATRIX_B->setItem(i,j,item);
        }
}

void MainWindow::button_trans() //транспонирование
{

    int M=ui->FORM_MATRIX_A->columnCount(), N =ui->FORM_MATRIX_A->rowCount();
    New_Matrix dataA(N, M);
    ui->FORM_MATRIX_C->setRowCount(M);
    ui->FORM_MATRIX_C->setColumnCount(N);
    float l;
    for(int i=0;i < N;i++)
        for(int j=0;j<M;j++){
            QTableWidgetItem *item;
            item = new QTableWidgetItem;
            item = ui->FORM_MATRIX_A->item(i,j);
            l = item->text().toFloat();
            dataA.set_value(i,j,l);
        }
    New_Matrix data_transp(M,N);
    data_transp = dataA.transp();
    for(int i=0;i < M;i++)
        for(int j=0;j<N;j++){
            QTableWidgetItem *item;
            item = new QTableWidgetItem;
            item->setText(QString::number(double(data_transp.get_value(i,j))));
            ui->FORM_MATRIX_C->setItem(i,j,item);

        }
}

void MainWindow::button_summ()    //сложение
{
    int M=ui->FORM_MATRIX_A->columnCount(), N =ui->FORM_MATRIX_A->rowCount();
    New_Matrix data1(N, M), data2(N,M);
    float l;
    if (N == ui->FORM_MATRIX_B->rowCount() && M == ui->FORM_MATRIX_B->columnCount()){
        ui->FORM_MATRIX_C->setRowCount(N);
        ui->FORM_MATRIX_C->setColumnCount(M);
        for(int i=0;i < N;i++)
            for(int j=0;j<M;j++){
                QTableWidgetItem *item;
                item = new QTableWidgetItem;
                item = ui->FORM_MATRIX_A->item(i,j);
                l = item->text().toFloat();
                data1.set_value(i,j,l);
                item = ui->FORM_MATRIX_B->item(i,j);
                l = item->text().toFloat();
                data2.set_value(i,j,l);
            }
        New_Matrix data3 = data1 + data2;
        for(int i=0;i < N;i++)
            for(int j=0;j<M;j++){
                QTableWidgetItem *item;
                item = new QTableWidgetItem;
                item->setText(QString::number(double(data3.get_value(i,j))));
                ui->FORM_MATRIX_C->setItem(i,j,item);
            }
    }
    else
    {
        ui->FORM_MATRIX_C->setRowCount(1);
        ui->FORM_MATRIX_C->setColumnCount(1);
        QString ERROR = "Ошибка, матрицы не равны по строкам/стоблцам";
        QTableWidgetItem *item;
        item = new QTableWidgetItem;
        item->setText(ERROR);
        ui->FORM_MATRIX_C->setItem(0,0,item);
    }

}

void MainWindow::button_rank() //нахождение ранга матрицы
{
    int N = ui->FORM_MATRIX_A->rowCount(), M = ui->FORM_MATRIX_A->columnCount() ,l;
    New_Matrix  dataA(N,M);
    for(int i=0;i < N;i++)
        for(int j=0;j<M;j++){
            QTableWidgetItem *item;
            item = new QTableWidgetItem;
            item = ui->FORM_MATRIX_A->item(i,j);
            l = item->text().toInt();
            dataA.set_value(i,j,l);
        }
    int Rank = dataA.Rank();
    ui->FORM_MATRIX_C->setRowCount(1);
    ui->FORM_MATRIX_C->setColumnCount(1);
    QTableWidgetItem *item;
    item = new QTableWidgetItem;
    item->setText(QString::number(Rank));
    ui->FORM_MATRIX_C->setItem(0,0,item);
}

void MainWindow::button_multiplication() //умножение
{
    if(ui->FORM_MATRIX_A->columnCount()==ui->FORM_MATRIX_B->rowCount()){
        int N = ui->FORM_MATRIX_A->rowCount(), M = ui->FORM_MATRIX_A->columnCount(), K = ui->FORM_MATRIX_B->columnCount();
        float l;
        New_Matrix dataA(N,M), dataB(M,K), dataC(N,K);
        for(int i=0;i < N;i++)
            for(int j=0;j<M;j++){
                QTableWidgetItem *item1;
                item1 = new QTableWidgetItem;
                item1 = ui->FORM_MATRIX_A->item(i,j);
                l = item1->text().toFloat();
                dataA.set_value(i,j,l);
            }
        for(int i=0;i < M;i++)
            for(int j=0;j<K;j++){
                QTableWidgetItem *item2;
                item2 = new QTableWidgetItem;
                item2 = ui->FORM_MATRIX_B->item(i,j);
                l = item2->text().toFloat();
                dataB.set_value(i,j,l);
            }
        dataC = dataA * dataB;
        for(int i=0;i < dataC.N;i++)
            for(int j=0;j<dataC.M;j++){
                QTableWidgetItem *item;
                item = new QTableWidgetItem;
                ui->FORM_MATRIX_C->setRowCount(N);
                ui->FORM_MATRIX_C->setColumnCount(K);
                item->setText(QString::number(dataC.get_value(i,j)));
                ui->FORM_MATRIX_C->setItem(i,j,item);
            }
    }
    else
    {
        ui->FORM_MATRIX_C->setRowCount(1);
        ui->FORM_MATRIX_C->setColumnCount(1);
        QString ERROR = "ОШИБКА";
        QTableWidgetItem *item;
        item = new QTableWidgetItem;
        item->setText(ERROR);
        ui->FORM_MATRIX_C->setItem(0,0,item);
    }

}

void MainWindow::button_reverse() //обратная
{
    int N = ui->FORM_MATRIX_A->rowCount(), M =ui->FORM_MATRIX_A->columnCount();
    int l,det;
    if(M == N){
        sqar_matrix dataA(N),dataC(N);
        for(int i=0;i < N;i++)
            for(int j=0;j<N;j++){
                QTableWidgetItem *item;
                item = new QTableWidgetItem;
                item = ui->FORM_MATRIX_A->item(i,j);
                l = item->text().toInt();
                dataA.set_value(i,j,l);
            }
        det = dataA.DET();
        if(det!=0){
            dataC = dataA.obratnaya();
            dataC.transp();
            ui->FORM_MATRIX_C->setRowCount(N);
            ui->FORM_MATRIX_C->setColumnCount(N);
            for(int i=0;i < N;i++)
                for(int j=0;j<N;j++){
                    QTableWidgetItem *item;
                    item = new QTableWidgetItem;
                    item->setText(QString::number(double(dataC.get_value(i,j))));
                    ui->FORM_MATRIX_C->setItem(i,j,item);
                }
        }
        else{
            ui->FORM_MATRIX_C->setRowCount(1);
            ui->FORM_MATRIX_C->setColumnCount(1);
            QString ERROR = "Ошибка, матрица вырождена";
            QTableWidgetItem *item;
            item = new QTableWidgetItem;
            item->setText(ERROR);
            ui->FORM_MATRIX_C->setItem(0,0,item);
        }
    }
    else {
        ui->FORM_MATRIX_C->setRowCount(1);
        ui->FORM_MATRIX_C->setColumnCount(1);
        QString ERROR = "Ошибка, матрица не квадратная";
        QTableWidgetItem *item;
        item = new QTableWidgetItem;
        item->setText(ERROR);
        ui->FORM_MATRIX_C->setItem(0,0,item);
    }

}
