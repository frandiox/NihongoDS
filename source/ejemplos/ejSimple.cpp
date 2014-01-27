/*
 * ejSimple.cpp
 *
 * NihongoDS
 *
 */

#include "all_gfx.h"
#include "vector.h"



//Constantes
#define NUM_ELS 10

//Variables y objetos
vector<u8> numeros;

//--------------- Metodos -----------------
void initSystems() {
	// Initialize PAlib
	PA_Init();
	// Initializes a standard VBL
	PA_InitVBL();
}

void initObjects() {
	numeros = vector<u8> (NUM_ELS);
}

void loadContent() {
	for (u8 i=0; i<NUM_ELS; i++) {
		numeros.add(i);
	}
}

void loadObjects() {
	numeros.erase(3);
	numeros.erase(numeros.size()-1);
	numeros.erase(0);
}

void predraw() {

}

void draw() {
	PA_InitText(1,0);
	for (u8 i=0; i<numeros.size(); i++) {
		PA_OutputText(1,i,0,"%d ",numeros[i]);
	}
	PA_OutputText(1,0,1,"size: %d   , cap:  %d   ",numeros.size(),numeros.capacity());
}

void update() {
}

void offSystems() {

}

void destroyObjects() {

}
