////////////////////////////
// PAlib project template //
////////////////////////////

// Lines starting with two slashes are ignored by the compiler
// Basically you can use them to comment what are you doing
// In fact, this kind of lines are called comments :P

// Include PAlib so that you can use it
#include <PA9.h>
#include "selector.h"

//Prototipos
void initSystems(); //Inicializa la libreria PAlib
void initObjects(); //Inicializa nuestras variables y objetos
void loadContent(); //Carga texturas, sprites y demas contenido multimedia
void loadObjects(); //Rellena nuestras variables y objetos
void predraw(); //Dibuja en pantalla pero solo una vez al comienzo. No se repite en cada frame
void draw(); //En cada frame dibuja la pantalla
void update(); //En cada frame actualiza variables del juego
void offSystems(); //Cierra las librerias y demas
void destroyObjects(); //Destruye todos nuestros objetos, cierra archivos y demas.
void* selector(u8 i);

#include "ejInterfaz.cpp"

using namespace NIHONGO;

int main() {

	initSystems();
	initObjects();

	// Put your initialization code here
	loadContent();
	loadObjects();

	predraw();
	// Infinite loop to keep the program running
	while (true) {
		// Put your game logic here
		draw();
		update();

		// Wait until the next frame.
		// The DS runs at 60 frames per second.
		PA_WaitForVBL();
	}

	offSystems();
	destroyObjects();
}
