/*
 * Diccionario_Simbolos.cpp
 *
 * NihongoDS
 *
 */

#include "Diccionario_Simbolos.h"
#include <string.h>

namespace NIHONGO {

static bool comprobar_indice(u8 total, u8 indice) {
	if (indice >= 0 && indice < total)
		return true;
	else
		return false;
}

u8 Diccionario_Simbolos::numeroSimbolos (TipoSimbolo tipo) {
	switch (tipo) {
	case SILABA_A: return NUM_SILABA_A;
	case SILABA_E: return NUM_SILABA_E;
	case SILABA_I: return NUM_SILABA_I;
	case SILABA_O: return NUM_SILABA_O;
	case SILABA_U: return NUM_SILABA_U;
	case SILABA_DOBLE_A:
	case SILABA_DOBLE_U:
	case SILABA_DOBLE_O:
		return NUM_SILABA_DOBLE;
	case KANJIS:
		return NUM_KANJIS;
	}
}

//Metodos
Simbolo* Diccionario_Simbolos::getSimbolo(TipoSimbolo tipo, u8 indice) {
	switch (tipo) {
	case SILABA_A:
		if (comprobar_indice(NUM_SILABA_A,indice))
			return silabaA(indice);
		break;
	case SILABA_E:
		if (comprobar_indice(NUM_SILABA_E,indice))
			return silabaE(indice);
		break;
	case SILABA_I:
		if (comprobar_indice(NUM_SILABA_I,indice))
			return silabaI(indice);
		break;
	case SILABA_O:
		if (comprobar_indice(NUM_SILABA_O,indice))
			return silabaO(indice);
		break;
	case SILABA_U:
		if (comprobar_indice(NUM_SILABA_U,indice))
			return silabaU(indice);
		break;
	case SILABA_DOBLE_A:
		if (comprobar_indice(NUM_SILABA_DOBLE,indice))
			return dobleA(indice);
		break;
	case SILABA_DOBLE_U:
		if (comprobar_indice(NUM_SILABA_DOBLE,indice))
			return dobleU(indice);
		break;
	case SILABA_DOBLE_O:
		if (comprobar_indice(NUM_SILABA_DOBLE,indice))
			return dobleO(indice);
		break;
	case KANJIS:
		if (comprobar_indice(NUM_KANJIS,indice)) {
			int sel = (indice / 10);
			switch (sel) {
			case 0:
				return kanji1(indice % 10);
				break;
			case 1:
				return kanji2(indice % 10);
				break;
			case 2:
				return kanji3(indice % 10);
				break;
			case 3:
				return kanji4(indice % 10);
				break;
			}
		}
		break;
	}
}

Simbolo* Diccionario_Simbolos::silabaA(u8 indice) {
	char* romaji = new char[10];
	switch (indice) {
	case 0:
		strcpy(romaji, "a");
		break;
	case 1:
		strcpy(romaji, "ka");
		break;
	case 2:
		strcpy(romaji, "sa");
		break;
	case 3:
		strcpy(romaji, "ta");
		break;
	case 4:
		strcpy(romaji, "na");
		break;
	case 5:
		strcpy(romaji, "ha");
		break;
	case 6:
		strcpy(romaji, "ma");
		break;
	case 7:
		strcpy(romaji, "ya");
		break;
	case 8:
		strcpy(romaji, "ra");
		break;
	case 9:
		strcpy(romaji, "wa");
		break;
	case 10:
		strcpy(romaji, "n");
		break;
	case 11:
		strcpy(romaji, "ga");
		break;
	case 12:
		strcpy(romaji, "za");
		break;
	case 13:
		strcpy(romaji, "da");
		break;
	case 14:
		strcpy(romaji, "ba");
		break;
	case 15:
		strcpy(romaji, "pa");
		break;
	}

	Simbolo* s = new HiraKata(romaji,Sprite(0,OBJ_SIZE_16X16,indice,0,(void*)hiragana_a_Sprite),Sprite(0,OBJ_SIZE_16X16,indice,0,(void*)katakana_a_Sprite),NULL,0);
	delete [] romaji;
	return s;
}

Simbolo* Diccionario_Simbolos::silabaE(u8 indice) {
	char* romaji = new char [10];
	switch (indice) {
	case 0: strcpy(romaji,"e"); break;
	case 1: strcpy(romaji,"ke"); break;
	case 2: strcpy(romaji,"se"); break;
	case 3: strcpy(romaji,"te"); break;
	case 4: strcpy(romaji,"ne"); break;
	case 5: strcpy(romaji,"he"); break;
	case 6: strcpy(romaji,"me"); break;
	case 7: strcpy(romaji,"re"); indice=8; break;
	case 8: strcpy(romaji,"ge"); indice=11; break;
	case 9: strcpy(romaji,"ze"); indice=12; break;
	case 10: strcpy(romaji,"de"); indice=13; break;
	case 11: strcpy(romaji,"be"); indice=14; break;
	case 12: strcpy(romaji,"pe"); indice=15; break;
	}

	Simbolo* s = new HiraKata (romaji,Sprite(0,OBJ_SIZE_16X16,indice,0,(void*)hiragana_e_Sprite),Sprite(0,OBJ_SIZE_16X16,indice,0,(void*)katakana_e_Sprite),NULL,0);
	delete [] romaji;
	return s;
}
Simbolo* Diccionario_Simbolos::silabaI(u8 indice) {
	char* romaji = new char[10];
	switch (indice) {
	case 0:
		strcpy(romaji, "i");
		break;
	case 1:
		strcpy(romaji, "ki");
		break;
	case 2:
		strcpy(romaji, "shi");
		break;
	case 3:
		strcpy(romaji, "chi");
		break;
	case 4:
		strcpy(romaji, "ni");
		break;
	case 5:
		strcpy(romaji, "hi");
		break;
	case 6:
		strcpy(romaji, "mi");
		break;
	case 7:
		strcpy(romaji, "ri");
		indice=8;
		break;
	case 8:
		strcpy(romaji, "gi");
		indice=11;
		break;
	case 9:
		strcpy(romaji, "ji");
		indice=12;
		break;
	case 10:
		strcpy(romaji, "di");
		indice=13;
		break;
	case 11:
		strcpy(romaji, "bi");
		indice=14;
		break;
	case 12:
		strcpy(romaji, "pi");
		indice=15;
		break;
	}

	Simbolo* s = new HiraKata(romaji,Sprite(0,OBJ_SIZE_16X16,indice,0,(void*)hiragana_i_Sprite),Sprite(0,OBJ_SIZE_16X16,indice,0,(void*)katakana_i_Sprite),NULL,0);
	delete [] romaji;
	return s;
}
Simbolo* Diccionario_Simbolos::silabaO(u8 indice) {
	char* romaji = new char[10];
	switch (indice) {
	case 0:
		strcpy(romaji, "o");
		break;
	case 1:
		strcpy(romaji, "ko");
		break;
	case 2:
		strcpy(romaji, "so");
		break;
	case 3:
		strcpy(romaji, "to");
		break;
	case 4:
		strcpy(romaji, "no");
		break;
	case 5:
		strcpy(romaji, "ho");
		break;
	case 6:
		strcpy(romaji, "mo");
		break;
	case 7:
		strcpy(romaji, "yo");
		break;
	case 8:
		strcpy(romaji, "ro");
		break;
	case 9:
		strcpy(romaji, "wo");
		break;
	case 10:
		strcpy(romaji, "go");
		indice=11;
		break;
	case 11:
		strcpy(romaji, "zo");
		indice=12;
		break;
	case 12:
		strcpy(romaji, "do");
		indice=13;
		break;
	case 13:
		strcpy(romaji, "bo");
		indice=14;
		break;
	case 14:
		strcpy(romaji, "po");
		indice=15;
		break;
	}

	Simbolo* s = new HiraKata(romaji,Sprite(0,OBJ_SIZE_16X16,indice,0,(void*)hiragana_o_Sprite),Sprite(0,OBJ_SIZE_16X16,indice,0,(void*)katakana_o_Sprite),NULL,0);
	delete [] romaji;
	return s;
}
Simbolo* Diccionario_Simbolos::silabaU(u8 indice) {
	char* romaji = new char[10];
	switch (indice) {
	case 0:
		strcpy(romaji, "u");
		break;
	case 1:
		strcpy(romaji, "ku");
		break;
	case 2:
		strcpy(romaji, "su");
		break;
	case 3:
		strcpy(romaji, "tsu");
		break;
	case 4:
		strcpy(romaji, "nu");
		break;
	case 5:
		strcpy(romaji, "fu");
		break;
	case 6:
		strcpy(romaji, "mu");
		break;
	case 7:
		strcpy(romaji, "yu");
		break;
	case 8:
		strcpy(romaji, "ru");
		break;
	case 9:
		strcpy(romaji, "gu");
		indice=11;
		break;
	case 10:
		strcpy(romaji, "zu");
		indice=12;
		break;
	case 11:
		strcpy(romaji, "du");
		indice=13;
		break;
	case 12:
		strcpy(romaji, "bu");
		indice=14;
		break;
	case 13:
		strcpy(romaji, "pu");
		indice=15;
		break;
	}

	Simbolo* s = new HiraKata(romaji,Sprite(0,OBJ_SIZE_16X16,indice,0,(void*)hiragana_u_Sprite),Sprite(0,OBJ_SIZE_16X16,indice,0,(void*)katakana_u_Sprite),NULL,0);
	delete [] romaji;
	return s;
}
Simbolo* Diccionario_Simbolos::dobleA(u8 indice) {
	char* romaji = new char[10];
	switch (indice) {
	case 0:
		strcpy(romaji, "kya");
		break;
	case 1:
		strcpy(romaji, "sha");
		break;
	case 2:
		strcpy(romaji, "cha");
		break;
	case 3:
		strcpy(romaji, "nya");
		break;
	case 4:
		strcpy(romaji, "hya");
		break;
	case 5:
		strcpy(romaji, "mya");
		break;
	case 6:
		strcpy(romaji, "rya");
		break;
	case 7:
		strcpy(romaji, "gya");
		break;
	case 8:
		strcpy(romaji, "ja");
		break;
	case 9:
		strcpy(romaji, "ja");
		break;
	case 10:
		strcpy(romaji, "bya");
		break;
	case 11:
		strcpy(romaji, "pya");
		break;
	}

	Simbolo* s = new HiraKata(romaji,Sprite(0,OBJ_SIZE_32X16,indice,0,(void*)hiragana_doble_a_Sprite),Sprite(0,OBJ_SIZE_32X16,indice,0,(void*)katakana_doble_a_Sprite),NULL,0);
	delete [] romaji;
	return s;
}
Simbolo* Diccionario_Simbolos::dobleU(u8 indice) {
	char* romaji = new char[10];
	switch (indice) {
	case 0:
		strcpy(romaji, "kyu");
		break;
	case 1:
		strcpy(romaji, "shu");
		break;
	case 2:
		strcpy(romaji, "chu");
		break;
	case 3:
		strcpy(romaji, "nyu");
		break;
	case 4:
		strcpy(romaji, "hyu");
		break;
	case 5:
		strcpy(romaji, "myu");
		break;
	case 6:
		strcpy(romaji, "ryu");
		break;
	case 7:
		strcpy(romaji, "gyu");
		break;
	case 8:
		strcpy(romaji, "ju");
		break;
	case 9:
		strcpy(romaji, "ju");
		break;
	case 10:
		strcpy(romaji, "byu");
		break;
	case 11:
		strcpy(romaji, "pyu");
		break;
	}

	Simbolo* s = new HiraKata(romaji,Sprite(0,OBJ_SIZE_32X16,indice,0,(void*)hiragana_doble_u_Sprite),Sprite(0,OBJ_SIZE_32X16,indice,0,(void*)katakana_doble_u_Sprite),NULL,0);
	delete [] romaji;
	return s;
}
Simbolo* Diccionario_Simbolos::dobleO(u8 indice) {
	char* romaji = new char[10];
	switch (indice) {
	case 0:
		strcpy(romaji, "kyo");
		break;
	case 1:
		strcpy(romaji, "sho");
		break;
	case 2:
		strcpy(romaji, "cho");
		break;
	case 3:
		strcpy(romaji, "nyo");
		break;
	case 4:
		strcpy(romaji, "hyo");
		break;
	case 5:
		strcpy(romaji, "myo");
		break;
	case 6:
		strcpy(romaji, "ryo");
		break;
	case 7:
		strcpy(romaji, "gyo");
		break;
	case 8:
		strcpy(romaji, "jo");
		break;
	case 9:
		strcpy(romaji, "jo");
		break;
	case 10:
		strcpy(romaji, "byo");
		break;
	case 11:
		strcpy(romaji, "pyo");
		break;
	}

	Simbolo* s = new HiraKata(romaji,Sprite(0,OBJ_SIZE_32X16,indice,0,(void*)hiragana_doble_o_Sprite),Sprite(0,OBJ_SIZE_32X16,indice,0,(void*)katakana_doble_o_Sprite),NULL,0);
	delete [] romaji;
	return s;
}
Simbolo* Diccionario_Simbolos::kanji1(u8 indice) {
	char* romaji = new char[15];
	char* sp = new char[15];

	switch (indice) {
	case 0:
		strcpy(romaji,"ichi");
		strcpy(sp,"uno");
		break;
	case 1:
		strcpy(romaji,"ni");
		strcpy(sp,"dos");
		break;
	case 2:
		strcpy(romaji,"san");
		strcpy(sp,"tres");
		break;
	case 3:
		strcpy(romaji,"shi");
		strcpy(sp,"cuatro");
		break;
	case 4:
		strcpy(romaji,"go");
		strcpy(sp,"cinco");
		break;
	case 5:
		strcpy(romaji,"roku");
		strcpy(sp,"seis");
		break;
	case 6:
		strcpy(romaji,"sichi");
		strcpy(sp,"siete");
		break;
	case 7:
		strcpy(romaji,"hachi");
		strcpy(sp,"ocho");
		break;
	case 8:
		strcpy(romaji,"ku");
		strcpy(sp,"nueve");
		break;
	case 9:
		strcpy(romaji,"jyu");
		strcpy(sp,"diez");
		break;
	}

	Simbolo* s = new Kanji (romaji,Sprite(0,OBJ_SIZE_16X16,indice,0,(void*)kanji_1_Sprite),sp);
	delete [] romaji;
	delete [] sp;
	return s;
}
Simbolo* Diccionario_Simbolos::kanji2(u8 indice) {
	char* romaji = new char[15];
	char* sp = new char[15];

	switch (indice) {
	case 0:
		strcpy(romaji,"hyaku");
		strcpy(sp,"cien");
		break;
	case 1:
		strcpy(romaji,"sen");
		strcpy(sp,"mil");
		break;
	case 2:
		strcpy(romaji,"hito");
		strcpy(sp,"persona");
		break;
	case 3:
		strcpy(romaji,"te");
		strcpy(sp,"mano");
		break;
	case 4:
		strcpy(romaji,"me");
		strcpy(sp,"ojo");
		break;
	case 5:
		strcpy(romaji,"kuchi");
		strcpy(sp,"boca");
		break;
	case 6:
		strcpy(romaji,"mimi");
		strcpy(sp,"oreja");
		break;
	case 7:
		strcpy(romaji,"ashi");
		strcpy(sp,"pie");
		break;
	case 8:
		strcpy(romaji,"ten");
		strcpy(sp,"cielo");
		break;
	case 9:
		strcpy(romaji,"ku");
		strcpy(sp,"cielo");
		break;
	}

	Simbolo* s = new Kanji (romaji,Sprite(0,OBJ_SIZE_16X16,indice,0,(void*)kanji_2_Sprite),sp);
	delete [] romaji;
	delete [] sp;
	return s;
}
Simbolo* Diccionario_Simbolos::kanji3(u8 indice) {
	char* romaji = new char[15];
	char* sp = new char[15];

	switch (indice) {
	case 0:
		strcpy(romaji,"nichi");
		strcpy(sp,"dia");
		break;
	case 1:
		strcpy(romaji,"getsu");
		strcpy(sp,"mes");
		break;
	case 2:
		strcpy(romaji,"mizu");
		strcpy(sp,"agua");
		break;
	case 3:
		strcpy(romaji,"ame");
		strcpy(sp,"lluvia");
		break;
	case 4:
		strcpy(romaji,"ta");
		strcpy(sp,"arrozal");
		break;
	case 5:
		strcpy(romaji,"yama");
		strcpy(sp,"montaña");
		break;
	case 6:
		strcpy(romaji,"kawa");
		strcpy(sp,"rio");
		break;
	case 7:
		strcpy(romaji,"tsuchi");
		strcpy(sp,"tierra");
		break;
	case 8:
		strcpy(romaji,"moku");
		strcpy(sp,"arbol");
		break;
	case 9:
		strcpy(romaji,"hayashi");
		strcpy(sp,"bosque");
		break;
	}

	Simbolo* s = new Kanji (romaji,Sprite(0,OBJ_SIZE_16X16,indice,0,(void*)kanji_3_Sprite),sp);
	delete [] romaji;
	delete [] sp;
	return s;
}
Simbolo* Diccionario_Simbolos::kanji4(u8 indice) {
	char* romaji = new char[15];
	char* sp = new char[15];

	switch (indice) {
	case 0:
		strcpy(romaji,"mori");
		strcpy(sp,"bosque");
		break;
	case 1:
		strcpy(romaji,"take");
		strcpy(sp,"bambu");
		break;
	case 2:
		strcpy(romaji,"gaku");
		strcpy(sp,"aprender");
		break;
	case 3:
		strcpy(romaji,"kou");
		strcpy(sp,"escuela");
		break;
	case 4:
		strcpy(romaji,"aka");
		strcpy(sp,"rojo");
		break;
	case 5:
		strcpy(romaji,"shiro");
		strcpy(sp,"blanco");
		break;
	case 6:
		strcpy(romaji,"ao");
		strcpy(sp,"azul");
		break;
	case 7:
		strcpy(romaji,"oo");
		strcpy(sp,"grande");
		break;
	case 8:
		strcpy(romaji,"chii");
		strcpy(sp,"pequeño");
		break;
	case 9:
		strcpy(romaji,"dan");
		strcpy(sp,"hombre");
		break;
	}

	Simbolo* s = new Kanji (romaji,Sprite(0,OBJ_SIZE_16X16,indice,0,(void*)kanji_4_Sprite),sp);
	delete [] romaji;
	delete [] sp;
	return s;
}

}
