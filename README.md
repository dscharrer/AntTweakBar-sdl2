# Gutted SDL 2, CMake port of AntTweakBar

This is a fork of AntTweakBar 1.16 that has been butchered for my own use.

Changes from upstream:

* Removed all rendering backends except OpenGL core
* Removed all event backends except SDL 1.3
* Upgraded SDL 1.3 backend to SDL 2
* Replaced remaining platform-specific code with SDL 2 calls
* Added minimal CMake build file, static lib only
* Removed OpenGL function loader code, added hooks to inject own loader

AntTweakBar is very hacky code (`-fno-strict-aliasing` should hint at that), so I suggest
you don't use this. But if you are, like me right now, in a hurry for a quick&easy UI,
here is how:

First, this project is not meant to compile on its own. Instead, include it as a
subdirectory in another CMake project. This is mostly because it doesn't ship the
(non-standard) [FindSDL2.cmake](https://github.com/arx/ArxLibertatis/blob/master/cmake/FindSDL2.cmake)
module, but also because you need to define some variables.

    # Set this to whatever your OpenGL loader include file is.
    # On Linux you could probably get away with GL/gl.h
    # This must be defined before everything else.
    # You could also pass this on the CMake command-cone as -DATB_OPENGL_HEADER=...
    set(ATB_OPENGL_HEADER GLXW/glxw.h)
    
    # Now include the subdirectory, easy enough!
    # This will provide you with an AntTweakBar target to link against!
    add_subdirectory(libs/AntTweakBar-sdl2 EXCLUDE_FROM_ALL)
    
    # Finally, hook AntTweakBar up to your program:
    include_directories(SYSTEM libs/AntTweakBar-sdl2/include)
    add_definitions(-DTW_STATIC)
    target_link_libraries(yourexe AntTweakBar)

## Original README

AntTweakBar is a small and easy-to-use C/C++ library that allows programmers
to quickly add a light and intuitive GUI into OpenGL and DirectX based 
graphic programs to interactively tweak parameters.

This package includes the development version of the AntTweakBar library 
for Windows, GNU/Linux and OSX, and some program examples (sources + binaries).

For installation and documentation please refer to:
http://anttweakbar.sourceforge.net/doc


