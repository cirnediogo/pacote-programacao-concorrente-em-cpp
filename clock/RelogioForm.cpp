/*
 * File:   RelogioForm.cpp
 * Author: diogo
 *
 * Created on 22 de Setembro de 2010, 22:24
 */

#include "RelogioForm.h"
#include <qt4/QtCore/qdatetime.h>

RelogioForm::RelogioForm() {
    widget.setupUi(this);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()), this, SLOT(rodar()));
    timer->start(1000);
}

RelogioForm::~RelogioForm() {
    timer->~QTimer();
}

void RelogioForm::rodar() {
    QTime t = QTime::currentTime();

    widget.lcdNumber_hora->display(t.hour());
    widget.lcdNumber_min->display(t.minute());
    widget.lcdNumber_seg->display(t.second());
    //startTimer(1000);
}