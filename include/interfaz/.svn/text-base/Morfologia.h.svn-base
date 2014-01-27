/*
 * Morfologia.h
 *
 * NihongoDS
 *
 */

#ifndef MORFOLOGIA_H_
#define MORFOLOGIA_H_

#include "Leccion.h"
#include "all_gfx.h"

#define SCREEN_UP 1
#define SCREEN_DOWN 0


namespace NIHONGO {


class Morfologia: public NIHONGO::Leccion{
public:
	//Constructores
	Morfologia();
	Morfologia(const Morfologia& orig);
	virtual ~Morfologia();

	//Metodos
	virtual void init();
	virtual void draw();
	virtual void update();

	//Operadores
	virtual Morfologia& operator= (const Morfologia& orig);

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


	virtual void copy(const Morfologia& orig);
};

}

#endif /* MORFOLOGIA_H_ */
