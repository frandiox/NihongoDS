/*
 * Sintaxis.h
 *
 * NihongoDS
 *
 */

#ifndef SINTAXIS_H_
#define SINTAXIS_H_

#include "Leccion.h"
#include "all_gfx.h"

#define SCREEN_UP 1
#define SCREEN_DOWN 0


namespace NIHONGO {


class Sintaxis: public NIHONGO::Leccion{
public:
	//Constructores
	Sintaxis();
	Sintaxis(const Sintaxis& orig);
	virtual ~Sintaxis();

	//Metodos
	virtual void init();
	virtual void draw();
	virtual void update();

	//Operadores
	virtual Sintaxis& operator= (const Sintaxis& orig);

protected:
	//Miembros


	//Metodos del juego


	//Metodos privados
	void draw_pg12();
	void update_pg12();
	void draw_pg34();
	void update_pg34();
	void draw_pg56();
	void update_pg56();
	void draw_pg78();
	void update_pg78();


	virtual void copy(const Sintaxis& orig);
};

}

#endif /* SINTAXIS_H_ */
