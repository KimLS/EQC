#ifndef EQC_PATCH_NULL
#define EQC_PATCH_NULL

#include "patch.h"

class PatchNull : public Patch
{
public:
	PatchNull() { }
	virtual ~PatchNull() { }
	
	virtual void Register();
	virtual void Unregister();
};

#endif
