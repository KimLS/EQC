CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(mod_sources
	dinput8.def
	main.cpp
	patch_manager.cpp
	patch_null.cpp
	patch_rof2.cpp
	patch_sod.cpp
	patch_titanium.cpp
	patch_uf.cpp
)

SET(mod_headers
	patch.h
	patch_manager.h
	patch_null.h
	patch_rof2.h
	patch_sod.h
	patch_titanium.h
	patch_uf.h
)

INCLUDE_DIRECTORIES("${DETOURS_INCLUDE_DIR}")

ADD_LIBRARY(dinput8 SHARED ${mod_sources} ${mod_headers})
TARGET_LINK_LIBRARIES(dinput8 common ${DETOURS_LIBRARIES})
INSTALL(TARGETS dinput8 RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX})

SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
