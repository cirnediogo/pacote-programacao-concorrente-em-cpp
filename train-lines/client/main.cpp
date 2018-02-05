#include <QtGui/QApplication>
#include "controle.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controle w;
    w.show();

    return a.exec();
}
