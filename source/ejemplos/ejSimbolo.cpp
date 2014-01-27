/*
 * ejSimbolo.cpp
 *
 * NihongoDS
 *
 */

#include "Kanji.h"
#include "vector.h"

using namespace NIHONGO;

//Constantes


//Variables
Kanji a;
Kanji b;
Kanji c;


//Prototipos
void initSystems() //Inicializa la libreria PAlib
{
	// Initialize PAlib
	PA_Init();
	// Initializes a standard VBL
	PA_InitVBL();
}
void initObjects() //Inicializa nuestras variables y objetos
{
	a = Kanji("a",Sprite(0,OBJ_SIZE_16X16,0,0,(void*)kanji_1_Sprite),"es una aaaaa");
	b = Kanji("b",Sprite(0,OBJ_SIZE_16X16,1,0,(void*)kanji_1_Sprite),"es una be");

}

void loadContent() //Carga texturas, sprites y demas contenido multimedia
{
	a.Simbologia.cargarSprite(Pos_Sprite(0,0,0));
	b.Simbologia.cargarSprite(Pos_Sprite(1,0,1<<4));
}
void loadObjects() //Rellena nuestras variables y objetos
{
	PA_LoadSpritePal(0,0,(void*)hiragana_a_Pal);
}
void predraw() { //Dibuja en pantalla pero solo una vez al comienzo. No se repite en cada frame
	a.Simbologia.dibujar();
	b.Simbologia.dibujar();

	Kanji d(a);
	PA_InitText(1,1);
	char* cad = NULL;
	cad = d.print();
	PA_OutputText(1,0,0,"%s",cad);
	delete [] cad;
}
void draw() { //En cada frame dibuja la pantalla

}
void update() { //En cada frame actualiza variables del juego

}
void offSystems() { //Cierra las librerias y demas

}
void destroyObjects() { //Destruye todos nuestros objetos, cierra archivos y demas.

}

