#ifndef _PANELPOSICIONBOLA_
#define _PANELPOSICIONBOLA_


#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDropEvent>
#include "bola.h"


class PanelPosicionBola : public QWidget {
Q_OBJECT
public:
	PanelPosicionBola(Bola *, QWidget * parent = NULL);
	Bola * miBola;
	void paintEvent(QPaintEvent *evento);
	void actualizarDibujo();
	/* Estado del panel */
	bool botonPulsado;
	int clicX , clicY;
	
	void dragEnterEvent(QDragEnterEvent *event);
	void dropEvent(QDropEvent *);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	
signals:
	void senyalBolaImagen(Bola *) ;
	
};

#endif
