//  ---------------------------------------------------------------------------
//
//  @file       TwPrecomp.h
//  @brief      Precompiled header
//  @author     Philippe Decaudin
//  @license    This file is part of the AntTweakBar library.
//              For conditions of distribution and use, see License.txt
//
//  note:       Private header
//
//  ---------------------------------------------------------------------------


#if !defined ANT_TW_PRECOMP_INCLUDED
#define ANT_TW_PRECOMP_INCLUDED

#include "SDL.h"

#if defined _MSC_VER
#   pragma warning(disable: 4514)   // unreferenced inline function has been removed
#   pragma warning(disable: 4710)   // function not inlined
#   pragma warning(disable: 4786)   // template name truncated
#   pragma warning(disable: 4530)   // exceptions not handled
#   define _CRT_SECURE_NO_DEPRECATE // visual 8 secure crt warning
#endif

#include <cstdio>
#include <cassert>
#include <cmath>
#include <cfloat>
#include <cstring>
#include <cstdlib>
#include <memory.h>

#if defined(_MSC_VER) && _MSC_VER<=1200
#   pragma warning(push, 3)
#endif
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <list>
#include <set>
#if defined(_MSC_VER) && _MSC_VER<=1200
#   pragma warning(pop)
#endif

#if !defined(_WIN32)
#   include <unistd.h>
#   include <stdlib.h>
#else
#   ifndef WIN32_LEAN_AND_MEAN
#       define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
#   endif
#   include <windows.h>
#   include <shellapi.h>
#endif

#endif  // !defined ANT_TW_PRECOMP_INCLUDED
