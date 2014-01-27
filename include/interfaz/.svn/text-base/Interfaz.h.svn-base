/*
 * Interfaz.h
 *
 * NihongoDS
 *
 */

#ifndef INTERFAZ_H_
#define INTERFAZ_H_

#include <PA9.h>
#include "TablaPuntuacion.h"
#include "VerSimbolos.h"
#include "Lluvia.h"
#include "Reunion.h"
#include "Fonetica.h"
#include "Morfologia.h"
#include "Morfologia2.h"
#include "Escritura.h"
#include "Kanjis.h"
#include "Sintaxis.h"
#include "UnirSimbolos.h"
#include "all_gfx.h"
#include "utiles.h"
#include "vector.h"

namespace NIHONGO {

#define MAX_SPRITES 15
#define SCREEN_UP 1
#define SCREEN_DOWN 0
#define BUTTON_MARGIN_LEFT 96
#define BUTTON_SPACE 8
#define BUTTON_COL1_SPACE 20
#define BUTTON_COL2_SPACE 85

enum Pantallas {
	MENU_PRINCIPAL,
	LECCIONES,
	MINIJUEGOS,
	CONFIG_MINIJUEGOS,
	PUNTUACIONES,
	SIMBOLOS,
	DICCIONARIO
};

class Interfaz
{
public:
	// Constructores
	Interfaz();
	Interfaz (const Interfaz& orig);

	//Destructor
	virtual ~Interfaz();

	//Operador de asignacion
	Interfaz& operator= (const Interfaz& orig);

	//Metodos
	void draw();
	void update();
	void Goto (Pantallas pantalla);

	//Funcion de depuracion
	virtual char* print ();		//Devuelve una cadena de caracteres con el contenido del objeto. Esta cadena debe ser eliminada con delete [] manualmente.


private:
	//Miembros
	Pantallas pantalla_actual;
	u8 cambio;
	Leccion* leccion;
	Minijuego* juego;
	VerSimbolos* vistaSimbolos;
	TablaPuntuacion tabla;
	Configuracion config_juego;
	u8 flecha;

	//Metodos privados
	void load_principal();
	void del_principal();
	void draw_principal();
	void update_principal();

	void load_lecciones();
	void del_lecciones();
	void draw_lecciones();
	void update_lecciones();

	void load_minijuegos();
	void del_minijuegos();
	void draw_minijuegos();
	void update_minijuegos();

	void load_configuracion();
	void del_configuracion();
	void draw_configuracion();
	void update_configuracion();

	void load_puntuaciones();
	void del_puntuaciones();
	void draw_puntuaciones();
	void update_puntuaciones();

	void load_simbolos();
	void del_simbolos();
	void draw_simbolos();
	void update_simbolos();

	void load_dict();
	void del_dict();
	void draw_dict();
	void update_dict();


	void clearSprites(u8 screen, u8 numSprite);		//Quita todos los sprites cargados
	void moverFlecha ();							//Comprueba si se pulsan los botones para mover la flecha. La flecha se mueve con la cruceta de direcciones.
	bool pulsadoFlecha(u8 posicion);				//Comprueba si se pulsa A y ademas si la flecha esta en la posicion dada

	//Otras pantallas
	void anyadirAPuntuacion(u32 puntuacion);
};

}

#endif /* INTERFAZ_H_ */
