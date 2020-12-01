#ifndef PAREDES_H
#define PAREDES_H
#include <QGraphicsItem>
#include <QPainter>


class paredes : public QGraphicsItem
{
private:
    int ancho;
    int largo;
    int pos_x;
    int pos_y;
public:
    paredes();
    paredes(int a,int l,int x,int y);

    QRectF boundingRect() const;//Para el color
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // PAREDES_H
