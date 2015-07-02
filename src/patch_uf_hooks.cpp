#include "../common/log.h"
#include "../common/string_util.h"

#include "patch_manager.h"
#define EQC_EXTERN
#include "patch_uf_hooks.h"


int __fastcall UFGameRegisterZoneHook(void *self, void* unk, int expansion, int zone_id, char *short_name, char *long_name, int string_id, int flag, int g, int h, int i) {
	auto patch = PatchManager::Get().GetPatch();
	return patch->OnRegisterZone(UFGame__RegisterZone, 713, self, expansion, zone_id, short_name, long_name, string_id, flag, g, h, i);
}

int __stdcall UFGameOnMsgRecvHook(void *self, const char *data, int sz) {
	auto patch = PatchManager::Get().GetPatch();
	return patch->OnMsgRecv(UFGame__OnMsgRecv, self, data, sz);
}

int __fastcall UFPlayerCommandHandlerHook(void *self, void *unk, DWORD pp, const char *command) {
	auto patch = PatchManager::Get().GetPatch();
	return patch->OnCommand(UFPlayer__CommandHandler, self, pp, command);
}

void __fastcall UFPlayerEnterZoneHook(void *self, void* unk, HWND *hwnd) {
	auto patch = PatchManager::Get().GetPatch();
	patch->OnEnterZone(UFPlayer__EnterZone, self, hwnd);
}
