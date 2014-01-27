#include <PA_BgStruct.h>

extern const char morfologia2_3_Tiles[];
extern const char morfologia2_3_Map[];
extern const char morfologia2_3_Pal[];

const PA_BgStruct morfologia2_3 = {
	PA_BgNormal,
	256, 192,

	morfologia2_3_Tiles,
	morfologia2_3_Map,
	{morfologia2_3_Pal},

	28224,
	{1536}
};
