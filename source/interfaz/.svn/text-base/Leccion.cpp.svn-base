/*
 * Leccion.cpp
 *
 * NihongoDS
 *
 */

#include "Leccion.h"

namespace NIHONGO {

Leccion::Leccion() {
}


Leccion::~Leccion() {
}

Leccion::Leccion(const Leccion & orig) {
	copy(orig);
}

void Leccion::init() {
	pagina_actual=1;
	estado=lec_EJECUCION;
}

void Leccion::change_pg(){
	if (Pad.Newpress.A){
		if (pagina_actual < (paginas_totales-1)){
			pagina_actual+=2;
		}
	}else if (Pad.Newpress.B){
		if (pagina_actual > 2){
			pagina_actual-=2;
		}
	}else if (Pad.Newpress.Start){
		estado=lec_FIN;
	}else if (Pad.Newpress.Select){
		estado=lec_SELECCION;
	}
}

EstadoLeccion Leccion::getEstado() {
	return estado;
}

void Leccion::copy(const Leccion & orig) {
	//seccion_actual=orig.seccion_actual;
	pagina_actual=orig.pagina_actual;
	//simbolos = vector<Simbolo*>(orig.simbolos);
}

Leccion & Leccion::operator =(const Leccion & orig) {
	if (this!=&orig) {
		copy(orig);
	}
	return *this;
}

/*Seccion Leccion::getSeccion() {
	return seccion_actual;
}*/

u8 Leccion::getPagina() {
	return pagina_actual;
}

}
