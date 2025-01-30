
#include "widgetposicionbola.h"
#include "panelposicionbola.h"
#include <QDebug>
#include <QHBoxLayout>

WidgetPosicionBola::WidgetPosicionBola(Bola * bolaPasada, QWidget *parent): QWidget(parent){
		setupUi(this);
		
		Bola * bola = bolaPasada; 
		PanelPosicionBola * panel = new PanelPosicionBola(bola);
		QHBoxLayout * layout = new QHBoxLayout;
		layout->addWidget(panel);
		framePosicionBola->setLayout(layout);
		
		connect(panel,SIGNAL(senyalBolaImagen(Bola*)),
			this ,SLOT(slotBolaImagen(Bola*)));
}


void WidgetPosicionBola::slotBolaImagen(Bola * bola){
	emit senyalBolaImagen(bola);
	
}

void WidgetPosicionBola::slotEjemplo(){

}


void WidgetPosicionBola::actualizarPosicion(){


//	panel->actualizarDibujo();

}


