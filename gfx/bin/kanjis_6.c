#include <PA_BgStruct.h>

extern const char kanjis_6_Tiles[];
extern const char kanjis_6_Map[];
extern const char kanjis_6_Pal[];

const PA_BgStruct kanjis_6 = {
	PA_BgNormal,
	256, 192,

	kanjis_6_Tiles,
	kanjis_6_Map,
	{kanjis_6_Pal},

	27776,
	{1536}
};
