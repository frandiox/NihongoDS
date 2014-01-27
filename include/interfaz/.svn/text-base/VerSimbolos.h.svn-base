/*
 * VerSimbolos.h
 *
 * NihongoDS
 *
 */

#ifndef VERSIMBOLOS_H_
#define VERSIMBOLOS_H_

#include <PA9.h>
#include "all_gfx.h"
#include "vector.h"
#include "Diccionario_Simbolos.h"

namespace NIHONGO {


enum SimbolosViendo {
	HIRAGANA_SIMPLE,
	HIRAGANA_DOBLE,
	KATAKANA_SIMPLE,
	KATAKANA_DOBLE,
	TODOS_KANJIS,
};

class VerSimbolos {
public:
	//Constructores
	VerSimbolos();
	VerSimbolos (const VerSimbolos& orig);
	virtual ~VerSimbolos();

	//Metodos
	void init();
	void draw();
	void update();
	bool Salir();

	//Operador de asignacion
	VerSimbolos& operator= (const VerSimbolos& orig);

private:
	//Miembros
	vector<Simbolo*> simbolos;
	SimbolosViendo actual;
	s8 indiceTocado;
	u8 flecha;
	u8 salir;

	//Metodos privados
	void cargaSimbolos();					//Rellena el vector de simbolos, segun que pantalla de simbolos se este viendo
	void dibujarFichaSimbolo();				//Dibuja en la pantalla de arriba la ficha del simbolo
	bool comprobarSimboloTocado();			//Comprueba si se ha tocado algun simbolo en la pantalla de abajo
	void dibujarBotones();					//Dibuja los botones para cambiar entre los distintos tipos de simbolos
	void moverFlecha();						//Mueve la flecha con las teclas de direccion
	void dibujarFlecha();					//Dibuja la flecha de seleccion de tipo de simbolos
	void borrarTodo();						//Borra toda la memoria usada y ademas limpia las pantallas de textos y sprites.

	void copy (const VerSimbolos& orig);
};

}

#endif /* VERSIMBOLOS_H_ */
