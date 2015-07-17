#if !defined __PCH_H__
#define __PCH_H__

#include "targetver.h"

#if defined WIN32
    #define DllExport __declspec(dllexport)
#else
    #define DllExport
#endif

#include <cassert>
#include <functional>
#include <initializer_list>
#include <memory>
#include <mutex>
#include <random>
#include <string>
#include <unordered_map>

#include <log4cpp/Category.hh>

#if defined WIN32
// can remove this once VC++ gets its shit together (VS 2015!)
#define noexcept throw()
#endif

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
TypeName(const TypeName&) = delete; \
TypeName& operator=(TypeName&&) = delete

#define DEFAULT_COPY_AND_ASSIGN(TypeName) \
TypeName(const TypeName&) = default; \
TypeName& operator=(const TypeName&) = default

#if defined WIN32
    #define ALIGN(s) __declspec(align(s))
#else
    #define __declspec(t)

    #define ALIGN(s) __attribute__((aligned(s)))
#endif

#endif
