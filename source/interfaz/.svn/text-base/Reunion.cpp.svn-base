/*
 * Reunion.cpp
 *
 * NihongoDS
 *
 */

#include "Reunion.h"

namespace NIHONGO {
//Constructores
Reunion::Reunion():Minijuego() {
	fase=MOSTRAR_SIMBOLOS;
	intentos=0;
}

Reunion::Reunion(Configuracion config):Minijuego(config){
	fase=MOSTRAR_SIMBOLOS;
	intentos=0;
}

Reunion::Reunion(const Reunion& orig) {
	copy(orig);
}

Reunion::~Reunion() {
	borrarTodo();
}

//Metodos
void Reunion::init() {
	estado=EJECUCION;
	fase=MOSTRAR_SIMBOLOS;

	//Cargar paletas
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

void Reunion::pause() {
	if (estado == EJECUCION) {
		estado = PAUSA;
	} else {
		estado = EJECUCION;
	}
}

void Reunion::draw() {
	//Borrar la pantalla.
	PA_InitText(1,0);
	PA_OutputText(1,12,10,"               ");
	PA_OutputText(1,7,11,"                                                                        ");
	if (estado==EJECUCION) {
		PA_InitText(1,0);
		PA_OutputText(1,0,4,"                                                                   ");

		//Dibujar la puntuacion
		PA_InitText(0,0);
		PA_OutputText(0,0,0,"Puntos: %d   ",puntuacion);
		if (fase==MOSTRAR_SIMBOLOS) {

		}
		else if (fase==ELEGIR_SIMBOLOS) {
			PA_OutputText(1,12,10,"ENCUENTRALOS");
				PA_OutputText(1,7,11,"Tienes %d   intentos para encontrar los simbolos.",NUM_SIMBOLOS-intentos);
		}
		else if (fase==MENU) {
			PA_InitText(1,0);
			PA_OutputText(1,0,4,"Pulse A para otra ronda. Si quiere terminar pulse Select.");
		}
	}
	else if (estado==PAUSA) {
		PA_InitText(1,0);
		PA_OutputText(1,12,10,"PAUSA");
		PA_OutputText(1,7,11,"Pulse Select para abandonar.");
	}
	else if (estado==PARA_TERMINAR) {
		PA_InitText(1,0);
		PA_OutputText(1,12,10,"FIN");
		PA_OutputText(1,7,11,"Pulse Select para salir al menu.");
	}
}

void Reunion::update() {
	if (estado==EJECUCION) {
		if (fase==MOSTRAR_SIMBOLOS) {
			elegirSimbolosMostrar();
			esperar(3);
			fase=ELEGIR_SIMBOLOS;
			elegirSimbolosElegir();
			ocultarSimbolos(1);
			return;
		}
		else if (fase==ELEGIR_SIMBOLOS) {
			if(Pad.Newpress.Start) {
				pause();
				return;
			}
			comprobarSpritesTocados();
			if(estanTodosTocados()) {
				fase=MENU;
			}
		}
		else if (fase==MENU) {
			ocultarSimbolos(0);
			if(Pad.Newpress.A) {
				intentos=0;
				fase=MOSTRAR_SIMBOLOS;
			}
			if (Pad.Newpress.Select) {
				estado=PARA_TERMINAR;
			}
		}
	}
	else if (estado==PAUSA) {
		if (Pad.Newpress.Start)
			pause();
		if (Pad.Newpress.Select)
			estado=FIN;
	}
	else if (estado==PARA_TERMINAR) {
		estado=FIN;
	}
}

//Operadores
Reunion& Reunion::operator= (const Reunion& orig) {
	if (this!=&orig) {
		copy(orig);
	}
	return *this;
}

//Metodos del juego
void Reunion::elegirSimbolosMostrar() {
	//Vaciar listas
	celdas.clear();
	simbolos.clear();

	cargarPaletas(1);
	//Generar los simbolos aleatoriamente
	//sin repetir ninguno
	simbolosPorAzar(NUM_SIMBOLOS,1);

	//Mostrar en pantalla los simbolos
	mostrarSimbolos(1);
}

void Reunion::ocultarSimbolos(u8 screen) {
	if (screen==1) {
		for (u8 i=0; i<NUM_SIMBOLOS; i++) {
			if (config==HIRAGANA) {
				HiraKata* simbolo = (HiraKata*)simbolos[i];
				simbolo->Hiragana.descargarSprite();
			}
			else if (config==KATAKANA) {
				HiraKata* simbolo = (HiraKata*)simbolos[i];
				simbolo->Katakana.descargarSprite();
			}
			else if (config==KANJI) {
				Kanji* simbolo = (Kanji*)simbolos[i];
				simbolo->Simbologia.descargarSprite();
			}
		}
	} else {
		for (u8 i=NUM_SIMBOLOS; i<simbolos.size(); i++) {
			if (config==HIRAGANA) {
				HiraKata* simbolo = (HiraKata*)simbolos[i];
				simbolo->Hiragana.descargarSprite();
			}
			else if (config==KATAKANA) {
				HiraKata* simbolo = (HiraKata*)simbolos[i];
				simbolo->Katakana.descargarSprite();
			}
			else if (config==KANJI) {
				Kanji* simbolo = (Kanji*)simbolos[i];
				simbolo->Simbologia.descargarSprite();
			}
		}
	}
}

void Reunion::simbolosPorAzar(u8 numSimbolos, u8 screen) {
	u8 azar;
	bool repetido;
	//Caso especial cuando estemos en la pantalla 0, puesto que
	//repetidos nos tiene que salir a la fuerza con los primeros simbolos
	//puesto que son los que el usuario tiene que encontrar.
	u8 indiceEmpezarBuscar = (screen==1) ? 0 : NUM_SIMBOLOS;

	for (u8 i=0; i<numSimbolos; i++) {
		//Generar numero aleatorio mientras este repetido
		do {
			repetido=false;
			azar=randomSimbolo();
			for (u8 ind=indiceEmpezarBuscar; ind<celdas.size(); ind++) {
				if (celdas[ind].numero==azar)
					repetido=true;
			}
		}while(repetido);
		//Añadir simbolo al vector
		Simbolo* simbolo = getSimbolo(azar,screen);
		simbolos.add(simbolo);
		//Añadir la celda correspondiente
		CeldaSimbolo celda;
		celda.numero=azar;
		celda.tocado=0;
		celda.esDoble=0;
		//Comprobar si el simbolo es de doble ancho o no
		if (config==HIRAGANA || config==KATAKANA) {
			if (azar>70) celda.esDoble=1;
		}
		celdas.add(celda);
	}
}

void Reunion::elegirSimbolosElegir() {
	cargarPaletas(0);

	//Coger los simbolos mostrados en la pantalla de arriba
	for (u8 i=0; i<NUM_SIMBOLOS; i++) {
		Simbolo* simbolo = getSimbolo(celdas[i].numero,0);
		simbolos.add(simbolo);
		CeldaSimbolo celda;
		celda.numero = celdas[i].numero;
		celda.esDoble = celdas[i].esDoble;
		celda.tocado = 0;
		celdas.add(celda);
	}
	//Generar los simbolos aleatoriamente
	simbolosPorAzar(NUM_SIMBOLOS,0);

	//Mostrar en pantalla los simbolos
	mostrarSimbolos(0);
}

void Reunion::mostrarSimbolos(u8 screen) {
	//Se muestran los primeros simbolos del vector
	//en la pantalla de arriba
	u8 x, y;
	if (screen==1) {
		for (u8 i=0; i<NUM_SIMBOLOS; i++) {
			//Obtenemos las coordenadas donde dibujar por azar
			y = PA_RandMax(175);
			x = (celdas[i].esDoble) ? PA_RandMax(223) : PA_RandMax(239);

			//Cargamos el sprite y lo dibujamos
			if (config==HIRAGANA) {
				HiraKata* simbolo = (HiraKata*) simbolos[i];
				simbolo->Hiragana.cargarSprite(Pos_Sprite(i,x,y));
				simbolo->Hiragana.dibujar();
			}
			else if (config==KATAKANA) {
				HiraKata* simbolo = (HiraKata*) simbolos[i];
				simbolo->Katakana.cargarSprite(Pos_Sprite(i,x,y));
				simbolo->Katakana.dibujar();
			}
			else if (config==KANJI) {
				Kanji* simbolo = (Kanji*) simbolos[i];
				simbolo->Simbologia.cargarSprite(Pos_Sprite(i,x,y));
				simbolo->Simbologia.dibujar();
			}
		}
	}
	//Y en la pantalla de abajo se muestran los ultimos simbolos
	//del vector
	else {
		for (u8 i=NUM_SIMBOLOS; i<simbolos.size(); i++) {
			//Obtenemos las coordenadas donde dibujar por azar
			y = PA_RandMax(175);
			x = (celdas[i].esDoble) ? PA_RandMax(223) : PA_RandMax(239);

			//Cargamos el sprite y lo dibujamos
			if (config==HIRAGANA) {
				HiraKata* simbolo = (HiraKata*) simbolos[i];
				simbolo->Hiragana.cargarSprite(Pos_Sprite(i-NUM_SIMBOLOS,x,y));
				simbolo->Hiragana.dibujar();
			}
			else if (config==KATAKANA) {
				HiraKata* simbolo = (HiraKata*) simbolos[i];
				simbolo->Katakana.cargarSprite(Pos_Sprite(i-NUM_SIMBOLOS,x,y));
				simbolo->Katakana.dibujar();
			}
			else if (config==KANJI) {
				Kanji* simbolo = (Kanji*) simbolos[i];
				simbolo->Simbologia.cargarSprite(Pos_Sprite(i-NUM_SIMBOLOS,x,y));
				simbolo->Simbologia.dibujar();
			}
		}
	}
}

void Reunion::comprobarSpritesTocados() {
	for (u8 i=NUM_SIMBOLOS; i<simbolos.size(); i++) {
		if(PA_SpriteTouched(i-NUM_SIMBOLOS) && !celdas[i].tocado) {
			celdas[i].tocado=1;
			intentos++;
			if (aciertaConSprite(i)) {
				puntuacion++;
			}
			else {
				if (puntuacion>0)
					puntuacion--;
			}
		}
	}
}

bool Reunion::aciertaConSprite(u8 indice) {
	if (indice>=NUM_SIMBOLOS) {
		bool encontrado=false;
		for (u8 i=0; i<NUM_SIMBOLOS; i++) {
			if (strcmp(simbolos[i]->Romaji,simbolos[indice]->Romaji)==0) {
				encontrado=true;
				break;
			}
		}
		return encontrado;
	}
	else
		return false;
}

void Reunion::esperar(u8 segundos) {
	u32 contador=segundos*60;
	for (u32 i=0; i<contador; i++)
		PA_WaitForVBL();
}

void Reunion::borrarTodo() {
	for (u8 i=0; i<simbolos.size(); i++) {
		if (config==HIRAGANA) {
			HiraKata* simbolo = (HiraKata*) simbolos[i];
			simbolo->Hiragana.descargarSprite();
		}
		else if (config==KATAKANA) {
			HiraKata* simbolo = (HiraKata*) simbolos[i];
			simbolo->Katakana.descargarSprite();
		}
		else if (config==KANJI) {
			Kanji* simbolo = (Kanji*) simbolos[i];
			simbolo->Simbologia.descargarSprite();
		}
		delete simbolos[i];
	}

	//Borrar texto de la pantalla
	PA_InitText(1,0);
	PA_OutputText(1,12,10,"               ");
	PA_OutputText(1,7,11,"                                                                        ");
	PA_InitText(0,0);
	PA_OutputText(0,0,0,"                         ");
}

bool Reunion::estanTodosTocados() {
	return (intentos>=NUM_SIMBOLOS);
}

//Metodos privados
void Reunion::copy(const Reunion& orig) {
	Minijuego::copy(orig);
	fase=orig.fase;
	celdas=orig.celdas;
	intentos=orig.intentos;
}

void Reunion::cargarPaletas(u8 screen) {
	if (config==HIRAGANA) {
		PA_LoadSpritePal(screen,0,(void*)hiragana_a_Pal);
		PA_LoadSpritePal(screen,1,(void*)hiragana_e_Pal);
		PA_LoadSpritePal(screen,2,(void*)hiragana_i_Pal);
		PA_LoadSpritePal(screen,3,(void*)hiragana_o_Pal);
		PA_LoadSpritePal(screen,4,(void*)hiragana_u_Pal);
		PA_LoadSpritePal(screen,5,(void*)hiragana_doble_a_Pal);
		PA_LoadSpritePal(screen,6,(void*)hiragana_doble_o_Pal);
		PA_LoadSpritePal(screen,7,(void*)hiragana_doble_u_Pal);
	}
	else if (config==KATAKANA) {
		PA_LoadSpritePal(screen,0,(void*)katakana_a_Pal);
		PA_LoadSpritePal(screen,1,(void*)katakana_e_Pal);
		PA_LoadSpritePal(screen,2,(void*)katakana_i_Pal);
		PA_LoadSpritePal(screen,3,(void*)katakana_o_Pal);
		PA_LoadSpritePal(screen,4,(void*)katakana_u_Pal);
		PA_LoadSpritePal(screen,5,(void*)katakana_doble_a_Pal);
		PA_LoadSpritePal(screen,6,(void*)katakana_doble_o_Pal);
		PA_LoadSpritePal(screen,7,(void*)katakana_doble_u_Pal);
	}
	else if (config==KANJI) {
		PA_LoadSpritePal(screen,0,(void*)kanji_1_Pal);
	}
}



}
