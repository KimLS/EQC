#ifndef EQC_SRC_PATCH_MANAGER_H
#define EQC_SRC_PATCH_MANAGER_H

#include <map>
#include <memory>
#include "patch.h"

class PatchManager
{
public:
	~PatchManager() { }
	
	void LoadPatch();
	void UnloadPatch();
	void RegisterPatch();
	void UnregisterPatch();

	static PatchManager& Get() {
		static PatchManager inst;
		return inst;
	}

	Patch *GetCurrentPatch();
private:
	PatchManager() { }
	PatchManager(const PatchManager&);
	PatchManager& operator=(const PatchManager&);

	std::map<void*, std::unique_ptr<Patch>> patches_;
};

#endif
