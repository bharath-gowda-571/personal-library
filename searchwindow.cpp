#include "searchwindow.h"
#include "ui_searchwindow.h"
#include "grocery.h"
#include <QDebug>
SearchWindow::SearchWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchWindow)
{
    ui->setupUi(this);
}

SearchWindow::~SearchWindow()
{
    delete ui;
}

void SearchWindow::on_pushButton_clicked()
{
    Library lib;
    string ser=ui->textEdit->toPlainText().toStdString();
    string res=lib.search(ser);

    if(res.length()==0)
    {
         qDebug()<<QString::fromStdString(res);
        ui->textBrowser->setText("No records with that key found");
    }
    else{
        ui->textBrowser->setText(QString::fromStdString(res));
    }

 //       qApp->processEvents();
}

