/* 
 * File:   TempoDeVidaForm.h
 * Author: diogo
 *
 * Created on 22 de Setembro de 2010, 17:17
 */

#ifndef _TEMPODEVIDAFORM_H
#define	_TEMPODEVIDAFORM_H

#include "ui_TempoDeVidaForm.h"

class TempoDeVidaForm : public QDialog {
    Q_OBJECT
public:
    TempoDeVidaForm();
    virtual ~TempoDeVidaForm();
public slots:
    void calcular();

private:
    Ui::TempoDeVidaForm widget;
};

#endif	/* _TEMPODEVIDAFORM_H */
