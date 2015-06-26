CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(common_sources
	crc32.cpp
	log.cpp
	safe_write.cpp
	string_util.cpp
)

SET(common_headers
	crc32.h
	log.h
	safe_write.h
	string_util.h
	types.h
)

ADD_LIBRARY(common ${common_sources} ${common_headers})
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
