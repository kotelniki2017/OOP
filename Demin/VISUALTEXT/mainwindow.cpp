#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<map>
using namespace std;
class My_text
{
    public:
    void get_text();
    void set_text(QString);
    QString use_search_to_text(QString,QString, int);
    QString use_replace_to_text(QString);
    My_text();
    ~My_text();
        int i1=0;
        int i2=0;
        int i3=0;
    QString str;
    private:
    char *array_text;
};
class My_QString:public My_text
{
public:
    map<std::string,QString>varsS;
    void get_QString();
    QString use_search_to_QString(int);
    QString use_replace_to_QString(QString, int);
    void set_QString();
    My_QString();
    ~My_QString();
private:
    char *array_QString;
};
class My_words:public My_QString
{
public:
    map<std::string,QString>varsC;
    map<std::string,QString>varsW;
    void set_words();
    void set_characters();
    QString regular(QString);
    QString counter();
    My_words();
    ~My_words();
private:
    char *array_character;
    char *array_words;
};


My_text::My_text(){}
void My_text::set_text(QString Cstr)
{
str=Cstr;
array_text=new char [str.length()];
strcpy(array_text, str.toLocal8Bit().constData());
}
void My_text::get_text()
{
        str=array_text;
}
QString My_text::use_search_to_text(QString sear, QString toList, int i=0)
{
QString check=sear;
i1=0;
char array_search[sear.length()];
strcpy(array_search, sear.toLocal8Bit().constData());
sear="";
while(i<=str.length())
{
if(array_search[i1]==array_text[i])
{
    sear+=array_text[i];
    i1++;
}
else
{
    sear="";
    i1=0;
}
if(sear==check)
{
toList+=sear;
toList+=" ";
}
i++;
}
return toList;
}
QString My_text::use_replace_to_text(QString repl)
{
    strcpy(array_text, repl.toLocal8Bit().constData());
    return array_text;
}

My_QString::My_QString(){}
void My_QString::set_QString()
{
    array_QString=new char[str.length()];
    strcpy(array_QString, str.toLocal8Bit().constData());
    i2=0;
    for(int i=0; i<str.length(); i++)
    {
        if((array_QString[i]=='.'||array_QString[i]=='!'||array_QString[i]=='?')&&array_QString[i+1]!=' ')
        {
            varsS["a"+std::to_string(i2)]+=array_QString[i];
            i++;
        }
        if(array_QString[i]=='.'||array_QString[i]=='!'||array_QString[i]=='?')
        {
            varsS["a"+std::to_string(i2)]+=array_QString[i];
            i2++;
            i++;
        }
        if(array_QString[i]==' '&&(array_QString[i-1]=='.'||array_QString[i-1]=='!'||array_QString[i-1]=='?'))
        {
            for(;array_QString[i]==' '; i++){}
        }
        varsS["a"+std::to_string(i2)]+=array_QString[i];
    }
}
void My_QString::get_QString()
{
    str=array_QString;
}
QString My_QString::use_search_to_QString(int i)
{
    varsS["a"+std::to_string(i2)];
    for(i2=0; i2<=i1; i2++)
    {
        if(i2==i)
        {
            return varsS["a"+std::to_string(i2)];
        }
    }
}
QString My_QString::use_replace_to_QString(QString repl, int i)
{
    i1=i2;
    for(i2=0; i2<=i1; i2++)
    {
        if(i2==i)
        {
            varsS["a"+std::to_string(i2)]=repl;
        }
    }
    str="";
    for(i=0; i<=i2; i++)
    {
        str+=varsS["a"+std::to_string(i)];
    }
    return str;
}

