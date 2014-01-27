#include <PA_BgStruct.h>

extern const char morfologia_6_Tiles[];
extern const char morfologia_6_Map[];
extern const char morfologia_6_Pal[];

const PA_BgStruct morfologia_6 = {
	PA_BgNormal,
	256, 192,

	morfologia_6_Tiles,
	morfologia_6_Map,
	{morfologia_6_Pal},

	23680,
	{1536}
};
