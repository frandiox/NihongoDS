/*
 * UnirSimbolos.h
 *
 * NihongoDS
 *
 */

#ifndef UNIRSIMBOLOS_H_
#define UNIRSIMBOLOS_H_

#include "Minijuego.h"

namespace NIHONGO {


struct Color {
	Color (u8 r, u8 g, u8 b) {red=r; green=g; blue=b; }
	u8 red;
	u8 green;
	u8 blue;
};

struct Pares {
	u8 izda;
	u8 dcha;
};

#define UNION_NUM_SIMBOLOS	6
#define LADO_IZDA 0
#define LADO_DCHA 1
#define COLOR_VERDE Color(0,31,0)
#define COLOR_ROJO  Color(31,0,0)

class UnirSimbolos: public NIHONGO::Minijuego {
public:
	//Constructores
	UnirSimbolos();
	UnirSimbolos(Configuracion config);
	UnirSimbolos (const UnirSimbolos& orig);
	virtual ~UnirSimbolos();

	//Metodos
	virtual void init();
	virtual void pause();
	virtual void draw();
	virtual void update();

	//Operador de asignacion
	UnirSimbolos& operator= (const UnirSimbolos& orig);
protected:
	//Miembros
	vector<char*> cadenas;
	vector<Pares> paresCorrectos;
	s8 izqTocado;
	s8 dchaTocado;
	u8 intentos;

	//Metodos privados
	void elegirSimbolos();											//Elige los simbolos a mostrar en la columna izquierda
	void elegirCadenas();											//Elige las cadenas romaji a mostrar en la columna derecha
	void comprobarTocados();										//Comprueba si se ha tocado los sprites o las cadenas
	bool estaYaMarcado(u8 lado, u8 indice);									//Comprueba si el indice pasado forma parte de un par ya marcado como correcto.
	bool verSiHaAcertado();											//Al ser tocado una cadena y un sprite, se comprueba si es correcto
	void dibujarLinea(u8 x1, u8 y1, u8 x2, u8 y2, Color color);		//Dibuja una linea entre el punto x1,y1 y el punto x2,y2 del color indicado
	void borrarTodo();												//Borra toda la memoria usada por los sprites ademas del texto y otros recursos

	virtual void copy(const UnirSimbolos& orig);
};

}

#endif /* UNIRSIMBOLOS_H_ */
