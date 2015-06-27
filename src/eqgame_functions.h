#ifndef EQC_SRC_EQGAME_FUNCTIONS_H
#define EQC_SRC_EQGAME_FUNCTIONS_H

//Game
typedef int(__thiscall *pGame__RegisterZone)(void*, int, int, const char*, const char*, int, int, int, int, int);
typedef int(__thiscall *pGame__RegisterZone2)(void*, int, int, const char*, const char*, int, int, int, int, int);

//Player
typedef void(__thiscall *pPlayer__EnterZone)(void*, void*);
typedef char(__thiscall *pPlayer__SendReliableMessage)(void*, int, char*, int);


#endif