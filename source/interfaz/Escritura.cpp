/*
 * Escritura.cpp
 *
 * NihongoDS
 *
 */

#include "Escritura.h"

namespace NIHONGO {
//Constructores
Escritura::Escritura():Leccion() {
}

Escritura::Escritura(const Escritura& orig) {
	copy(orig);
}

Escritura::~Escritura() {

}

//Metodos

//Operadores
Escritura& Escritura::operator= (const Escritura& orig) {
	if (this!=&orig) {
		copy(orig);
	}
	return *this;
}

//Metodos del juego

void Escritura::init() {
	Leccion::init();
	paginas_totales=10;
}


//Metodos privados
void Escritura::copy(const Escritura& orig) {
	Leccion::copy(orig);
}


//Draws y Updates

void Escritura::draw() {
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
	}

}

void Escritura::update() {
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
	}
}

void Escritura::draw_pg12(){
	PA_LoadBackground(SCREEN_UP, 3, &escritura_1);
	PA_LoadBackground(SCREEN_DOWN, 3, &escritura_2);
}

void Escritura::update_pg12(){
	change_pg();
}

void Escritura::draw_pg34(){
	PA_LoadBackground(SCREEN_UP, 3, &escritura_3);
	PA_LoadBackground(SCREEN_DOWN, 3, &escritura_4);
}

void Escritura::update_pg34(){
	change_pg();
}

void Escritura::draw_pg56(){
	PA_LoadBackground(SCREEN_UP, 3, &escritura_5);
	PA_LoadBackground(SCREEN_DOWN, 3, &escritura_6);

}

void Escritura::update_pg56(){
	change_pg();
}

void Escritura::draw_pg78(){
	PA_LoadBackground(SCREEN_UP, 3, &escritura_7);
	PA_LoadBackground(SCREEN_DOWN, 3, &escritura_8);

}

void Escritura::update_pg78(){
	change_pg();
}

void Escritura::draw_pg910(){
	PA_LoadBackground(SCREEN_UP, 3, &escritura_9);
	PA_LoadBackground(SCREEN_DOWN, 3, &escritura_10);

}

void Escritura::update_pg910(){
	change_pg();
}


}
