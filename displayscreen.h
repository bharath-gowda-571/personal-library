#ifndef DISPLAYSCREEN_H
#define DISPLAYSCREEN_H

#include <QDialog>

namespace Ui {
class DisplayScreen;
}

class DisplayScreen : public QDialog
{
    Q_OBJECT

public:
    explicit DisplayScreen(QWidget *parent = nullptr);
    ~DisplayScreen();

private:
    Ui::DisplayScreen *ui;
};

#endif // DISPLAYSCREEN_H
