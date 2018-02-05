/*
 * File:   main.cpp
 * Author: diogo
 *
 * Created on 22 de Setembro de 2010, 17:16
 */

#include <QtGui/QApplication>

#include "TempoDeVidaForm.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);

    TempoDeVidaForm f;
    f.show();

    // create and show your widgets here

    return app.exec();
}
