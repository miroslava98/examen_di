
#include "widgetbola.h"
#include <QDebug>

WidgetBola::WidgetBola(Bola * bPasada,QWidget *parent): QWidget(parent){
		setupUi(this);
		
	miBola = bPasada;
	connect(botonParar,SIGNAL(clicked()),this,SLOT(slotParar()));
	
}


void WidgetBola::slotEjemplo(){

}


void WidgetBola::slotParar() {

	miBola->velX = miBola -> velY = 0;

}
