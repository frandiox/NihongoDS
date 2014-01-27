#include <PA_BgStruct.h>

extern const char kanjis_7_Tiles[];
extern const char kanjis_7_Map[];
extern const char kanjis_7_Pal[];

const PA_BgStruct kanjis_7 = {
	PA_BgNormal,
	256, 192,

	kanjis_7_Tiles,
	kanjis_7_Map,
	{kanjis_7_Pal},

	26752,
	{1536}
};
