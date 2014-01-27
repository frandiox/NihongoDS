#include <PA_BgStruct.h>

extern const char morfologia2_6_Tiles[];
extern const char morfologia2_6_Map[];
extern const char morfologia2_6_Pal[];

const PA_BgStruct morfologia2_6 = {
	PA_BgNormal,
	256, 192,

	morfologia2_6_Tiles,
	morfologia2_6_Map,
	{morfologia2_6_Pal},

	24448,
	{1536}
};
