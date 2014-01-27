#include <PA_BgStruct.h>

extern const char sintaxis_7_Tiles[];
extern const char sintaxis_7_Map[];
extern const char sintaxis_7_Pal[];

const PA_BgStruct sintaxis_7 = {
	PA_BgNormal,
	256, 192,

	sintaxis_7_Tiles,
	sintaxis_7_Map,
	{sintaxis_7_Pal},

	16960,
	{1536}
};
