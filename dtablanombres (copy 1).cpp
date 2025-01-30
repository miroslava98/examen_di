#include "dtablanombres.h"
#include <QDebug>

DTablaNombres::DTablaNombres(QVector<Bola*>* pBolas, QWidget *parent): QDialog(parent){
		setupUi(this);
		
  ModeloTablaNombres * modelo = new ModeloTablaNombres(pBolas);
  vista -> setModel(modelo);
	
}


void DTablaNombres::slotEjemplo(){

}

ModeloTablaNombres::ModeloTablaNombres(QVector<Bola * > * bolasPasadas, QObject *parent ) : QAbstractTableModel(parent) {

	pBolas = bolasPasadas;

}


int ModeloTablaNombres::columnCount(const QModelIndex &parent ) const{
    return 4;
}

int ModeloTablaNombres::rowCount(const QModelIndex &parent ) const {
	return pBolas->length();

}

QVariant ModeloTablaNombres::data(const QModelIndex &index, int role ) const {

	 if ( role != Qt::DisplayRole ) return QVariant();

    int fila = index.row();
    int columna = index.column();
    Bola * bola = pBolas->at(fila);

    QString resultado;
    switch (columna) {
   	 case 0:
   		  resultado = bola->nombre;
   		  break;
   	 case 1:
   		  resultado = bola->nombreCompleto.at(1);
   		  break;
   	 case 2:
   		  resultado = bola->nombreCompleto.at(2);
   		  break;
   		  
   	 case 3: 
   	 	//Violación de segmento 
   	 	//qDebug()<< "HAY 3ER APELLIDO "<< bola->nombreCompleto.at(3);	  
		break;
   		  
    };
    return QVariant(resultado);

}

Qt::ItemFlags ModeloTablaNombres::flags(const QModelIndex &index) const
{
	if (index.column() <= 1 ) 
	    return Qt::ItemIsEditable | QAbstractTableModel::flags(index) ;

	return QAbstractTableModel::flags(index);
}

bool ModeloTablaNombres::setData(const QModelIndex &index, const QVariant &value, int role ){

	QVariant dato;
	int fila = index.row();
	Bola * bola = pBolas->at(fila);
	dato = value.toString();

	int columna = index.column();

	switch( columna){
		case 0: 
			bola->nombre;
			break;
		case 1: //
			bola->nombreCompleto.at(0);
			break;
		default:
			qDebug() << "Tratando de establecer un dato inválido en bola " << fila;
	}

	return true;
}

  QVariant ModeloTablaNombres::headerData(int section, Qt::Orientation orientation, int role ) const {
  		
  		if (role == Qt::BackgroundColorRole && orientation == Qt::Vertical)
  			return pBolas->at(section)->color;
  	
  		if (role != Qt::DisplayRole ) 
			return QVariant() ;

		QStringList lista = {"Nombre", "Apellido1", "Apellido2", "Apellido3"};			
		
		if (orientation == Qt::Horizontal) 
			 return lista[section];
		
		if (orientation == Qt::Vertical) {
			return pBolas->at(section)->nombre;
		}	
  
  
  }


