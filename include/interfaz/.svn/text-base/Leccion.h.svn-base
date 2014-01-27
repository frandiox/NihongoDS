/*
 * Leccion.h
 *
 * NihongoDS
 *
 */

#ifndef LECCION_H_
#define LECCION_H_

#include <PA9.h>
//#include "vector.h"


enum EstadoLeccion {
	lec_SELECCION,
	lec_EJECUCION,
	lec_FIN
};

namespace NIHONGO {

class Leccion {
public:
	//Constructores
	Leccion();
	//Minijuego(Configuracion config);				//Constructor
	Leccion (const Leccion& orig);				//Constructor de copias
	virtual ~Leccion();							//Destructor

	//Metodos
	EstadoLeccion getEstado();						//Devuelve el estado
	//Seccion getSeccion();						//Devuelve la seccion
	virtual void init()=0;							//Inicializa la leccion
	virtual void draw()=0;							//Dibujar el minijuego
	virtual void update()=0;						//Actualizar el minijuego
	u8 getPagina();							//Devuelve la pagina
	void change_pg();


	//Operadores
	virtual Leccion& operator= (const Leccion& orig);  //Operador de asignacion


protected:
	//Seccion seccion_actual;
	u8 pagina_actual;
	u8 paginas_totales;
	EstadoLeccion estado;
	//vector<Simbolo*> simbolos;
	//Configuracion config;
	//u32 puntuacion;
	//EstadoJuego estado;

	virtual void copy( const Leccion & orig);
	//virtual u8 randomSimbolo ();
	//virtual Simbolo* getSimbolo (u8 idSimbolo, u8 screen);		//Devuelve el simbolo segun el id que ha salido en la funcion
																//randomSimbolo. Tambien se configura de forma automatica la paleta a usar en orden.

};

}

#endif /* LECCION_H_ */
