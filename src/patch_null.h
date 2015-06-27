#ifndef EQC_SRC_PATCH_NULL_H
#define EQC_SRC_PATCH_NULL_H

#include "patch.h"

class PatchNull : public Patch
{
public:
	PatchNull() { }
	virtual ~PatchNull() { }
	
	virtual void Register();
	virtual void Unregister();
	virtual void OnEnterWorld(HWND *hWnd) { }
};

#endif
