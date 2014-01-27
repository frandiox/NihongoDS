#include <PA_BgStruct.h>

extern const char fondo_abajo_Tiles[];
extern const char fondo_abajo_Map[];
extern const char fondo_abajo_Pal[];

const PA_BgStruct fondo_abajo = {
	PA_BgNormal,
	256, 192,

	fondo_abajo_Tiles,
	fondo_abajo_Map,
	{fondo_abajo_Pal},

	22400,
	{1536}
};
