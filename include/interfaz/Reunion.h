/*
 * Reunion.h
 *
 * NihongoDS
 *
 */

#ifndef REUNION_H_
#define REUNION_H_

#include "Minijuego.h"

namespace NIHONGO {

enum Fases {
	MOSTRAR_SIMBOLOS,
	ELEGIR_SIMBOLOS,
	MENU
};

struct CeldaSimbolo {
	u8 numero;
	u8 tocado;
	u8 esDoble;
};

#define NUM_SIMBOLOS 6

class Reunion: public NIHONGO::Minijuego {
public:
	//Constructores
	Reunion();
	Reunion(Configuracion config);
	Reunion(const Reunion& orig);
	virtual ~Reunion();

	//Metodos
	virtual void init();
	virtual void pause();
	virtual void draw();
	virtual void update();

	//Operadores
	virtual Reunion& operator= (const Reunion& orig);

protected:
	//Miembros
	Fases fase;
	vector<CeldaSimbolo> celdas;
	u8 intentos;


	//Metodos del juego
	void elegirSimbolosMostrar();					//Se eligen los simbolos a mostrar en la pantalla de arriba para que el usuario los memorice
	void elegirSimbolosElegir();					//Los simbolos que apareceran en la pantalla de abajo para que el usuario los toque y busque los que han salido en la de arriba
	void ocultarSimbolos(u8 screen);				//Quita los simbolos de la pantalla de arriba
	void mostrarSimbolos(u8 screen);				//Muestra los simbolos correspondientes en la pantalla que se elija por parametro
	void simbolosPorAzar(u8 numSimbolos,u8 screen); //Genera un numero de simbolos por azar dado por parametro. Los genera sin repetidos.
	void comprobarSpritesTocados();					//Comprueba si han sido tocados los sprites de la pantalla de abajo
	bool aciertaConSprite(u8 indice);				//Comprueba si un sprite tocado en la pantalla de abajo era uno de los que salian en la pantalla de arriba
	bool estanTodosTocados();						//Comprueba si todos los sprite de la pantalla de abajo han sido tocados
	void esperar(u8 segundos);						//Hace esperar unos cuantos segundos
	void borrarTodo();								//Borra y destruye todo el minijuego
	void cargarPaletas(u8 screen);					//Carga las paletas apropiadas segun la pantalla


	//Metodos privados
	virtual void copy(const Reunion& orig);
};

}

#endif /* REUNION_H_ */
