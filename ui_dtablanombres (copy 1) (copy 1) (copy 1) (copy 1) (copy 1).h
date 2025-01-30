/********************************************************************************
** Form generated from reading UI file 'dtablanombres.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DTABLANOMBRES_H
#define UI_DTABLANOMBRES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_DTablaNombres
{
public:
    QDialogButtonBox *buttonBox;
    QTableView *vista;

    void setupUi(QDialog *DTablaNombres)
    {
        if (DTablaNombres->objectName().isEmpty())
            DTablaNombres->setObjectName(QString::fromUtf8("DTablaNombres"));
        DTablaNombres->resize(797, 625);
        buttonBox = new QDialogButtonBox(DTablaNombres);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(420, 570, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        vista = new QTableView(DTablaNombres);
        vista->setObjectName(QString::fromUtf8("vista"));
        vista->setGeometry(QRect(5, 21, 661, 531));

        retranslateUi(DTablaNombres);
        QObject::connect(buttonBox, SIGNAL(accepted()), DTablaNombres, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DTablaNombres, SLOT(reject()));

        QMetaObject::connectSlotsByName(DTablaNombres);
    } // setupUi

    void retranslateUi(QDialog *DTablaNombres)
    {
        DTablaNombres->setWindowTitle(QCoreApplication::translate("DTablaNombres", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DTablaNombres: public Ui_DTablaNombres {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DTABLANOMBRES_H
