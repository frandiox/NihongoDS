/*
 * Sintaxis.cpp
 *
 * NihongoDS
 *
 */

#include "Sintaxis.h"

namespace NIHONGO {
//Constructores
Sintaxis::Sintaxis():Leccion() {
}

Sintaxis::Sintaxis(const Sintaxis& orig) {
	copy(orig);
}

Sintaxis::~Sintaxis() {

}

//Metodos

//Operadores
Sintaxis& Sintaxis::operator= (const Sintaxis& orig) {
	if (this!=&orig) {
		copy(orig);
	}
	return *this;
}

//Metodos del juego

void Sintaxis::init() {
	Leccion::init();
	paginas_totales=8;
}


//Metodos privados
void Sintaxis::copy(const Sintaxis& orig) {
	Leccion::copy(orig);
}


//Draws y Updates

void Sintaxis::draw() {
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

void Sintaxis::update() {
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

void Sintaxis::draw_pg12(){
	PA_LoadBackground(SCREEN_UP, 3, &sintaxis_1);
	PA_LoadBackground(SCREEN_DOWN, 3, &sintaxis_2);
}

void Sintaxis::update_pg12(){
	change_pg();
}

void Sintaxis::draw_pg34(){
	PA_LoadBackground(SCREEN_UP, 3, &sintaxis_3);
	PA_LoadBackground(SCREEN_DOWN, 3, &sintaxis_4);
}

void Sintaxis::update_pg34(){
	change_pg();
}

void Sintaxis::draw_pg56(){
	PA_LoadBackground(SCREEN_UP, 3, &sintaxis_5);
	PA_LoadBackground(SCREEN_DOWN, 3, &sintaxis_6);

}

void Sintaxis::update_pg56(){
	change_pg();
}

void Sintaxis::draw_pg78(){
	PA_LoadBackground(SCREEN_UP, 3, &sintaxis_7);
	PA_LoadBackground(SCREEN_DOWN, 3, &sintaxis_8);

}

void Sintaxis::update_pg78(){
	change_pg();
}


}
