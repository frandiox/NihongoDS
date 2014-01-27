#include <PA_BgStruct.h>

extern const char kanjis_1_Tiles[];
extern const char kanjis_1_Map[];
extern const char kanjis_1_Pal[];

const PA_BgStruct kanjis_1 = {
	PA_BgNormal,
	256, 192,

	kanjis_1_Tiles,
	kanjis_1_Map,
	{kanjis_1_Pal},

	32128,
	{1536}
};
