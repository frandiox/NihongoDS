/*
 * Kanjis.cpp
 *
 *
 * NihongoDS
 *
 */

#include "Kanjis.h"

namespace NIHONGO {
//Constructores
Kanjis::Kanjis():Leccion() {
}

Kanjis::Kanjis(const Kanjis& orig) {
	copy(orig);
}

Kanjis::~Kanjis() {

}

//Metodos

//Operadores
Kanjis& Kanjis::operator= (const Kanjis& orig) {
	if (this!=&orig) {
		copy(orig);
	}
	return *this;
}

//Metodos del juego

void Kanjis::init() {
	Leccion::init();
	paginas_totales=16;
}


//Metodos privados
void Kanjis::copy(const Kanjis& orig) {
	Leccion::copy(orig);
}


//Draws y Updates

void Kanjis::draw() {
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
	case 9 :
		draw_pg910();
		break;
	case 11 :
		draw_pg1112();
		break;
	case 13 :
		draw_pg1314();
		break;
	case 15 :
		draw_pg1516();
		break;
	}

}

void Kanjis::update() {
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
	case 9 :
		update_pg910();
		break;
	case 11 :
		update_pg1112();
		break;
	case 13 :
		update_pg1314();
		break;
	case 15 :
		update_pg1516();
		break;
	}
}

void Kanjis::draw_pg12(){
	PA_LoadBackground(SCREEN_UP, 3, &kanjis_1);
	PA_LoadBackground(SCREEN_DOWN, 3, &kanjis_2);
}

void Kanjis::update_pg12(){
	change_pg();
}

void Kanjis::draw_pg34(){
	PA_LoadBackground(SCREEN_UP, 3, &kanjis_3);
	PA_LoadBackground(SCREEN_DOWN, 3, &kanjis_4);
}

void Kanjis::update_pg34(){
	change_pg();
}

void Kanjis::draw_pg56(){
	PA_LoadBackground(SCREEN_UP, 3, &kanjis_5);
	PA_LoadBackground(SCREEN_DOWN, 3, &kanjis_6);

}

void Kanjis::update_pg56(){
	change_pg();
}

void Kanjis::draw_pg78(){
	PA_LoadBackground(SCREEN_UP, 3, &kanjis_7);
	PA_LoadBackground(SCREEN_DOWN, 3, &kanjis_8);

}

void Kanjis::update_pg78(){
	change_pg();
}

void Kanjis::draw_pg910(){
	PA_LoadBackground(SCREEN_UP, 3, &kanjis_9);
	PA_LoadBackground(SCREEN_DOWN, 3, &kanjis_10);

}

void Kanjis::update_pg910(){
	change_pg();
}

void Kanjis::draw_pg1112(){
	PA_LoadBackground(SCREEN_UP, 3, &kanjis_11);
	PA_LoadBackground(SCREEN_DOWN, 3, &kanjis_12);

}

void Kanjis::update_pg1112(){
	change_pg();
}

void Kanjis::draw_pg1314(){
	PA_LoadBackground(SCREEN_UP, 3, &kanjis_13);
	PA_LoadBackground(SCREEN_DOWN, 3, &kanjis_14);

}

void Kanjis::update_pg1314(){
	change_pg();
}

void Kanjis::draw_pg1516(){
	PA_LoadBackground(SCREEN_UP, 3, &kanjis_15);
	PA_LoadBackground(SCREEN_DOWN, 3, &fondo_abajo);

}

void Kanjis::update_pg1516(){
	change_pg();
}

}
