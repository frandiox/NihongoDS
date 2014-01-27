/*
 * Simbolo.cpp
 *
 * NihongoDS
 *
 */

#include "Simbolo.h"

using namespace NIHONGO;

// Constructores 	
Simbolo::Simbolo() {
	Romaji=NULL;
}
Simbolo::Simbolo (char* romaji) {
	Romaji=NULL;
	CopiarCadena(Romaji,romaji);
}

Simbolo::Simbolo (const Simbolo& orig) {
	Romaji=NULL;
	CopiarCadena(Romaji,orig.Romaji);
}

//Destructor
Simbolo::~Simbolo() {
	if (Romaji!=NULL) delete [] Romaji;
}

//Operador de asignacion
Simbolo& Simbolo::operator= (const Simbolo& orig) {
	if (this!=&orig) {
		if (Romaji!=NULL) delete [] Romaji;
		Romaji=NULL;
		CopiarCadena(Romaji,orig.Romaji);
	}
	return *this;
}

//Funcion de depuracion
char* Simbolo::print () {		//Devuelve una cadena de caracteres con el contenido del objeto. Esta cadena debe ser eliminada con delete [] manualmente.
	char* buffer = new char [100];
	sprintf(buffer,"(romaji:%s)",Romaji);
	return buffer;
}
