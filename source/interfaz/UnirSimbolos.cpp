/*
 * UnirSimbolos.cpp
 *
 * NihongoDS
 *
 */

#include "../../include/interfaz/UnirSimbolos.h"

namespace NIHONGO {

UnirSimbolos::UnirSimbolos() : Minijuego () {
	izqTocado=-1;
	dchaTocado=-1;
	intentos=0;
}

UnirSimbolos::~UnirSimbolos() {
	PA_DeleteBg(0,3);
	borrarTodo();
}
UnirSimbolos::UnirSimbolos(Configuracion config):Minijuego(config) {
	izqTocado=-1;
	dchaTocado=-1;
	intentos=0;

}

UnirSimbolos::UnirSimbolos (const UnirSimbolos& orig) {
	copy(orig);
}

void UnirSimbolos::copy(const UnirSimbolos& orig) {
	Minijuego::copy(orig);
	cadenas=orig.cadenas;
	paresCorrectos=orig.paresCorrectos;
	izqTocado=orig.izqTocado;
	dchaTocado=orig.dchaTocado;
	intentos=orig.intentos;
}

//Metodos
void UnirSimbolos::init() {

	simbolos.clear();
	cadenas.clear();
	paresCorrectos.clear();
	estado=EJECUCION;
	izqTocado=dchaTocado=-1;
	intentos=0;

	//Inicializar fondo
	PA_InitFake16bitBg(0,3);

	//Cargar las paletas
	if (config==HIRAGANA) {
		PA_LoadSpritePal(0,0,(void*)hiragana_a_Pal);
		PA_LoadSpritePal(0,1,(void*)hiragana_e_Pal);
		PA_LoadSpritePal(0,2,(void*)hiragana_i_Pal);
		PA_LoadSpritePal(0,3,(void*)hiragana_o_Pal);
		PA_LoadSpritePal(0,4,(void*)hiragana_u_Pal);
		PA_LoadSpritePal(0,5,(void*)hiragana_doble_a_Pal);
		PA_LoadSpritePal(0,6,(void*)hiragana_doble_o_Pal);
		PA_LoadSpritePal(0,7,(void*)hiragana_doble_u_Pal);
	}
	else if (config==KATAKANA) {
		PA_LoadSpritePal(0,0,(void*)katakana_a_Pal);
		PA_LoadSpritePal(0,1,(void*)katakana_e_Pal);
		PA_LoadSpritePal(0,2,(void*)katakana_i_Pal);
		PA_LoadSpritePal(0,3,(void*)katakana_o_Pal);
		PA_LoadSpritePal(0,4,(void*)katakana_u_Pal);
		PA_LoadSpritePal(0,5,(void*)katakana_doble_a_Pal);
		PA_LoadSpritePal(0,6,(void*)katakana_doble_o_Pal);
		PA_LoadSpritePal(0,7,(void*)katakana_doble_u_Pal);
	}
	else if (config==KANJI) {
		PA_LoadSpritePal(0,0,(void*)kanji_1_Pal);
	}

	elegirSimbolos();
	elegirCadenas();
}

void UnirSimbolos::pause() {
	if (estado==EJECUCION) estado=PAUSA;
	else if (estado==PAUSA) estado=EJECUCION;
}

void UnirSimbolos::draw() {
	//Dibujar cadenas
	PA_InitText(0,0);
	for (u8 i=0; i<cadenas.size(); i++) {
		PA_OutputText(0,22,1+(i*3),"%s",cadenas[i]);
	}

	if (estado==EJECUCION) {
		PA_InitText(1,0);
		PA_OutputSimpleText(1,12,12,"UNE SIMBOLOS");
		PA_OutputSimpleText(1,4,13,"Une pareja de simbolo con su escritura romaji");
		PA_OutputText(1,0,14,"Puntuacion: %d   ", puntuacion);
		PA_OutputText(1,0,15,"Intentos: %d   ",UNION_NUM_SIMBOLOS-intentos);
	}
	else if (estado==PAUSA) {
		PA_InitText(1,0);
		PA_OutputSimpleText(1,12,12,"PAUSA");
		PA_OutputSimpleText(1,4,13,"Pulse Select para volver al menu principal");
	}
	else if (estado==PARA_TERMINAR) {
		PA_InitText(1,0);
		PA_OutputSimpleText(1,12,12,"TERMINADO");
		PA_OutputSimpleText(1,4,13,"Pulse Select para volver al menu principal");
		PA_OutputSimpleText(1,4,14,"Pulse A para jugar otra ronda.");
		PA_OutputText(1,0,15,"Puntuacion conseguida: %d   ", puntuacion);
	}
}

void UnirSimbolos::update() {
	if (estado==EJECUCION) {
		if (Pad.Newpress.Start)
			pause();
		comprobarTocados();
		if (izqTocado!=-1 && dchaTocado!=-1) {
			u8 i=izqTocado, j=dchaTocado;
			if(verSiHaAcertado()) {
				//Si se acierta, se dibuja una linea verde entre simbolo y romaji
				dibujarLinea(32,8+(i*24),176,8+(j*24),COLOR_VERDE);
				dibujarLinea(32,8+(i*24)+1,176,8+(j*24)+1,COLOR_VERDE);
			}
			else {
				//Si no, se baja la puntuacion
				puntuacion--;
				izqTocado = dchaTocado = -1;
				intentos++;
				if (intentos==UNION_NUM_SIMBOLOS) {
					estado=PARA_TERMINAR;
				}
			}
		}
		//Si ya se han creado todos los pares correctos, se ha ganado el juego
		if (paresCorrectos.size()==UNION_NUM_SIMBOLOS) {
			estado=PARA_TERMINAR;
		}
	}
	else if (estado==PAUSA) {
		if (Pad.Newpress.Start)
			pause();
		if (Pad.Newpress.Select)
			estado=FIN;
	}
	else if (estado==PARA_TERMINAR) {
		if(Pad.Newpress.Select) {
			estado=FIN;
			if (puntuacion<0) puntuacion=0;
		}
		if (Pad.Newpress.A) {
			init();
		}
	}
}

//Operador de asignacion
UnirSimbolos& UnirSimbolos::operator= (const UnirSimbolos& orig) {
	if (this!=&orig) {
		copy(orig);
	}
	return *this;
}

void UnirSimbolos::borrarTodo() {
	PA_ClearTextBg(0);
	PA_ClearTextBg(1);
	for (u8 i=0; i<simbolos.size(); i++) {
		delete simbolos[i];
	}
}

void UnirSimbolos::dibujarLinea(u8 x1, u8 y1, u8 x2, u8 y2, Color color) {
	PA_DrawFake16bitLine(0,x1,y1,x2,y2,PA_RGB(color.red,color.green,color.blue));
}

bool UnirSimbolos::verSiHaAcertado() {
	Simbolo* simbolo = simbolos[izqTocado];
	if (strcmp(simbolo->Romaji,cadenas[dchaTocado])==0) {
		//Se añade el par correcto
		Pares par;
		par.izda=izqTocado;
		par.dcha=dchaTocado;
		paresCorrectos.add(par);
		//Se suma puntuacion y se resetean los tocados
		puntuacion++;
		izqTocado = dchaTocado = -1;
		return true;
	}
	return false;
}

void UnirSimbolos::comprobarTocados() {
	for (u8 i=0; i<simbolos.size(); i++) {
		if (PA_SpriteTouched(i)) {
			if (!estaYaMarcado(LADO_IZDA,i))
				izqTocado=i;
		}
	}
	for (u8 i=0; i<cadenas.size(); i++) {
		if (Stylus.Newpress) {
			if (Stylus.X>=176 && Stylus.X<=240 && Stylus.Y>=(8+(i*24)) && Stylus.Y<=(16+(i*24))) {
				if (!estaYaMarcado(LADO_DCHA,i)) dchaTocado=i;
			}
		}
	}
}

bool UnirSimbolos::estaYaMarcado(u8 lado, u8 indice) {
	bool encontrado=false;
	if (lado==LADO_IZDA) {
		for (u8 i=0; i<paresCorrectos.size() && !encontrado; i++) {
			if (paresCorrectos[i].izda==indice)
				encontrado=true;
		}
	}
	else if (lado==LADO_DCHA) {
		for (u8 i=0; i<paresCorrectos.size() && !encontrado; i++) {
			if (paresCorrectos[i].dcha==indice)
				encontrado=true;
		}
	}
	return encontrado;
}

void UnirSimbolos::elegirCadenas() {
	vector<u8> yaElegidos;	//Para no repetir cadenas
	u8 azar;

	while (cadenas.size()<simbolos.size()) {
		 azar=PA_RandMax(simbolos.size()-1);
		 bool encontrado=false;
		 for (u8 i=0; i<yaElegidos.size() && !encontrado; i++) {
			 if(azar==yaElegidos[i]) encontrado=true;
		 }
		 if (!encontrado) {
			 yaElegidos.add(azar);
			 Simbolo* simbolo = simbolos[azar];
			 cadenas.add(simbolo->Romaji);
		 }
	}
}

void UnirSimbolos::elegirSimbolos() {
	int* azarSacado = new int [UNION_NUM_SIMBOLOS];//Se van guardando en este vector los numeros de azar que han salido, para no repetir simbolos
	u8 azar;

	//Generar los numeros aleatorios para elegir los simbolos
	for (u8 i=0; i<UNION_NUM_SIMBOLOS; i++) {
		bool repetido=false;
		do {
			repetido=false;
			azar=randomSimbolo();
			for (u8 j=0; j<i; j++) {
				if (azar==azarSacado[j])
					repetido=true;
			}
		}while(repetido);
		azarSacado[i]=azar;
	}

	//Crea los simbolos a partir de los numeros aleatorios
	for (u8 i=0; i<UNION_NUM_SIMBOLOS; i++) {
		Simbolo* simbolo = getSimbolo(azarSacado[i],0);
		if (config==HIRAGANA) {
			HiraKata* hSimbolo = (HiraKata*)simbolo;
			hSimbolo->Hiragana.cargarSprite(Pos_Sprite(i,32,8+(i*24)));
			hSimbolo->Hiragana.dibujar();
		}
		else if (config==KATAKANA) {
			HiraKata* hSimbolo = (HiraKata*)simbolo;
			hSimbolo->Katakana.cargarSprite(Pos_Sprite(i,32,8+(i*24)));
			hSimbolo->Katakana.dibujar();
		}
		else if (config==KANJI) {
			Kanji* kSimbolo = (Kanji*)simbolo;
			kSimbolo->Simbologia.cargarSprite(Pos_Sprite(i,32,8+(i*24)));
			kSimbolo->Simbologia.dibujar();
		}
		simbolos.add(simbolo);
	}
	delete [] azarSacado;
}

}
