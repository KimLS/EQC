#ifndef EQC_SRC_PATCH_SOD_EQGAME_H
#define EQC_SRC_PATCH_SOD_EQGAME_H

#include "eqgame_functions.h"

#define EQAddr(n, addr) const size_t RoF2_a##n = ((addr - 0x400000) + RoF2_base_address)

#ifdef EQC_EXTERN
#define EQVar(n, type, value) extern type RoF2_##n;
#define EQFunc(n) extern p##n RoF2##n
#else
#define EQVar(n, type, value) type RoF2_##n = (type)value
#define EQFunc(n) p##n RoF2##n = (p##n)(RoF2_a##n)
#endif

EQVar(base_address, DWORD, GetModuleHandle(NULL));

//Game
EQAddr(Game__RegisterZone, 0x7DC290);
EQAddr(Game__RegisterZone2, 0x7DC430);
EQFunc(Game__RegisterZone);
EQFunc(Game__RegisterZone2);

//Player
EQAddr(Player__EnterZone, 0x531F90);
EQFunc(Player__EnterZone);

EQAddr(Player__UDPConnection, 0xDD25AC);
EQVar(Player__UDPConnection, void**, 0xDD25AC);

EQAddr(Player__SendReliableMessage, 0x8C51F0);
EQFunc(Player__SendReliableMessage);

#endif
