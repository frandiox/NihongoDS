/*
 * TablaPuntuacion.cpp
 *
 * NihongoDS
 *
 */

#include "../../include/otras/TablaPuntuacion.h"

namespace NIHONGO {

TablaPuntuacion::TablaPuntuacion() {
	actual=0;
	clear();

}

TablaPuntuacion::TablaPuntuacion(const TablaPuntuacion& orig) {
	copy(orig);
}

TablaPuntuacion::~TablaPuntuacion() {

}

TablaPuntuacion& TablaPuntuacion::operator= (const TablaPuntuacion& orig) {
	if(this!=&orig) {
		copy(orig);
	}
	return *this;
}

void TablaPuntuacion::cargar(char* rutaArchivo) {
	FILE* f = fopen(rutaArchivo,"rb");
	for (u8 i=0; i<PTOS_NUM_FILAS; i++) {
		fread(puntos[i].nombre,1,sizeof(puntos[i].nombre),f);
		fread(&puntos[i].puntos,sizeof(u32),1,f);
	}
	fclose(f);
}

void TablaPuntuacion::guardar(char* rutaArchivo) {
	FILE* f = fopen(rutaArchivo,"wb");
	for (u8 i=0; i<PTOS_NUM_FILAS; i++) {
		fwrite(puntos[i].nombre,1,sizeof(puntos[i].nombre),f);
		fwrite(&puntos[i].puntos,sizeof(u32),1,f);
	}
	fclose(f);
}

void TablaPuntuacion::add(char nombre[5], u32 points) {
	if(actual<PTOS_NUM_FILAS) {
		puntos[actual].set(nombre,points);
		actual++;
	}
	else {
		if (points>this->puntos[PTOS_NUM_FILAS-1].puntos) {
			set(PTOS_NUM_FILAS-1,nombre,points);
		}
	}
	ordenar();
}

Puntuacion TablaPuntuacion::get (u8 indice) {
	if (indice>=0 && indice<PTOS_NUM_FILAS) {
		return puntos[indice];
	}
}

void TablaPuntuacion::set (u8 indice, char nombre[5], u32 points) {
	if (indice>=0 && indice<PTOS_NUM_FILAS) {
		puntos[indice].set(nombre,points);
	}
	ordenar();
}

void TablaPuntuacion::clear() {
	for (u8 i=0; i<PTOS_NUM_FILAS; i++)
		puntos[i].set("     ",0);
}

void TablaPuntuacion::copy(const TablaPuntuacion& orig) {
	actual=orig.actual;
	for (u8 i=0; i<PTOS_NUM_FILAS; i++) {
		puntos[i].set((char*)orig.puntos[i].nombre,orig.puntos[i].puntos);
	}
}

void TablaPuntuacion::ordenar() {
	for (u8 i=0; i<PTOS_NUM_FILAS-1; i++) {
		u8 imax=i, max=puntos[i].puntos;
		for (u8 j=i+1; j<PTOS_NUM_FILAS; j++) {
			if (max<puntos[j].puntos){
				imax=j;
				max=puntos[j].puntos;
			}
		}
		Puntuacion temp;
		temp.set(puntos[imax].nombre,puntos[imax].puntos);
		puntos[imax].set(puntos[i].nombre,puntos[i].puntos);
		puntos[i].set(temp.nombre,temp.puntos);
	}
}

}
