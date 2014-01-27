/*
 * Kanjis.h
 *
 * NihongoDS
 *
 */

#ifndef KANJIS_H_
#define KANJIS_H_

#include "Leccion.h"
#include "all_gfx.h"

#define SCREEN_UP 1
#define SCREEN_DOWN 0


namespace NIHONGO {


class Kanjis: public NIHONGO::Leccion{
public:
	//Constructores
	Kanjis();
	Kanjis(const Kanjis& orig);
	virtual ~Kanjis();

	//Metodos
	virtual void init();
	virtual void draw();
	virtual void update();

	//Operadores
	virtual Kanjis& operator= (const Kanjis& orig);

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
	void draw_pg1112();
	void update_pg1112();
	void draw_pg1314();
	void update_pg1314();
	void draw_pg1516();
	void update_pg1516();


	virtual void copy(const Kanjis& orig);
};

}

#endif /* KANJIS_H_ */
