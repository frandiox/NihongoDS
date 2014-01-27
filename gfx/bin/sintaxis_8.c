#include <PA_BgStruct.h>

extern const char sintaxis_8_Tiles[];
extern const char sintaxis_8_Map[];
extern const char sintaxis_8_Pal[];

const PA_BgStruct sintaxis_8 = {
	PA_BgNormal,
	256, 192,

	sintaxis_8_Tiles,
	sintaxis_8_Map,
	{sintaxis_8_Pal},

	20352,
	{1536}
};
