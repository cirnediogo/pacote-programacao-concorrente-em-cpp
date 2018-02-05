#include "trilhos.h"
#include "ui_trilhos.h"
#include <QNetworkInterface>
#include <QMouseEvent>
#include <QDebug>
#include <QSemaphore>
#include "time.h"
#include "trem.h"
#include <QTimer>

QTcpServer tcpserver;
QTcpSocket * client;
trilhos::trilhos(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::trilhos)
{
    ui->setupUi(this);

    connect(&tcpserver, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
    tcpserver.listen(QHostAddress::Any, 8888);
   /* if (!tcpserver.listen()) {
          QMessageBox::critical(this, tr("Fortune Server"),
                                tr("Unable to start the server: %1.")
                                .arg(tcpserver.errorString()));
          close();
          return;
     }*/
    QString ipAddress;
    ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    QString ownIpAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ownIpAddress = ipAddressesList.at(i).toString();
            break;
        }
    }

    ui->statusBar->showMessage(tr("The server is running on\n\nIP: %1\nport: %2\n\n").arg(ownIpAddress).arg(tcpserver.serverPort()));

    //trainWidth = 143;
    //trainHeight = 60;
    trainWheelPos = QPointF(15,42);
    //L01Length = 280;

    myScene = new QGraphicsScene(0,0,1100,650,ui->graphicsView);
    ui->graphicsView->setScene(myScene);

    QPixmap backgroundPix(":/trilhos.png");
    myScene->addPixmap(backgroundPix);

//    trainPix = QPixmap(":/trem.png");
    trainPix = QPixmap(":/bola.png");

}

//QPointF positions [6] = {QPointF(80,25), QPointF(370,25), QPointF(720,25), QPointF(130,400), QPointF(925,250), QPointF(700,625)};
QPointF positions [6] = {QPointF(64,56), QPointF(348,56), QPointF(702,56), QPointF(163,405), QPointF(878,232), QPointF(704,579)};
//qreal rotations [6] = {0,0,0,270,90,180};
int executando [6] = {0,0,0,0,0,0};
QPointF trilhosLadoA [23] = {QPoint(64,56), QPoint(348,56), QPoint(702,56),
                         QPoint(64,56), QPoint(348,56), QPoint(702,56), QPoint(1008,56),
                         QPoint(64,232), QPoint(163,232), QPoint(344,232), QPoint(537,232), QPoint(701,232), QPoint(878,232),
                         QPoint(163,232), QPoint(537,232), QPoint(878,232),
                         QPoint(163,405), QPoint(351,405), QPoint(538,405), QPoint(705,405),
                         QPoint(351,405), QPoint(705,405), QPoint(351,579)};
QPointF trilhosLadoB [23] = {QPoint(348,56), QPoint(702,56), QPoint(1008,56),
                         QPoint(63,232), QPoint(346,232), QPoint(700,232), QPoint(1009,232),
                         QPoint(162,232), QPoint(344,232), QPoint(537,232), QPoint(701,232), QPoint(878,232), QPoint(1008,232),
                         QPoint(161,405), QPoint(535,405), QPoint(879,405),
                         QPoint(351,405), QPoint(538,405), QPoint(705,405), QPoint(880,405),
                         QPoint(351,579), QPoint(704,579), QPoint(704,579)};
//QPointF trilhosLadoA [23] = {QPoint(82,65), QPoint(365,65), QPoint(725,65),
//                         QPoint(72,77), QPoint(355,77), QPoint(711,77), QPoint(1018,77),
//                         QPoint(82,240), QPoint(180,240), QPoint(370,240), QPoint(555,240), QPoint(725,240), QPoint(897,240),
//                         QPoint(170,251), QPoint(544,251), QPoint(885,251),
//                         QPoint(180,412), QPoint(370,412), QPoint(555,412), QPoint(725,412),
//                         QPoint(360,426), QPoint(713,426), QPoint(370,585)};
//QPointF trilhosLadoB [23] = {QPoint(345,65), QPoint(700,65), QPoint(1006,65),
//                         QPoint(72,229), QPoint(355,229), QPoint(711,229), QPoint(1018,229),
//                         QPoint(161,240), QPoint(345,240), QPoint(535,240), QPoint(700,240), QPoint(875,240), QPoint(1006,239),
//                         QPoint(170,403), QPoint(544,403), QPoint(885,403),
//                         QPoint(345,412), QPoint(535,412), QPoint(700,412), QPoint(875,412),
//                         QPoint(360,575), QPoint(713,575), QPoint(700,585)};

