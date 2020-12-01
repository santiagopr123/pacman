#include "paredes.h"

paredes::paredes()
{

    ancho = 0;
    largo = 0;
    pos_x = 0;
    pos_y = 0;
    setPos(pos_x,pos_y);

}

paredes::paredes(int a, int l, int x, int y)
{
    ancho = a;
    largo = l;
    pos_x = x;
    pos_y = y;
    setPos(pos_x,pos_y);
}

QRectF paredes::boundingRect() const
{
    return QRectF(pos_x,pos_y, ancho, largo);
}

void paredes::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRect(boundingRect());

}
