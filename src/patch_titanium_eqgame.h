#ifndef EQC_SRC_PATCH_TITANIUM_EQGAME_H
#define EQC_SRC_PATCH_TITANIUM_EQGAME_H

#include "eqgame_functions.h"

#define EQAddr(n, addr) const size_t Titanium_a##n = ((addr - 0x400000) + Titanium_base_address)

#ifdef EQC_EXTERN
#define EQVar(n, type, value) extern type Titanium_##n;
#define EQFunc(n) extern p##n Titanium##n
#else
#define EQVar(n, type, value) type Titanium_##n = (type)value
#define EQFunc(n) p##n Titanium##n = (p##n)(Titanium_a##n)
#endif

EQVar(base_address, DWORD, GetModuleHandle(NULL));

EQAddr(Game__RegisterZone, 0x5F6B00);
EQFunc(Game__RegisterZone);

EQAddr(Game__DisplayChat, 0x4982C6);
EQFunc(Game__DisplayChat);

//Player
EQAddr(Player__EnterZone, 0x4A861D);
EQFunc(Player__EnterZone);

EQVar(Player__UDPConnection, void**, 0x905CA0);
EQAddr(Player__SendReliableMessageTitanium, 0x4912B1);
EQFunc(Player__SendReliableMessageTitanium);

EQAddr(Player__CommandHandler, 0x498B78);
EQFunc(Player__CommandHandler);

EQAddr(Game__OnMsgRecv, 0x424E57);
EQFunc(Game__OnMsgRecv);

#endif
