#include <PA_BgStruct.h>

extern const char morfologia_8_Tiles[];
extern const char morfologia_8_Map[];
extern const char morfologia_8_Pal[];

const PA_BgStruct morfologia_8 = {
	PA_BgNormal,
	256, 192,

	morfologia_8_Tiles,
	morfologia_8_Map,
	{morfologia_8_Pal},

	32768,
	{1536}
};
