#ifndef EQC_PATCH_MANAGER
#define EQC_PATCH_MANAGER

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
private:
	PatchManager() { }
	PatchManager(const PatchManager&);
	PatchManager& operator=(const PatchManager&);

	std::map<void*, std::unique_ptr<Patch>> patches_;
};

#endif
