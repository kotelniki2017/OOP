#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButton_clicked();
    void button_trans();
    void button_summ();
    void button_rank();
    void button_multiplication();
    void button_reverse();
private:
    Ui::MainWindow *ui;
};



#endif // MAINWINDOW_H
