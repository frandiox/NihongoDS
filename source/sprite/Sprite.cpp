/*
 * Sprite.cpp
 *
 * NihongoDS
 *
 */

#include "Sprite.h"

using namespace NIHONGO;

Sprite::Sprite() {
	Screen = 0;
	Size = 0;
	Shape =0;
	Datos = NULL;
	Indice = 0;
	Paleta = 0;
	Posicion = NULL;
}

Sprite::Sprite (u8 screen, u8 size, u8 shape, u8 indice, u8 paleta, void* datos){
	Screen = screen;
	Size=size;
	Shape=shape;
	Datos=datos;
	Indice=indice;
	Paleta=paleta;
	Posicion=NULL;
}

Sprite::Sprite(const Sprite& orig) {
	Screen = orig.Screen;
	Size = orig.Size;
	Shape = orig.Shape;
	Datos = orig.Datos;
	Indice = orig.Indice;
	Paleta = orig.Paleta;
	if (orig.Posicion != NULL)
		Posicion = new Pos_Sprite(*orig.Posicion);
	else
		Posicion = NULL;
}

char* Sprite::print() {
	char* buffer = new char[500];
	char* temp = new char[200];

	if (Posicion == NULL)
		sprintf(temp, "NULL");
	else
		temp = Posicion->print();

	sprintf(buffer, "(screen:%d,size:(%d,%d),indice:%d,paleta:%d,pos:%s)", Screen,Size,Shape, Indice,
			Paleta, temp);
	delete[] temp;
	return buffer;
}

Sprite& Sprite::operator=(const Sprite& orig) {
	if (this != &orig) {
		Screen = orig.Screen;
		Size = orig.Size;
		Shape = orig.Shape;
		Indice = orig.Indice;
		Paleta = orig.Paleta;
		Datos = orig.Datos;
		if (Posicion != NULL)
			delete Posicion;
		if (orig.Posicion != NULL)
			Posicion = new Pos_Sprite(*orig.Posicion);
		else
			Posicion = NULL;
	}
	return *this;
}

//Operaciones
bool Sprite::cargarSprite(const Pos_Sprite& pos) {
	if (Posicion!=NULL) descargarSprite();
	Posicion = new Pos_Sprite (pos);
	if (Datos!=NULL) {
			PA_CreateSprite(Screen, // Screen
					Posicion->Id, // Sprite number
					Datos, // Sprite data
					Size,Shape, // Sprite size
					1, // 256 color mode
					Paleta, // Sprite palette number
					Posicion->X, Posicion->Y
					); // X and Y position on the screen
			return true;
		} else {
			return false;
		}
}
bool Sprite::dibujar() {
	if (estaEnPantalla()) {
		PA_StartSpriteAnim(Screen,Posicion->Id,Indice,Indice,0);
		return true;
	}
	else
		return false;
}
bool Sprite::estaEnPantalla() {
	return (Posicion!=NULL);
}

void Sprite::descargarSprite () {
	if (Posicion!=NULL) {
		PA_DeleteGfx(Screen,PA_GetSpriteGfx(Screen,Posicion->Id));
		PA_DeleteSprite(Screen,Posicion->Id);
		delete Posicion;
		Posicion=NULL;
	}
}

bool Sprite::mover(u8 x, u8 y) {
	if (estaEnPantalla()) {
		PA_SetSpriteXY(Screen,Posicion->Id,x,y);
		Posicion->X = x;
		Posicion->Y = y;
		return true;
	}
	else
		return false;

}

Sprite::~Sprite() {
	descargarSprite();
	if (Posicion != NULL)
		delete Posicion;
}
