#include <PA_BgStruct.h>

extern const char escritura_8_Tiles[];
extern const char escritura_8_Map[];
extern const char escritura_8_Pal[];

const PA_BgStruct escritura_8 = {
	PA_BgNormal,
	256, 192,

	escritura_8_Tiles,
	escritura_8_Map,
	{escritura_8_Pal},

	24448,
	{1536}
};
