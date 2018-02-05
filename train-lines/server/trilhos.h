#ifndef TRILHOS_H
#define TRILHOS_H

#include <QMainWindow>
#include <QtNetwork/QTcpServer>
#include <QMessageBox>
#include <QtNetwork/QTcpSocket>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QPropertyAnimation>
//#include "trem.h"

class PixmapItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
    Q_PROPERTY(qreal rot READ rotation WRITE setRotation)
public:
    PixmapItem(const QPixmap &pix) : QGraphicsPixmapItem(pix)
    {
    }
};

namespace Ui {
    class trilhos;
}

class trilhos : public QMainWindow
{
    Q_OBJECT

public:
    explicit trilhos(QWidget *parent = 0);
    void addTrain(int);
    void updateTrain(int);
    ~trilhos();

    Ui::trilhos *ui;
    QGraphicsScene *myScene;
    QPixmap trainPix;
    PixmapItem *pixItens[6];
    PixmapItem *it;
    static const int trainWidth = 95;
    static const int trainHeight = 40;
    QPointF trainWheelPos;
    QPropertyAnimation *anim1;
    QPropertyAnimation *anims[6];
    int velocidades[6];

    void mousePressEvent(QMouseEvent *evt);

public slots:
    void animateTrain(int);
    void receber();
    void acceptConnection();
    void startTrain(int);
    void continueTrain0();
    void continueTrain1();
    void getSem05();
    void continueTrain2();
    void continueTrain3();
    void continueTrain4();
    void continueTrain5();
//    void turnTrain0();
//    void turnTrain1();
//    void turnTrain2();
//    void turnTrain3();
//    void turnTrain4();
//    void turnTrain5();
//    void turn2Train0();
//    void turn2Train1();
//    void turn2Train2();
//    void turn2Train3();
//    void turn2Train4();
//    void turn2Train5();
signals:
    void sem05free();
    void sem06free();
    void sem09free();
    void sem10free();
    void sem11free();
    void sem12free();
    void sem15free();
    void sem18free();
    void sem19free();

private:
};

#endif // TRILHOS_H
