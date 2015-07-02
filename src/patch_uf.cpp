#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <SDKDDKVer.h>
#include <detours.h>

#include "../common/log.h"
#include "../common/string_util.h"

#include "patch_uf.h"
#include "patch_uf_hooks.h"

void PatchUF::Register() {
	Log::Get().Write(Log::Status, "Registering patch UF");
	DetourAttach(&(PVOID&)UFPlayer__EnterZone, UFPlayerEnterZoneHook);
	DetourAttach(&(PVOID&)UFPlayer__CommandHandler, UFPlayerCommandHandlerHook);
	DetourAttach(&(PVOID&)UFGame__RegisterZone, UFGameRegisterZoneHook);
	DetourAttach(&(PVOID&)UFGame__OnMsgRecv, UFGameOnMsgRecvHook);
}

void PatchUF::Unregister() {
	Log::Get().Write(Log::Status, "Unregistering patch UF");
	DetourDetach(&(PVOID&)UFPlayer__EnterZone, UFPlayerEnterZoneHook);
	DetourDetach(&(PVOID&)UFPlayer__CommandHandler, UFPlayerCommandHandlerHook);
	DetourDetach(&(PVOID&)UFGame__RegisterZone, UFGameRegisterZoneHook);
	DetourDetach(&(PVOID&)UFGame__OnMsgRecv, UFGameOnMsgRecvHook);
}

void PatchUF::DisplayChat(int color, std::string msg) {
	UFGame__DisplayChat(msg.c_str(), color, true, true);
}
