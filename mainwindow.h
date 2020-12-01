#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <bola.h>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <paredes.h>
#include <QList>
#include <QFile>
#include <QDebug>
#include <QString>
#include <QStringList>
#include <monedas.h>
#include <QMap>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    int incremento = 0;


    bola *bolita;
    paredes *muro,*muro_1,*muro_2;
    monedas *comida;
    QGraphicsScene *ventana;


    QList<paredes*> almacenamiento;
    QList<monedas*> almacenamiento_4;
    QStringList almacenamiento_2;
    QStringList almacenamiento_3;
    QFile archivo;
    QFile archivo_2;
    QMap<int, monedas*> registro;

    void keyPressEvent(QKeyEvent *evento);

};
#endif // MAINWINDOW_H
