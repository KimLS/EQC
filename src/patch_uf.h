#ifndef EQC_PATCH_UF
#define EQC_PATCH_UF

#include "patch.h"

class PatchUF : public Patch
{
public:
	PatchUF() { }
	virtual ~PatchUF() { }
	
	virtual void Register();
	virtual void Unregister();
};

#endif
