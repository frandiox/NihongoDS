/*
 * Lluvia.cpp
 *
 * NihongoDS
 *
 */

#include "../../include/interfaz/Lluvia.h"

namespace NIHONGO {


Lluvia::Lluvia() : Minijuego() {
	anterior=0;
	buffer=new char[30];
	contador=0;
	iletra=0;
}

Lluvia::Lluvia(Configuracion config) :
	Minijuego(config) {
	anterior = 0;
	buffer = new char[30];
	contador=0;
	iletra=0;
}

Lluvia::Lluvia(const Lluvia& orig) {
	copy(orig);
}

void Lluvia::pause() {
	if (estado == EJECUCION) {
		estado = PAUSA;
	} else {
		estado = EJECUCION;
		anterior = PA_RTC.Seconds;
	}
}

void Lluvia::update() {
	u8 tiempo;						//Numero de segundos que ha pasado

	if (estado==PAUSA) {
		//Sacar del pause
		if (Pad.Newpress.Start) {
			pause();
			PA_InitText(1,0);
			//Borrar texto de pausa
			PA_OutputSimpleText(1,7,12,"     ");
			PA_OutputSimpleText(1,4,13,"                                          ");
		}
		if (Pad.Newpress.Select) {
			estado=FIN;
		}
	}
	else if (estado==EJECUCION) {
		//Comprobar si se pausara
		if (Pad.Newpress.Start) {
			pause();
			return; //Salir al siguiente ciclo directamente.
		}

		//Comprobar eventos de si hace falta añadir un simbolo o bajar sprites
		tiempo = restarTiempo();
		contador+=tiempo;
		if (contador%T_BAJAR==0 && marcado!=anterior) {
			marcado=anterior;
			bajarSprites();
			if (comprobarSiLleganFinal())
				estado=PARA_TERMINAR;
		}
		if (contador%T_ADDS==0 && marcado2!=anterior) {
			marcado2=anterior;
			anyadirSimbolo();
		}

		//Leer una cadena de teclado y comprobar si hay un simbolo
		leerTeclado();
	}
	else if (estado==PARA_TERMINAR) {
		//Terminar del todo si se pulsa Start
		if (Pad.Newpress.Start) {
			estado=FIN;
			borrarTodo();
		}
	}
}

Lluvia & Lluvia::operator =(const Lluvia & orig) {
	if (this != &orig) {
		copy(orig);
	}
	return *this;
}

void Lluvia::init() {
	estado = EJECUCION;
	anterior=PA_RTC.Seconds;
	PA_InitKeyboard(2);
	PA_KeyboardIn(20,100);

	//Cargar las paletas
	if (config==HIRAGANA) {
		PA_LoadSpritePal(1,0,(void*)hiragana_a_Pal);
		PA_LoadSpritePal(1,1,(void*)hiragana_e_Pal);
		PA_LoadSpritePal(1,2,(void*)hiragana_i_Pal);
		PA_LoadSpritePal(1,3,(void*)hiragana_o_Pal);
		PA_LoadSpritePal(1,4,(void*)hiragana_u_Pal);
		PA_LoadSpritePal(1,5,(void*)hiragana_doble_a_Pal);
		PA_LoadSpritePal(1,6,(void*)hiragana_doble_o_Pal);
		PA_LoadSpritePal(1,7,(void*)hiragana_doble_u_Pal);
	}
	else if (config==KATAKANA) {
		PA_LoadSpritePal(1,0,(void*)katakana_a_Pal);
		PA_LoadSpritePal(1,1,(void*)katakana_e_Pal);
		PA_LoadSpritePal(1,2,(void*)katakana_i_Pal);
		PA_LoadSpritePal(1,3,(void*)katakana_o_Pal);
		PA_LoadSpritePal(1,4,(void*)katakana_u_Pal);
		PA_LoadSpritePal(1,5,(void*)katakana_doble_a_Pal);
		PA_LoadSpritePal(1,6,(void*)katakana_doble_o_Pal);
		PA_LoadSpritePal(1,7,(void*)katakana_doble_u_Pal);
	}
	else if (config==KANJI) {
		PA_LoadSpritePal(1,0,(void*)kanji_1_Pal);
	}
}

Lluvia::~Lluvia() {
	delete[] buffer;
	borrarTodo();
}

void Lluvia::copy(const Lluvia & orig) {
	Minijuego::copy(orig);
	for (int i = 0; i < 30; i++)
		buffer[i] = orig.buffer[i];
	anterior = orig.anterior;
	contador=orig.contador;
	marcado=orig.marcado;
	marcado2=orig.marcado2;
	iletra=orig.iletra;
}

void Lluvia::draw() {
	if (estado==PAUSA) {
		PA_InitText(1,0);
		PA_OutputSimpleText(1,7,12,"PAUSA");
		PA_OutputSimpleText(1,4,13,"Pulse Select para volver al menu principal");
	}
	else if (estado==EJECUCION) {
		PA_InitText(0,0);
		PA_OutputText(0,0,0,"Puntos: %d   ",puntuacion);
		PA_OutputText(0,0,2,"Escribe: %s    ",buffer);
		//dibujarSimbolos(simbolos,config);
	}
	else if (estado==PARA_TERMINAR) {
		PA_InitText(1,0);
		PA_OutputSimpleText(1,7,12,"FIN");
		PA_OutputText(1,4,13,"Puntuacion conseguida: %d   ", puntuacion);
	}
}

void Lluvia::anyadirSimbolo() {
	u8 azarSimbolo = randomSimbolo();
	u8 x;
	u8 indice;
	Simbolo* simbolo = getSimbolo(azarSimbolo,1);

	//Se mira primero en la pila de huecos de indice si hay alguno
	//puesto que si hay alguno, se le asigna al nuevo simbolo a crear
	//si no se le asigna uno nuevo
	if (pilaHuecos.size()>0) {
		indice=pilaHuecos[pilaHuecos.size()-1];
		pilaHuecos.erase(pilaHuecos.size()-1);
	} else {
		indice = simbolos.size();
	}


	if (config==HIRAGANA) {
		//Se coloca en la pantalla de manera aleatoria, pero hay que
		//controlar el ancho del sprite, puesto que los dobles, ocupan
		//el doble de ancho.
		if (azarSimbolo>70) x=PA_RandMax(223);
		else x=PA_RandMax(239);

		((HiraKata*)simbolo)->Hiragana.cargarSprite(Pos_Sprite(indice,x,0));
		((HiraKata*)simbolo)->Hiragana.dibujar();
	}
	else if (config==KATAKANA) {

		//Se coloca en la pantalla de manera aleatoria, pero hay que
		//controlar el ancho del sprite, puesto que los dobles, ocupan
		//el doble de ancho.
		if (azarSimbolo>70) x=PA_RandMax(223);
		else x=PA_RandMax(239);

		((HiraKata*)simbolo)->Katakana.cargarSprite(Pos_Sprite(indice,x,0));
		((HiraKata*)simbolo)->Katakana.dibujar();
	}
	else if (config==KANJI) {

		x = PA_RandMax(239);
		((Kanji*)simbolo)->Simbologia.cargarSprite(Pos_Sprite(indice,x,0));
		((Kanji*)simbolo)->Simbologia.dibujar();
	}
	simbolos.add(simbolo);
}
void Lluvia::bajarSprites() {
	for (u8 i = 0; i < simbolos.size(); i++) {
		if (config == HIRAGANA) {
			HiraKata* simbolo = (HiraKata*) simbolos[i];
			simbolo->Hiragana.mover(simbolo->Hiragana.Posicion->X,
					simbolo->Hiragana.Posicion->Y + GRAVEDAD);
		} else if (config == KATAKANA) {
			HiraKata* simbolo = (HiraKata*) simbolos[i];
			simbolo->Katakana.mover(simbolo->Katakana.Posicion->X,
					simbolo->Katakana.Posicion->Y + GRAVEDAD);
		} else if (config == KANJI) {
			Kanji* simbolo = (Kanji*) simbolos[i];
			simbolo->Simbologia.mover(simbolo->Simbologia.Posicion->X,
					simbolo->Simbologia.Posicion->Y + GRAVEDAD);
		}
	}
}
void Lluvia::comprobarCadena() {
	for (u8 i = 0; i < simbolos.size(); i++) {
		Simbolo* simbolo = simbolos[i];
		if (strcmp(buffer, simbolo->Romaji) == 0) {
			if (config == HIRAGANA) {
				pilaHuecos.add(((HiraKata*) simbolo)->Hiragana.Posicion->Id);
				((HiraKata*) simbolo)->Hiragana.descargarSprite();
			}
			else if (config == KATAKANA) {
				pilaHuecos.add(((HiraKata*) simbolo)->Katakana.Posicion->Id);
				((HiraKata*) simbolo)->Katakana.descargarSprite();
			}
			else if (config == KANJI) {
				pilaHuecos.add(((Kanji*) simbolo)->Simbologia.Posicion->Id);
				((Kanji*) simbolo)->Simbologia.descargarSprite();
			}
			delete simbolos[i];
			simbolos.erase(i);
			i--;
			puntuacion++;
			break;
		}
	}
}


void Lluvia::leerTeclado() {
	char letra;

	letra = PA_CheckKeyboard();
	if (letra > 31) {
		buffer[iletra] = letra;
		iletra++;
	} else if ((letra == PA_BACKSPACE) && iletra) {
		iletra--;
		buffer[iletra] = ' ';
	} else if (letra=='\n') {
		//Cuando se pulsa Enter, se finaliza la entrada de caracteres
		buffer[iletra] = '\0';
		comprobarCadena();
		iletra=0;
	}
}

bool Lluvia::comprobarSiLleganFinal() {
	for (u8 i = 0; i < simbolos.size(); i++) {
		if (config == HIRAGANA) {
			HiraKata* simbolo = (HiraKata*) simbolos[i];
			if (simbolo->Hiragana.Posicion->Y >= 175)
				return true;
		} else if (config == KATAKANA) {
			HiraKata* simbolo = (HiraKata*) simbolos[i];
			if (simbolo->Katakana.Posicion->Y >= 175)
				return true;
		} else if (config == KANJI) {
			Kanji* simbolo = (Kanji*) simbolos[i];
			if (simbolo->Simbologia.Posicion->Y >= 175)
				return true;
		}
	}
	return false;
}
u8 Lluvia::restarTiempo() {
	u8 diferencia;
	if (PA_RTC.Seconds > anterior) {
		diferencia = PA_RTC.Seconds - anterior;
		anterior = PA_RTC.Seconds;
		return diferencia;
	} else if (PA_RTC.Seconds < anterior) {
		diferencia = (PA_RTC.Seconds + 60) - anterior;
		anterior = PA_RTC.Seconds;
		return diferencia;
	}
	return 0;
}

void Lluvia::borrarTodo() {
	//Borrar los simbolos
	for (u8 i=0; i<simbolos.size(); i++) {
		delete simbolos[i];
	}
	simbolos.clear();
	pilaHuecos.clear();
	//Borrar texto de puntuacion mostrada
	PA_InitText(1,0);
	PA_OutputSimpleText(1,7,12,"   ");
	PA_OutputText(1,4,13,"                                  ");
	PA_InitText(0,0);
	PA_OutputText(0,0,0,"                                  ");
	PA_OutputText(0,0,1,"                                                                                          ");
	PA_OutputText(0,0,2,"                                                                                          ");
	//Quita el teclado de la pantalla de abajo
	PA_KeyboardOut();
}


}
