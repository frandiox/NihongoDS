#include <PA_BgStruct.h>

extern const char kanjis_14_Tiles[];
extern const char kanjis_14_Map[];
extern const char kanjis_14_Pal[];

const PA_BgStruct kanjis_14 = {
	PA_BgNormal,
	256, 192,

	kanjis_14_Tiles,
	kanjis_14_Map,
	{kanjis_14_Pal},

	22080,
	{1536}
};
