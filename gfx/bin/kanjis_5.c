#include <PA_BgStruct.h>

extern const char kanjis_5_Tiles[];
extern const char kanjis_5_Map[];
extern const char kanjis_5_Pal[];

const PA_BgStruct kanjis_5 = {
	PA_BgNormal,
	256, 192,

	kanjis_5_Tiles,
	kanjis_5_Map,
	{kanjis_5_Pal},

	18688,
	{1536}
};