My_words::My_words(){}
void My_words::set_words()
{
    int i=0;
    i1=0;
    array_words=new char[str.length()];
    strcpy(array_words, str.toLocal8Bit().constData());
    while(i<str.length())
    {
        if(array_words[i]==' ')
        {
            i1++;
            for(; array_words[i]=='\0'; i++){}
        }
    varsW["b"+std::to_string(i1)]+=array_words[i];
    i++;
    }
}
void My_words::set_characters()
{
    array_character=new char [str.length()];
    strcpy(array_character, str.toLocal8Bit().constData());
}
QString My_words::regular(QString regl)
{
    char i1;
    char i2;
    char array_regular[str.length()];
    strcpy(array_regular, regl.toLocal8Bit().constData());
    i1=array_regular[0];
    i2=array_regular[2];
    regl="";
    if((i1=='1'||i1=='2'||i1=='3'||i1=='4'||i1=='5'||i1=='6'||i1=='7'||i1=='8'||i1=='9'||i1=='0')&&
            (i2=='1'||i2=='2'||i2=='3'||i2=='4'||i2=='5'||i2=='6'||i2=='7'||i2=='8'||i2=='9'||i2=='0'))
    {
    for(int i=0; i<=str.length(); i++)
    {
        if(array_character[i]>=i1 && array_character[i]<=i2)
        {
            regl+=array_character[i];
        }
    }
    }
    if(i1=='.')
    {
            regl="";
    for(int i=0; i<=str.length(); i++)
    {
        if(array_character[i]=='.'||array_character[i]=='!'||array_character[i]=='?')
        {
            regl+=array_character[i];
        }
    }
    }
    return regl;
}
QString My_words::counter()
{
    varsS["a"+std::to_string(i1)];
    varsW["b"+std::to_string(i1)];
    i1;//слова
    i2;//строки
    QString count_words=QString::number(i1+1);
    QString count_strings=QString::number(i2+1);
    QString count_characters=QString::number(str.length());
    if(str.length()==0)
    {
        QString count_words=QString::number(0);
        QString count_strings=QString::number(0);
    }
    QString get_count=count_words+"-Words "+count_strings+"-Strings "+count_characters+"-Characters";
    return get_count;
}
My_text::~My_text(){}
My_QString::~My_QString(){}
My_words::~My_words(){}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_6->setInputMask("99999999999999");
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
My_text t;
QString sear;
QString toList;
QString Cstr;
Cstr=ui->textEdit->toPlainText();
t.set_text(Cstr);
sear=ui->lineEdit->text();
t.use_search_to_text(sear, toList);
ui->listWidget->addItem(t.use_search_to_text(sear, toList));
}

void MainWindow::on_pushButton_4_clicked()
{
    My_text t;
    QString Cstr;
    QString repl;
    Cstr=ui->textEdit->toPlainText();
    t.set_text(Cstr);
    repl=ui->lineEdit_3->text();
    t.use_replace_to_text(repl);
    ui->textEdit->clear();
    ui->textEdit->insertPlainText(t.use_replace_to_text(repl));
}

void MainWindow::on_pushButton_clicked()
{
    My_QString s;
    QString Cstr;
    int i;
    Cstr=ui->textEdit->toPlainText();
    i=ui->lineEdit_6->text().toInt();
    s.set_text(Cstr);
    s.set_QString();
    s.use_search_to_QString(i);
    ui->listWidget->addItem(s.use_search_to_QString(i));
}

void MainWindow::on_pushButton_2_clicked()
{
    int i;
    My_QString s;
    QString Cstr;
    QString repl;
    Cstr=ui->textEdit->toPlainText();
    i=ui->lineEdit_6->text().toInt();
    repl=ui->lineEdit_5->text();
    s.set_text(Cstr);
    s.set_QString();
    s.use_replace_to_QString(repl, i);
    ui->textEdit->clear();
    ui->textEdit->insertPlainText(s.use_replace_to_QString(repl, i));
}

void MainWindow::on_pushButton_5_clicked()
{
    My_words w;
    QString Cstr;
    QString regl;
    Cstr=ui->textEdit->toPlainText();
    regl=ui->lineEdit_2->text();
    w.set_text(Cstr);
    w.set_characters();
    w.regular(regl);
    ui->listWidget->addItem(w.regular(regl));
}

void MainWindow::on_pushButton_7_clicked()
{
My_words w;
QString Cstr;
Cstr=ui->textEdit->toPlainText();
w.set_text(Cstr);
w.set_QString();
w.set_words();
w.counter();
ui->statusBar->showMessage(w.counter());
}
