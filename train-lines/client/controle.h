#ifndef CONTROLE_H
#define CONTROLE_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>

namespace Ui {
    class Controle;
}

struct Trem{
    int trem;
    int valor;
};


class Controle : public QMainWindow
{
    Q_OBJECT

public:
    Controle(QWidget *parent = 0);
    ~Controle();
public slots:
    void trem1();
    void trem1Ativar();
    void trem2();
    void trem2Ativar();
    void trem3();
    void trem3Ativar();
    void trem4();
    void trem4Ativar();
    void trem5();
    void trem5Ativar();
    void trem6();
    void trem6Ativar();
    void mandar();
private:
    Ui::Controle *ui;

};

#endif // CONTROLE_H
