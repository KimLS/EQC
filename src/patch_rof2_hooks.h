#ifndef EQC_SRC_PATCH_ROF2_HOOKS_H
#define EQC_SRC_PATCH_ROF2_HOOKS_H

#include "patch_rof2_eqgame.h"

//Game
int __fastcall RoF2RegisterZoneHook(void *self, void* unk, int expansion, int zone_id, char *short_name, char *long_name, int e, int flag, int g, int h, int i);
int __fastcall RoF2RegisterZone2Hook(void *self, void* unk, int expansion, int zone_id, char *short_name, char *long_name, int e, int flag, int g, int h, int i);

//Player
void __fastcall RoF2EnterZoneHook(void *self, void* unk, HWND *hwnd);

#endif
