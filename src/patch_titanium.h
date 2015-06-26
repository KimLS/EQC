#ifndef EQC_PATCH_TITANIUM
#define EQC_PATCH_TITANIUM

#include "patch.h"

class PatchTitanium : public Patch
{
public:
	PatchTitanium() { }
	virtual ~PatchTitanium() { }
	
	virtual void Register();
	virtual void Unregister();
};

#endif
