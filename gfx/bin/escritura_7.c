#include <PA_BgStruct.h>

extern const char escritura_7_Tiles[];
extern const char escritura_7_Map[];
extern const char escritura_7_Pal[];

const PA_BgStruct escritura_7 = {
	PA_BgNormal,
	256, 192,

	escritura_7_Tiles,
	escritura_7_Map,
	{escritura_7_Pal},

	24896,
	{1536}
};
