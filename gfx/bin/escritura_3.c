#include <PA_BgStruct.h>

extern const char escritura_3_Tiles[];
extern const char escritura_3_Map[];
extern const char escritura_3_Pal[];

const PA_BgStruct escritura_3 = {
	PA_BgNormal,
	256, 192,

	escritura_3_Tiles,
	escritura_3_Map,
	{escritura_3_Pal},

	26432,
	{1536}
};
