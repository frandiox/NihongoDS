/*
 * Simbolo.h
 *
 * NihongoDS
 *
 */

#pragma once

#ifndef _SIMBOLO_H
#define _SIMBOLO_H

#include <PA9.h>
#include "utiles.h"

namespace NIHONGO {

class Simbolo
{
public:
	// Constructores 	
	Simbolo();
	Simbolo (char* romaji);
	Simbolo (const Simbolo& orig);

	//Destructor
	virtual ~Simbolo();

	//Operador de asignacion
	virtual Simbolo& operator= (const Simbolo& orig);

	//Funcion de depuracion
	virtual char* print ();		//Devuelve una cadena de caracteres con el contenido del objeto. Esta cadena debe ser eliminada con delete [] manualmente.

public:
	//Miembros
	char* Romaji;			//Cadena con la traduccion a romaji del simbolo
};

}

#endif
