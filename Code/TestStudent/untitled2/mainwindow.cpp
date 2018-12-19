#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<string>

using namespace std;
class man{
protected:
    std::string lastname;
    std::string firstname;
    std::string secondname;
    int dayofbirth;
    int monthofbirth;
    int yearofbirth;
public:
    man(string, string, string, int, int, int);
    string get_lastname()const;
    string get_firstname()const;
    string get_secondname()const;
    int get_dayOfbirth()const;
    int get_monthOfbirth()const;
    int get_yearOfbirth()const;
    void set_changeLastname(string);
};
man::man(string ln, string fn, string sn, int d, int m, int y){
    lastname=ln;
    firstname=fn;
    secondname=sn;
    dayofbirth=d;
    monthofbirth=m;
    yearofbirth=y;
}
string man::get_lastname()const
{
    return lastname;
}
string man::get_firstname()const
{
    return firstname;
}
string man::get_secondname()const
{
    return secondname;
}
int man::get_dayOfbirth()const
{
    return  dayofbirth;
}
int man::get_monthOfbirth()const
{
    return  monthofbirth;
}
int man::get_yearOfbirth()const
{
    return  yearofbirth;
}
void man::set_changeLastname(string ln)
{
    lastname=ln;
}
/*
class Student: public man
{
protected:
    string NumberBook;
    string Universe;
    float AverageValue;
    int Course;
public:
    Student(string, string, string, int , int, int, string, string, float, int);
    string get_NumberBook()const;
    string get_Universe()const;
    float get_AverageValue()const;
    int get_Course()const;
    void set_AverageValue(float);
    void set_Course(int);
};

Student::Student(string ln, string fn, string sn, int d, int m, int y,string NumB, string Un, float Av, int Cour)
    :man(ln, fn, sn, d, m, y)
{
    NumberBook=NumB;
    Universe=Un;
    AverageValue=Av;
    Course=Cour;
}
string Student::get_NumberBook()const
{
    return NumberBook;
}
string Student::get_Universe()const
{
    return Universe;
}
float Student::get_AverageValue()const
{
    return  AverageValue;
}
int Student::get_Course()const
{
    return  Course;
}
void Student::set_AverageValue(float av)
{
    AverageValue=av;
}
void Student::set_Course(int c)
{
    Course=c;
}
class Workman:public man
{
protected:
    string Place;
    float Payment;
    int YearOfWork;
public:
    Workman(string, string, string, int, int, int, string, float, int);
    string get_Place();
    float get_Payment();
    int get_YearOfWork();
    void set_Payment(float);
    void set_Place(string);
};
Workman::Workman(string ln, string fn, string sn, int d, int m, int y, string Pl, float Pay, int YofW)
    :man(ln, fn, sn, d, m, y)
{
    Place=Pl;
    Payment=Pay;
    YearOfWork=YofW;
}
string Workman::get_Place()
{
    return Place;
}
float Workman::get_Payment()
{
    return Payment;
}
int Workman::get_YearOfWork()
{
    return YearOfWork;
}
void Workman::set_Payment(float Pay)
{
    Payment=Pay;
}
void Workman::set_Place(string Pl)
{
    Place=Pl;
}

*/
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


template <class T>
class node
{
 public:
  node(T*);
  void set_next(node*);
  void set_prev(node*);
  void set_value(T* value);
  node* get_next();
  node* get_prev();
  T get_value();
 private:
  T* value;
  node* next;
  node* prev;
};

template <class T>
node<T>::node(T* a)
{
  value=a;
  next=NULL;
  prev=NULL;
}
template <class T>
T node<T>::get_value()
{
  return value;
}
template <class T>
node<T>* node<T>::get_prev()
{
  return prev;
}
template <class T>
node<T>* node<T>::get_next()
{
  return next;
}
template <class T>
void node<T>::set_next(node* p)
{
  next=p;
}
template <class T>
void node<T>::set_prev(node* p)
{
  prev=p;
}
template <class T>
void node<T>::set_value(T* x)
{
  value=x;
}

template <class T>
class mylist
{
 public:
  mylist(node<T>*);
//  ~mylist();
  void add_node(node<T>*);
  node<T>* get_left();
  node<T>* get_right();
  node<T>* get_current();
  void set_current(node<T>*);
private:
  node<T>* current;
  node<T>* top;
};


template <class T>
mylist<T>::mylist(node<T>* a)
{
  current = a;
  top = a;
}


template <class T>
void mylist<T>::add_node(node<T>* a)
{
  top->set_prev(a);
  a->set_next(top);
  top=a;
}

template <class T>
node<T>* mylist<T>::get_current()
{
  return current;
}

template <class T>
node<T>* mylist<T>::get_next()
{
  return current->get_next();
}

template <class T>
node<T>* mylist<T>::get_prev()
{
  return current->get_prev();
}

/*
template <class T>
list::~list()
{
  node * current_del, *current_next;
  current_del = top;
  while (current_del != NULL)
    {
      current_next = current_del->get_next();
      delete current_del;
      current_del = current_next;
    }
  cout<<"It's ok!";

}

template <class T>
node list::get_top()
{
  return *top;
}
template <class T>
node list::get_last()
{
  return *last;
}
template <class T>
void list::add_node_begin(T x)
{
  node * current;
  current = new node;
  current->set_value(x);
  current->set_next(top);
  top->set_prev(current);
  top=current;
}
template <class T>
void list::show_list()
{
  node *x;
  x=top;
  while(x != NULL)
    {
      cout<<x->get_value()<<"->";
      x=x->get_next();
    }
  cout<<endl;
}

*/

man human ("adamov","edem", "edemovich", 1,1,1);
node<man> firstnode(&human);
mylist<man> g(&firstnode);


void MainWindow::on_pushButton_clicked()
{
    man a(ui->lineEdit->text().toStdString(), ui->lineEdit_2->text().toStdString(),
          ui->lineEdit_3->text().toStdString(),
          ui->spinBox->value(),ui->spinBox_2->value(), ui->spinBox_3->value());

}
