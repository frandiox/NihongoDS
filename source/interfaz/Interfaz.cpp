/*
 * Interfaz.cpp
 *
 * NihongoDS
 *
 */

#include "Interfaz.h"

namespace NIHONGO {

Interfaz::Interfaz() {
	Goto(MENU_PRINCIPAL);
	leccion = NULL;
	juego = NULL;
	tabla.cargar("nihongo.dat");
	config_juego = C_EMPTY;
	vistaSimbolos=NULL;
}

Interfaz::Interfaz(const Interfaz & orig) {
	pantalla_actual = orig.pantalla_actual;
	cambio = orig.cambio;
	leccion = orig.leccion;
	juego = orig.juego;
	tabla = orig.tabla;
	config_juego = orig.config_juego;
	flecha = orig.flecha;
	vistaSimbolos = orig.vistaSimbolos;
}

void Interfaz::update_lecciones() {
	if (pulsadoFlecha(6)) {
		if (leccion != NULL)
			delete leccion;
		leccion = NULL;
		del_lecciones();
		Goto(MENU_PRINCIPAL);
	} else if (pulsadoFlecha(0)){
		leccion = new Fonetica();
		leccion->init();
		del_lecciones();
	} else if (pulsadoFlecha(1)){
		leccion = new Morfologia();
		leccion->init();
		del_lecciones();
	} else if (pulsadoFlecha(2)){
		leccion = new Morfologia2();
		leccion->init();
		del_lecciones();
	} else if (pulsadoFlecha(3)){
		leccion = new Escritura();
		leccion->init();
		del_lecciones();
	}  else if (pulsadoFlecha(4)){
		leccion = new Sintaxis();
		leccion->init();
		del_lecciones();
	} else if (pulsadoFlecha(5)){
		leccion = new Kanjis();
		leccion->init();
		del_lecciones();
	}
}

Interfaz & Interfaz::operator =(const Interfaz & orig) {
	if (this != &orig) {
		pantalla_actual = orig.pantalla_actual;
		cambio = orig.cambio;
		leccion = orig.leccion;
		juego = orig.juego;
		tabla = orig.tabla;
		config_juego = orig.config_juego;
		flecha = orig.flecha;
		vistaSimbolos=orig.vistaSimbolos;
	}
	return *this;
}

void Interfaz::update() {
	moverFlecha();
	if (juego == NULL && leccion == NULL) {
		switch (pantalla_actual) {
		case MENU_PRINCIPAL:
			update_principal();
			break;
		case LECCIONES:
			update_lecciones();
			break;
		case MINIJUEGOS:
			update_minijuegos();
			break;
		case CONFIG_MINIJUEGOS:
			update_configuracion();
			break;
		case PUNTUACIONES:
			update_puntuaciones();
			break;
		case SIMBOLOS:
			update_simbolos();
			break;
		case DICCIONARIO:
			update_dict();
			break;
		}
	} else if (juego != NULL) {
		juego->update();
		if (juego->getEstado() == FIN) {
			u32 puntuacion = juego->getPuntuacion();
			delete juego;
			juego = NULL;
			anyadirAPuntuacion(puntuacion);
			Goto(MENU_PRINCIPAL);
		}
	}else if (leccion != NULL){
		leccion->update();
		EstadoLeccion Est_temp = leccion->getEstado();
		if (Est_temp == lec_FIN || Est_temp == lec_SELECCION) {
			delete leccion;
			leccion = NULL;
			if (Est_temp == lec_FIN)
				Goto(MENU_PRINCIPAL);
			else
				Goto(LECCIONES);
		}
	}
}

void Interfaz::draw() {
	if (juego == NULL && leccion == NULL) {
		if (cambio) {
			cambio = 0;
			switch (pantalla_actual) {
			case MENU_PRINCIPAL:
				draw_principal();
				break;
			case LECCIONES:
				draw_lecciones();
				break;
			case MINIJUEGOS:
				draw_minijuegos();
				break;
			case CONFIG_MINIJUEGOS:
				draw_configuracion();
				break;
			case PUNTUACIONES:
				draw_puntuaciones();
				break;
			case SIMBOLOS:
				draw_simbolos();
				break;
			case DICCIONARIO:
				draw_dict();
				break;
			}
		}
	} else if (juego != NULL) {
		juego->draw();
	} else if (leccion != NULL){
		leccion->draw();
	}
}

Interfaz::~Interfaz() {

}

void Interfaz::load_dict() {

}

void Interfaz::del_dict() {

}

void Interfaz::draw_dict() {
	//TODO Dibujar pantalla de diccionario
}

void Interfaz::update_minijuegos() {
	if (pulsadoFlecha(3)) {
		if (juego != NULL)
			delete juego;
		juego = NULL;
		del_minijuegos();
		Goto(MENU_PRINCIPAL);
	} else if (pulsadoFlecha(0)) {
		juego = new Lluvia(config_juego);
		juego->init();
		del_minijuegos();
	} else if (pulsadoFlecha(1)) {
		juego = new UnirSimbolos (config_juego);
		del_minijuegos();
		juego->init();
	} else if (pulsadoFlecha(2)) {
		juego = new Reunion(config_juego);
		juego->init();
		del_minijuegos();
	}
}

void Interfaz::load_configuracion() {
	//Dibujar informacion
	PA_InitText(0, 0);
	PA_OutputSimpleText(0, 0, 0,"Que simbolos apareceran en el minijuego");
	//Cargar paletas
	PA_LoadSpritePal(SCREEN_DOWN, 0, (void*) (boton_hiragana_Pal));
	PA_LoadSpritePal(SCREEN_DOWN, 1, (void*) (boton_katakana_Pal));
	PA_LoadSpritePal(SCREEN_DOWN, 2, (void*) (boton_kanjis_Pal));
	//Cargar fondos
	PA_LoadBackground(SCREEN_DOWN, 3, &fondo_abajo);
	PA_LoadBackground(SCREEN_UP, 3, &logo_final);
	//Cargar sprites
	u8 i = 0;
	PA_CreateSprite(SCREEN_DOWN, i, (void*) (boton_hiragana_Sprite),
			OBJ_SIZE_64X32, 1, i, BUTTON_MARGIN_LEFT, BUTTON_SPACE + (32 +BUTTON_SPACE) * i); i++;
	PA_CreateSprite(SCREEN_DOWN, i, (void*)(boton_katakana_Sprite), OBJ_SIZE_64X32, 1, i, BUTTON_MARGIN_LEFT, BUTTON_SPACE + (32 + BUTTON_SPACE) * i); i++;
	PA_CreateSprite(SCREEN_DOWN, i, (void*)(boton_kanjis_Sprite), OBJ_SIZE_64X32, 1, i, BUTTON_MARGIN_LEFT, BUTTON_SPACE + (32 + BUTTON_SPACE) * i); i++;
	//Cargar boton de atras
	PA_LoadSpritePal(SCREEN_DOWN, i, (void*)(boton_atras_Pal));
	PA_CreateSprite(SCREEN_DOWN, i, (void*)(boton_atras_Sprite), OBJ_SIZE_64X32, 1, i, 191, 159);
	i++;
	//Dibujar flecha
	PA_LoadSpritePal(SCREEN_DOWN, i, (void*)(flecha_Pal));
	PA_CreateSprite(SCREEN_DOWN, i, (void*)(flecha_Sprite), OBJ_SIZE_16X16, 1, i, BUTTON_MARGIN_LEFT-16, BUTTON_SPACE + (32 + BUTTON_SPACE) * flecha);
}

void Interfaz::del_configuracion() {
	clearSprites(SCREEN_DOWN,4);
	PA_DeleteBg(SCREEN_UP,3);
	PA_DeleteBg(SCREEN_DOWN,3);
	//Quitar texto
	PA_InitText(0, 0);
	PA_OutputSimpleText(0, 0, 0,"                                                                   ");
}

void Interfaz::draw_configuracion() {

	if (flecha>3)			flecha=0;
	else if (flecha==3)		PA_SetSpriteXY(SCREEN_DOWN, 4, 175, 159);
	else					PA_SetSpriteXY(SCREEN_DOWN, 4, BUTTON_MARGIN_LEFT-16, BUTTON_SPACE + (32 + BUTTON_SPACE) * flecha);
}

void Interfaz::update_configuracion() {
	if (pulsadoFlecha(0)) {
		config_juego=HIRAGANA;
		del_configuracion();
		Goto(MINIJUEGOS);
	}
	else if (pulsadoFlecha(1)) {
		config_juego=KATAKANA;
		del_configuracion();
		Goto(MINIJUEGOS);
	}
	else if (pulsadoFlecha(2)) {
		/*config_juego=KANJI;
		del_configuracion();
		Goto(MINIJUEGOS);*/
	}
	else if (pulsadoFlecha(3)) {
		del_configuracion();
		Goto(MENU_PRINCIPAL);
	}
}

void Interfaz::update_simbolos() {
	if (vistaSimbolos!=NULL){
		vistaSimbolos->update();
		if (vistaSimbolos->Salir()) {
			del_simbolos();
			Goto(MENU_PRINCIPAL);
		}
	}
}

void Interfaz::update_dict() {
	// TODO Actualizar pantalla de simbolos
}

void Interfaz::load_puntuaciones() {
	PA_LoadBackground(SCREEN_UP,3,&fondo_abajo);
	PA_LoadSpritePal(SCREEN_DOWN,0,(void*)boton_atras_Pal);
	PA_CreateSprite(SCREEN_DOWN,0,(void*)boton_atras_Sprite,OBJ_SIZE_64X32,1,0,191,159);
}

void Interfaz::del_puntuaciones() {
	PA_DeleteBg(SCREEN_UP,3);
	clearSprites(SCREEN_DOWN,0);
	PA_InitText(1,0);
	for (u8 i=0; i<24; i++)
		PA_OutputSimpleText(1,0,i,"                                                          ");
}

void Interfaz::draw_puntuaciones() {
	// TODO Actualizar pantalla de puntuaciones
	PA_InitText(1,0);
	PA_OutputText(1,12,0,"PUNTUACIONES");
	PA_OutputText(1,0,1,"Nombre \t\t\t  Puntuacion");
	for (u8 i=0; i<PTOS_NUM_FILAS; i++) {
		Puntuacion p = tabla.get(i);
		PA_OutputText(1,0,i+2,"%s \t\t\t\t\t %d",p.nombre,p.puntos);
	}
}

void Interfaz::load_minijuegos() {
	//Imprimir informacion
	PA_InitText(0,0);
	PA_OutputSimpleText(0,0,0,"Elija un minijuego");
	//Cargar paletas
	PA_LoadSpritePal(SCREEN_DOWN, 0, (void*) (boton_lluvia_Pal));
	PA_LoadSpritePal(SCREEN_DOWN, 1, (void*) (boton_memvis_Pal));
	PA_LoadSpritePal(SCREEN_DOWN, 2, (void*) (boton_reunion_Pal));
	//Cargar fondos
	PA_LoadBackground(SCREEN_DOWN, 3, &fondo_abajo);
	PA_LoadBackground(SCREEN_UP, 3, &logo_final);
	//Cargar sprites
	u8 i = 0;
	PA_CreateSprite(SCREEN_DOWN, i, (void*) (boton_lluvia_Sprite),
			OBJ_SIZE_64X32, 1, i, BUTTON_MARGIN_LEFT, BUTTON_SPACE + (32 +BUTTON_SPACE) * i); i++;
	PA_CreateSprite(SCREEN_DOWN, i, (void*)(boton_memvis_Sprite), OBJ_SIZE_64X32, 1, i, BUTTON_MARGIN_LEFT, BUTTON_SPACE + (32 + BUTTON_SPACE) * i); i++;
	PA_CreateSprite(SCREEN_DOWN, i, (void*)(boton_reunion_Sprite), OBJ_SIZE_64X32, 1, i, BUTTON_MARGIN_LEFT, BUTTON_SPACE + (32 + BUTTON_SPACE) * i); i++;

	//Cargar boton de atras
	PA_LoadSpritePal(SCREEN_DOWN, i, (void*)(boton_atras_Pal));
	PA_CreateSprite(SCREEN_DOWN, i, (void*)(boton_atras_Sprite), OBJ_SIZE_64X32, 1, i, 191, 159);
	i++;
	//Dibujar flecha
	PA_LoadSpritePal(SCREEN_DOWN, i, (void*)(flecha_Pal));
	PA_CreateSprite(SCREEN_DOWN, i, (void*)(flecha_Sprite), OBJ_SIZE_16X16, 1, i, BUTTON_MARGIN_LEFT-16, BUTTON_SPACE + (32 + BUTTON_SPACE) * flecha);
}

void Interfaz::del_minijuegos() {
	clearSprites(SCREEN_DOWN,4);
	PA_DeleteBg(SCREEN_UP,3);
	PA_DeleteBg(SCREEN_DOWN,3);
	//Borrar texto
	PA_InitText(0,0);
	PA_OutputSimpleText(0,0,0,"                           ");
}

void Interfaz::draw_minijuegos() {

    if (flecha>3)			flecha=0;
    else if (flecha==3)		PA_SetSpriteXY(SCREEN_DOWN, 4,  175, 159);
    else					PA_SetSpriteXY(SCREEN_DOWN, 4,  BUTTON_MARGIN_LEFT-16, BUTTON_SPACE + (32 + BUTTON_SPACE) * flecha);
}

void Interfaz::load_lecciones() {
	//Cargar paletas
	PA_LoadSpritePal(SCREEN_DOWN, 0, (void*)(boton_fonetica_Pal));
	PA_LoadSpritePal(SCREEN_DOWN, 1, (void*)(boton_morfologia_Pal));
	PA_LoadSpritePal(SCREEN_DOWN, 2, (void*)(boton_morf2_Pal));
	PA_LoadSpritePal(SCREEN_DOWN, 3, (void*)(boton_escritura_Pal));
	PA_LoadSpritePal(SCREEN_DOWN, 4, (void*)(boton_sintaxis_Pal));
	PA_LoadSpritePal(SCREEN_DOWN, 5, (void*)(boton_kanjis_Pal));
	//Cargar fondos
	PA_LoadBackground(SCREEN_DOWN, 3, &fondo_abajo);
	PA_LoadBackground(SCREEN_UP, 3, &lecciones_0);
	//Cargar sprites
	u8 i = 0;
	PA_CreateSprite(SCREEN_DOWN, i, (void*)(boton_fonetica_Sprite), OBJ_SIZE_64X32, 1, i, ((int)(i / 4)) * BUTTON_COL2_SPACE + BUTTON_COL1_SPACE, BUTTON_SPACE + (32 + BUTTON_SPACE) * i);
	i++;
	PA_CreateSprite(SCREEN_DOWN, i, (void*)(boton_morfologia_Sprite), OBJ_SIZE_64X32, 1, i, (i / 4) * BUTTON_COL2_SPACE + BUTTON_COL1_SPACE, BUTTON_SPACE + (32 + BUTTON_SPACE) * i);
	i++;
	PA_CreateSprite(SCREEN_DOWN, i, (void*)(boton_morf2_Sprite), OBJ_SIZE_64X32, 1, i, (i / 4) * BUTTON_COL2_SPACE + BUTTON_COL1_SPACE, BUTTON_SPACE + (32 + BUTTON_SPACE) * i);
	i++;
	PA_CreateSprite(SCREEN_DOWN, i, (void*)(boton_escritura_Sprite), OBJ_SIZE_64X32, 1, i, (i / 4) * BUTTON_COL2_SPACE + BUTTON_COL1_SPACE, BUTTON_SPACE + (32 + BUTTON_SPACE) * i);
	i++;
	PA_CreateSprite(SCREEN_DOWN, i, (void*)(boton_sintaxis_Sprite), OBJ_SIZE_64X32, 1, i, (i / 4) * BUTTON_COL2_SPACE + BUTTON_COL1_SPACE, BUTTON_SPACE + (32 + BUTTON_SPACE) * (i-4));
	i++;
	PA_CreateSprite(SCREEN_DOWN, i, (void*)(boton_kanjis_Sprite), OBJ_SIZE_64X32, 1, i, (i / 4) * BUTTON_COL2_SPACE + BUTTON_COL1_SPACE, BUTTON_SPACE + (32 + BUTTON_SPACE) * (i-4));
	i++;
	//Cargar boton de atras
	PA_LoadSpritePal(SCREEN_DOWN, i, (void*)(boton_atras_Pal));
	PA_CreateSprite(SCREEN_DOWN, i, (void*)(boton_atras_Sprite), OBJ_SIZE_64X32, 1, i, 191, 159);
	i++;
	//Dibujar flecha
	PA_LoadSpritePal(SCREEN_DOWN, i, (void*)(flecha_Pal));
	PA_CreateSprite(SCREEN_DOWN, i, (void*)(flecha_Sprite), OBJ_SIZE_16X16, 1, i, (flecha / 4) * BUTTON_COL2_SPACE + BUTTON_COL1_SPACE - 16, BUTTON_SPACE + (32 + BUTTON_SPACE) * (flecha+(flecha/4)*-4));
}

void Interfaz::del_lecciones() {
	clearSprites(SCREEN_DOWN,8);
	PA_DeleteBg(SCREEN_UP,3);
	PA_DeleteBg(SCREEN_DOWN,3);
}

void Interfaz::draw_lecciones()
{
	if (flecha>6) 		flecha=0;
	if (flecha==6) 		PA_SetSpriteXY(SCREEN_DOWN, 7, 175, 159);
	else 	 			PA_SetSpriteXY(SCREEN_DOWN, 7, (flecha / 4) * BUTTON_COL2_SPACE + BUTTON_COL1_SPACE - 16, BUTTON_SPACE + (32 + BUTTON_SPACE) * (flecha+(flecha/4)*-4));
}

void Interfaz::load_simbolos() {
	if (vistaSimbolos!=NULL) vistaSimbolos->init();
	else {
		vistaSimbolos = new VerSimbolos ();
		vistaSimbolos->init();
	}
}

void Interfaz::del_simbolos() {
	if (vistaSimbolos!=NULL) delete vistaSimbolos;
	vistaSimbolos=NULL;
}

void Interfaz::draw_simbolos()
{
	if (vistaSimbolos!=NULL) vistaSimbolos->draw();
}

void Interfaz::update_puntuaciones()
{
	if (PA_SpriteTouched(0)) {
		del_puntuaciones();
		Goto(MENU_PRINCIPAL);
	}
}

char *Interfaz::print()
{
	char *buffer = new char[20];
	sprintf(buffer, "Pantalla:%d", pantalla_actual);
	return buffer;
}

void Interfaz::load_principal() {
	//Cargar paletas
	PA_LoadSpritePal(SCREEN_DOWN, 0, (void*)(boton_lecciones_Pal));
	PA_LoadSpritePal(SCREEN_DOWN, 1, (void*)(boton_minijuegos_Pal));
	PA_LoadSpritePal(SCREEN_DOWN, 2, (void*)(boton_puntuaciones_Pal));
	PA_LoadSpritePal(SCREEN_DOWN, 3, (void*)(boton_simbolos_Pal));
	PA_LoadSpritePal(SCREEN_DOWN, 4, (void*)(boton_dict_Pal));
	PA_LoadSpritePal(SCREEN_DOWN, 5, (void*)(flecha_Pal));
	//Pintar fondos
	PA_LoadBackground(SCREEN_DOWN, 3, &fondo_abajo);
	PA_LoadBackground(SCREEN_UP, 3, &logo_final);
	//Pintar botones
	PA_CreateSprite(SCREEN_DOWN, 0, (void*)(boton_lecciones_Sprite), OBJ_SIZE_64X32, 1, 0, BUTTON_MARGIN_LEFT, 0);
	PA_CreateSprite(SCREEN_DOWN, 1, (void*)(boton_minijuegos_Sprite), OBJ_SIZE_64X32, 1, 1, BUTTON_MARGIN_LEFT, BUTTON_SPACE + 32);
	PA_CreateSprite(SCREEN_DOWN, 2, (void*)(boton_puntuaciones_Sprite), OBJ_SIZE_64X32, 1, 2, BUTTON_MARGIN_LEFT, (BUTTON_SPACE + 32)*2);
	PA_CreateSprite(SCREEN_DOWN, 3, (void*)(boton_simbolos_Sprite), OBJ_SIZE_64X32, 1, 3, BUTTON_MARGIN_LEFT, (BUTTON_SPACE + 32)*3);
	PA_CreateSprite(SCREEN_DOWN, 4, (void*)(boton_dict_Sprite), OBJ_SIZE_64X32, 1, 4, BUTTON_MARGIN_LEFT, (BUTTON_SPACE + 32)*4);
	PA_CreateSprite(SCREEN_DOWN,5, (void*)flecha_Sprite,OBJ_SIZE_16X16,1,5,BUTTON_MARGIN_LEFT-16,0);
}

void Interfaz::del_principal() {
	clearSprites(SCREEN_DOWN,5);
	PA_DeleteBg(SCREEN_UP,3);
	PA_DeleteBg(SCREEN_DOWN,3);
}

void Interfaz::draw_principal()
{
	//Pintar flecha
	if (flecha>4)	flecha=0;
	PA_SetSpriteXY(SCREEN_DOWN,5,BUTTON_MARGIN_LEFT-16,(BUTTON_SPACE + 32)*flecha);
}

void Interfaz::Goto(Pantallas pantalla)
{
	pantalla_actual = pantalla;
	cambio = 1;
	flecha=0;

	switch(pantalla_actual) {
	case MENU_PRINCIPAL: load_principal(); break;
	case LECCIONES: load_lecciones(); break;
	case MINIJUEGOS: load_minijuegos(); break;
	case CONFIG_MINIJUEGOS: load_configuracion(); break;
	case PUNTUACIONES: load_puntuaciones(); break;
	case SIMBOLOS: load_simbolos(); break;
	case DICCIONARIO: load_dict(); break;
	}
}

void Interfaz::update_principal()
{
	if(pulsadoFlecha(0)){
		del_principal();
		Goto (LECCIONES);
	}else if(pulsadoFlecha(1)){
		del_principal();
		Goto (CONFIG_MINIJUEGOS);
	} else if (pulsadoFlecha(2)) {
		del_principal();
		Goto(PUNTUACIONES);
	} else if (pulsadoFlecha(3)) {
		del_principal();
		Goto(SIMBOLOS);
	}

}

void Interfaz::clearSprites(u8 screen, u8 numSprite)
{
	for (int i=0; i<=numSprite; i++) {
		PA_DeleteGfx(screen,PA_GetSpriteGfx(screen,i));
		PA_DeleteSprite(screen,i);
	}
}

void Interfaz::moverFlecha () {
	if (Pad.Newpress.Up || Pad.Newpress.Left)    {
		flecha--;
		cambio=1;
	}
	if (Pad.Newpress.Down || Pad.Newpress.Right) {
		flecha++;
		cambio=1;
	}
}

bool Interfaz::pulsadoFlecha(u8 posicion) {
	return Pad.Newpress.A && flecha==posicion;
}

void Interfaz::anyadirAPuntuacion(u32 puntuacion) {
	char nombre[]={' ',' ',' ',' ',' '};
	u8 iletra=0;
	char letra;

	//Dibujar
	PA_InitText(1,0);
	PA_OutputText(1,0,0,"Introduzca su nombre para almacenar la puntuacion.");
	PA_OutputText(1,0,2,"Puntuacion conseguida: %d    ",puntuacion);
	PA_OutputText(1,0,3,"Pulse Enter para terminar de introducir nombre");

	//Mostrar teclado
	PA_InitKeyboard(2);
	PA_KeyboardIn(20,100);

	PA_InitText(0,0);
	do {
		PA_OutputText(0,0,0,"Nombre: %s   ",nombre);
		letra = PA_CheckKeyboard();
		if (iletra<5) {
			if (letra > 31) {
				nombre[iletra] = letra;
				iletra++;
			} else if ((letra == PA_BACKSPACE) && iletra) {
				iletra--;
				nombre[iletra] = ' ';
			}
		}
		else {
			letra='\n';
		}
		PA_WaitForVBL();
	}while(letra!='\n');

	//Añadir puntuacion a la tabla
	tabla.add(nombre,puntuacion);
	tabla.guardar("nihongo.dat");

	//Borrar todo el texto impreso
	PA_OutputText(0,0,0,"                            ");
	PA_InitText(1,0);
	PA_OutputText(1,0,0,"                                                       ");
	PA_OutputText(1,0,2,"                                         ");
	PA_OutputText(1,0,3,"                                                    ");
	//Quitar teclado
	PA_KeyboardOut();
}

}
