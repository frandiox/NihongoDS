/*
 * Kanji
 *
 * NihongoDS
 *
 */

#include "Kanji.h"

using namespace NIHONGO;

Kanji::Kanji() : Simbolo() {
	Trad_Sp=NULL;
}
Kanji::Kanji(char* romaji, Sprite simbolito, char* spanish)
: Simbolo(romaji)
{
	Simbologia=simbolito;
	Trad_Sp=NULL;
	CopiarCadena(Trad_Sp,spanish);
}
Kanji::Kanji (const Kanji& orig) : Simbolo(orig) {
	Simbologia=orig.Simbologia;
	Trad_Sp=NULL;
	CopiarCadena(Trad_Sp,orig.Trad_Sp);
}

//Destructor
Kanji::~Kanji() {
	if (Trad_Sp!=NULL) delete [] Trad_Sp;
}

//Operador de asignacion
Kanji& Kanji::operator= (const Kanji& orig) {
	Simbolo::operator=(orig);
	if (this!=&orig) {
		Simbologia=orig.Simbologia;
		if (Trad_Sp!=NULL) delete [] Trad_Sp;
		Trad_Sp=NULL;
		CopiarCadena(Trad_Sp,orig.Trad_Sp);
	}
	return *this;
}

//Funcion de depuracion
char* Kanji::print () {		//Devuelve una cadena de caracteres con el contenido del objeto. Esta cadena debe ser eliminada con delete [] manualmente.
	char* cadenaSprite = Simbologia.print();
	char* buffer = new char [500];

	sprintf(buffer,"{ romaji:%s, Sprite: %s, Espanyol: %s }",Romaji,cadenaSprite,Trad_Sp);
	
	delete [] cadenaSprite;
	return buffer;
}
