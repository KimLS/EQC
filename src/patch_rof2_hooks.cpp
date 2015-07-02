#include "../common/log.h"
#include "../common/string_util.h"

#include "patch_manager.h"
#include "patch_rof2.h"
#define EQC_EXTERN
#include "patch_rof2_hooks.h"

// Game Hooks
int __fastcall RoF2GameRegisterZoneHook(void *self, void* unk, int expansion, int zone_id, char *short_name, char *long_name, int string_id, int flag, int g, int h, int i) {
	auto patch = PatchManager::Get().GetPatch();
	return patch->OnRegisterZoneNew(RoF2Game__RegisterZone, self, expansion, zone_id, short_name, long_name, string_id, flag, g, h, i);
}

int __fastcall RoF2GameRegisterZone2Hook(void *self, void* unk, int expansion, int zone_id, char *short_name, char *long_name, int string_id, int flag, int g, int h, int i) {
	auto patch = PatchManager::Get().GetPatch();
	return patch->OnRegisterZoneNew2(RoF2Game__RegisterZone2, 767, self, expansion, zone_id, short_name, long_name, string_id, flag, g, h, i);
}

int __stdcall RoF2GameOnMsgRecvHook(void *self, const char *data, int sz) {
	auto patch = PatchManager::Get().GetPatch();
	return patch->OnMsgRecv(RoF2Game__OnMsgRecv, self, data, sz);
}

// Player Hooks
int __fastcall RoF2PlayerCommandHandlerHook(void *self, void *unk, DWORD pp, const char *command) {
	auto patch = PatchManager::Get().GetPatch();
	return patch->OnCommand(RoF2Player__CommandHandler, self, pp, command);
}

void __fastcall RoF2PlayerEnterZoneHook(void *self, void* unk, HWND *hwnd) {
	auto patch = PatchManager::Get().GetPatch();
	patch->OnEnterZone(RoF2Player__EnterZone, self, hwnd);
}

