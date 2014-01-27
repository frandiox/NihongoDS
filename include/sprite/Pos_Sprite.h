/*
 * Pos_Sprite.h
 *
 * NihongoDS
 *
 */

#ifndef POS_SPRITE_H_
#define POS_SPRITE_H_

#include <PA9.h>

namespace NIHONGO {

class Pos_Sprite {
public:
	//Constructores
	Pos_Sprite();
	Pos_Sprite(u8 id, u8 x, u8 y);
	Pos_Sprite(const Pos_Sprite& orig);
	virtual ~Pos_Sprite();

	//Funcion de derivacion
	char* print ();


	//Miembros
	u8 Id;			//Id del sprite
	u8 X;			//Coordenada X de la pantalla
	u8 Y;			//Coordenada Y de la pantalla
};

}

#endif /* POS_SPRITE_H_ */
