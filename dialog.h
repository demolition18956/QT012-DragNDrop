#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "draglabel.h"
#include "droplabel.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QLabel* dropL;
    QLabel* dragL;
    DragLabel* d1;
    DragLabel* d2;
    DragLabel* d3;
    DragLabel* d4;

    DropLabel* l1;
    DropLabel* l2;
    DropLabel* l3;
    DropLabel* l4;

};

#endif // DIALOG_H
