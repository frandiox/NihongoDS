/*
 * Morfologia2.cpp
 *
 * NihongoDS
 *
 */

#include "Morfologia2.h"

namespace NIHONGO {
//Constructores
Morfologia2::Morfologia2():Leccion() {
}

Morfologia2::Morfologia2(const Morfologia2& orig) {
	copy(orig);
}

Morfologia2::~Morfologia2() {

}

//Metodos

//Operadores
Morfologia2& Morfologia2::operator= (const Morfologia2& orig) {
	if (this!=&orig) {
		copy(orig);
	}
	return *this;
}

//Metodos del juego

void Morfologia2::init() {
	Leccion::init();
	paginas_totales=8;
}


//Metodos privados
void Morfologia2::copy(const Morfologia2& orig) {
	Leccion::copy(orig);
}


//Draws y Updates

void Morfologia2::draw() {
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

void Morfologia2::update() {
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

void Morfologia2::draw_pg12(){
	PA_LoadBackground(SCREEN_UP, 3, &morfologia2_1);
	PA_LoadBackground(SCREEN_DOWN, 3, &morfologia2_2);
}

void Morfologia2::update_pg12(){
	change_pg();
}

void Morfologia2::draw_pg34(){
	PA_LoadBackground(SCREEN_UP, 3, &morfologia2_3);
	PA_LoadBackground(SCREEN_DOWN, 3, &morfologia2_4);
}

void Morfologia2::update_pg34(){
	change_pg();
}

void Morfologia2::draw_pg56(){
	PA_LoadBackground(SCREEN_UP, 3, &morfologia2_5);
	PA_LoadBackground(SCREEN_DOWN, 3, &morfologia2_6);

}

void Morfologia2::update_pg56(){
	change_pg();
}

void Morfologia2::draw_pg78(){
	PA_LoadBackground(SCREEN_UP, 3, &morfologia2_7);
	PA_LoadBackground(SCREEN_DOWN, 3, &fondo_abajo);

}

void Morfologia2::update_pg78(){
	change_pg();
}


}
