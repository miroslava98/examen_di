
#include "dposicionbolas.h"
#include <QDebug>
#include <QTimer>
#include <QFrame>
#include <QLayout>
#include <QLayoutItem>
#include "panelposicionbola.h"

DPosicionBolas::DPosicionBolas(QVector<Bola *> *bolasPasadas, QWidget *parent): QDialog(parent){
		setupUi(this);
		
		lasBolas = bolasPasadas;
		tabBolas->clear();
		
		inicializarPestanyas();
		
		QTimer * temporizador;
		temporizador = new QTimer();
		temporizador->setInterval(50);
		temporizador->setSingleShot(false);
	
		temporizador->start();
		
		connect(temporizador,SIGNAL(timeout()),
				this,SLOT(slotTemporizador()));
	
}

void DPosicionBolas::inicializarPestanyas(){

	tabBolas->clear();
	for (int i=0; i < lasBolas->length(); i++) {
		WidgetPosicionBola * unWidget;
		unWidget = new WidgetPosicionBola( lasBolas->at(i) ) ;
		connect(unWidget,SIGNAL(senyalBolaImagen(Bola*)),
				this,SLOT(slotBolaImagen(Bola * )));
		tabBolas->addTab(unWidget, lasBolas->at(i)->nombre);
		
		
	}
}

void DPosicionBolas::slotTemporizador(){

	QWidget * widgetActual ;
	widgetActual  = tabBolas->widget(tabBolas->currentIndex());
	widgetActual  = tabBolas->currentWidget();
	
	WidgetPosicionBola *wPB;
	wPB = qobject_cast<WidgetPosicionBola*>(widgetActual);
	
//	wPB->actualizarPosicion();
	
	QFrame *frame = wPB->framePosicionBola;
	
	QLayout * layoutFrame = frame->layout();
	
	int numElementos = layoutFrame->count();
	
	if (numElementos != 1 ) {
		return; // atom arporcu lo 
	} 
	
	QLayoutItem * itemDelLayout = layoutFrame->itemAt(0);
	
	QWidget * widgetPanel = itemDelLayout->widget();
	
	PanelPosicionBola *panel ;
	panel = qobject_cast<PanelPosicionBola*>(widgetPanel);
	
	panel->actualizarDibujo(); 
	
}

void DPosicionBolas::slotBolaImagen(Bola * bola){
	emit senyalBolaImagen(bola);
}


void DPosicionBolas::slotEjemplo(){

}

