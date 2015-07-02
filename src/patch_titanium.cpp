#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <SDKDDKVer.h>
#include <detours.h>

#include "../common/log.h"
#include "../common/string_util.h"

#include "patch_titanium.h"
#include "patch_titanium_hooks.h"

void PatchTitanium::Register() {
	Log::Get().Write(Log::Status, "Registering patch Titanium");
	DetourAttach(&(PVOID&)TitaniumPlayer__EnterZone, TitaniumPlayerEnterZoneHook);
	DetourAttach(&(PVOID&)TitaniumGame__RegisterZone, TitaniumGameRegisterZoneHook);
	DetourAttach(&(PVOID&)TitaniumGame__OnMsgRecv, TitaniumGameOnMsgRecvHook);
}

void PatchTitanium::Unregister() {
	Log::Get().Write(Log::Status, "Unregistering patch Titanium");
	DetourDetach(&(PVOID&)TitaniumPlayer__EnterZone, TitaniumPlayerEnterZoneHook);
	DetourDetach(&(PVOID&)TitaniumGame__RegisterZone, TitaniumGameRegisterZoneHook);
	DetourDetach(&(PVOID&)TitaniumGame__OnMsgRecv, TitaniumGameOnMsgRecvHook);
}

