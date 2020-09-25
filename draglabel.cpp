#include "draglabel.h"
#include <QPixmap>
#include <QMouseEvent>
#include <QImage>
#include <QMimeData>
#include <QDrag>

DragLabel::DragLabel(const QString& path, QWidget* parent):
    QLabel(parent)
{
    filename = path;
    this->setFixedSize(50,50);
    setPixmap(QPixmap(filename).scaled(50,50));
}

void DragLabel::mousePressEvent(QMouseEvent* event)
{
    if (event && (event->button() == Qt::LeftButton))
    {
        QMimeData* md = new QMimeData;  // Create "Data holder" object
        QImage pic(filename);
        md->setImageData(pic);          // Set picture data into object

        QDrag* drag = new QDrag(this);  // Create drag object
        drag->setMimeData(md);          // store image mimedata into drag object

        if (pixmap())                               // if pixmap attached...
        {
            QSize s = this->sizeHint();             // find size
            drag->setPixmap(pixmap()->scaled(s));   // set pixmap and scale to size
        }
        drag->start();                  // Initiate drag
    }
}
