#include "../common/eq_data_file.h"
#include "../common/log.h"
#include "../common/string_util.h"
#include "../common/memory_dump.h"
#include "patch.h"

void Patch::OnEnterZone(pPlayer__EnterZone enter, void *self, HWND *hWnd)
{
	enter(self, hWnd);
	Log::Get().Write(Log::Status, "Enter Zone");
}

int Patch::OnMsgRecv(pGame__OnMsgRecv mr, void *self, const char *data, int sz) {
	Log::Get().Write(Log::Debug, StringFormat("[0x%04x, size: %u]", *(uint16*)data, sz - 2));
	MemoryDump(data + 2, sz - 2);
	return mr(self, data, sz);
}