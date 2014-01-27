#include <PA_BgStruct.h>

extern const char escritura_10_Tiles[];
extern const char escritura_10_Map[];
extern const char escritura_10_Pal[];

const PA_BgStruct escritura_10 = {
	PA_BgNormal,
	256, 192,

	escritura_10_Tiles,
	escritura_10_Map,
	{escritura_10_Pal},

	23744,
	{1536}
};
