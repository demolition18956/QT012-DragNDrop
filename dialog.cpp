#include "dialog.h"
#include "ui_dialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QHBoxLayout* dropLayout = new QHBoxLayout();
    QHBoxLayout* dragLayout = new QHBoxLayout();

    setLayout(mainLayout);
    mainLayout->addLayout(dropLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(dragLayout);

    l1 = new DropLabel();
    l2 = new DropLabel();
    l3 = new DropLabel();
    l4 = new DropLabel();
    dropL = new QLabel("Drop Here");

    dropLayout->addWidget(dropL);
    dropLayout->addWidget(l1);
    dropLayout->addWidget(l2);
    dropLayout->addWidget(l3);
    dropLayout->addWidget(l4);

    d1 = new DragLabel(":images/red.png");
    d2 = new DragLabel(":images/green.png");
    d3 = new DragLabel(":images/blue.png");
    d4 = new DragLabel(":images/purple.png");
    dragL = new QLabel("Drag Here");

    dragLayout->addWidget(dragL);
    dragLayout->addWidget(d1);
    dragLayout->addWidget(d2);
    dragLayout->addWidget(d3);
    dragLayout->addWidget(d4);
}

Dialog::~Dialog()
{
    delete ui;
}
