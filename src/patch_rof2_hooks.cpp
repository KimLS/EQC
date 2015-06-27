#include "../common/log.h"

#include "patch_manager.h"
#define EQC_EXTERN
#include "patch_rof2_hooks.h"

// Game Hooks
int __fastcall RoF2RegisterZoneHook(void *self, void* unk, int expansion, int zone_id, char *short_name, char *long_name, int e, int flag, int g, int h, int i) {
	return RoF2Game__RegisterZone(self, expansion, zone_id, short_name, long_name, e, flag, g, h, i);
}

int __fastcall RoF2RegisterZone2Hook(void *self, void* unk, int expansion, int zone_id, char *short_name, char *long_name, int e, int flag, int g, int h, int i) {
	return RoF2Game__RegisterZone2(self, expansion, zone_id, short_name, long_name, e, flag, g, h, i);
}

// Player Hooks
void __fastcall RoF2EnterZoneHook(void *self, void* unk, HWND *hwnd) {
	RoF2Player__EnterZone(self, hwnd);

	auto patch = PatchManager::Get().GetCurrentPatch();
	if(patch) {
		patch->OnEnterWorld(hwnd);
	}
}

