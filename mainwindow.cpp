#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bolita = new bola(10,200,150);
    ventana = new QGraphicsScene();
    ui->graphicsView->setScene(ventana);
    ventana->setSceneRect(0,0,400,250);//sistema en donde se parara el objeto u objetos
    ventana->addItem(bolita);
    setWindowTitle("PACMAN");
    ui->puntos->setText("0");
    ventana->setBackgroundBrush(QPixmap(":/imagenes/descarga.jpg"));
    int cont = 0;

    archivo.setFileName("objetos.txt");

    archivo.open(QIODevice::ReadOnly | QIODevice::Text);

    if(!archivo.isOpen())
    {
        qDebug()<<"El archivo no se pudo abrir-->";
        exit(1);

    }
    while(!archivo.atEnd())//leer el archivo
    {
        QString linea = archivo.readLine();//se guarda la linea del archivo
        qDebug()<<linea<<endl;
        almacenamiento_2 = linea.split(",");
        int contador = 0;
        int primero = 0, segundo = 0, tercero = 0, cuarto = 0;
        foreach (QString it, almacenamiento_2)//leer la lista
        {
            if(contador == 0)
            {
                primero = it.toInt();
                qDebug()<<primero<<endl;
            }
            else if(contador == 1)
            {
                segundo = it.toInt();
                qDebug()<<segundo<<endl;
            }
            else if(contador == 2)
            {
                tercero = it.toInt();
                qDebug()<<tercero<<endl;
            }
            else if(contador == 3)
            {
                cuarto = it.toInt();
                qDebug()<<cuarto<<endl;
            }
            contador++;
        }
        muro = new paredes(primero, segundo, tercero, cuarto);
        almacenamiento.push_back(muro);//meter en la lista

    }

    QListIterator<paredes*> it(almacenamiento);
    while(it.hasNext())
    {
        ventana->addItem(it.next());
    }

    archivo_2.setFileName("monedas.txt");

    archivo_2.open(QIODevice::ReadOnly | QIODevice::Text);

    if(!archivo_2.isOpen())
    {
        qDebug()<<"El archivo no se pudo abrir-->";
        exit(1);

    }
    while(!archivo_2.atEnd())//leer el archivo
    {
        QString linea = archivo_2.readLine();//se guarda la linea del archivo
        qDebug()<<linea<<endl;
        almacenamiento_3 = linea.split(",");
        int contador = 0;
        int primero = 0, segundo = 0, tercero = 0;
        foreach (QString it, almacenamiento_3)//leer la lista
        {
            if(contador == 0)
            {
                primero = it.toInt();
                qDebug()<<primero<<endl;
            }
            else if(contador == 1)
            {
                segundo = it.toInt();
                qDebug()<<segundo<<endl;
            }
            else if(contador == 2)
            {
                tercero = it.toInt();
                qDebug()<<tercero<<endl;
            }
            contador++;
        }

        comida = new monedas(primero, segundo, tercero);
        registro[cont] = comida;
        cont++;
    }

    QMap<int, monedas*>::iterator it_2;
    for(it_2 = registro.begin(); it_2 != registro.end(); it_2++)
    {
        ventana->addItem(it_2.value());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    QListIterator<paredes*> it(almacenamiento);
    QMap<int, monedas*>::iterator mueve;
    if(evento->key()==Qt::Key_D)
    {
        bolita->mover_izquierda();
        while(it.hasNext())
        {
            if(bolita->collidesWithItem(it.next()))
            {
                bolita->mover_derecha();
            }
        }

        for(mueve = registro.begin(); mueve != registro.end(); mueve++)
        {
            if(bolita->collidesWithItem(mueve.value()))
            {
                ventana->removeItem(mueve.value());
                registro.remove(mueve.key());
                incremento++;
                ui->puntos->setText(QString::number(incremento));
            }
        }
        if(registro.empty())
        {
            exit(1);
        }

    }
    else if(evento->key()==Qt::Key_A)
    {
        bolita->mover_derecha();
        while(it.hasNext())
        {
            if(bolita->collidesWithItem(it.next()))
            {
                bolita->mover_izquierda();
            }
        }

        for(mueve = registro.begin(); mueve != registro.end(); mueve++)
        {
            if(bolita->collidesWithItem(mueve.value()))
            {
                ventana->removeItem(mueve.value());
                registro.remove(mueve.key());
                incremento++;
                ui->puntos->setText(QString::number(incremento));
            }
        }
        if(registro.empty())
        {
            exit(1);
        }

    }
    else if(evento->key()==Qt::Key_S)
    {
        bolita->mover_arriba();
        while(it.hasNext())
        {
            if(bolita->collidesWithItem(it.next()))
            {
                bolita->mover_abajo();
            }
        }

        for(mueve = registro.begin(); mueve != registro.end(); mueve++)
        {
            if(bolita->collidesWithItem(mueve.value()))
            {
                ventana->removeItem(mueve.value());
                registro.remove(mueve.key());
                incremento++;
                ui->puntos->setText(QString::number(incremento));
            }
        }
        if(registro.empty())
        {
            exit(1);
        }

    }
    else if(evento->key()==Qt::Key_Z)
    {
        bolita->mover_abajo();
        while(it.hasNext())
        {
            if(bolita->collidesWithItem(it.next()))
            {
                bolita->mover_arriba();
            }
        }

        for(mueve = registro.begin(); mueve != registro.end(); mueve++)
        {
            if(bolita->collidesWithItem(mueve.value()))
            {
                ventana->removeItem(mueve.value());
                registro.remove(mueve.key());
                incremento++;
                ui->puntos->setText(QString::number(incremento));
            }
        }
        if(registro.empty())
        {
            exit(1);
        }

    }

}
