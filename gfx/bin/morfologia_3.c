#include <PA_BgStruct.h>

extern const char morfologia_3_Tiles[];
extern const char morfologia_3_Map[];
extern const char morfologia_3_Pal[];

const PA_BgStruct morfologia_3 = {
	PA_BgNormal,
	256, 192,

	morfologia_3_Tiles,
	morfologia_3_Map,
	{morfologia_3_Pal},

	17856,
	{1536}
};
