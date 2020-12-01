#ifndef MONEDAS_H
#define MONEDAS_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class monedas : public QObject, public QGraphicsItem
{
    int radio;
    int posicion_y;
    int posicion_x;
public:
    monedas();
    monedas(int r,int x,int y);

    QRectF boundingRect() const;//Para el color
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);


};

#endif // MONEDAS_H
