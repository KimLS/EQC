#ifndef EQC_SRC_PATCH_SOD_EQGAME_H
#define EQC_SRC_PATCH_SOD_EQGAME_H

#include "eqgame_functions.h"

#define EQAddr(n, addr) const size_t SoD_a##n = ((addr - 0x400000) + SoD_base_address)

#ifdef EQC_EXTERN
#define EQVar(n, type, value) extern type SoD_##n;
#define EQFunc(n) extern p##n SoD##n
#else
#define EQVar(n, type, value) type SoD_##n = (type)value
#define EQFunc(n) p##n SoD##n = (p##n)(SoD_a##n)
#endif

EQVar(base_address, DWORD, GetModuleHandle(NULL));

//Functions
//Enter Zone
EQAddr(Player__EnterZone, 0x4F2420);
EQFunc(Player__EnterZone);

//EQAddr(Player__UDPConnection, 0xDD25AC);
//EQVar(Player__UDPConnection, void**, 0xDD25AC);

//EQAddr(Player__SendReliableMessage, 0x8C51F0);
//EQFunc(Player__SendReliableMessage);


#endif
