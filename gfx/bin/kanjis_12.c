#include <PA_BgStruct.h>

extern const char kanjis_12_Tiles[];
extern const char kanjis_12_Map[];
extern const char kanjis_12_Pal[];

const PA_BgStruct kanjis_12 = {
	PA_BgNormal,
	256, 192,

	kanjis_12_Tiles,
	kanjis_12_Map,
	{kanjis_12_Pal},

	19136,
	{1536}
};
