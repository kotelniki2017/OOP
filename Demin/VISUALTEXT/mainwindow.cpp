#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<map>// Контейнер map для создавания новых переменных с использованием циклов
using namespace std;
class My_text//Класс текста
{
    public:
    void get_text();//прототип для получения изменненного текта
    void set_text(QString);// прототип для записи текста в массив
    QString use_search_to_text(QString,QString, int);//прототип реализации поиска фрагмента текста
    QString use_replace_to_text(QString);//прототип реализации замены текста
    My_text();//конструктор класса
    ~My_text();//Деструктор класса
        int i1=0;// переменная для прототипов класса
        int i2=0;// переменная для прототипов класса
        int i3=0;// переменная для прототипов класса
    QString str;// сохраняет новый текст или измененный
    private:
    char *array_text;//массив текста
};
class My_QString:public My_text //класс текста, наследует прототипы и их изменения из класса My_Text
{
public:
    map<std::string,QString>varsS;// Контейнер map для создания переменных varsS с использованием цикла
    void get_QString();//прототип для получения строки
    QString use_search_to_QString(int);//прототип поиска строки
    QString use_replace_to_QString(QString, int);//прототип замены строки
    void set_QString();//прототип записи строк
    My_QString();// констркутор класса
    ~My_QString();// деструктор класса
private:
    char *array_QString;//массив из строк
};
class My_words:public My_QString//Класс слов, наследует свойства и их изменения из класса My_QString
{
public:
    map<std::string,QString>varsC;// Контейнер map для создания переменных varsC с использованием цикла
    map<std::string,QString>varsW;// Контейнер map для создания переменных varsW с использованием цикла
    void set_words();//прототип записи слов
    void set_characters();//прототип записи символов
    QString regular(QString);//прототип поиска по регулярным выражениям
    QString counter();//прототип подсчета символов, слов, строк
    My_words();// констркутор класса
    ~My_words();// деструктор класса
private:
    char *array_character;// массив символов
    char *array_words;// массив слов
};


My_text::My_text(){}//вызов конструктора класса
void My_text::set_text(QString Cstr)//реализация протипа записи текста в классе My_text
{
str=Cstr;// присваивание написанного текста из Cstr в str
array_text=new char [str.length()];//Создание массива размерности строки str
strcpy(array_text, str.toLocal8Bit().constData());//копирование строки str в массив array_text
}
void My_text::get_text()//реализация протипа получения измененного текста из класса My_text
{
        str=array_text;//запись массива в строку str
}
QString My_text::use_search_to_text(QString sear, QString toList, int i=0)//реализация протипа поиска фрагмента текста
{
QString check=sear;//запись строки sear с текстом пользователя в строку check
i1=0;//просваиваем 0 к i1
char array_search[sear.length()];//создание массива поиска размерности строки sear
strcpy(array_search, sear.toLocal8Bit().constData());// копирование строки sear в массив array_search
sear="";//строку приравниваем к пустоте
while(i<=str.length())//цикл пока i меньше или равен длине строке str из класса My_text
{
if(array_search[i1]==array_text[i])//Условие если элементу массива под номером i1 равен элементу массива под номером i
{
    sear+=array_text[i];//к строке sear прибавляется i элемент массива
    i1++;//прибавление к i1 1
}
else//условие иначе
{
    sear="";//срока sear приравнивается к пустоте
    i1=0;//i1 приравнивается к 0
}
if(sear==check)//условие sear равно check
{
toList+=sear; //к строке toList добавляется sear
toList+=" ";// к строке toList добавляется пробел
}
i++;//к i добавляется 1
}
return toList;//возвращаемая строчка toList
}
QString My_text::use_replace_to_text(QString repl)//реализация протипа замены текста
{
    strcpy(array_text, repl.toLocal8Bit().constData());// копирование сроки repl введеный пользователем в массив array_text
    return array_text;//возврат массива текста
}

