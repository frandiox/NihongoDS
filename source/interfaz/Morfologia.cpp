/*
 * Morfologia.cpp
 *
 * NihongoDS
 *
 */

#include "Morfologia.h"

namespace NIHONGO {
//Constructores
Morfologia::Morfologia():Leccion() {
}

Morfologia::Morfologia(const Morfologia& orig) {
	copy(orig);
}

Morfologia::~Morfologia() {

}

//Metodos

//Operadores
Morfologia& Morfologia::operator= (const Morfologia& orig) {
	if (this!=&orig) {
		copy(orig);
	}
	return *this;
}

//Metodos del juego

void Morfologia::init() {
	Leccion::init();
	paginas_totales=8;
}


//Metodos privados
void Morfologia::copy(const Morfologia& orig) {
	Leccion::copy(orig);
}


//Draws y Updates

void Morfologia::draw() {
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

void Morfologia::update() {
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

void Morfologia::draw_pg12(){
	PA_LoadBackground(SCREEN_UP, 3, &morfologia_1);
	PA_LoadBackground(SCREEN_DOWN, 3, &morfologia_2);
}

void Morfologia::update_pg12(){
	change_pg();
}

void Morfologia::draw_pg34(){
	PA_LoadBackground(SCREEN_UP, 3, &morfologia_3);
	PA_LoadBackground(SCREEN_DOWN, 3, &morfologia_4);
}

void Morfologia::update_pg34(){
	change_pg();
}

void Morfologia::draw_pg56(){
	PA_LoadBackground(SCREEN_UP, 3, &morfologia_5);
	PA_LoadBackground(SCREEN_DOWN, 3, &morfologia_6);

}

void Morfologia::update_pg56(){
	change_pg();
}

void Morfologia::draw_pg78(){
	PA_LoadBackground(SCREEN_UP, 3, &morfologia_7);
	PA_LoadBackground(SCREEN_DOWN, 3, &morfologia_8);

}

void Morfologia::update_pg78(){
	change_pg();
}


}
