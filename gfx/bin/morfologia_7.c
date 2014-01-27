#include <PA_BgStruct.h>

extern const char morfologia_7_Tiles[];
extern const char morfologia_7_Map[];
extern const char morfologia_7_Pal[];

const PA_BgStruct morfologia_7 = {
	PA_BgNormal,
	256, 192,

	morfologia_7_Tiles,
	morfologia_7_Map,
	{morfologia_7_Pal},

	26816,
	{1536}
};
