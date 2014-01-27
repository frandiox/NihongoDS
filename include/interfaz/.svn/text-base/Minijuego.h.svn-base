/*
 * Minijuego.h
 *
 * NihongoDS
 *
 */

#ifndef MINIJUEGO_H_
#define MINIJUEGO_H_

#include <PA9.h>
#include "utiles.h"
#include "vector.h"
#include "Diccionario_Simbolos.h"

enum Configuracion {
	C_EMPTY,
	HIRAGANA,
	KATAKANA,
	KANJI
};

enum EstadoJuego {
	EJ_EMPTY,
	EJECUCION,
	PAUSA,
	PARA_TERMINAR,
	FIN
};

namespace NIHONGO {

class Minijuego {
public:
	//Constructores
	Minijuego();
	Minijuego(Configuracion config);				//Constructor
	Minijuego (const Minijuego& orig);				//Constructor de copias
	virtual ~Minijuego();							//Destructor

	//Metodos
	Configuracion getConfiguracion ();				//Devuelve la configuracion
	virtual void init()=0;							//Inicializa el minijuego
	virtual void pause()=0;							//Pausa el juego o lo continua
	EstadoJuego getEstado();						//Devuelve el estado
	virtual void draw() =0;							//Dibujar el minijuego
	virtual void update()=0;						//Actualizar el minijuego
	u32 getPuntuacion();							//Devuelve la puntuacion

	//Operadores
	virtual Minijuego& operator= (const Minijuego& orig);  //Operador de asignacion


protected:
	vector<Simbolo*> simbolos;
	Configuracion config;
	u32 puntuacion;
	EstadoJuego estado;

	virtual void copy( const Minijuego& orig);
	virtual u8 randomSimbolo ();
	virtual Simbolo* getSimbolo (u8 idSimbolo, u8 screen);		//Devuelve el simbolo segun el id que ha salido en la funcion
																//randomSimbolo. Tambien se configura de forma automatica la paleta a usar en orden.

};

}

#endif /* MINIJUEGO_H_ */
