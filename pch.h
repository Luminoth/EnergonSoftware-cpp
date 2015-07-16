#if !defined __PCH_H__
#define __PCH_H__

#include "targetver.h"

#if defined WIN32
    #define DllExport __declspec(dllexport)
#else
    #define DllExport
#endif

#endif
