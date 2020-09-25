#ifndef DRAGLABEL_H
#define DRAGLABEL_H

#include <QWidget>
#include <QLabel>
#include <QString>

class DragLabel : public QLabel
{
public:
    DragLabel(const QString& path, QWidget* parent = 0);

protected:
    void mousePressEvent(QMouseEvent* event);

private:
    QString filename;
};

#endif // DRAGLABEL_H