int trilhoAtual[6] = {0, 1, 2, 13, 15, 22};
int direcao[6] = {1, 1, 1, 0, 2, 3};
QSemaphore sem05(1);
QSemaphore sem06(1);
QSemaphore sem09(1);
QSemaphore sem10(1);
QSemaphore sem11(1);
QSemaphore sem12(1);
QSemaphore sem15(1);
QSemaphore sem18(1);
QSemaphore sem19(1);
bool testeSem05;
bool testeSem06;
bool testeSem09;
bool testeSem10;
bool testeSem11;
bool testeSem12;
bool testeSem15;
bool testeSem18;
bool testeSem19;

void trilhos::acceptConnection(){
    client = tcpserver.nextPendingConnection();
    connect(client, SIGNAL(readyRead()), this, SLOT(receber()));
}

void trilhos::receber(){
    ui->statusBar->showMessage("");
    char buffer[1024] = {0};
    client->read(buffer,client->bytesAvailable());
    std::string k = buffer;
    int indice = atoi(k.substr(0,1).c_str());
    int vel = atoi(k.substr(1).c_str());
    k.erase(0,4);
    client->close();
    QString s = "Trem ";
    s.append(QString::number(indice+1));
    s.append(": velocidade = ");
    s.append(QString::number(vel));
    ui->statusBar->showMessage(s);
    velocidades[indice] = vel;
    if (!executando[indice]) startTrain(indice);
    else updateTrain(indice);
}

//void trilhos::addTrain(int i) {
//    pixItens[i] = new PixmapItem(trainPix);
//    //    pixItens[i]->setTransformOriginPoint(trainWheelPos);
//    pixItens[i]->setPos(positions[i]);
//    pixItens[i]->setRotation(rotations[i]);
//    myScene->addItem(pixItens[i]);
//}
void trilhos::addTrain(int i) {
    pixItens[i] = new PixmapItem(trainPix);
    myScene->addItem(pixItens[i]);
}

