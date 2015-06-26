#ifndef EQC_PATCH_H
#define EQC_PATCH_H

class Patch
{
public:
	Patch() { }
	virtual ~Patch() { }
	
	virtual void Register() = 0;
	virtual void Unregister() = 0;
};

#endif
