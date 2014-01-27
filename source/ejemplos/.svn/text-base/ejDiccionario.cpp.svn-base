/*
 * ejDiccionario.cpp
 *
 * NihongoDS
 *
 */

#include "Diccionario_Simbolos.h"
#include "all_gfx.h"

using namespace NIHONGO;

//Constantes


//Variables
Simbolo** simbolitos;
Simbolo** kanjis;

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
	simbolitos = new Simbolo*[NUM_SILABA_A];
	for (int i = 0; i < NUM_SILABA_A; i++) {
		simbolitos[i] = Diccionario_Simbolos::getSimbolo(SILABA_A, i);
	}
	kanjis = new Simbolo*[4];
	for (int i = 0; i < 4; i++) {
		kanjis[i] = Diccionario_Simbolos::getSimbolo(KANJIS, (i * 10)+8);
	}
}

void loadContent() //Carga texturas, sprites y demas contenido multimedia
{
	for (int i = 0; i < NUM_SILABA_A; i++) {
		HiraKata* s = (HiraKata*) simbolitos[i];
		s->Hiragana.cargarSprite(Pos_Sprite(i, i << 4, 0));
	}
	for (int i = 0; i < 4; i++) {
		Kanji* k = (Kanji*) kanjis[i];
		k->Simbologia.cargarSprite(Pos_Sprite(16 + i, i << 4, 1 << 4));
	}
}
void loadObjects() //Rellena nuestras variables y objetos
{
	PA_LoadSpritePal(0, 0, (void*) hiragana_a_Pal);
}
void predraw() { //Dibuja en pantalla pero solo una vez al comienzo. No se repite en cada frame
	for (int i = 0; i < NUM_SILABA_A; i++) {
		HiraKata* s = (HiraKata*) simbolitos[i];
		s->Hiragana.dibujar();
	}
	for (int i = 0; i < 4; i++) {
		Kanji* k = (Kanji*) kanjis[i];
		k->Simbologia.dibujar();
	}
}
void draw() { //En cada frame dibuja la pantalla

}
void update() { //En cada frame actualiza variables del juego

}
void offSystems() { //Cierra las librerias y demas

}
void destroyObjects() { //Destruye todos nuestros objetos, cierra archivos y demas.
	for (int i = 0; i < NUM_SILABA_A; i++) {
		delete simbolitos[i];
	}
	delete[] simbolitos;

	for (int i = 0; i < 4; i++) {
		delete kanjis[i];
	}
	delete[] kanjis;
}
