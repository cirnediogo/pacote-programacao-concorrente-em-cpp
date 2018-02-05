/*
 * File:   TempoDeVidaForm.cpp
 * Author: diogo
 *
 * Created on 22 de Setembro de 2010, 17:17
 */
#include "TempoDeVidaForm.h"
//#include <QPushButton>

#include <iostream> // para: cout
#include <time.h>   // para: time()
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <strings.h>
#include <sstream>

TempoDeVidaForm::TempoDeVidaForm() {
    widget.setupUi(this);
    connect(widget.pushButton, SIGNAL(clicked()), this, SLOT(calcular()));
}

TempoDeVidaForm::~TempoDeVidaForm() {
}

void TempoDeVidaForm::calcular() {
    time_t tempo_atual = time (NULL); //time ( &tempo_atual )

    QDate d = widget.dateEdit->date();

    int ano = d.year();
    int mes = d.month();
    int dia = d.day();

    struct tm * timeinfo = localtime ( &tempo_atual );

    timeinfo->tm_year = ano-1900;//-1900;
    timeinfo->tm_mon = mes-1;//-1;
    timeinfo->tm_mday = dia;

    time_t tempo_data = mktime(timeinfo);

    time_t diferenca = difftime(tempo_atual, tempo_data);


      std::stringstream ss2 (std::stringstream::in | std::stringstream::out);
      ss2 << diferenca;
      std::string s = ss2.str();

    QString q = QString::fromStdString(s);

    widget.label->setText("O tempo total de vida em segundos e:\n"+q);
}
