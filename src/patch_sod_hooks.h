#ifndef EQC_SRC_PATCH_SOD_HOOKS_H
#define EQC_SRC_PATCH_SOD_HOOKS_H

#include "patch_sod_eqgame.h"

void __fastcall SoDEnterZoneHook(void *self, void* unk, HWND *hwnd);

DWORD __fastcall ZoneRegistrationHook(void *self, void* unk, int expansion, int zone_id, char *short_name, char *long_name,
									int e, int flag, int g, int h, int unknown_zero);

DWORD __fastcall ZoneRegistrationHook2(void *self, void* unk, int expansion, int zone_id, char *short_name, char *long_name,
									  int e, int flag, int g, int h, int unknown_zero);

#endif
