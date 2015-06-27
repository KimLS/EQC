#include "../common/log.h"

#include "patch_manager.h"
#define EQC_EXTERN
#include "patch_sod_hooks.h"

void __fastcall SoDEnterZoneHook(void *self, void* unk, HWND *hwnd) {
	SoDPlayer__EnterZone(self, hwnd);

	auto patch = PatchManager::Get().GetCurrentPatch();
	if(patch) {
		patch->OnEnterWorld(hwnd);
	}
}
