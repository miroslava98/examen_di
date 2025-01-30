#ifndef _VENTANAPRINCIPAL_H_
#define  _VENTANAPRINCIPAL_H_

#include <QPaintEvent>
#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QJsonValue>
#include <QSystemTrayIcon>

#include "bola.h"
#include "dlistabolas.h"
#include "dtablabolas.h"
#include "dcontrolbolas.h"
#include "dposicionbolas.h"
#include "dtablanombres.h"
#include "dnombrebola.h"

//Tabla punto 10

class VentanaPrincipal : public QMainWindow {
Q_OBJECT


public :

	// float posX,posY,velX,velY;

//	QTimer temporizador;
	QVector<Bola*> bolas;
	Bola * bolaJugador;
	
	QSystemTrayIcon * trayIcon;
	
	QAction *accionListaBolas, *accionTablaBolas, * accionControlBolas, *accionTablaNombres, *accionConfiguraNombre;
	QAction *accionGuardarPartida, *accionCargarPartida;
	QAction *accionPosicionBolas;
	
	DListaBolas * dListaBolas;
	DTablaBolas * dTablaBolas;
	DControlBolas * dControlBolas;
	DPosicionBolas * dPosicionBolas;
	DTablaNombres * dTablaNombres;
	DNombreBola * dNombreBola;
	
	QMenu *menuBolaImagenes;
	QMenu *menuConfigNombres;
	
	void crearActions();
	void crearMenus();
	
	VentanaPrincipal(QWidget * parent = NULL);
	void paintEvent(QPaintEvent *event);
	void keyPressEvent(QKeyEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void incializarBolas();
	bool crearBolaJson(QJsonValue &elemento);
public slots:
	void slotTemporizador();
	void slotListaBolas();
	void slotTablaBolas();
	void slotControlBolas();
	void slotPosicionBolas();
	
	void slotGuardarPartida();
	void slotCargarPartida();
	
	void slotBolaImagen(Bola *);
	void slotEliminarImagen();
	void slotTablaNombres();
	void slotNombreBola();
	void slotAbrirDNombre();
	
	
signals:
	void senyalBolaMuerta(int );
};


#endif








