#include <PA_BgStruct.h>

extern const char sintaxis_3_Tiles[];
extern const char sintaxis_3_Map[];
extern const char sintaxis_3_Pal[];

const PA_BgStruct sintaxis_3 = {
	PA_BgNormal,
	256, 192,

	sintaxis_3_Tiles,
	sintaxis_3_Map,
	{sintaxis_3_Pal},

	24960,
	{1536}
};
