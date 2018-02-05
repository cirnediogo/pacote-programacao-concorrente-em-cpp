/*
 * File:   main.cpp
 * Author: diogo
 *
 * Created on 22 de Setembro de 2010, 22:19
 */

#include <QtGui/QApplication>

#include "RelogioForm.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);

    RelogioForm f;
    f.show();

    // create and show your widgets here

    return app.exec();
}
