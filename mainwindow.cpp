#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "hash_util.h"
#include "secondwindow.h"
#include "searchwindow.h"
#include "displayscreen.h"
#include "deletewindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Hash h;
    qDebug()<<QString::fromStdString(to_string(h.hash("milk")));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    SecondWindow sec_win(this);
    sec_win.exec();
}


void MainWindow::on_pushButton_4_clicked()
{
    SearchWindow ser_win(this);
    ser_win.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    DisplayScreen ds(this);
    ds.exec();
}


void MainWindow::on_pushButton_3_clicked()
{
    DeleteWindow dw(this);
    dw.exec();
}

