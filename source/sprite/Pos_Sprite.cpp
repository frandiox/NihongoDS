/*
 * Pos_Sprite.cpp
 *
 * NihongoDS
 *
 */

#include "Pos_Sprite.h"

namespace NIHONGO {

//Constructores
Pos_Sprite::Pos_Sprite() {
	Id=0;
	X=0;
	Y=0;
}
Pos_Sprite::Pos_Sprite(u8 id, u8 x, u8 y) {
	Id=id;
	X=x;
	Y=y;
}

Pos_Sprite::Pos_Sprite(const Pos_Sprite& orig) {
	Id=orig.Id;
	X=orig.X;
	Y=orig.Y;
}

Pos_Sprite::~Pos_Sprite() {}

//Funcion de derivacion
char* Pos_Sprite::print() {
	char* buffer = new char [200];
	sprintf(buffer,"(id:%d,x:%d,y:%d)",Id,X,Y);
	return buffer;
}

}
