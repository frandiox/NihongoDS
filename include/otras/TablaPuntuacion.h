/*
 * TablaPuntuacion.h
 *
 * NihongoDS
 *
 */
#ifndef TABLAPUNTUACION_H_
#define TABLAPUNTUACION_H_

#include <PA9.h>
#include <fat.h>
#include "vector.h"

namespace NIHONGO {

//Constantes
#define PTOS_NUM_FILAS 12
//Estructura puntuacion
struct Puntuacion {
	char nombre[5];
	u32 puntos;

	void set (char nombre[5], u32 puntos) {
		strcpy(this->nombre,nombre);
		this->puntos=puntos;
	}
};

class TablaPuntuacion {
public:
	//Constructores
	TablaPuntuacion();
	TablaPuntuacion(const TablaPuntuacion& orig);
	virtual ~TablaPuntuacion();

	TablaPuntuacion& operator= (const TablaPuntuacion& orig);

	//Metodos
	void cargar(char* rutaArchivo);
	void guardar(char* rutaArchivo);
	void add(char nombre[5], u32 points);
	Puntuacion get (u8 indice);
	void set (u8 indice, char nombre[5], u32 puntos);
	void clear();
private:
	//Miembros
	Puntuacion puntos[PTOS_NUM_FILAS];
	u8 actual;

	void copy(const TablaPuntuacion& orig);
	void ordenar();
};

}

#endif /* TABLAPUNTUACION_H_ */
