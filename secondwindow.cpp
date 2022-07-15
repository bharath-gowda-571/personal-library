#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <string>
#include "grocery.h"
#include <QMessageBox>
using namespace std;
SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_pushButton_clicked()
{
    Library lib;
    string book_name=ui->textEdit->toPlainText().toStdString();
    string author=ui->textEdit_2->toPlainText().toStdString();
    string publisher=ui->textEdit_3->toPlainText().toStdString();
    string description=ui->textEdit_4->toPlainText().toStdString();
    if(book_name.length()==0)
    {
    QApplication::beep();
    return;
    }
    lib.add_book(book_name,author,publisher,description);
    QMessageBox Msgbox;


      Msgbox.setText("book entry added");



    Msgbox.exec();
}

