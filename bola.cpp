#include "bola.h"

bola::bola()
{
    radio = 0;
    posicion_x = 0;
    posicion_y = 0;
    velocidad = 3;
    setPos(posicion_x, posicion_y);

}

bola::bola(int r, int x, int y)
{
    radio = r;
    posicion_x = x;
    posicion_y = y;
    velocidad = 3;
    setPos(posicion_x, posicion_y);

}

QRectF bola::boundingRect() const
{
    return QRectF(-radio,-radio, 2*radio, 2*radio);

}

void bola::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());
}

void bola::mover_arriba()
{
    posicion_y = posicion_y-(2*velocidad);
    setPos(posicion_x, posicion_y);
}

void bola::mover_abajo()
{
    posicion_y = posicion_y+(2*velocidad);
    setPos(posicion_x, posicion_y);
}

void bola::mover_derecha()
{
    posicion_x = posicion_x-(2*velocidad);
    setPos(posicion_x, posicion_y);
}

void bola::mover_izquierda()
{
    posicion_x = posicion_x+(2*velocidad);
    setPos(posicion_x, posicion_y);
}

