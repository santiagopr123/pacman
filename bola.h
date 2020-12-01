#ifndef BOLA_H
#define BOLA_H
#include <QGraphicsItem>
#include <QPainter>

class bola : public QGraphicsItem
{
private:
    int radio;
    int posicion_y;
    int posicion_x;
    int movimiento;
    int velocidad;
public:
    bola();
    bola(int r,int x,int y);

    QRectF boundingRect() const;//Para el color
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    void mover_arriba();
    void mover_abajo();
    void mover_derecha();
    void mover_izquierda();



};

#endif // BOLA_H
