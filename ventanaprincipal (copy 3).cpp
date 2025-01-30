#include "ventanaprincipal.h"
#include <QPainter>
#include <math.h>
#include <stdlib.h>

#include <QColor>
#include <QDebug>

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

VentanaPrincipal::VentanaPrincipal(QWidget * parent) : QMainWindow(parent) {
	
    qRegisterMetaType<Bola*>("Bola*");
	
	QTimer * temporizador;
	temporizador = new QTimer();
	temporizador->setInterval(50);
	temporizador->setSingleShot(false);
	
	temporizador->start();
	
	dListaBolas = NULL;
	dTablaBolas = NULL;
	dControlBolas = NULL;
	dPosicionBolas = NULL;
	dTablaNombres = NULL;
	dNombreBola = NULL;
	
	trayIcon = NULL;	connect(temporizador,SIGNAL(timeout()),this,SLOT(slotTemporizador()));
	incializarBolas();
	
	crearActions();
	crearMenus();
	slotNombreBola();
	
	resize(800,600);

	for (int i=0; i < bolas.size();i++){
		bolas.at(i)->anchuraJuego = width();
		bolas.at(i)->alturaJuego = height();
	}
}

void VentanaPrincipal::crearActions(){
       accionListaBolas  = new QAction("listarBolas",this);
       
       connect(accionListaBolas,SIGNAL(triggered()),
       		this,SLOT(slotListaBolas()));
	
       accionTablaBolas  = new QAction("Tabla Bolas",this);
       
       connect(accionTablaBolas,SIGNAL(triggered()),
       		this,SLOT(slotTablaBolas()));   
	
    accionControlBolas = new QAction("ControlBolas",this);
    	connect(accionControlBolas,SIGNAL(triggered()),
    	this,SLOT(slotControlBolas()));  
    	
    accionPosicionBolas = new QAction("posicionBolas",this);
    	connect(accionPosicionBolas,SIGNAL(triggered()),
    	this,SLOT(slotPosicionBolas()));  	
    	
    accionGuardarPartida = new QAction("Guardar Partida",this);
    	connect(accionGuardarPartida,SIGNAL(triggered()),
    			this,SLOT(slotGuardarPartida())) ;
    			
    accionCargarPartida = new QAction("Cargar Partida",this);
		connect(accionCargarPartida,SIGNAL(triggered()),
			this,SLOT(slotCargarPartida()));
			
    accionTablaNombres = new QAction("Tabla Nombres",this);
	      connect(accionTablaNombres,SIGNAL(triggered()),
	              this,SLOT(slotTablaNombres()));	
	              
    	              	   			
}

void VentanaPrincipal::crearMenus(){
	QMenu *menuInfo = menuBar()->addMenu("Informasion");
	
	menuInfo->addAction(accionListaBolas);
	menuInfo->addAction(accionTablaBolas);
	menuInfo->addAction(accionControlBolas);
	menuInfo->addAction(accionPosicionBolas);
	
	QMenu *menuPartida = menuBar()->addMenu("Partida");
	menuPartida->addAction(accionGuardarPartida);
	menuPartida->addAction(accionCargarPartida);
	
	menuBolaImagenes = menuBar()->addMenu("Restaurar Color");
	
	QMenu * menuTablaBolas = menuBar()->addMenu("TablaBolas Nombres");
	
	menuTablaBolas->addAction(accionTablaNombres);
	
	menuConfigNombres = menuBar()->addMenu("Configurar nombres");
	
	if ( QSystemTrayIcon::isSystemTrayAvailable() ) {
		trayIcon = new QSystemTrayIcon(this);
		QIcon icono("imagenes/asusordenes.png");
		if (icono.isNull())
			qDebug()<< "El icono no es valido";
		
		trayIcon->setIcon(icono);
		trayIcon->setContextMenu(menuInfo);
		trayIcon->show();
		qDebug()<< " se ha creado un elemento en la bandeja";
	} else
		qDebug()<< "Tu sistema no soporta systemTrayInfo";
	
}

