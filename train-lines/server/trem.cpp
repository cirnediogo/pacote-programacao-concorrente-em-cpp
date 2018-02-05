#include <QDebug>
#include "trem.h"

void Trem::run() {
    interface->addTrain(id);
    interface->animateTrain(id);
}

void Trem::configure(trilhos *i, int id) {
    interface = i;
    this->id = id;
}

