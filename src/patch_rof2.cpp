#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <SDKDDKVer.h>
#include <detours.h>

#include "../common/log.h"
#include "../common/logical_packet.h"
#include "../common/string_util.h"

#include "patch_rof2.h"
#include "patch_rof2_hooks.h"

void PatchRoF2::Register() {
	Log::Get().Write(Log::Status, "Registering patch RoF2");
	DetourAttach(&(PVOID&)RoF2Player__EnterZone, RoF2EnterZoneHook);
	DetourAttach(&(PVOID&)RoF2Game__RegisterZone, RoF2RegisterZoneHook);
	DetourAttach(&(PVOID&)RoF2Game__RegisterZone2, RoF2RegisterZone2Hook);
}

void PatchRoF2::Unregister() {
	Log::Get().Write(Log::Status, "Unregistering patch RoF2");
	DetourDetach(&(PVOID&)RoF2Player__EnterZone, RoF2EnterZoneHook);
	DetourDetach(&(PVOID&)RoF2Game__RegisterZone, RoF2RegisterZoneHook);
	DetourDetach(&(PVOID&)RoF2Game__RegisterZone2, RoF2RegisterZone2Hook);
}

void PatchRoF2::OnEnterWorld(HWND *hWnd) {
	Log::Get().Write(Log::Status, "Enter Zone");
}
