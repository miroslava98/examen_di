
#ifndef DTABLANOMBRES_H
#define DTABLANOMBRES_H
#include "ui_dtablanombres.h"
#include "bola.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>
#include <QAbstractTableModel>
#include <QModelIndex>
#include <QVariant>

class DTablaNombres : public QDialog, public Ui::DTablaNombres {
Q_OBJECT

public:
	DTablaNombres(QVector<Bola*>*, QWidget *parent = NULL);

public slots:
	void slotEjemplo();

};

class ModeloTablaNombres : public QAbstractTableModel {
Q_OBJECT

public:

	QVector<Bola * > * pBolas; 

	ModeloTablaNombres(QVector<Bola * > * pBolasPasadas, QObject *parent = nullptr);
	
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	int rowCount(const QModelIndex &parent = QModelIndex()) const ;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const ;
        Qt::ItemFlags flags(const QModelIndex &index) const ;

	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

	
        QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;


public slots:


};

#endif 
