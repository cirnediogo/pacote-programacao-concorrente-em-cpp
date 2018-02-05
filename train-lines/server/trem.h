#ifndef TREM_H
#define TREM_H

#include <QThread>
#include <QPointF>
#include <QPropertyAnimation>
#include "trilhos.h"


class Trem : public QThread
{
public:
    void run();
    void configure(trilhos *i, int id);
    //void setId(int i);

private:
    trilhos *interface;
    int id;

};

#endif // TREM_H
