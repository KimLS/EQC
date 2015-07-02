#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <SDKDDKVer.h>
#include <detours.h>

#include "../common/log.h"
#include "../common/string_util.h"

#include "patch_sod.h"
#include "patch_sod_hooks.h"


void PatchSoD::Register() {
	Log::Get().Write(Log::Status, "Registering patch SoD");
	DetourAttach(&(PVOID&)SoDPlayer__EnterZone, SoDPlayerEnterZoneHook);
	DetourAttach(&(PVOID&)SoDGame__RegisterZone, SoDGameRegisterZoneHook);
	DetourAttach(&(PVOID&)SoDGame__OnMsgRecv, SoDGameOnMsgRecvHook);
}

void PatchSoD::Unregister() {
	Log::Get().Write(Log::Status, "Unregistering patch SoD");
	DetourDetach(&(PVOID&)SoDPlayer__EnterZone, SoDPlayerEnterZoneHook);
	DetourDetach(&(PVOID&)SoDGame__RegisterZone, SoDGameRegisterZoneHook);
	DetourDetach(&(PVOID&)SoDGame__OnMsgRecv, SoDGameOnMsgRecvHook);
}

