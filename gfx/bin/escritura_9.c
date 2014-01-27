#include <PA_BgStruct.h>

extern const char escritura_9_Tiles[];
extern const char escritura_9_Map[];
extern const char escritura_9_Pal[];

const PA_BgStruct escritura_9 = {
	PA_BgNormal,
	256, 192,

	escritura_9_Tiles,
	escritura_9_Map,
	{escritura_9_Pal},

	23296,
	{1536}
};
