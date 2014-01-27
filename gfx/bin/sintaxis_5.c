#include <PA_BgStruct.h>

extern const char sintaxis_5_Tiles[];
extern const char sintaxis_5_Map[];
extern const char sintaxis_5_Pal[];

const PA_BgStruct sintaxis_5 = {
	PA_BgNormal,
	256, 192,

	sintaxis_5_Tiles,
	sintaxis_5_Map,
	{sintaxis_5_Pal},

	21952,
	{1536}
};
