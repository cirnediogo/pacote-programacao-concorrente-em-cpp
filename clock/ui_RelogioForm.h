/********************************************************************************
** Form generated from reading ui file 'RelogioForm.ui'
**
** Created: Thu Sep 23 09:45:35 2010
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_RELOGIOFORM_H
#define UI_RELOGIOFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>

QT_BEGIN_NAMESPACE

class Ui_RelogioForm
{
public:
    QLCDNumber *lcdNumber_hora;
    QLCDNumber *lcdNumber_min;
    QLCDNumber *lcdNumber_seg;

    void setupUi(QDialog *RelogioForm)
    {
        if (RelogioForm->objectName().isEmpty())
            RelogioForm->setObjectName(QString::fromUtf8("RelogioForm"));
        RelogioForm->resize(266, 90);
        lcdNumber_hora = new QLCDNumber(RelogioForm);
        lcdNumber_hora->setObjectName(QString::fromUtf8("lcdNumber_hora"));
        lcdNumber_hora->setGeometry(QRect(20, 20, 64, 51));
        lcdNumber_hora->setMidLineWidth(2);
        lcdNumber_hora->setNumDigits(2);
        lcdNumber_hora->setProperty("digitCount", QVariant(2));
        lcdNumber_min = new QLCDNumber(RelogioForm);
        lcdNumber_min->setObjectName(QString::fromUtf8("lcdNumber_min"));
        lcdNumber_min->setGeometry(QRect(100, 20, 64, 51));
        lcdNumber_min->setAutoFillBackground(false);
        lcdNumber_min->setFrameShape(QFrame::Box);
        lcdNumber_min->setFrameShadow(QFrame::Raised);
        lcdNumber_min->setLineWidth(1);
        lcdNumber_min->setMidLineWidth(2);
        lcdNumber_min->setSmallDecimalPoint(false);
        lcdNumber_min->setNumDigits(2);
        lcdNumber_seg = new QLCDNumber(RelogioForm);
        lcdNumber_seg->setObjectName(QString::fromUtf8("lcdNumber_seg"));
        lcdNumber_seg->setGeometry(QRect(180, 20, 64, 51));
        lcdNumber_seg->setMouseTracking(false);
        lcdNumber_seg->setMidLineWidth(2);
        lcdNumber_seg->setNumDigits(2);

        retranslateUi(RelogioForm);

        QMetaObject::connectSlotsByName(RelogioForm);
    } // setupUi

    void retranslateUi(QDialog *RelogioForm)
    {
        RelogioForm->setWindowTitle(QApplication::translate("RelogioForm", "RelogioForm", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(RelogioForm);
    } // retranslateUi

};

namespace Ui {
    class RelogioForm: public Ui_RelogioForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RELOGIOFORM_H
