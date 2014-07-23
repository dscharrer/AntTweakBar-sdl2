cmake_minimum_required(VERSION 2.8.8)

project(AntTweakBar-sdl)

find_package(SDL2 REQUIRED)
include_directories(SYSTEM ${SDL2_INCLUDE_DIR})

set(anttweakbar_sources
	src/TwBar.cpp
	src/TwColors.cpp
	src/TwEventSDL2.cpp
	src/TwFonts.cpp
	src/TwMgr.cpp
	src/TwOpenGLCore.cpp
)

if(NOT DEFINED ATB_OPENGL_HEADER)
	set(ATB_OPENGL_HEADER GL/glcorearb.h)
endif()

if(NOT MSVC)
	string(REGEX REPLACE "-W[^ ]*" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-strict-aliasing") # sigh
endif()

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

add_definitions("-DATB_OPENGL_HEADER=<${ATB_OPENGL_HEADER}>" -DTW_STATIC)

add_library(AntTweakBar STATIC ${anttweakbar_sources})
