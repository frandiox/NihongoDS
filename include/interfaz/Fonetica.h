/*
 * Fonetica.h
 *
 * NihongoDS
 *
 */

#ifndef FONETICA_H_
#define FONETICA_H_

#include "Leccion.h"
#include "all_gfx.h"

#define SCREEN_UP 1
#define SCREEN_DOWN 0


namespace NIHONGO {


class Fonetica: public NIHONGO::Leccion{
public:
	//Constructores
	Fonetica();
	Fonetica(const Fonetica& orig);
	virtual ~Fonetica();

	//Metodos
	virtual void init();
	virtual void draw();
	virtual void update();

	//Operadores
	virtual Fonetica& operator= (const Fonetica& orig);

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


	virtual void copy(const Fonetica& orig);
};

}

#endif /* FONETICA_H_ */