void VentanaPrincipal::incializarBolas() {

     QStringList nombres = {"Juan","perico","andres","Jordi","Denis","Daniel","Jose",
     	"Pedro,Pedro,Pedro","Hanjel", " Donald", "Ampersand"};
     	
     
     /* Examen */
     QStringList apellidos = {
    "García", "Fernández", "González", "Rodríguez", "López",
    "Martínez", "Sánchez", "Pérez", "Gómez", "Martín",
    "Jiménez", "Ruiz", "Hernández", "Díaz", "Moreno",
    "Álvarez", "Muñoz", "Romero", "Gutiérrez", "Navarro"
}; 


	for (int i = 0; i < 10 ; i++ ) {
		int posIniX = random() % 800 ;
		int posIniY = random() % 600 ;
	
		float velX = (float)(random()%100) / 50 - 1;
		velX = velX * 3 ;
		float velY = (float)(random()%100) / 50 - 1;

		Bola *nueva = new Bola (posIniX,posIniY,velX,velY);

	/* connect(nueva,SIGNAL(senyalAlgoPasaEnBola(Bola*))
		this, SLOT(slotTratarAlgoConBola(Bola*)));*/

		if (i % 3 == 0)  nueva->establecerImagen();
		
		nueva->nombre = nombres.at(i % nombres.length());	
		nueva->nombreCompleto.append(nueva->nombre);
		bolas.append(nueva);	
		
		int numPartesNombre = random()%2+2;
		for (int i=0 ; i < numPartesNombre; i++)
			nueva->nombreCompleto.append(apellidos.at(random()%apellidos.length()));
		
	}
	

	
	bolaJugador = new Bola(400,400,0.5,0.5);
	

}

void VentanaPrincipal::paintEvent(QPaintEvent * e) {
	QPainter pintor(this);
	

	pintor.fillRect(10,10,50,50,"Red");

	for (int i=0; i < bolas.length() ; i++ ) {	
		bolas.at(i) -> pintar(pintor);
	}
	
	QColor colorJugador = QColor(255,0,0);
	pintor.setBrush(colorJugador);
	pintor.drawEllipse(bolaJugador->posX, bolaJugador->posY,Bola::diametro,Bola::diametro);
}

void VentanaPrincipal::slotTemporizador() {

	for (int i=0; i < bolas.length() ; i++ ) {			
		bolas[i]->mover(this->width(), this->height());
	}
	
	bolaJugador->mover(this->width(),this->height());
	//qDebug() << "revisar choques";
	for (int i = 0; i < bolas.length() ; i++ ) {			
		for (int j = i + 1; j < bolas.length() ; j++ ) {			
			if (i != j )
				if (bolas[i]->choca(bolas[j])) {
					bolas[i]->vidas--;
					bolas[j]->vidas--;
					//qDebug() << "vida quitada "<< i << " " << j ;
				}
		}
	}

	
	/* bola jugador rebota contra otras */
	for (int i = 0; i < bolas.length() ; i++ ) 			
		bolaJugador->choca(bolas.at(i));


	for (int i = 0; i < bolas.length() ; i++ ) 			
		if (bolas.at(i)->vidas < 0 ) 
			bolas.at(i)->vidas = 0;
	
	
	for (int i=0; i < bolas.length() && true ; i++ )
		if ( bolas.at(i)->vidas <=0 ) {
			emit senyalBolaMuerta(i );
			delete bolas.at(i) ;
			bolas.remove(i);
			if (trayIcon != NULL) 
			   	trayIcon->showMessage(
					"Cosa mala",
					"S'ha muerto la bola");
			break;
					
		}
		
	this->update();  // estoy llamandoi a paintEvent
}



void VentanaPrincipal::keyPressEvent(QKeyEvent *evento){

	int tecla = evento->key();

	   switch (tecla) {
                case Qt::Key_Up : 
                        bolaJugador->velY = bolaJugador->velY - 0.1 ;
                        break;
                case Qt::Key_Down : 
                        bolaJugador->velY = bolaJugador->velY + 0.1 ;
                        break;
                case Qt::Key_Right : 
                        bolaJugador->velX = bolaJugador->velX + 0.1 ;
                        break;
                case Qt::Key_Left : 
                        bolaJugador->velX = bolaJugador->velX - 0.1 ;
                        break;
        }
}


void VentanaPrincipal::mousePressEvent(QMouseEvent *event){

	
	float empujeX = event->x() - bolaJugador->posX; 
	empujeX = empujeX / 250;

	float empujeY = event->y() - bolaJugador->posY; 
	empujeY = empujeY / 250;

	
	bolaJugador->velX += empujeX;
	bolaJugador->velY += empujeY;	


}



void VentanaPrincipal::slotListaBolas(){

	if (dListaBolas == NULL)
		dListaBolas = new DListaBolas( &bolas );
		
	dListaBolas->show();
}



void VentanaPrincipal::slotTablaBolas(){

	if (dTablaBolas == NULL)
		dTablaBolas = new DTablaBolas( &bolas );
		
	dTablaBolas->show();
}



