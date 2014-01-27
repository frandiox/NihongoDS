/*
 * ejSprite.cpp
 *
 * NihongoDS
 *
 */

#include "Sprite.h"
#include "all_gfx.h"

using namespace NIHONGO;

//Constantes
#define CANT_SINGLE 16
#define NUM_SIMBOLOS 5
#define DBL_NUM 3
#define DBL_SIZE 12
#define KANJ_NUM 4
#define KANJ_SIZE 10

//Variables y objetos
Sprite** hira_sim;
Sprite** hira_dobl;
Sprite** kanji;
char* cadPOS = NULL;
char* cadSPR = NULL;


//--------------- Metodos -----------------
void initSystems() {
	// Initialize PAlib
	PA_Init();
	// Initializes a standard VBL
	PA_InitVBL();
}

void initObjects() {
	hira_sim = new Sprite*[NUM_SIMBOLOS];
	for (u8 i = 0; i < NUM_SIMBOLOS; i++) {
		hira_sim[i] = new Sprite[CANT_SINGLE];
	}
	for (u8 i = 0; i < NUM_SIMBOLOS; i++) {
		for (u8 j = 0; j < CANT_SINGLE; j++) {
			hira_sim[i][j] = Sprite(0, OBJ_SIZE_16X16,j,  0,selector(i));
		}
	}

	hira_dobl = new Sprite* [DBL_NUM];
	for (u8 i = 0; i < DBL_NUM; i++) {
		hira_dobl[i] = new Sprite[DBL_SIZE];
	}
	for (u8 i = 0; i < DBL_NUM; i++) {
		for (u8 j = 0; j < DBL_SIZE; j++) {
			hira_dobl[i][j] = Sprite(0, OBJ_SIZE_32X16,j, 0,selector(i+5));
		}
	}

	kanji = new Sprite* [KANJ_NUM];
	for (u8 i = 0; i < KANJ_NUM; i++) {
		kanji[i] = new Sprite[KANJ_SIZE];
	}
	for (u8 i = 0; i < KANJ_NUM; i++) {
		for (u8 j = 0; j < KANJ_SIZE; j++) {
			kanji[i][j] = Sprite(1, OBJ_SIZE_16X16,j, 1,selector(i+8));
		}
	}
}

void loadContent() {
	PA_LoadSpritePal(0, 0, (void*) hiragana_e_Pal);
	PA_LoadSpritePal(1, 1, (void*) kanji_1_Pal);
}

void loadObjects() {
	u8 id = 0;
	for (u8 i = 0; i < NUM_SIMBOLOS; i++) {
		for (u8 j = 0; j < CANT_SINGLE; j++) {
			hira_sim[i][j].cargarSprite(Pos_Sprite(id, j << 4, i << 4));
			id++;
		}
	}

	for (u8 i = 0; i < DBL_NUM; i++) {
		for (u8 j = 0; j < DBL_SIZE; j++) {
			if (j < 8) {
				hira_dobl[i][j].cargarSprite(Pos_Sprite(id, (j << 5), (5 << 4)
						+ (i << 5)));
			} else {
				u8 j2 = j - 8;
				hira_dobl[i][j].cargarSprite(Pos_Sprite(id, j2 << 5, (6 << 4)
						+ (i << 5)));
			}
			id++;
		}
	}

	id = 0;
	for (u8 i = 0; i < KANJ_NUM; i++) {
		for (u8 j = 0; j < KANJ_SIZE; j++) {
			kanji[i][j].cargarSprite(Pos_Sprite(id, j << 4, i << 4));
			id++;
		}
	}
}

void predraw() {
	PA_InitText(1, 2);
	for (u8 i = 0; i < NUM_SIMBOLOS; i++) {
		for (u8 j = 0; j < CANT_SINGLE; j++) {
			hira_sim[i][j].dibujar();
		}
	}

	for (u8 i = 0; i < DBL_NUM; i++) {
		for (u8 j = 0; j < DBL_SIZE; j++) {
			hira_dobl[i][j].dibujar();
		}
	}

	for (u8 i = 0; i < KANJ_NUM; i++) {
		for (u8 j = 0; j < KANJ_SIZE; j++) {
			kanji[i][j].dibujar();
		}
	}
}

void draw() {

}

void update() {
}

void offSystems() {

}

void destroyObjects() {
	if (cadPOS != NULL)
		delete[] cadPOS;
	if (cadSPR != NULL)
		delete[] cadSPR;
}
