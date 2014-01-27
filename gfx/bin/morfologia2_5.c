#include <PA_BgStruct.h>

extern const char morfologia2_5_Tiles[];
extern const char morfologia2_5_Map[];
extern const char morfologia2_5_Pal[];

const PA_BgStruct morfologia2_5 = {
	PA_BgNormal,
	256, 192,

	morfologia2_5_Tiles,
	morfologia2_5_Map,
	{morfologia2_5_Pal},

	17792,
	{1536}
};
