/*
 * ejInterfaz.cpp
 *
 * NihongoDS
 *
 */

#include "all_gfx.h"
#include "Interfaz.h"
#include <fat.h>

using namespace NIHONGO;


//Constantes


//Variables
Interfaz* ui;

//Prototipos
void initSystems() //Inicializa la libreria PAlib
{
	// Initialize PAlib
	PA_Init();
	// Initializes a standard VBL
	PA_InitVBL();

	fatInitDefault();
}
void initObjects() //Inicializa nuestras variables y objetos
{

}

void loadContent() //Carga texturas, sprites y demas contenido multimedia
{

}
void loadObjects() //Rellena nuestras variables y objetos
{
	ui = new Interfaz();
}
void predraw() { //Dibuja en pantalla pero solo una vez al comienzo. No se repite en cada frame

}
void draw() { //En cada frame dibuja la pantalla
	ui->draw();
}
void update() { //En cada frame actualiza variables del juego
	ui->update();
}
void offSystems() { //Cierra las librerias y demas

}
void destroyObjects() { //Destruye todos nuestros objetos, cierra archivos y demas.
	delete ui;
}
