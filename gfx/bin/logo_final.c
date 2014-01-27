#include <PA_BgStruct.h>

extern const char logo_final_Tiles[];
extern const char logo_final_Map[];
extern const char logo_final_Pal[];

const PA_BgStruct logo_final = {
	PA_BgNormal,
	256, 192,

	logo_final_Tiles,
	logo_final_Map,
	{logo_final_Pal},

	17856,
	{1536}
};
