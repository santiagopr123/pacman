#include "monedas.h"

monedas::monedas()
{
    radio = 0;
    posicion_x = 0;
    posicion_y = 0;

    setPos(posicion_x, posicion_y);
}

monedas::monedas(int r, int x, int y)
{
    radio = r;
    posicion_x = x;
    posicion_y = y;

    setPos(posicion_x, posicion_y);

}

QRectF monedas::boundingRect() const
{
    return QRectF(-radio,-radio, 2*radio, 2*radio);

}

void monedas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::cyan);
    painter->drawEllipse(boundingRect());
}
