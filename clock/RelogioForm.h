/* 
 * File:   RelogioForm.h
 * Author: diogo
 *
 * Created on 22 de Setembro de 2010, 22:24
 */

#ifndef _RELOGIOFORM_H
#define	_RELOGIOFORM_H

#include "ui_RelogioForm.h"
#include <QTimer>


class RelogioForm : public QDialog {
    Q_OBJECT
public:
    RelogioForm();
    virtual ~RelogioForm();
public slots:
    void rodar();
    
private:
    Ui::RelogioForm widget;
    QTimer *timer;
};

#endif	/* _RELOGIOFORM_H */
