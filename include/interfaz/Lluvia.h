/*
 * Lluvia.h
 *
 * NihongoDS
 *
 */

#ifndef LLUVIA_H_
#define LLUVIA_H_

#define T_BAJAR 1
#define T_ADDS	4
#define GRAVEDAD 3

#include "Minijuego.h"

namespace NIHONGO {

class Lluvia: public NIHONGO::Minijuego {
public:
	//Constructores
	Lluvia();
	Lluvia(Configuracion config);		//Constructor
	Lluvia(const Lluvia& orig);			//Constructor de copias
	virtual ~Lluvia();					//Destructor

	virtual void init();				//Inicializa el minijuego
	virtual void pause();				//Pausar el minijuego
	virtual void draw();				//Dibujar el minijuego
	virtual void update();				//Actualizar el minijuego
	virtual Lluvia& operator= (const Lluvia& orig);		//Operador de asignacion

protected:
	//Miembros
	char* buffer;
	vector<u8> pilaHuecos;
	u8 anterior;
	u8 marcado;
	u8 marcado2;
	u32 contador;
	u8 iletra;

	//Metodos de juego
	void anyadirSimbolo();				//Añade un simbolo a la lista para que caiga
	void bajarSprites();				//Hace que baje los sprites
	void comprobarCadena();				//Comprueba la cadena romaji con algun simbolo. Si acierta entonces lo quita.
	void leerTeclado();					//Lee del teclado un caracter y lo añade al buffer
	bool comprobarSiLleganFinal();		//Comprueba si un simbolo ha llegado al final
	u8 restarTiempo();					//Hace la diferencia entre la marca de tiempo y el actual.
										//Ademas actualiza la marca de tiempo.
	void borrarTodo();					//Borra los sprites y demas cosas. Se hace al terminar el juego.


	//Copiar
	virtual void copy( const Lluvia& orig);
};

}

#endif /* LLUVIA_H_ */
