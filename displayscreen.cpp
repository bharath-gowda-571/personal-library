#include "displayscreen.h"
#include "ui_displayscreen.h"
#include "grocery.h"

DisplayScreen::DisplayScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplayScreen)
{
    ui->setupUi(this);
    Library lib;
    string res=lib.display();
    if(res=="")
        ui->textBrowser->setText(QString::fromStdString("No books in your library yet"));
    else
        ui->textBrowser->setText(QString::fromStdString(res));
}

DisplayScreen::~DisplayScreen()
{
    delete ui;
}
