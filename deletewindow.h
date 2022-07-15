#ifndef DELETEWINDOW_H
#define DELETEWINDOW_H

#include <QDialog>

namespace Ui {
class DeleteWindow;
}

class DeleteWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteWindow(QWidget *parent = nullptr);
    ~DeleteWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DeleteWindow *ui;
};

#endif // DELETEWINDOW_H
