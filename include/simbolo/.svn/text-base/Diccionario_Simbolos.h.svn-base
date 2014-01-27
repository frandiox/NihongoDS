/*
 * Diccionario_Simbolos.h
 *
 * NihongoDS
 *
 */

#ifndef DICCIONARIO_SIMBOLOS_H_
#define DICCIONARIO_SIMBOLOS_H_

#include <PA9.h>
#include "all_gfx.h"
#include "vector.h"
#include "HiraKata.h"
#include "Kanji.h"

namespace NIHONGO {

//Enumeraciones
enum TipoSimbolo {
	SILABA_A,
	SILABA_E,
	SILABA_I,
	SILABA_O,
	SILABA_U,
	SILABA_DOBLE_A,
	SILABA_DOBLE_O,
	SILABA_DOBLE_U,
	KANJIS
};

#define NUM_SILABA_A 16
#define NUM_SILABA_E 13
#define NUM_SILABA_I 13
#define NUM_SILABA_O 15
#define NUM_SILABA_U 14
#define NUM_SILABA_DOBLE 12
#define NUM_KANJI_FILA 10
#define NUM_KANJIS 80
#define TOTAL_SIMBOLOS 187

class Diccionario_Simbolos {
public:
	//Metodos
	static Simbolo* getSimbolo (TipoSimbolo tipo, u8 indice);
	static u8 numeroSimbolos (TipoSimbolo tipo);

private:
	//constuir silabas
	static Simbolo* silabaA(u8 indice);
	static Simbolo* silabaE (u8 indice);
	static Simbolo* silabaI (u8 indice);
	static Simbolo* silabaO (u8 indice);
	static Simbolo* silabaU (u8 indice);
	static Simbolo* dobleA (u8 indice);
	static Simbolo* dobleU (u8 indice);
	static Simbolo* dobleO (u8 indice);
	static Simbolo* kanji1 (u8 indice);
	static Simbolo* kanji2 (u8 indice);
	static Simbolo* kanji3 (u8 indice);
	static Simbolo* kanji4 (u8 indice);
};

}

#endif /* DICCIONARIO_SIMBOLOS_H_ */