My_QString::My_QString(){}//вызов конструктора строки
void My_QString::set_QString()//реализация протипа записи строк
{
    array_QString=new char[str.length()];//создание массива строк размерности строки str
    strcpy(array_QString, str.toLocal8Bit().constData());//копирование в массив array_QString строки str из класса My_text
    i2=0;//i2 равняется 0
    i1=0;//i1 равняется 0
    for(int i=0; i<str.length(); i++)//цикл for для создания новых строк
    {
        if((array_QString[i]=='.'||array_QString[i]=='!'||array_QString[i]=='?')&&array_QString[i+1]!=' ')// проверка на знаки препинания и пробел
        {
            varsS["a"+std::to_string(i2)]+=array_QString[i];// запись в i2 элемента контейнера i элемент массива
            i++;// к i прибавляется 1
        }
        if(array_QString[i]=='.'||array_QString[i]=='!'||array_QString[i]=='?')//проверка на знаки препинания элемента массива
        {
            varsS["a"+std::to_string(i2)]+=array_QString[i];//запись знака препинания к концу строки
            i2++;//к i2 прибавляется 1 после происходит запись в новый элемента контейнера
            i++;// к i прибавляется 1
            i1++;// подсчет строк
        }
        if(array_QString[i]==' '&&(array_QString[i-1]=='.'||array_QString[i-1]=='!'||array_QString[i-1]=='?'))// проверка на знаки препинания и пробел
        {
            for(;array_QString[i]==' '; i++){}// цикл пропускающий пробелы после последнего знака препинания
        }
        varsS["a"+std::to_string(i2)]+=array_QString[i];// запись в i2 элемента контейнера i элемент массива
    }
}
void My_QString::get_QString()//реализация протипа
{
    str=array_QString;
}
QString My_QString::use_search_to_QString(int i)//реализация протипа
{
    for(i2=0; i2<=i1; i2++)// на основе подсчитанного i1 выполняется цикл
    {
        if(i2==i)// если i2 равен i
        {
            return varsS["a"+std::to_string(i2)]; // выводится найденная строка
        }
    }
}
QString My_QString::use_replace_to_QString(QString repl, int i)//реализация протипа замены строки
{
    i1=i2;// к i1 присваивается количество строк i2
    for(i2=0; i2<=i1; i2++)//Цикл for поиска строки для замены
    {
        if(i2==i)// если i2 равен i
        {
            varsS["a"+std::to_string(i2)]=repl;//присваиваем элементу контейнера i2 строку repl
        }
    }
    str="";//строка str пустая
    for(i=0; i<=i2; i++)//цикл для записи в строку
    {
        str+=varsS["a"+std::to_string(i)];// присваивание к строке str i элемента контейнера
    }
    return str;// возврат строки str
}

My_words::My_words(){}//вызов конструктора My_words
void My_words::set_words()//реализация протипа записи слова
{
    int i=0;//к i присваиваем 0
    i1=0;// к i1 присваиваем 0
    array_words=new char[str.length()];//создаем массив слов размерностью строки str
    strcpy(array_words, str.toLocal8Bit().constData());// копируем строку str в массив array_words
    while(i<str.length())//цикл для создания элементов контейнера varsW со словами
    {
        if(array_words[i]==' ')// если i элемент массива array_words равен пробелу
        {
            i1++; // к i1 добавляем 1 тем самым создавая новый элемент контейнера
            for(; array_words[i]=='\0'; i++){}// цикл пропускает пробелы
        }
    varsW["b"+std::to_string(i1)]+=array_words[i];//к i1 элементу контейнера добавляется i элемент array_words
    i++;// переход к следующему элементу цикла
    }
}
void My_words::set_characters()//реализация протипа запись букв
{
    array_character=new char [str.length()];// создание массива размерностью строки str
    strcpy(array_character, str.toLocal8Bit().constData());// копирование в массив array_character строки str
}
QString My_words::regular(QString regl)//реализация протипа поиска по регулярным выражениям
{
    char i1;// создается переменная типа char i1
    char i2;// создается переменная типа char i2
    char array_regular[str.length()];//создается массив array_regular размерностью строки str
    strcpy(array_regular, regl.toLocal8Bit().constData());//копирование в массив array_regular введенного пользователем строки regl
    i1=array_regular[0];//к i1 присваивается элемент 0 массива array_regular
    i2=array_regular[2];//к i2 присваивается элемент 2 массива array_regular
    regl="";// пустой regl
    if((i1=='1'||i1=='2'||i1=='3'||i1=='4'||i1=='5'||i1=='6'||i1=='7'||i1=='8'||i1=='9'||i1=='0')&&
            (i2=='1'||i2=='2'||i2=='3'||i2=='4'||i2=='5'||i2=='6'||i2=='7'||i2=='8'||i2=='9'||i2=='0'))//условие поиска цифр в тексте
    {
    for(int i=0; i<=str.length(); i++)//цикл проверки цифр в тексте
    {
        if(array_character[i]>=i1 && array_character[i]<=i2)//если число входит в диапозон от i1 до i2
        {
            regl+=array_character[i];// число добавляется в строку regl
        }
    }
    }
    if(i1=='.')//если i1 равно точке
    {
            regl="";// пустой regl
    for(int i=0; i<=str.length(); i++)//цикл поиска знаков препинаний
    {
        if(array_character[i]=='.'||array_character[i]=='!'||array_character[i]=='?')//проверка элемента на знак препинания
        {
            regl+=array_character[i];//добавляем знак препинания в строку regl
        }
    }
    }
    return regl; //возврат строки regl
}
QString My_words::counter()//реализация протипа счетчика
{
    i1;//слова
    i2;//строки
    QString count_words=QString::number(i1+1);// присваивает количество слов в строку count_words
    QString count_strings=QString::number(i2+1);// присваивает количество строк в строку count_string
    QString count_characters=QString::number(str.length());// присваивает количество символов в строку count_characters
    if(str.length()==0)//если длина строки str равна 0
    {
        QString count_words=QString::number(0);//присваивает 0 к строке count_words
        QString count_strings=QString::number(0);//присваивает 0 к строке count_strings
    }
    QString get_count=count_words+"-Words "+count_strings+"-Strings "+count_characters+"-Characters";// присваивает к get_count строки count_words, count_string, count_characters c комментариями
    return get_count;// возврат get_count
}
My_text::~My_text(){}//Деструктор
My_QString::~My_QString(){}//Деструктор
My_words::~My_words(){}//Деструктор

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_6->setInputMask("999");//разрешаем элементу lineedit вводить только цифры
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
My_text t;// переменная для вызова функций класса My_text
QString sear;// создание строки sear
QString toList;// создание строки toList
QString Cstr;// создание строки Cstr
Cstr=ui->textEdit->toPlainText();//Вводим из виджета textedit строку Cstr
t.set_text(Cstr);// вызываем функцию ввода текста в строку str
sear=ui->lineEdit->text();// вводим словосочетание которое необходимо найти
t.use_search_to_text(sear, toList);// вызов функции поиска в тексте фрагмента sear
ui->listWidget->addItem(t.use_search_to_text(sear, toList));// Вывод на виджет listWidget найденного значения
}

