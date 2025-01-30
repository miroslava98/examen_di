#ifndef _BOLA_H
#define _BOLA_H
#include <QString>
#include <QColor>
#include <QImage>
#include <QPainter>
#include <QStringList>

class Bola {

public:

/* EXAMEN */
	
	QStringList nombreCompleto;
	bool resaltar;	
	
	static const int diametro = 50;
	static const int vidasIniciales = 10;
	
	
	
	QColor color;

	float posX, posY;
	float velX, velY;
	QString nombre;
	int vidas;
	
	QImage imagen;
	bool esImagen;
	
	float anchuraJuego, alturaJuego;
	
	
	Bola(float px, float py , float vx, float vy);
	Bola();

	void mover(int, int);
	
	float distancia(Bola *otra);
	bool choca(Bola *);
	void pintar(QPainter&);
	
	void establecerImagen();
	void establecerImagen(QString);

};

Q_DECLARE_METATYPE(Bola *)

#endif