//void trilhos::animateTrain(int i) {
//    if (velocidades[i] == 0) return;
//    //    anims[i] = new QPropertyAnimation(pixItens[i], "rot");
//    //    anims[i]->setStartValue(270);
//    //    anims[i]->setEndValue(360);
//    //    anims[i]->setDuration(2000);
//    //    anims[i]->start();
//    anims[i] = new QPropertyAnimation(pixItens[i], "pos");
//    qDebug() << pixItens[i]->pos();
//    anims[i]->setStartValue(pixItens[i]->pos());
//    switch(direcao[i]) {
//    case 0:
//        anims[i]->setEndValue(QPointF(pixItens[i]->pos().x(), trilhosLadoA[trilhoAtual[i]].y()+trainWidth));
//        anims[i]->setDuration(1000*(anims[i]->startValue().toPointF().y()-anims[i]->endValue().toPointF().y())/velocidades[i]);
//        break;
//    case 1:
//        anims[i]->setEndValue(QPointF(trilhosLadoB[trilhoAtual[i]].x()-trainWidth, pixItens[i]->pos().y()));
//        anims[i]->setDuration(1000*(anims[i]->endValue().toPointF().x()-anims[i]->startValue().toPointF().x())/velocidades[i]);
//        break;
//    case 2:
//        anims[i]->setEndValue(QPointF(pixItens[i]->pos().x(), trilhosLadoB[trilhoAtual[i]].y()-trainWidth));
//        anims[i]->setDuration(1000*(anims[i]->endValue().toPointF().y()-anims[i]->startValue().toPointF().y())/velocidades[i]);
//        break;
//    case 3:
//        anims[i]->setEndValue(QPointF(trilhosLadoA[trilhoAtual[i]].x()+trainWidth, pixItens[i]->pos().y()));
//        anims[i]->setDuration(1000*(anims[i]->startValue().toPointF().x()-anims[i]->endValue().toPointF().x())/velocidades[i]);
//        break;
//    default:
//        break;
//    }
//    switch(i) {
//    case 0:
//        qDebug() << "oaisdhaosi";
//        connect(anims[i], SIGNAL(finished()), this, SLOT(continueTrain0()));
//        break;
//    case 1:
//        connect(anims[i], SIGNAL(finished()), this, SLOT(continueTrain1()));
//        break;
//    case 2:
//        connect(anims[i], SIGNAL(finished()), this, SLOT(continueTrain2()));
//        break;
//    case 3:
//        connect(anims[i], SIGNAL(finished()), this, SLOT(continueTrain3()));
//        break;
//    case 4:
//        connect(anims[i], SIGNAL(finished()), this, SLOT(continueTrain4()));
//        break;
//    case 5:
//        connect(anims[i], SIGNAL(finished()), this, SLOT(continueTrain5()));
//        break;
//    default:
//        break;
//    }
//    anims[i]->start();
//}
void trilhos::animateTrain(int i) {
    if (velocidades[i] == 0) return;
    anims[i] = new QPropertyAnimation(pixItens[i], "pos");
    switch(direcao[i]) {
        case 0:
            anims[i]->setStartValue(positions[i]);
            anims[i]->setEndValue(trilhosLadoA[trilhoAtual[i]]);
            anims[i]->setDuration(1000*(anims[i]->startValue().toPointF().y()-anims[i]->endValue().toPointF().y())/velocidades[i]);
            break;
        case 1:
            anims[i]->setStartValue(positions[i]);
            anims[i]->setEndValue(trilhosLadoB[trilhoAtual[i]]);
            anims[i]->setDuration(1000*(anims[i]->endValue().toPointF().x()-anims[i]->startValue().toPointF().x())/velocidades[i]);
            break;
        case 2:
            anims[i]->setStartValue(positions[i]);
            anims[i]->setEndValue(trilhosLadoB[trilhoAtual[i]]);
            anims[i]->setDuration(1000*(anims[i]->endValue().toPointF().y()-anims[i]->startValue().toPointF().y())/velocidades[i]);
            break;
        case 3:
            anims[i]->setStartValue(positions[i]);
            anims[i]->setEndValue(trilhosLadoA[trilhoAtual[i]]);
            anims[i]->setDuration(1000*(anims[i]->startValue().toPointF().x()-anims[i]->endValue().toPointF().x())/velocidades[i]);
            break;
        default:
            break;
        }
    switch(i) {
    case 0:
        connect(anims[i], SIGNAL(finished()), this, SLOT(continueTrain0()));
        break;
    case 1:
        connect(anims[i], SIGNAL(finished()), this, SLOT(continueTrain1()));
        break;
    case 2:
        connect(anims[i], SIGNAL(finished()), this, SLOT(continueTrain2()));
        break;
    case 3:
        connect(anims[i], SIGNAL(finished()), this, SLOT(continueTrain3()));
        break;
    case 4:
        connect(anims[i], SIGNAL(finished()), this, SLOT(continueTrain4()));
        break;
    case 5:
        connect(anims[i], SIGNAL(finished()), this, SLOT(continueTrain5()));
        break;
    default:
        break;
    }
    anims[i]->start();
}

void trilhos::updateTrain(int i) {
    //anims[i]->disconnect(SIGNAL(finished), this);
    anims[i]->stop();
    positions[i] = pixItens[i]->pos();
    animateTrain(i);
}

//void trilhos::startTrain(int i) {
//    //trens[i] = new Trem();
//    //trens[i]->configure(this, i);
//    executando[i] = 1;
//    addTrain(i);
//    animateTrain(i);
//    //trens[i]->start();
//}
void trilhos::startTrain(int i) {
    //trens[i] = new Trem();
    //trens[i]->configure(this, i);
    executando[i] = 1;
    addTrain(i);
    animateTrain(i);
    //trens[i]->start();
}

