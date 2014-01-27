#include <PA_BgStruct.h>

extern const char kanjis_13_Tiles[];
extern const char kanjis_13_Map[];
extern const char kanjis_13_Pal[];

const PA_BgStruct kanjis_13 = {
	PA_BgNormal,
	256, 192,

	kanjis_13_Tiles,
	kanjis_13_Map,
	{kanjis_13_Pal},

	17856,
	{1536}
};
