#include <PA_BgStruct.h>

extern const char kanjis_11_Tiles[];
extern const char kanjis_11_Map[];
extern const char kanjis_11_Pal[];

const PA_BgStruct kanjis_11 = {
	PA_BgNormal,
	256, 192,

	kanjis_11_Tiles,
	kanjis_11_Map,
	{kanjis_11_Pal},

	17600,
	{1536}
};
