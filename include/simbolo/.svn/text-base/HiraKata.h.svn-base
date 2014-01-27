/*
 * HiraKata.h
 *
 * NihongoDS
 *
 */

#pragma once

#ifndef _HIRAKATA_H
#define _HIRAKATA_H

#include <PA9.h>
#include "Simbolo.h"
#include "Sprite.h"
#include "utiles.h"
#include "vector.h"

namespace NIHONGO {

class HiraKata : public Simbolo
{
public:
	// Constructores 	
	HiraKata();
	HiraKata(char* romaji, Sprite hiragana, Sprite katakana, HiraKata* principal, u8 numDerivaciones);
	HiraKata (const HiraKata& orig);

	//Destructor
	virtual ~HiraKata();

	//Operador de asignacion
	virtual HiraKata& operator= (const HiraKata& orig);

	//Funcion de depuracion
	virtual char* print ();		//Devuelve una cadena de caracteres con el contenido del objeto. Esta cadena debe ser eliminada con delete [] manualmente.

public:
	//Miembros
	Sprite Hiragana;					//El simbolo grafico del hiragana
	Sprite Katakana;					//El simbolo grafico del katakana
	vector<HiraKata*> Derivaciones;		//Vector con las derivaciones
	HiraKata* Principal;				//Simbolo principal o NULL si no tiene

};

}

#endif
