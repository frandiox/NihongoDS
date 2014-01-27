/*
 * HiraKata.cpp
 *
 * NihongoDS
 *
 */

#include "HiraKata.h"

using namespace NIHONGO;

// Constructores 	
HiraKata::HiraKata() : Simbolo() {
	Principal=NULL;
}

HiraKata::HiraKata(char* romaji, Sprite hiragana, Sprite katakana, HiraKata* principal, u8 numDerivaciones)
: Simbolo(romaji)
{
	Hiragana=hiragana;
	Katakana=katakana;
	Principal=principal;
	Derivaciones = vector<HiraKata*>(numDerivaciones); //Derivaciones vacias
}
HiraKata::HiraKata (const HiraKata& orig) : Simbolo(orig) {
	Hiragana=orig.Hiragana;
	Katakana=orig.Katakana;
	Derivaciones=orig.Derivaciones;
	Principal=orig.Principal;
}

//Destructor
HiraKata::~HiraKata() {
}

//Operador de asignacion
HiraKata& HiraKata::operator= (const HiraKata& orig) {
	Simbolo::operator=(orig);
	if (this!=&orig) {
		Hiragana=orig.Hiragana;
		Katakana=orig.Katakana;
		Derivaciones=orig.Derivaciones;
		Principal=orig.Principal;
	}
	return *this;
}

//Funcion de depuracion
char* HiraKata::print () {		//Devuelve una cadena de caracteres con el contenido del objeto. Esta cadena debe ser eliminada con delete [] manualmente.
	char* buffer = new char [500];
	char temp[20];
	char* hirastr = Hiragana.print();
	char* katastr = Katakana.print();
	if (Principal!=NULL) sprintf(temp,Principal->Romaji);
	else sprintf(temp,"NULL");
	sprintf(buffer,"(Romaji:%s,Hira:%s,Kata:%s,%d,%s)",Romaji,hirastr,katastr,Derivaciones.size(),temp);
	delete [] hirastr;
	delete [] katastr;
	return buffer;
}
