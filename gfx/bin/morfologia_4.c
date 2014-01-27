#include <PA_BgStruct.h>

extern const char morfologia_4_Tiles[];
extern const char morfologia_4_Map[];
extern const char morfologia_4_Pal[];

const PA_BgStruct morfologia_4 = {
	PA_BgNormal,
	256, 192,

	morfologia_4_Tiles,
	morfologia_4_Map,
	{morfologia_4_Pal},

	21632,
	{1536}
};
