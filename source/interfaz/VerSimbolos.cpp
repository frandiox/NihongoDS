/*
 * VerSimbolos.cpp
 *
 * NihongoDS
 *
 */

#include "VerSimbolos.h"

namespace NIHONGO {

static void clearSprites (u8 min, u8 max, u8 screen) {
	for (u8 i=min; i<=max; i++)  {
		PA_DeleteGfx(screen,PA_GetSpriteGfx(screen,i));
		PA_DeleteSprite(screen,i);
	}
}

VerSimbolos::VerSimbolos() {
	actual=HIRAGANA_SIMPLE;
	indiceTocado=-1;
	flecha=0;
	salir=0;
}

VerSimbolos::VerSimbolos (const VerSimbolos& orig) {
	copy(orig);
}

VerSimbolos::~VerSimbolos() {
	borrarTodo();
}

void VerSimbolos::copy (const VerSimbolos& orig) {
	simbolos=orig.simbolos;
	actual=orig.actual;
	indiceTocado=orig.indiceTocado;
	flecha=orig.flecha;
	salir=0;
}

//Operador de asignacion
VerSimbolos& VerSimbolos::operator= (const VerSimbolos& orig) {
	if (this!=&orig) {
		copy(orig);
	}
	return *this;
}

//Metodos
void VerSimbolos::init() {
	actual=HIRAGANA_SIMPLE;
	indiceTocado=-1;
	salir=0;
	flecha=0;
	dibujarBotones();
	cargaSimbolos();
}

void VerSimbolos::draw() {
	//Dibuja la flecha
	dibujarFlecha();
}

void VerSimbolos::update() {
	//Controla la flecha
	moverFlecha();
	if (Pad.Newpress.A) {
		//Borrar memoria de sprites
		for (u8 i=0; i<simbolos.size(); i++) {
			delete simbolos[i];
		}
		switch (flecha) {
		case 0: actual=HIRAGANA_SIMPLE; cargaSimbolos(); break;
		case 1: actual=HIRAGANA_DOBLE; cargaSimbolos(); break;
		case 2: actual=KATAKANA_SIMPLE; cargaSimbolos(); break;
		case 3: actual=KATAKANA_DOBLE; cargaSimbolos(); break;
		case 4: actual=TODOS_KANJIS; cargaSimbolos(); break;
		case 5: salir=1; return; break;
		}
	}

	//Comprueba si se ha tocado algun simbolo
	//si se ha tocado, actualizar ficha del simbolo
	if(comprobarSimboloTocado())
		dibujarFichaSimbolo();
}



//Metodos privados
void VerSimbolos::cargaSimbolos() {
	simbolos.clear();
	u8 id=0;
	//Cargar las paletas
	if (actual==HIRAGANA_SIMPLE || actual==HIRAGANA_DOBLE) {
		PA_LoadSpritePal(0,0,(void*)hiragana_a_Pal);
		PA_LoadSpritePal(0,1,(void*)hiragana_e_Pal);
		PA_LoadSpritePal(0,2,(void*)hiragana_i_Pal);
		PA_LoadSpritePal(0,3,(void*)hiragana_o_Pal);
		PA_LoadSpritePal(0,4,(void*)hiragana_u_Pal);
		PA_LoadSpritePal(0,5,(void*)hiragana_doble_a_Pal);
		PA_LoadSpritePal(0,6,(void*)hiragana_doble_o_Pal);
		PA_LoadSpritePal(0,7,(void*)hiragana_doble_u_Pal);
	}
	else if (actual==KATAKANA_SIMPLE || actual==KATAKANA_DOBLE) {
		PA_LoadSpritePal(0,0,(void*)katakana_a_Pal);
		PA_LoadSpritePal(0,1,(void*)katakana_e_Pal);
		PA_LoadSpritePal(0,2,(void*)katakana_i_Pal);
		PA_LoadSpritePal(0,3,(void*)katakana_o_Pal);
		PA_LoadSpritePal(0,4,(void*)katakana_u_Pal);
		PA_LoadSpritePal(0,5,(void*)katakana_doble_a_Pal);
		PA_LoadSpritePal(0,6,(void*)katakana_doble_o_Pal);
		PA_LoadSpritePal(0,7,(void*)katakana_doble_u_Pal);
	}
	else if (actual==TODOS_KANJIS) {
		PA_LoadSpritePal(0,0,(void*)kanji_1_Pal);
	}


	if (actual==HIRAGANA_SIMPLE) {
		for (u8 i=0; i<5; i++) {
			for (u8 j=0; j<Diccionario_Simbolos::numeroSimbolos((TipoSimbolo)i); j++) {
				Simbolo* simbolo = Diccionario_Simbolos::getSimbolo((TipoSimbolo)i,j);
				HiraKata* hSimbolo = (HiraKata*)simbolo;
				hSimbolo->Hiragana.Screen=0;
				hSimbolo->Hiragana.Paleta=i;
				hSimbolo->Hiragana.cargarSprite(Pos_Sprite(id,j<<4,i<<4));
				hSimbolo->Hiragana.dibujar();
				simbolos.add(simbolo);
				id++;
			}
		}
	} else if (actual==HIRAGANA_DOBLE){
		for (u8 i=0; i<3; i++) {
			u8 x,y;		//Para calcular las posiciones de los sprites
			for (u8 j=0; j<12; j++) {
				Simbolo* simbolo = Diccionario_Simbolos::getSimbolo((TipoSimbolo)(i+5),j);
				HiraKata* hSimbolo = (HiraKata*)simbolo;

				//No caben todos los sprites en la misma fila, solo caben ocho en una misma fila
				//en la pantalla de la consola. Por lo que debemos repartirlos en dos filas.
				if (j>7) {
					x=(j-8)<<5; y=(i<<5)+16;
				}
				else {
					x=j<<5; y=i<<5;
				}
				hSimbolo->Hiragana.Screen=0;
				hSimbolo->Hiragana.Paleta=i+5;
				hSimbolo->Hiragana.cargarSprite(Pos_Sprite(id,x,y));
				hSimbolo->Hiragana.dibujar();
				simbolos.add(simbolo);
				id++;
			}
		}
	} else if (actual==KATAKANA_SIMPLE) {
		for (u8 i=0; i<5; i++) {
			for (u8 j=0; j<Diccionario_Simbolos::numeroSimbolos((TipoSimbolo)i); j++) {
				Simbolo* simbolo = Diccionario_Simbolos::getSimbolo((TipoSimbolo)i,j);
				HiraKata* hSimbolo = (HiraKata*)simbolo;
				hSimbolo->Katakana.Screen=0;
				hSimbolo->Katakana.Paleta=i;
				hSimbolo->Katakana.cargarSprite(Pos_Sprite(id,j<<4,i<<4));
				hSimbolo->Katakana.dibujar();
				simbolos.add(simbolo);
				id++;
			}
		}
	} else if (actual==KATAKANA_DOBLE) {
		for (u8 i=0; i<3; i++) {
			u8 x,y;		//Para calcular las posiciones de los sprites
			for (u8 j=0; j<12; j++) {
				Simbolo* simbolo = Diccionario_Simbolos::getSimbolo((TipoSimbolo)(i+5),j);
				HiraKata* hSimbolo = (HiraKata*)simbolo;

				//No caben todos los sprites en la misma fila, solo caben ocho en una misma fila
				//en la pantalla de la consola. Por lo que debemos repartirlos en dos filas.
				if (j>7) {
					x=(j-8)<<5; y=(i<<5)+16;
				}
				else {
					x=j<<5; y=i<<5;
				}
				hSimbolo->Katakana.Screen=0;
				hSimbolo->Katakana.Paleta=i+5;
				hSimbolo->Katakana.cargarSprite(Pos_Sprite(id,x,y));
				hSimbolo->Katakana.dibujar();
				simbolos.add(simbolo);
				id++;
			}
		}
	} else if (actual==TODOS_KANJIS) {
		for (u8 i=0; i<8; i++) {
			for (u8 j=0; j<NUM_KANJI_FILA; j++) {
				Simbolo* simbolo1 = Diccionario_Simbolos::getSimbolo(KANJIS,i*10+j);
				Kanji* simbolo = (Kanji*)simbolo1;
				simbolo->Simbologia.cargarSprite(Pos_Sprite(id,i<<4,j<<4));
				simbolo->Simbologia.dibujar();
				simbolos.add(simbolo);
				id++;
			}
		}
	}
}

void VerSimbolos::dibujarFichaSimbolo() {
	if (indiceTocado>-1) {
		char buffer[300];   //Buffer de texto

		switch (actual){
		case HIRAGANA_SIMPLE:
		case HIRAGANA_DOBLE:
			PA_InitText(1,0);
			sprintf(buffer,"Romaji: %s", simbolos[indiceTocado]->Romaji);
			PA_OutputText(1,3,5,"%s",buffer);
			break;
		case KATAKANA_SIMPLE:
		case KATAKANA_DOBLE:
			PA_InitText(1,0);
			sprintf(buffer,"Romaji: %s", simbolos[indiceTocado]->Romaji);
			PA_OutputText(1,3,5,"%s",buffer);
			break;
		case TODOS_KANJIS:
			PA_InitText(1,0);
			sprintf(buffer,"Romaji: %s", simbolos[indiceTocado]->Romaji);
			PA_OutputText(1,3,5,"%s",buffer);
			sprintf(buffer,"Traduccion: %s",((Kanji*)simbolos[indiceTocado])->Trad_Sp);
			PA_OutputText(1,3,6,"%s",buffer);
			break;
		}
	}
}

bool VerSimbolos::comprobarSimboloTocado() {
	for (u8 i=0; i<simbolos.size(); i++) {
		if (PA_SpriteTouched(i)) {
			indiceTocado=i;
			return true;
		}
	}
	return false;
}

void VerSimbolos::dibujarBotones() {
	//Cargar paletas
	PA_LoadSpritePal(1,9,(void*)flecha_Pal);
	PA_LoadSpritePal(1,10,(void*)boton_hiragana_simple_Pal);
	PA_LoadSpritePal(1,11,(void*)boton_hiragana_doble_Pal);
	PA_LoadSpritePal(1,12,(void*)boton_katakana_simple_Pal);
	PA_LoadSpritePal(1,13,(void*)boton_katakana_doble_Pal);
	PA_LoadSpritePal(1,14,(void*)boton_kanjis_Pal);
	PA_LoadSpritePal(1,15,(void*)boton_salir_Pal);
	//Cargar los sprites
	PA_CreateSprite(1,1,(void*)flecha_Sprite,OBJ_SIZE_16X16,1,9,0,117);
	PA_CreateSprite(1,2,(void*)boton_hiragana_simple_Sprite,OBJ_SIZE_64X32,1,10,16,117);
	PA_CreateSprite(1,3,(void*)boton_hiragana_doble_Sprite,OBJ_SIZE_64X32,1,11,16,160);
	PA_CreateSprite(1,4,(void*)boton_katakana_simple_Sprite,OBJ_SIZE_64X32,1,12,96,117);
	PA_CreateSprite(1,5,(void*)boton_katakana_doble_Sprite,OBJ_SIZE_64X32,1,13,96,160);
	PA_CreateSprite(1,6,(void*)boton_kanjis_Sprite,OBJ_SIZE_64X32,1,14,176,117);
	PA_CreateSprite(1,7,(void*)boton_salir_Sprite,OBJ_SIZE_64X32,1,15,176,160);
}

void VerSimbolos::moverFlecha() {
	if(Pad.Newpress.Up || Pad.Newpress.Left) {
		if (flecha>0) flecha--;
	}
	if (Pad.Newpress.Down || Pad.Newpress.Right) {
		if (flecha<5) flecha++;
	}
}

void VerSimbolos::dibujarFlecha() {
	u8 x,y;
	switch (flecha) {
	case 0:
		x=0; y=117;
		break;
	case 1:
		x=0; y=160;
		break;
	case 2:
		x=80; y=117;
		break;
	case 3:
		x=80; y=160;
		break;
	case 4:
		x=160; y=117;
		break;
	case 5:
		x=160; y=160;
		break;
	}
	PA_SetSpriteXY(1,1,x,y);
}

void VerSimbolos::borrarTodo() {
	//Borrar memoria de sprites

	clearSprites(9,15,1);	//Borra los botones y la flecha de la pantalla de arriba
	//Borrar textos
	//PA_ClearTextBg(1);
	PA_InitText(1,0);
	PA_OutputText(1,3,5,"                                                    ");
}

bool VerSimbolos::Salir() {
	return (salir==1);
}

}