void MainWindow::on_pushButton_4_clicked()
{
    My_text t;// переменная для вызова функций класса My_text
    QString Cstr;// создание строки Cstr
    QString repl;// создание строки repl
    Cstr=ui->textEdit->toPlainText();//Вводим из виджета textedit строку Cstr
    t.set_text(Cstr);// вызываем функцию ввода текста в строку str
    repl=ui->lineEdit_3->text();// присваеивает значение на которое нужно заменить в repl из виджета lineEdit_3
    t.use_replace_to_text(repl);//вызываем функцию
    ui->textEdit->clear();//очистка текста из виджета
    ui->textEdit->insertPlainText(t.use_replace_to_text(repl));// вставка нового текста
}

void MainWindow::on_pushButton_clicked()
{
    My_QString s;// переменная для вызова функций класса My_QString
    QString Cstr;// создание строки Cstr
    int i;// переменная int
    Cstr=ui->textEdit->toPlainText();//Вводим из виджета textedit строку Cstr
    i=ui->lineEdit_6->text().toInt();//присваиваем цифру из виджета lineEdit_6
    s.set_text(Cstr);// вызываем функцию ввода текста в строку str
    s.set_QString();// вызывается функция записи в строки
    s.use_search_to_QString(i);//вызывается функция поиска строки по цифре из i
    ui->listWidget->addItem(s.use_search_to_QString(i));// Вывод на виджет listWidget найденного значения
}

void MainWindow::on_pushButton_2_clicked()
{
    int i;
    My_QString s;// переменная для вызова функций класса My_QString
    QString Cstr;// создание строки Cstr
    QString repl;// создание строки repl
    Cstr=ui->textEdit->toPlainText();//Вводим из виджета textedit строку Cstr
    i=ui->lineEdit_6->text().toInt();//Вводим значения номера строки 1 элемент равен=0
    repl=ui->lineEdit_5->text();
    s.set_text(Cstr);// вызываем функцию ввода текста в строку str
    s.set_QString();// запись в строки
    s.use_replace_to_QString(repl, i);//функция замены строки на другую
    ui->textEdit->clear();//очистка текста из виджета textEdit
    ui->textEdit->insertPlainText(s.use_replace_to_QString(repl, i));//вывод на textEdit измененного текста
}

void MainWindow::on_pushButton_5_clicked()
{
    My_words w;// переменная для вызова функций класса My_words
    QString Cstr;// создание строки Cstr
    QString regl;// создание строки regl
    Cstr=ui->textEdit->toPlainText();//Вводим из виджета textedit строку Cstr
    regl=ui->lineEdit_2->text();//присваиваем в строку regl текст из виджета lineEdit_2 для поиска по регулярным выражениям
    w.set_text(Cstr);// вызываем функцию ввода текста в строку str
    w.set_characters();//вызов функции записи букв
    w.regular(regl);// вызов функции поиска по регулярным выражениям
    ui->listWidget->addItem(w.regular(regl));// Вывод на виджет listWidget найденного значения
}

void MainWindow::on_pushButton_7_clicked()
{
My_words w;// переменная для вызова функций класса My_words
QString Cstr;// создание строки Cstr
Cstr=ui->textEdit->toPlainText();//Вводим из виджета textedit строку Cstr
w.set_text(Cstr);// вызываем функцию ввода текста в строку str
w.set_QString();//вызов функции ввода в строки
w.set_words();//функция вызова вписать слова
w.counter();// вызов функции подсчета слов, строк, символов
ui->statusBar->showMessage(w.counter());//вывод на виджет statusBar сообщения о количестве элементов
}
