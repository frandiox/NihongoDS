#include <PA_BgStruct.h>

extern const char morfologia2_1_Tiles[];
extern const char morfologia2_1_Map[];
extern const char morfologia2_1_Pal[];

const PA_BgStruct morfologia2_1 = {
	PA_BgNormal,
	256, 192,

	morfologia2_1_Tiles,
	morfologia2_1_Map,
	{morfologia2_1_Pal},

	24704,
	{1536}
};