void trilhos::getSem05() {
    testeSem05 = sem05.tryAcquire(1);

}
int t1 [2] = {0,0};
void trilhos::continueTrain0() {
    int i = 0;
    positions[i] = pixItens[i]->pos();
    qDebug() << "trem1 : trilho" << trilhoAtual[i];
    switch(trilhoAtual[i]) {
    case 0:
        //qDebug() << sem05.available();
        if ((sem05.available() < 1)/* && (t1[0] == 0)*/) {
            disconnect(this, SIGNAL(sem05free()), 0, 0);
            connect(this, SIGNAL(sem05free()), this, SLOT(continueTrain0()));
        } else {
            disconnect(this, SIGNAL(sem05free()), 0, 0);
            sem05.acquire(1);
            t1[0] = 1;
            if ((sem09.available() < 1)/* && (t1[1] == 0)*/) {
                disconnect(this, SIGNAL(sem09free()), 0, 0);
                sem05.release(1);
                emit sem05free();
                connect(this, SIGNAL(sem09free()), this, SLOT(continueTrain0()));
            } else {
                disconnect(this, SIGNAL(sem09free()), 0, 0);
                sem09.acquire(1);
                t1[1] = 1;
                ui->statusBar->showMessage("Trem 1 pegou semaforos 5 e 9");
                direcao[i] = 2;
                trilhoAtual[i] = 4;
                animateTrain(i);
            }
        }
        break;
    case 4:
        sem05.release(1);
        emit sem05free();
        t1[0] = 0;
        ui->statusBar->showMessage("Trem 1 devolveu semaforo 5");
        direcao[i] = 3;
        trilhoAtual[i] = 8;
        animateTrain(i);
        break;
    case 8:
        sem09.release(1);
        emit sem09free();
        t1[1] = 0;
        ui->statusBar->showMessage("Trem 1 devolveu semaforo 9");
        trilhoAtual[i] = 7;
        animateTrain(i);
        break;
    case 7:
        direcao[i] = 0;
        trilhoAtual[i] = 3;
        animateTrain(i);
        break;
    case 3:
        direcao[i] = 1;
        trilhoAtual[i] = 0;
        animateTrain(i);
        break;
    default:
        break;
    }
}
int t2 [4] = {0,0,0,0};
void trilhos::continueTrain1() {
    int i = 1;
    qDebug() << "trem2 : trilho" << trilhoAtual[i];
    positions[i] = pixItens[i]->pos();
    switch(trilhoAtual[i]) {
    case 1:
        if ((sem06.available() < 1)/* && (t2[0] == 0)*/) {
            disconnect(this, SIGNAL(sem06free()), 0, 0);
            connect(this, SIGNAL(sem06free()), this, SLOT(continueTrain1()));
        } else {
            disconnect(this, SIGNAL(sem06free()), 0, 0);
            sem06.acquire(1);
            t2[0] = 1;
            ui->statusBar->showMessage("Trem 2 pegou semaforo 6");
            if ((sem11.available() < 1)/* && (t2[1] == 0)*/) {
                disconnect(this, SIGNAL(sem11free()), 0, 0);
                sem06.release(1);
                emit sem06free();
                connect(this, SIGNAL(sem11free()), this, SLOT(continueTrain1()));
            } else {
                disconnect(this, SIGNAL(sem11free()), 0, 0);
                sem11.acquire(1);
                t2[1] = 1;
                ui->statusBar->showMessage("Trem 2 pegou semaforos 6 e 11");
                if ((sem10.available() < 1)/* && (t2[2] == 0)*/) {
                    disconnect(this, SIGNAL(sem10free()), 0, 0);
                    sem06.release(1);
                    emit sem06free();
                    sem11.release(1);
                    emit sem11free();
                    connect(this, SIGNAL(sem10free()), this, SLOT(continueTrain1()));
                } else {
                    disconnect(this, SIGNAL(sem10free()), 0, 0);
                    sem10.acquire(1);
                    t2[2] = 1;
                    ui->statusBar->showMessage("Trem 2 pegou semaforos 6, 11 e 10");
                    if ((sem05.available() < 1)/* && (t2[3] == 0)*/) {
                        disconnect(this, SIGNAL(sem05free()), 0, 0);
                        sem06.release(1);
                        emit sem06free();
                        sem11.release(1);
                        emit sem11free();
                        sem10.release(1);
                        emit sem10free();
                        connect(this, SIGNAL(sem05free()), this, SLOT(continueTrain1()));
                    } else {
                        disconnect(this, SIGNAL(sem05free()), 0, 0);
                        sem05.acquire(1);
                        t2[3] = 1;
                        ui->statusBar->showMessage("Trem 2 pegou semaforos 6, 11, 10 e 5");
                        trilhoAtual[i] = 5;
                        direcao[i] = 2;
                        animateTrain(i);
                    }
                }
            }
        }
        break;
    case 5:
        sem06.release(1);
        emit sem06free();
        t2[0] = 0;
        ui->statusBar->showMessage("Trem 2 devolveu semaforo 6");
        direcao[i] = 3;
        trilhoAtual[i] = 10;
        animateTrain(i);
        break;
    case 10:
        sem11.release(1);
        emit sem11free();
        t2[1] = 0;
        ui->statusBar->showMessage("Trem 2 devolveu semaforo 11");
        trilhoAtual[i] = 9;
        animateTrain(i);
        break;
    case 9:
        sem10.release(1);
        emit sem10free();
        t2[2] = 0;
        ui->statusBar->showMessage("Trem 2 devolveu semaforo 10");
        direcao[i] = 0;
        trilhoAtual[i] = 4;
        animateTrain(i);
        break;
    case 4:
        sem05.release(1);
        emit sem05free();
        t2[0] = 0;
        ui->statusBar->showMessage("Trem 2 devolveu semaforo 5");
        direcao[i] = 1;
        trilhoAtual[i] = 1;
        animateTrain(i);
        break;
    }
}
int t3 [2] = {0,0};
void trilhos::continueTrain2() {
    int i = 2;
    qDebug() << "trem3 : trilho" << trilhoAtual[i];
    positions[i] = pixItens[i]->pos();
    switch(trilhoAtual[i]) {
    case 2:
        direcao[i] = 2;
        trilhoAtual[i] = 6;
        animateTrain(i);
        break;

    case 6:
        direcao[i] = 3;
        trilhoAtual[i] = 12;
        animateTrain(i);
        break;

    case 12:
        if ((sem12.available() < 1)/* && (t3[0] == 0)*/) {
            disconnect(this, SIGNAL(sem12free()), 0, 0);
            connect(this, SIGNAL(sem12free()), this, SLOT(continueTrain2()));
        } else {
            disconnect(this, SIGNAL(sem12free()), 0, 0);
            sem12.acquire(1);
            t3[0] = 1;
            if ((sem06.available() < 1)/* && (t3[1] == 0)*/) {
                disconnect(this, SIGNAL(sem06free()), 0, 0);
                sem12.release(1);
                emit sem12free();
                connect(this, SIGNAL(sem06free()), this, SLOT(continueTrain2()));
            } else {
                disconnect(this, SIGNAL(sem06free()), 0, 0);
                sem06.acquire(1);
                t3[1] = 1;
                ui->statusBar->showMessage("Trem 3 pegou semaforos 12 e 6");
                trilhoAtual[i] = 11;
                animateTrain(i);
            }
        }
        break;

    case 11:
        sem12.release(1);
        emit sem12free();
        t3[1] = 0;
        ui->statusBar->showMessage("Trem 3 devolveu semaforo 12");
        trilhoAtual[i] = 5;
        direcao[i] = 0;
        animateTrain(i);
        break;
    case 5:
        sem06.release(1);
        emit sem06free();
        t3[2] = 0;
        ui->statusBar->showMessage("Trem 3 devolveu semaforo 6");
        trilhoAtual[i] = 2;
        direcao[i] = 1;
        animateTrain(i);
        break;
    default:
        break;
    }
}
int t4 [4] = {0,0,0,0};
void trilhos::continueTrain3() {
    int i = 3;
    qDebug() << "trem4 : trilho" << trilhoAtual[i];
    positions[i] = pixItens[i]->pos();
    switch(trilhoAtual[i]) {
    case 13:
        if ((sem09.available() < 1)/* && (t4[0] == 0)*/) {
            disconnect(this, SIGNAL(sem09free()), 0, 0);
            connect(this, SIGNAL(sem09free()), this, SLOT(continueTrain3()));
        } else {
            disconnect(this, SIGNAL(sem09free()), 0, 0);
            sem09.acquire(1);
            t4[0] = 1;
            ui->statusBar->showMessage("Trem 4 pegou semaforo 9");
            if ((sem10.available() < 1)/* && (t4[1] == 0)*/) {
                sem09.release(1);
                emit sem09free();
                disconnect(this, SIGNAL(sem10free()), 0, 0);
                connect(this, SIGNAL(sem10free()), this, SLOT(continueTrain3()));
            } else {
                disconnect(this, SIGNAL(sem10free()), 0, 0);
                sem10.acquire(1);
                t4[1] = 1;
                ui->statusBar->showMessage("Trem 4 pegou semaforos 9 e 10");
                if ((sem15.available() < 1)/* && (t4[2] == 0)*/) {
                    disconnect(this, SIGNAL(sem15free()), 0, 0);
                    sem09.release(1);
                    emit sem09free();
                    sem10.release(1);
                    emit sem10free();
                    connect(this, SIGNAL(sem15free()), this, SLOT(continueTrain3()));
                } else {
                    disconnect(this, SIGNAL(sem15free()), 0, 0);
                    sem15.acquire(1);
                    t4[2] = 1;
                    ui->statusBar->showMessage("Trem 4 pegou semaforos 9, 10 e 15");
                    if ((sem18.available() < 1) /*&& (t4[3] == 0)*/) {
                        disconnect(this, SIGNAL(sem18free()), 0, 0);
                        sem09.release(1);
                        emit sem09free();
                        sem10.release(1);
                        emit sem10free();
                        sem15.release(1);
                        emit sem15free();
                        connect(this, SIGNAL(sem18free()), this, SLOT(continueTrain3()));
                    } else {
                        disconnect(this, SIGNAL(sem18free()), 0, 0);
                        sem18.acquire(1);
                        t4[3] = 1;
                        ui->statusBar->showMessage("Trem 4 pegou semaforos 9, 10, 15 e 18");
                        trilhoAtual[i] = 8;
                        direcao[i] = 1;
                        animateTrain(i);
                    }
                }
            }
        }
        break;

    case 8:
        sem09.release(1);
        emit sem09free();
        ui->statusBar->showMessage("Trem 4 devolveu semaforo 9");
        t4[0] = 0;
        trilhoAtual[i] = 9;
        animateTrain(i);
        break;

    case 9:
        sem10.release(1);
        emit sem10free();
        ui->statusBar->showMessage("Trem 4 devolveu semaforo 10");
        t4[1] = 0;
        trilhoAtual[i] = 14;
        direcao[i] = 2;
        animateTrain(i);
        break;

    case 14:
        sem15.release(1);
        emit sem15free();
        t4[2] = 0;
        ui->statusBar->showMessage("Trem 4 devolveu semaforo 15");
        trilhoAtual[i] = 17;
        direcao[i] = 3;
        animateTrain(i);
        break;
    case 17:
        sem18.release(1);
        emit sem18free();
        t4[3] = 0;
        ui->statusBar->showMessage("Trem 4 devolveu semaforo 6");
        trilhoAtual[i] = 16;
        animateTrain(i);
        break;
    case 16:
        direcao[i] = 0;
        trilhoAtual[i] = 13;
        animateTrain(i);
        break;
    default:
        break;
    }
}
int t5 [4] = {0,0,0,0};
void trilhos::continueTrain4() {
    int i = 4;
    qDebug() << "trem5 : trilho" << trilhoAtual[i];
    positions[i] = pixItens[i]->pos();
    switch(trilhoAtual[i]) {
    case 15:
        direcao[i] = 3;
        trilhoAtual[i] = 19;
        animateTrain(i);
        break;
    case 19:
        if ((sem19.available() < 1)/* && (t5[0] == 0)*/) {
            disconnect(this, SIGNAL(sem19free()), 0, 0);
            connect(this, SIGNAL(sem19free()), this, SLOT(continueTrain4()));
        } else {
            disconnect(this, SIGNAL(sem19free()), 0, 0);
            sem19.acquire(1);
            t5[0] = 1;
            ui->statusBar->showMessage("Trem 5 pegou semaforo 19");
            if ((sem15.available() < 1)/* && (t5[1] == 0)*/) {
                disconnect(this, SIGNAL(sem15free()), 0, 0);
                sem19.release(1);
                emit sem19free();
                connect(this, SIGNAL(sem15free()), this, SLOT(continueTrain4()));
            } else {
                disconnect(this, SIGNAL(sem15free()), 0, 0);
                sem15.acquire(1);
                t5[1] = 1;
                ui->statusBar->showMessage("Trem 5 pegou semaforos 19 e 15");
                if ((sem11.available() < 1)/* && (t5[2] == 0)*/) {
                    disconnect(this, SIGNAL(sem11free()), 0, 0);
                    sem19.release(1);
                    emit sem19free();
                    sem15.release(1);
                    emit sem15free();
                    connect(this, SIGNAL(sem11free()), this, SLOT(continueTrain4()));
                } else {
                    disconnect(this, SIGNAL(sem11free()), 0, 0);
                    sem11.acquire(1);
                    t5[2] = 1;
                    ui->statusBar->showMessage("Trem 5 pegou semaforos 19, 15 e 11");
                    if ((sem12.available() < 1)/* && (t5[3] == 0)*/) {
                        disconnect(this, SIGNAL(sem12free()), 0, 0);
                        sem19.release(1);
                        emit sem19free();
                        sem15.release(1);
                        emit sem15free();
                        sem11.release(1);
                        emit sem11free();
                        connect(this, SIGNAL(sem12free()), this, SLOT(continueTrain4()));
                    } else {
                        disconnect(this, SIGNAL(sem12free()), 0, 0);
                        sem12.acquire(1);
                        t5[3] = 1;
                        ui->statusBar->showMessage("Trem 5 pegou semaforos 19, 15, 11 e 12");
                        trilhoAtual[i] = 18;
                        animateTrain(i);
                    }
                }
            }
        }
        break;

    case 18:
        sem19.release(1);
        emit sem19free();
        ui->statusBar->showMessage("Trem 5 devolveu semaforo 19");
        t5[0] = 0;
        direcao[i] = 0;
        trilhoAtual[i] = 14;
        animateTrain(i);
        break;

    case 14:
        sem15.release(1);
        emit sem15free();
        ui->statusBar->showMessage("Trem 5 devolveu semaforo 15");
        t5[1] = 0;
        trilhoAtual[i] = 10;
        direcao[i] = 1;
        animateTrain(i);
        break;

    case 10:
        sem11.release(1);
        emit sem11free();
        t5[2] = 0;
        ui->statusBar->showMessage("Trem 5 devolveu semaforo 11");
        trilhoAtual[i] = 11;
        animateTrain(i);
        break;
    case 11:
        sem12.release(1);
        emit sem12free();
        t5[3] = 0;
        ui->statusBar->showMessage("Trem 5 devolveu semaforo 12");
        trilhoAtual[i] = 15;
        direcao[i] = 2;
        animateTrain(i);
        break;
    default:
        break;
    }
}
int t6 [2] = {0,0};
void trilhos::continueTrain5() {
    int i = 5;
    qDebug() << "trem6 : trilho" << trilhoAtual[i];
    positions[i] = pixItens[i]->pos();
    switch(trilhoAtual[i]) {
    case 22:
        direcao[i] = 0;
        trilhoAtual[i] = 20;
        animateTrain(i);
        break;
    case 20:
        if ((sem18.available() < 1)/* && (t6[0] == 0)*/) {
            disconnect(this, SIGNAL(sem18free()), 0, 0);
            connect(this, SIGNAL(sem18free()), this, SLOT(continueTrain5()));
        } else {
            disconnect(this, SIGNAL(sem18free()), 0, 0);
            sem18.acquire(1);
            t6[0] = 1;
            if ((sem19.available() < 1)/* && (t6[1] == 0)*/) {
                disconnect(this, SIGNAL(sem19free()), 0, 0);
                sem18.release(1);
                emit sem18free();
                connect(this, SIGNAL(sem19free()), this, SLOT(continueTrain5()));
            } else {
                disconnect(this, SIGNAL(sem19free()), 0, 0);
                sem19.acquire(1);
                t6[1] = 1;
                ui->statusBar->showMessage("Trem 6 pegou semaforos 18 e 19");
                direcao[i] = 1;
                trilhoAtual[i] = 17;
                animateTrain(i);
            }
        }
        break;
    case 17:
        sem18.release(1);
        emit sem18free();
        t1[0] = 0;
        ui->statusBar->showMessage("Trem 6 devolveu semaforo 18");
        trilhoAtual[i] = 18;
        animateTrain(i);
        break;
    case 18:
        sem19.release(1);
        emit sem19free();
        t6[1] = 0;
        ui->statusBar->showMessage("Trem 6 devolveu semaforo 19");
        trilhoAtual[i] = 21;
        direcao[i] = 2;
        animateTrain(i);
        break;
    case 21:
        direcao[i] = 3;
        trilhoAtual[i] = 22;
        animateTrain(i);
        break;
    default:
        break;
    }
}
//void trilhos::continueTrain0() {
//    qDebug() << "uuuuuu";
//    int i = 0;
//    anims[i] = new QPropertyAnimation(pixItens[i],"pos");
//    anims[i]->setStartValue(pixItens[i]->pos());
//    positions[i] = pixItens[i]->pos();
//    switch(trilhoAtual[i]) {
//    case 0:
//        qDebug() << "1";
//        sem05.acquire(1);
//        ui->statusBar->showMessage("Trem 1 pegou semaforo 5");
//        sem09.acquire(1);
//        ui->statusBar->showMessage("Trem 1 pegou semaforo 5");
//        anims[i]->setEndValue(QPointF(pixItens[i]->pos().x()+trainWidth, pixItens[i]->pos().y()));
//        anims[i]->setDuration(1000*(anims[i]->endValue().toPointF().x()-anims[i]->startValue().toPointF().x())/velocidades[i]);
//        connect(anims[i],SIGNAL(finished()), this, SLOT(turnTrain0()));
//        direcao[i] = 2;
//        trilhoAtual[i] = 5;
//        anims[i]->start();
//        break;
//    case 4:
//        sem05.release(1);
//        ui->statusBar->showMessage("Trem 1 devolveu semaforo 5");
//        anims[i]->setEndValue(QPointF(pixItens[i]->pos().x(), pixItens[i]->pos().y()+trainWidth));
//        anims[i]->setDuration(1000*(anims[i]->endValue().toPointF().y()-anims[i]->startValue().toPointF().y())/velocidades[i]);
//        connect(anims[i],SIGNAL(finished()), this, SLOT(turnTrain0()));
//        rotations[i] = 180;
//        direcao[i] = 3;
//        trilhoAtual[i] = 9;
//        anims[i]->start();
//        break;
//    case 8:
//        sem09.release(1);
//        ui->statusBar->showMessage("Trem 1 devolveu semaforo 5");
//        trilhoAtual[i] = 8;
//        positions[i] = pixItens[i]->pos();
//        animateTrain(0);
//    case 7:
//        anims[i]->setEndValue(QPointF(pixItens[i]->pos().x()-trainWidth, pixItens[i]->pos().y()));
//        anims[i]->setDuration(1000*(anims[i]->startValue().toPointF().x()-anims[i]->endValue().toPointF().x())/velocidades[i]);
//        connect(anims[i],SIGNAL(finished()), this, SLOT(turnTrain0()));
//        rotations[i] = 270;
//        direcao[i] = 0;
//        trilhoAtual[i] = 4;
//        anims[i]->start();
//        break;
//    case 3:
//        anims[i]->setEndValue(QPointF(pixItens[i]->pos().x(), pixItens[i]->pos().y()-trainWidth));
//        anims[i]->setDuration(1000*(anims[i]->startValue().toPointF().y()-anims[i]->endValue().toPointF().y())/velocidades[i]);
//        connect(anims[i],SIGNAL(finished()), this, SLOT(turnTrain0()));
//        rotations[i] = 0;
//        direcao[i] = 1;
//        trilhoAtual[i] = 1;
//        anims[i]->start();
//        break;
//    }
//}
//void trilhos::turnTrain0() {
//    qDebug() << "2";
//    int i = 0;
//    positions[i] = pixItens[i]->pos();
//    pixItens[i]->setTransformOriginPoint(trainWheelPos);
//    anims[i] = new QPropertyAnimation(pixItens[i], "rot");
//    anims[i]->setStartValue(rotations[i]);
//    anims[i]->setEndValue(rotations[i]+90);
//    anims[i]->setDuration(1000*90/velocidades[i]);
//    connect(anims[i], SIGNAL(finished()), this, SLOT(turn2Train0()));
//    rotations[i] = rotations[i]+90;
//    if (rotations[i] == 360) rotations[i] = 0;
//    anims[i]->start();
//}
//void trilhos::turn2Train0() {
//    int i = 0;
//    //QPointF tempPos = pixItens[i]->pos();
//    int xc = 0;
//    int yc = 0;
//    if (rotations[i] == 90) xc = trainWidth;
//    if (rotations[i] == 180) {xc = trainWidth; yc = trainHeight;}
//    if (rotations[i] == 90) xc = trainWidth;
//    pixItens[i]->setTransformOriginPoint(xc,yc);
//    //pixItens[i]->setPos(tempPos.x()+15, tempPos.y()+42);
//    positions[i] = pixItens[i]->pos();
//    qDebug() << pixItens[i]->pos();
//    animateTrain(0);
//}


//void trilhos::continueTrain1() {
//    //    switch(trilhoAtual[1]) {
//    //    case 1:

//    //    }
//}
//void trilhos::continueTrain2() {
//    //    switch(trilhoAtual[2]) {
//    //    case 1:

//    //    }
//}
//void trilhos::continueTrain3() {
//    //    switch(trilhoAtual[3]) {
//    //    case 1:

//    //    }
//}
//void trilhos::continueTrain4() {
//    //    switch(trilhoAtual[4]) {
//    //    case 1:

//    //    }
//}
//void trilhos::continueTrain5() {
////    switch(trilhoAtual[5]) {
////    case 1:

////    }
//}

void trilhos::mousePressEvent(QMouseEvent *evt) {
    qDebug() << evt->pos();
}


trilhos::~trilhos()
{
    delete ui;
}
