#include <PA_BgStruct.h>

extern const char morfologia_5_Tiles[];
extern const char morfologia_5_Map[];
extern const char morfologia_5_Pal[];

const PA_BgStruct morfologia_5 = {
	PA_BgNormal,
	256, 192,

	morfologia_5_Tiles,
	morfologia_5_Map,
	{morfologia_5_Pal},

	22784,
	{1536}
};
