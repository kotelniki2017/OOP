#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

class my_array{
    friend ostream & operator<< (ostream &, my_array &);
    friend istream & operator>> (istream &, my_array &);
    friend my_array & operator+(my_array &, my_array&);
public:
    int & operator [] (int);
    my_array & operator++();
    my_array & operator++(int);
    my_array & operator+=(int);
    my_array & operator=(my_array &);
    bool operator ==(my_array &);
    void filling_random(void);
    const int get_size();
    my_array(int);
    my_array(my_array &);
    ~my_array();

private:
    int size;
    int *mass;
};
my_array current(1);
my_array ArrayA(1);
my_array ArrayB(1);
my_array ArrayC(1);
my_array ArrayD(1);





my_array::my_array(int n)
{
    size = n;
    mass = new int [size];
    for(int i=0; i<size; i++) mass[i]=0;
}
my_array & operator+(my_array &ar1, my_array &ar2)
{
    current=((ar1.get_size()<ar2.get_size())?ar2:ar1);
    for (int i=0;i<current.get_size();i++)
    {
        if((i<ar1.get_size())&&(i<ar2.get_size()))
            current[i]=ar1[i]+ar2[i];
        if((i<ar1.get_size())&&(i>=ar2.get_size()))
            current[i]=ar1[i];
        if((i>=ar1.get_size())&&(i<ar2.get_size()))
            current[i]=ar2[i];
    }
    return current;
}
my_array::my_array(my_array & copy)
{
    size=copy.get_size();
    mass=new int [size];
    for(int i =0; i<size; i++) mass[i]=copy[i];
}
bool my_array::operator==(my_array&ar2)
{
    if(size==ar2.get_size()){
        bool pr=true;
        for(int i=0; i<ar2.get_size();i++)
            if((mass[i])!=(ar2[i])){
                pr=false;
                break;
            }
        return pr;
    }
    else
        return false;
}
my_array & my_array::operator=(my_array & ar)
{
    size=ar.get_size();
    delete [] mass;
    mass=new int [size];
    for(int i=0;i<this->size;i++)this->mass[i]=ar[i];
    return *this;
}
my_array::~my_array(void)
{
    delete [] this->mass;
}

const int my_array::get_size()
{
    return this->size;
}
int & my_array::operator[](int n)
{
    if(n<size)
        return mass[n];
    else{
        if(n<0)
            return mass[0];
        else
            return mass[size-1];
    }
}
ostream & operator<<(ostream&output, my_array&arr){
    for(int i=0;i<arr.size;i++)
        output<<(arr[i])<<"; ";
    output<<endl;
}
istream & operator>>(istream & input, my_array &arr)
{
    cout<<"my_array size:";
    cin>>arr.size;
    delete [] arr.mass;
    arr.mass=new int[arr.size];
    for(int i =0;i<arr.size;i++)
    {
        cout<<"element"<<i<<": ";
        cin>>arr[i];}
}
my_array&my_array::operator++()
{
    for(int i=0;i<size;i++)
        mass[i]++;
    return *this;
}
my_array&my_array::operator++(int)
{
    current=*this;
    for(int i=0;i<size;i++)
        mass[i]++;
    return current;
}
my_array&my_array::operator+=(int value)
{
    for(int i=0;i<size;i++)
        mass[i]+=value;
    return *this;
}
void my_array::filling_random()
{
    for(int i=0; i<size;i++) mass[i]=rand()&100+1;
}



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

void MainWindow::on_pushButton_6_clicked()
{
    srand(time(0));
    switch (ui->spinBox->value()){
    case 1:
    {
        my_array Array_F(ui->spinBox_2->value());
        Array_F.filling_random();
        ArrayA = Array_F;
        break;
    }
    case 2:
    {
        my_array Array_F(ui->spinBox_2->value());
        Array_F.filling_random();
        ArrayB = Array_F;
        break;
    }
    case 3:
    {
        my_array Array_F(ui->spinBox_2->value());
        Array_F.filling_random();
        ArrayC = Array_F;
        break;
    }
    case 4:
    {
        my_array Array_F(ui->spinBox_2->value());
        Array_F.filling_random();
        ArrayD = Array_F;
        break;
    }
    default:
        break;
    }
}

void MainWindow::on_action_triggered()
{
   switch (ui->spinBox->value()){
   case 1:
       ui->comboBox->clear();
       for(int i=0;i<ArrayA.get_size();i++)
           ui->comboBox->insertItem(i,QString::number(ArrayA[i]));
       break;
   case 2:
       ui->comboBox_2->clear();
       for(int i=0;i<ArrayB.get_size();i++)
           ui->comboBox_2->insertItem(i,QString::number(ArrayB[i]));
       break;
   case 3:
       ui->comboBox_3->clear();
       for(int i=0;i<ArrayC.get_size();i++)
           ui->comboBox_3->insertItem(i,QString::number(ArrayC[i]));
       break;
   case 4:
       ui->comboBox_4->clear();
       for(int i=0;i<ArrayD.get_size();i++)
           ui->comboBox_4->insertItem(i,QString::number(ArrayD[i]));
       break;
   default:
       break;
   }
}