void VentanaPrincipal::slotControlBolas(){

	if (dControlBolas == NULL){
		dControlBolas = new DControlBolas( &bolas );
		connect( this, SIGNAL(senyalBolaMuerta( int)),
			dControlBolas,SLOT(slotBolaMuerta(int )));
		}
		
	dControlBolas->show();
}


void VentanaPrincipal::slotPosicionBolas(){

	if (dPosicionBolas == NULL){
		dPosicionBolas = new DPosicionBolas( &bolas );
		connect( dPosicionBolas , SIGNAL(senyalBolaImagen(Bola *)),
			this,SLOT(slotBolaImagen(Bola *)));	
	}
		
	dPosicionBolas->show();
}

void VentanaPrincipal::slotTablaNombres(){


  if ( dTablaNombres == NULL) {
  
     dTablaNombres = new DTablaNombres(&bolas);
  
  }
  
  dTablaNombres->show();

}

void VentanaPrincipal::slotNombreBola(){

  for (int i = 0; i < bolas.size(); i++){
    Bola * bola = bolas.at(i);

   QAction *accion = new QAction(bola->nombre);
   qDebug()<< "nombrebola " << bola->nombre;
  
   menuConfigNombres->addAction(accion);    
     connect(accion,SIGNAL(triggered()),this,SLOT(slotAbrirDNombre(bola)));
 }

}

void VentanaPrincipal::slotAbrirDNombre(Bola *bola){

  Bola *bolaAEnviar = bola;

  if (dNombreBola == NULL ) {
  
    dNombreBola = new DNombreBola(&bolaAEnviar);
  }
  
  dNombreBola->show();

}
	
void VentanaPrincipal::slotGuardarPartida(){

	QJsonObject jsonPrincipal;
	/* INICIO crear JSON con datos del juego*/
	
	jsonPrincipal["miNombre"] =  QString("Nacho");
	jsonPrincipal["edad"] = 51;

	QJsonArray versiones;
	versiones.append(2);
	versiones.append(2.1);
	versiones.append(3.3);
	jsonPrincipal["versiones"] = versiones;
	
	/* Bola del Jugador */
	
	QJsonObject jsonJugador;
	jsonJugador["posX"] = bolaJugador->posX;
	jsonJugador["posY"] = bolaJugador->posY;	
		
	QJsonArray coloresJugador;
	coloresJugador.append(bolaJugador->color.red());
	coloresJugador.append(bolaJugador->color.green());
	coloresJugador.append(bolaJugador->color.blue());

	jsonJugador["color"] = coloresJugador;
	
	jsonPrincipal["bolaJugador"] = jsonJugador;	
	
	
	QJsonArray arrayBolas;

	
	for (int i = 0; i< bolas.size(); i++) {
		QJsonObject objetoBola;
		objetoBola["posX"] = bolas.at(i)->posX;
		objetoBola["posY"] = bolas.at(i)->posY;	
		objetoBola["velX"] = bolas.at(i)->velX;
		objetoBola["velY"] = bolas.at(i)->velY;
		objetoBola["nombre"] = bolas.at(i)->nombre;					
		
		QJsonArray coloresJugador;
		coloresJugador.append(bolas.at(i)->color.red());
		coloresJugador.append(bolas.at(i)->color.green());
		coloresJugador.append(bolas.at(i)->color.blue());

		objetoBola["color"] = coloresJugador;
		
		arrayBolas.append(objetoBola);
	}
	
	jsonPrincipal["bolas"] = arrayBolas;
	
	
	/* FIN crear JSON con datos del juego. Guardo el archivo*/
	QFile saveFile(QStringLiteral("partida.json"));
	saveFile.open(QIODevice::WriteOnly);
	
	QJsonDocument saveDoc(jsonPrincipal);
	saveFile.write(saveDoc.toJson());
}

