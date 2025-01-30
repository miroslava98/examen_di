
#ifndef DNOMBREBOLA_H
#define DNOMBREBOLA_H
#include "ui_dnombrebola.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>

class DNombreBola : public QDialog, public Ui::DNombreBola {
Q_OBJECT

public:
	DNombreBola(QWidget *parent = NULL);

public slots:
	void slotEjemplo();

};

#endif 
