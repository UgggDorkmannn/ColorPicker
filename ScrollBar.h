#ifndef SCROLLBAR_H
#define SCROLLBAR_H

#include <QWidget>
#include <QScrollBar>
class VScrollBar:public QScrollBar
{
public:
    VScrollBar();
protected:
    void paintEvent(QPaintEvent* e);
};

#endif // SCROLLBAR_H
