/********************************************************************************
** Form generated from reading ui file 'TempoDeVidaForm.ui'
**
** Created: Thu Sep 23 09:39:04 2010
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_TEMPODEVIDAFORM_H
#define UI_TEMPODEVIDAFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TempoDeVidaForm
{
public:
    QDateEdit *dateEdit;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *TempoDeVidaForm)
    {
        if (TempoDeVidaForm->objectName().isEmpty())
            TempoDeVidaForm->setObjectName(QString::fromUtf8("TempoDeVidaForm"));
        TempoDeVidaForm->resize(400, 171);
        dateEdit = new QDateEdit(TempoDeVidaForm);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(60, 50, 121, 28));
        pushButton = new QPushButton(TempoDeVidaForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(220, 50, 92, 28));
        label = new QLabel(TempoDeVidaForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 99, 251, 41));

        retranslateUi(TempoDeVidaForm);

        QMetaObject::connectSlotsByName(TempoDeVidaForm);
    } // setupUi

    void retranslateUi(QDialog *TempoDeVidaForm)
    {
        TempoDeVidaForm->setWindowTitle(QApplication::translate("TempoDeVidaForm", "TempoDeVidaForm", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("TempoDeVidaForm", "OK", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        Q_UNUSED(TempoDeVidaForm);
    } // retranslateUi

};

namespace Ui {
    class TempoDeVidaForm: public Ui_TempoDeVidaForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPODEVIDAFORM_H
