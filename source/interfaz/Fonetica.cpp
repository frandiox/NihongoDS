/*
 * Fonetica.cpp
 *
 * NihongoDS
 *
 */

#include "Fonetica.h"

namespace NIHONGO {
//Constructores
Fonetica::Fonetica():Leccion() {
}

Fonetica::Fonetica(const Fonetica& orig) {
	copy(orig);
}

Fonetica::~Fonetica() {

}

//Metodos

//Operadores
Fonetica& Fonetica::operator= (const Fonetica& orig) {
	if (this!=&orig) {
		copy(orig);
	}
	return *this;
}

//Metodos del juego

void Fonetica::init() {
	Leccion::init();
	paginas_totales=8;
}


//Metodos privados
void Fonetica::copy(const Fonetica& orig) {
	Leccion::copy(orig);
}


//Draws y Updates

void Fonetica::draw() {
	switch (pagina_actual){
	case 1 :
		draw_pg12();
		break;
	case 3 :
		draw_pg34();
		break;
	case 5 :
		draw_pg56();
		break;
	case 7 :
		draw_pg78();
		break;
	}

}

void Fonetica::update() {
	switch (pagina_actual){
	case 1 :
		update_pg12();
		break;
	case 3 :
		update_pg34();
		break;
	case 5 :
		update_pg56();
		break;
	case 7 :
		update_pg78();
		break;
	}
}

void Fonetica::draw_pg12(){
	PA_LoadBackground(SCREEN_UP, 3, &fonetica_1);
	PA_LoadBackground(SCREEN_DOWN, 3, &fonetica_2);
}

void Fonetica::update_pg12(){
	change_pg();
}

void Fonetica::draw_pg34(){
	PA_LoadBackground(SCREEN_UP, 3, &fonetica_3);
	PA_LoadBackground(SCREEN_DOWN, 3, &fonetica_4);
}

void Fonetica::update_pg34(){
	change_pg();
}

void Fonetica::draw_pg56(){
	PA_LoadBackground(SCREEN_UP, 3, &fonetica_5);
	PA_LoadBackground(SCREEN_DOWN, 3, &fonetica_6);

}

void Fonetica::update_pg56(){
	change_pg();
}

void Fonetica::draw_pg78(){
	PA_LoadBackground(SCREEN_UP, 3, &fonetica_7);
	PA_LoadBackground(SCREEN_DOWN, 3, &fondo_abajo);

}

void Fonetica::update_pg78(){
	change_pg();
}


}
