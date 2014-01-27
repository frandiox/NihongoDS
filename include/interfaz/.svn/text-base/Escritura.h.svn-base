/*
 * Escritura.h
 *
 * NihongoDS
 *
 */

#ifndef ESCRITURA_H_
#define ESCRITURA_H_

#include "Leccion.h"
#include "all_gfx.h"

#define SCREEN_UP 1
#define SCREEN_DOWN 0


namespace NIHONGO {


class Escritura: public NIHONGO::Leccion{
public:
	//Constructores
	Escritura();
	Escritura(const Escritura& orig);
	virtual ~Escritura();

	//Metodos
	virtual void init();
	virtual void draw();
	virtual void update();

	//Operadores
	virtual Escritura& operator= (const Escritura& orig);

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
	void draw_pg910();
	void update_pg910();


	virtual void copy(const Escritura& orig);
};

}

#endif /* ESCRITURA_H_ */
