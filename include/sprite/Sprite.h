/*
 * Sprite.h
 *
 * NihongoDS
 *
 */

#pragma once

#ifndef _SPRITE_H
#define _SPRITE_H

#include <PA9.h>
#include "utiles.h"
#include "Pos_Sprite.h"

namespace NIHONGO {

class Sprite
{
public:
	// Constructores 	
	Sprite();
	Sprite (u8 screen, u8 size, u8 shape, u8 indice, u8 paleta, void* datos);
	Sprite (const Sprite& orig);

	//Destructor
	virtual ~Sprite();

	//Operador de asignacion
	Sprite& operator= (const Sprite& orig);

	//Funcion de depuracion
	char* print ();		//Devuelve una cadena de caracteres con el contenido del objeto. Esta cadena debe ser eliminada con delete [] manualmente.

	//Operaciones
	bool cargarSprite (const Pos_Sprite& pos);	//Se carga el sprite para dibujarse
	void descargarSprite ();					//Descarga el sprite
	bool dibujar();								//Se dibuja en pantalla en la posicion de antes
	bool estaEnPantalla ();						//Indica si el sprite se encuentra en pantalla
	bool mover(u8 x, u8 y);

public:
	//Miembros
	u8 Screen;				// Pantalla donde permanecera el sprite.
	u8 Size;				// Constante de tamaño del sprite. Ej: OBJ_SIZE_32X32
	u8 Shape;				// Constante de tamaño del sprite. Ej: OBJ_SIZE_32X32. Estas constantes en realidad son dos variables. Hay que tener cuidado
	void* Datos;			// Puntero a los datos de imagen
	u8 Indice;				// Indice dentro de la imagen donde se encuentra. Empieza a numerarse en 0.
	u8 Paleta;				// Indice de la paleta a cargar
	Pos_Sprite* Posicion; 	// Indica la posicion del sprite, si se encuentra en pantalla
};

}

#endif
