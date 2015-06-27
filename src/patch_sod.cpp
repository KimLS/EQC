#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <SDKDDKVer.h>
#include <detours.h>

#include "../common/log.h"
#include "../common/string_util.h"
#include "../common/logical_packet.h"

#include "patch_sod.h"
#include "patch_sod_hooks.h"


void PatchSoD::Register() {
	Log::Get().Write(Log::Status, "Registering patch SoD");
	DetourAttach(&(PVOID&)SoDPlayer__EnterZone, SoDEnterZoneHook);
}

void PatchSoD::Unregister() {
	Log::Get().Write(Log::Status, "Unregistering patch SoD");
	DetourDetach(&(PVOID&)SoDPlayer__EnterZone, SoDEnterZoneHook);
}

void PatchSoD::OnEnterWorld(HWND *hWnd) {
	Log::Get().Write(Log::Status, "Enter Zone");
}
