#ifndef EQC_PATCH_SOD
#define EQC_PATCH_SOD

#include "patch.h"

class PatchSoD : public Patch
{
public:
	PatchSoD() { }
	virtual ~PatchSoD() { }
	
	virtual void Register();
	virtual void Unregister();
};

#endif