void VentanaPrincipal::slotCargarPartida(){


	for (int i=0; i< bolas.size(); i++)
   	 delete bolas[i];
    
    bolas.clear();
	

	QFile loadFile(QStringLiteral("partida.json"));
	if (! loadFile.open(QIODevice::ReadOnly))
		return;

	QByteArray savedData = loadFile.readAll();
	QJsonDocument documento( QJsonDocument::fromJson(savedData));
	
	QJsonObject jsonPrincipal = documento.object();

	QStringList listaClaves =  jsonPrincipal.keys();
	
	qDebug() << "Lista de claves " << listaClaves;
	
	if (listaClaves.contains("miNombre") ) {
		QJsonValue valormiNombre = jsonPrincipal["miNombre"];
		QString stringmiNombre;
		if (valormiNombre.isString()) 
			stringmiNombre = valormiNombre.toString();
		qDebug() << "BIEN HECHO nombre :" << stringmiNombre;
	}
		
	if (jsonPrincipal.contains("nombre"))
		qDebug() << "contiene nombre : " << jsonPrincipal["nombre"].toString() ;

	if (jsonPrincipal.contains("miNombre"))
		qDebug() << "contiene miNombre : " << jsonPrincipal["miNombre"].toString() ;
		
	QJsonValue valorBolas =	jsonPrincipal["bolas"] ;
	
	if (! valorBolas.isArray() ){
		qDebug() << "ERROR gordo, las bolas no son un array" ;
		return;	
	}
	
	QJsonArray arrayBolas = valorBolas.toArray();
	
	for (int i=0; i < arrayBolas.size() ; i++ ) {
		qDebug()<< " analizando bola " << i;
		QJsonValue elemento = arrayBolas[i];
		if (! crearBolaJson(elemento) ) {
			qDebug() << "No puedo crear una bola " << i;
			return ;
		}
			
	}
	
	QJsonValue valorVersiones =	jsonPrincipal["versiones"] ;
	QJsonArray arrayVersiones = valorVersiones.toArray();
	
	qDebug()<< "VERSIONES" ;
	for (int i=0; i <arrayVersiones.size() ; i++ ) {
		QJsonValue valorVersion = arrayVersiones[i];
		qDebug() << valorVersion.toDouble();
	
	
	}
	
}


bool VentanaPrincipal::crearBolaJson(QJsonValue &elemento){

	if (! elemento.isObject() ) {
		qDebug() << "Error: No objeto en Array de bolas ";
		return false;
	}
		
	QJsonObject objetoBola = elemento.toObject();
	if (!objetoBola.contains("posX")) {
		qDebug()<< "Erro. La bola no tiene posiciónX";
		return false;
	}
	QJsonValue valorPosX = objetoBola["posX"];
	if (! valorPosX.isDouble() ) {
		qDebug()<< " Error. PosX no es un número ";
		return false;
	}
	float posX = valorPosX.toDouble();
	
	float posY = objetoBola["posY"].toDouble();
	float velX = objetoBola["velX"].toDouble();
	float velY = objetoBola["velY"].toDouble();	
	QString nombre = objetoBola["nombre"].toString();
	int rojo,verde,azul;
	
	QJsonValue colores = objetoBola["color"];
	if (! colores.isArray() ) {
		qDebug()<< "Error el color no está bien";
		return false;
	}
	qDebug()<< "antes del error";
	QJsonArray arrayColores = colores.toArray();
	rojo = arrayColores[0].toInt();
	verde = arrayColores[1].toInt();
	azul = arrayColores[2].toInt();

	qDebug()<< "después del error";
	Bola * nueva = new Bola(posX,posY,velX,velY);
	nueva->nombre = nombre;
	nueva->color = QColor(rojo,verde,azul);
	
	nueva->anchuraJuego = width();
	nueva->alturaJuego = height();
	
	
	bolas.append(nueva);	
	
	
	return true;
// demasiao		QJsonObject objetoBola = arrayBolas[i].toObject();
}
	

void VentanaPrincipal::slotBolaImagen(Bola * bola) {
	
	QAction *accion = new QAction(bola->nombre,this);
	 /*	void * bolaVoid = (void*) bola; 
   	QVariant dato;
   	dato.setValue(bolaVoid);
    accion->setData( dato ) ;*/
	
    QVariant variant = QVariant::fromValue(bola);
    variant.setValue(bola);
    accion->setData(variant);
   	connect(accion,SIGNAL(triggered()),this,SLOT(slotEliminarImagen()));  
    menuBolaImagenes->addAction(accion);   
}
void VentanaPrincipal::slotEliminarImagen() {
	QObject * objCulp = sender();
	QAction * actCulp = qobject_cast<QAction*>(objCulp);
	
	/*QVariant datoVariant = actCulp->data();
	void * bolaVoid = datoVariant.value<void*>();	
	Bola * bola = (Bola*) bolaVoid;*/
	
	QVariant datoVariant = actCulp->data();
	Bola * bola = datoVariant.value<Bola *>();
	
	bola->esImagen = false;	
/*	bolaQuitarImagen->esImagen = false;*/
}






