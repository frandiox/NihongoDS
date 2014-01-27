#include <PA_BgStruct.h>

extern const char fonetica_7_Tiles[];
extern const char fonetica_7_Map[];
extern const char fonetica_7_Pal[];

const PA_BgStruct fonetica_7 = {
	PA_BgNormal,
	256, 192,

	fonetica_7_Tiles,
	fonetica_7_Map,
	{fonetica_7_Pal},

	17600,
	{1536}
};
