#include "ScrollBar.h"
#include <QPainter>
VScrollBar::VScrollBar()
{

}
void VScrollBar::paintEvent(QPaintEvent* e){
    qreal pos = this->value() * 1.0 / this->maximum();
    static const int w = 16; // width of knob
    static const int round = w / 2 + 1;
    int x = width();
    int y = height();
    QPainter p(this);
    p.setRenderHints(QPainter::Antialiasing );
    QPen pen;
    pen.setColor("black");
    p.setPen(pen);
    //draw a line
    p.drawRoundedRect(QRectF(x/2-1,20,2,y - 40),1,1); // draw a line

    int _y = (y-40-w) * pos;
    p.setBrush(QBrush("gray"));
    //draw a knob
    p.drawRoundedRect(QRectF((x-w)/2,_y+20,w,w),round,round);
}
