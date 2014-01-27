#include <PA_BgStruct.h>

extern const char fonetica_3_Tiles[];
extern const char fonetica_3_Map[];
extern const char fonetica_3_Pal[];

const PA_BgStruct fonetica_3 = {
	PA_BgNormal,
	256, 192,

	fonetica_3_Tiles,
	fonetica_3_Map,
	{fonetica_3_Pal},

	31168,
	{1536}
};
