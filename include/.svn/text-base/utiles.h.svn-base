
#ifndef _UTILES_H
#define _UTILES_H

#include <cstring>

// Copia en destino la cadena origen. 
// destino debe estar inicializado a NULL sino se devolvera false.
// Al finalizar, destino tendra una copia exacta de la cadena origen
//   y se devolvera true
inline bool CopiarCadena (char*& destino, char* origen) {
	if (destino!=NULL || origen==NULL) {
		return false;
	}
	destino = new char [strlen(origen)+1];
	strcpy(destino,origen);
	return true;
}

#endif
