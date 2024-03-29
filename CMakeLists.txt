CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/" ${CMAKE_MODULE_PATH})

PROJECT(EQEmu-Client-Mod)

IF(NOT CMAKE_BUILD_TYPE)
	SET(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build." FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE)

#Only designed for MSVC and 32 bit (because client is 32 bit derp):
IF(CMAKE_CL_64)
	MESSAGE(FATAL_ERROR "EQEmu Client Mod can only be built in 32 bit mode.") 
ENDIF(CMAKE_CL_64)

SET(DETOURS_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/detours")
FIND_PACKAGE("Detours")

OPTION(EQC_ENABLE_COMMANDS "Hook the command handler (will not play nice with MQ2)" ON)
IF(EQC_ENABLE_COMMANDS)
	ADD_DEFINITIONS(-DEQC_ENABLE_COMMANDS)
ENDIF(EQC_ENABLE_COMMANDS)

ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS)

ADD_SUBDIRECTORY(common)
ADD_SUBDIRECTORY(src)
