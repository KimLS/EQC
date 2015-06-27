#ifndef EQC_SRC_PATCH_H
#define EQC_SRC_PATCH_H

#include <Windows.h>

class Patch
{
public:
	Patch() { }
	virtual ~Patch() { }
	
	virtual void Register() = 0;
	virtual void Unregister() = 0;

	virtual void OnEnterWorld(HWND *hWnd) = 0;
};

#endif
