/*
 * Morfologia2.h
 *
 * NihongoDS
 *
 */

#ifndef MORFOLOGIA2_H_
#define MORFOLOGIA2_H_

#include "Leccion.h"
#include "all_gfx.h"

#define SCREEN_UP 1
#define SCREEN_DOWN 0


namespace NIHONGO {


class Morfologia2: public NIHONGO::Leccion{
public:
	//Constructores
	Morfologia2();
	Morfologia2(const Morfologia2& orig);
	virtual ~Morfologia2();

	//Metodos
	virtual void init();
	virtual void draw();
	virtual void update();

	//Operadores
	virtual Morfologia2& operator= (const Morfologia2& orig);

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


	virtual void copy(const Morfologia2& orig);
};

}

#endif /* MORFOLOGIA2_H_ */
