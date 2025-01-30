#include "panelposicionbola.h"
#include <QPainter>
#include <QDebug>
#include <QMimeData>

PanelPosicionBola::PanelPosicionBola( Bola * bolaPasada,
				QWidget *parent): 
				QWidget(parent),miBola(bolaPasada){

	miBola = bolaPasada;	
	botonPulsado = false;
	
	setAcceptDrops(true);
		
}

void PanelPosicionBola::paintEvent(QPaintEvent *evento){

	QPainter pintor(this);
	pintor.drawRect(10,20,30,40);


	float posXenPanel;
	posXenPanel = 
		miBola->posX *  ( width() / miBola->anchuraJuego );
		
	float posYenPanel;
	posYenPanel = 
		miBola->posY *  ( height() / miBola->alturaJuego );		
		
	pintor. drawLine(0,posYenPanel,      width(),posYenPanel );
	pintor.drawLine(posXenPanel,0 , posXenPanel,height() );
	
}


void PanelPosicionBola::actualizarDibujo(){

	this->update();
}


void PanelPosicionBola::mousePressEvent(QMouseEvent *event){

	botonPulsado = true;
	clicX = event->x();
	clicY = event->y();
}


void PanelPosicionBola::mouseReleaseEvent(QMouseEvent *event){

	botonPulsado = false;
	miBola->posX = clicX * (miBola->anchuraJuego / width());
	miBola->posY = clicY * (miBola->alturaJuego / height());
	
	float cX = clicX;
	float cY = clicY;
	
	float factor = 0.05;
	
	miBola->velX = ( event->x() - cX ) * factor;
	miBola->velY = ( event->y() - cY ) * factor;	
}

void PanelPosicionBola::dragEnterEvent(QDragEnterEvent *event){
	qDebug()<< "Me quieren arrastrar";
	
	const QMimeData * datos = event->mimeData();
	if (event->mimeData()->hasImage() )
		qDebug()<< "Esto tiene una imagen";
		
	if (datos->hasText())
		qDebug() << "El texto es " << datos ->text();
		
	if (datos->hasUrls() )
		for (int i=0; i< datos->urls().length();i++)
			qDebug()<< i<< " " << 
				datos->urls().at(i).url();
	
	event->accept();
}

void PanelPosicionBola::dropEvent(QDropEvent *event){
	qDebug()<< "Están soltando mierda sobre mi";

 miBola->establecerImagen( event->mimeData()->urls().at(0).path());
 
 emit senyalBolaImagen(miBola);
}








