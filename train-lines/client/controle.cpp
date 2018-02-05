#include "controle.h"
#include "ui_controle.h"
#include <iostream>

QString valor;
using namespace std;
QTcpSocket tcpsocket;
bool andando1 = false;
bool andando2 = false;
bool andando3 = false;
bool andando4 = false;
bool andando5 = false;
bool andando6 = false;
QString ipstr = "10.13.100.157";
int portstr = 6749;
Controle::Controle(QWidget *parent) :
        QMainWindow(parent),

        ui(new Ui::Controle)
{
    ui->setupUi(this);
    ui->lineEdit->setText(ipstr);
    ui->lineEdit_2->setText(QString::number(portstr));
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(trem1()));
    connect(ui->horizontalSlider_2,SIGNAL(valueChanged(int)),this,SLOT(trem2()));
    connect(ui->horizontalSlider_3,SIGNAL(valueChanged(int)),this,SLOT(trem3()));
    connect(ui->horizontalSlider_4,SIGNAL(valueChanged(int)),this,SLOT(trem4()));
    connect(ui->horizontalSlider_5,SIGNAL(valueChanged(int)),this,SLOT(trem5()));
    connect(ui->horizontalSlider_6,SIGNAL(valueChanged(int)),this,SLOT(trem6()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(trem1Ativar()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(trem2Ativar()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(trem3Ativar()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(trem4Ativar()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(trem5Ativar()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(trem6Ativar()));
}

Controle::~Controle()
{
    delete ui;
}

void Controle::trem1(){
    if (andando1){
        connect(&tcpsocket, SIGNAL(connected()), this, SLOT(mandar()));
        tcpsocket.connectToHost(ui->lineEdit->text(), ui->lineEdit_2->text().toInt());
        QString x = "0";
        x += QString::number(ui->horizontalSlider->value());
        valor = x;
    }
}

void Controle::trem2(){
    if (andando2){
        connect(&tcpsocket, SIGNAL(connected()), this, SLOT(mandar()));
        tcpsocket.connectToHost(ui->lineEdit->text(), ui->lineEdit_2->text().toInt());
        QString x = "1";
        x += QString::number(ui->horizontalSlider_2->value());
        valor = x;
    }
}

void Controle::trem3(){
    if (andando3){
        connect(&tcpsocket, SIGNAL(connected()), this, SLOT(mandar()));
        tcpsocket.connectToHost(ui->lineEdit->text(), ui->lineEdit_2->text().toInt());
        QString x = "2";
        x += QString::number(ui->horizontalSlider_3->value());
        valor = x;
    }
}

void Controle::trem4(){
    if (andando4){
        connect(&tcpsocket, SIGNAL(connected()), this, SLOT(mandar()));
        tcpsocket.connectToHost(ui->lineEdit->text(), ui->lineEdit_2->text().toInt());
        QString x = "3";
        x += QString::number(ui->horizontalSlider_4->value());
        valor = x;
    }
}

void Controle::trem5(){
    if (andando5){
        connect(&tcpsocket, SIGNAL(connected()), this, SLOT(mandar()));
        tcpsocket.connectToHost(ui->lineEdit->text(), ui->lineEdit_2->text().toInt());
        QString x = "4";
        x += QString::number(ui->horizontalSlider_5->value());
        valor = x;
    }
}

void Controle::trem6(){
    if (andando6){
        connect(&tcpsocket, SIGNAL(connected()), this, SLOT(mandar()));
        tcpsocket.connectToHost(ui->lineEdit->text(), ui->lineEdit_2->text().toInt());
        QString x = "5";
        x += QString::number(ui->horizontalSlider_6->value());
        valor = x;
    }
}

void Controle::mandar(){
    tcpsocket.write(valor.toStdString().c_str());
    tcpsocket.close();
}

void Controle::trem1Ativar(){
    andando1 = true;
    ui->pushButton->setEnabled(false);
    trem1();
}

void Controle::trem2Ativar(){
    andando2 = true;
    ui->pushButton_2->setEnabled(false);
    trem2();
}

void Controle::trem3Ativar(){
    andando3 = true;
    ui->pushButton_3->setEnabled(false);
    trem3();
}

void Controle::trem4Ativar(){
    andando4 = true;
    ui->pushButton_4->setEnabled(false);
    trem4();
}

void Controle::trem5Ativar(){
    andando5 = true;
    ui->pushButton_5->setEnabled(false);
    trem5();
}

void Controle::trem6Ativar(){
   andando6 = true;
   ui->pushButton_6->setEnabled(false);
   trem6();
}
