#include <QtGui/QApplication>
#include "trilhos.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(Imagens);
    QApplication a(argc, argv);
    trilhos w;
    w.show();

    return a.exec();
}
