#ifndef EQC_PATCH_ROF2
#define EQC_PATCH_ROF2

#include "patch.h"

class PatchRoF2 : public Patch
{
public:
	PatchRoF2() { }
	virtual ~PatchRoF2() { }
	
	virtual void Register();
	virtual void Unregister();
};

#endif
