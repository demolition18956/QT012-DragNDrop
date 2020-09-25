#include "droplabel.h"
#include <QPixmap>

DropLabel::DropLabel(QWidget* parent) :
    QLabel (parent)
{
    this->setFrameStyle(QFrame::WinPanel);
    this->setFixedSize(50,50);
    setAcceptDrops(true);
}

void DropLabel::dragEnterEvent(QDragEnterEvent *event)
{
    if (event && event->mimeData())                 // If drag contains mimeData
    {
        const QMimeData* md = event->mimeData();    // Retrieve data from event

        if (md->hasImage())                         // if data has an image
        {
            event->acceptProposedAction();          // accept drag action (seen in cursor change)
        }
    }
}

void DropLabel::dropEvent(QDropEvent *event)
{
    QPixmap pic;                                        // Create QPixmap instance
    if (event && event->mimeData())                     // If event is has mimeData
    {
        const QMimeData* md = event->mimeData();        // Retrieve data from event

        if (md->hasImage())                             // if data has an image
        {
            pic = md->imageData().value<QPixmap>();     // place image data in instance
        }
    }
    if (!pic.isNull())                                  // if image is not null
    {
        setPixmap(pic.scaled(50,50));                   // Set Pixmap to drag pic
    }
}
