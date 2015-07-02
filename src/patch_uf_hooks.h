#ifndef EQC_SRC_PATCH_UF_HOOKS_H
#define EQC_SRC_PATCH_UF_HOOKS_H

#include "patch_uf_eqgame.h"

//Game 
int __fastcall UFGameRegisterZoneHook(void *self, void* unk, int expansion, int zone_id, char *short_name, char *long_name, int string_id, int flag, int g, int h, int i);
int __stdcall UFGameOnMsgRecvHook(void *self, const char *data, int sz);

//Player
void __fastcall UFPlayerEnterZoneHook(void *self, void* unk, HWND *hwnd);
int __fastcall UFPlayerCommandHandlerHook(void* self, void *unk, DWORD pp, const char *command);

#endif
