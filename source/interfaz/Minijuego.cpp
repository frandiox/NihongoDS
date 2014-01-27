/*
 * Minijuego.cpp
 *
 * NihongoDS
 *
 */

#include "Minijuego.h"

namespace NIHONGO {

Minijuego::Minijuego() {
	config=C_EMPTY;
	estado=EJ_EMPTY;
	puntuacion=0;
}

Minijuego::Minijuego(Configuracion config) {
	this->config=config;
	estado=EJ_EMPTY;
	puntuacion=0;
}

Minijuego::~Minijuego() {
}

Minijuego::Minijuego(const Minijuego & orig) {
	copy(orig);
}

EstadoJuego Minijuego::getEstado() {
	return estado;
}

void Minijuego::copy(const Minijuego & orig) {
	config=orig.config;
	puntuacion=orig.puntuacion;
	estado=orig.estado;
	simbolos = vector<Simbolo*>(orig.simbolos);
}

Minijuego & Minijuego::operator =(const Minijuego & orig) {
	if (this!=&orig) {
		copy(orig);
	}
	return *this;
}

Configuracion Minijuego::getConfiguracion() {
	return config;
}

u32 Minijuego::getPuntuacion() {
	return puntuacion;
}

u8 Minijuego::randomSimbolo () {
	switch(config) {
	case HIRAGANA:
	case KATAKANA:
		return PA_RandMax(107-1);
		break;
	case KANJI:
		return PA_RandMax(80-1);
		break;
	}
	return 0;
}

Simbolo* Minijuego::getSimbolo (u8 id, u8 screen) {
	Simbolo * simbolo;
	u8 paleta;
	switch(config) {
	case HIRAGANA:
	case KATAKANA:
		if (id>=0 && id<=15) { simbolo = Diccionario_Simbolos::getSimbolo(SILABA_A,id); paleta=0; }
		id-=16;
		if (id>=0 && id<=12) { simbolo = Diccionario_Simbolos::getSimbolo(SILABA_E,id); paleta=1; }
		id-=13;
		if (id>=0 && id<=12) { simbolo = Diccionario_Simbolos::getSimbolo(SILABA_I,id); paleta=2; }
		id-=13;
		if (id>=0 && id<=14) { simbolo =  Diccionario_Simbolos::getSimbolo(SILABA_O,id); paleta=3; }
		id-=15;
		if (id>=0 && id<=13) { simbolo = Diccionario_Simbolos::getSimbolo(SILABA_U,id); paleta=4; }
		id-=14;
		if (id>=0 && id<=11) { simbolo = Diccionario_Simbolos::getSimbolo(SILABA_DOBLE_A,id); paleta=5; }
		id-=12;
		if (id>=0 && id<=11) { simbolo = Diccionario_Simbolos::getSimbolo(SILABA_DOBLE_O,id); paleta=6; }
		id-=12;
		if (id>=0 && id<=11) { simbolo = Diccionario_Simbolos::getSimbolo(SILABA_DOBLE_U,id); paleta=7; }
		break;
	case KANJI:
		simbolo = Diccionario_Simbolos::getSimbolo(KANJIS,id);
		paleta=0;
		break;
	default:
		simbolo=NULL;
		paleta=0;
		break;
	}

	//Configurar pantalla y id de paleta
	if (simbolo!=NULL) {
		if (config==HIRAGANA) {
			HiraKata* hSimbolo = (HiraKata*)simbolo;
			hSimbolo->Hiragana.Screen=screen;
			hSimbolo->Hiragana.Paleta=paleta;
		}
		else if (config==KATAKANA) {
			HiraKata* hSimbolo = (HiraKata*)simbolo;
			hSimbolo->Katakana.Screen=screen;
			hSimbolo->Katakana.Paleta=paleta;
		}
		else if (config==KANJI) {
			Kanji* hSimbolo = (Kanji*)simbolo;
			hSimbolo->Simbologia.Screen=screen;
			hSimbolo->Simbologia.Paleta=paleta;
		}
	}
	return simbolo;
}

}
