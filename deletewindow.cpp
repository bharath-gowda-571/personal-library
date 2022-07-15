#include "deletewindow.h"
#include "ui_deletewindow.h"
#include <string>
#include <grocery.h>
#include <QMessageBox>
using namespace std;
DeleteWindow::DeleteWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteWindow)
{
    ui->setupUi(this);
}

DeleteWindow::~DeleteWindow()
{
    delete ui;
}

void DeleteWindow::on_pushButton_clicked()
{
    string key=ui->textEdit->toPlainText().toStdString();
    Library lib;
    bool res=lib.delete_rec(key);
    QMessageBox Msgbox;


    if(res)
    {
        Msgbox.setText("book entry deleted");
    }
    else{
        Msgbox.setText("book entry could not be found or deleted");
    }
    Msgbox.exec();
}

