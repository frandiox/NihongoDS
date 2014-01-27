/*
 * Kanji.h
 *
 * NihongoDS
 *
 */

#pragma once

#ifndef _KANJI_H
#define _KANJI_H

#include <PA9.h>
#include "utiles.h"
#include "Simbolo.h"
#include "Sprite.h"

namespace NIHONGO {

	class Kanji : public Simbolo
{
public:
	// Constructores 	
	Kanji();
	Kanji(char* romaji, Sprite simbolito, char* spanish);
	Kanji (const Kanji& orig);

	//Destructor
	virtual ~Kanji();

	//Operador de asignacion
	Kanji& operator= (const Kanji& orig);

	//Funcion de depuracion
	virtual char* print ();		//Devuelve una cadena de caracteres con el contenido del objeto. Esta cadena debe ser eliminada con delete [] manualmente.


public:
	//Miembros
	Sprite Simbologia;			//El Sprite del simbolo
	char* Trad_Sp;				//Traduccion al español	
};

}

#endif
