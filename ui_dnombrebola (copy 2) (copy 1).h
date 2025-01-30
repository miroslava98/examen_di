/********************************************************************************
** Form generated from reading UI file 'dnombrebola.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DNOMBREBOLA_H
#define UI_DNOMBREBOLA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_DNombreBola
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineENombre;
    QLineEdit *lineEditApe1;
    QLineEdit *lineEditApe2;
    QLineEdit *lineEditApe3;
    QLabel *nombre;
    QLabel *apellido1;
    QLabel *apellido2;
    QLabel *apellido3;

    void setupUi(QDialog *DNombreBola)
    {
        if (DNombreBola->objectName().isEmpty())
            DNombreBola->setObjectName(QString::fromUtf8("DNombreBola"));
        DNombreBola->resize(400, 300);
        buttonBox = new QDialogButtonBox(DNombreBola);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineENombre = new QLineEdit(DNombreBola);
        lineENombre->setObjectName(QString::fromUtf8("lineENombre"));
        lineENombre->setGeometry(QRect(140, 30, 113, 25));
        lineEditApe1 = new QLineEdit(DNombreBola);
        lineEditApe1->setObjectName(QString::fromUtf8("lineEditApe1"));
        lineEditApe1->setGeometry(QRect(140, 80, 113, 25));
        lineEditApe2 = new QLineEdit(DNombreBola);
        lineEditApe2->setObjectName(QString::fromUtf8("lineEditApe2"));
        lineEditApe2->setGeometry(QRect(140, 130, 113, 25));
        lineEditApe3 = new QLineEdit(DNombreBola);
        lineEditApe3->setObjectName(QString::fromUtf8("lineEditApe3"));
        lineEditApe3->setGeometry(QRect(140, 180, 113, 25));
        nombre = new QLabel(DNombreBola);
        nombre->setObjectName(QString::fromUtf8("nombre"));
        nombre->setGeometry(QRect(20, 30, 54, 17));
        apellido1 = new QLabel(DNombreBola);
        apellido1->setObjectName(QString::fromUtf8("apellido1"));
        apellido1->setGeometry(QRect(20, 90, 54, 17));
        apellido2 = new QLabel(DNombreBola);
        apellido2->setObjectName(QString::fromUtf8("apellido2"));
        apellido2->setGeometry(QRect(20, 140, 54, 17));
        apellido3 = new QLabel(DNombreBola);
        apellido3->setObjectName(QString::fromUtf8("apellido3"));
        apellido3->setGeometry(QRect(20, 190, 54, 17));

        retranslateUi(DNombreBola);
        QObject::connect(buttonBox, SIGNAL(accepted()), DNombreBola, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DNombreBola, SLOT(reject()));

        QMetaObject::connectSlotsByName(DNombreBola);
    } // setupUi

    void retranslateUi(QDialog *DNombreBola)
    {
        DNombreBola->setWindowTitle(QCoreApplication::translate("DNombreBola", "Dialog", nullptr));
        nombre->setText(QCoreApplication::translate("DNombreBola", "Nombre", nullptr));
        apellido1->setText(QCoreApplication::translate("DNombreBola", "Apellido1", nullptr));
        apellido2->setText(QCoreApplication::translate("DNombreBola", "Apellido2", nullptr));
        apellido3->setText(QCoreApplication::translate("DNombreBola", "Apellido3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DNombreBola: public Ui_DNombreBola {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DNOMBREBOLA_H
