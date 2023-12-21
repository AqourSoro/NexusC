#pragma once

#ifdef NC_PLATFORM_WINDOWS

	#ifdef NC_BUILD_DLL
		#define NEXUSC_API __declspec(dllexport)
	#else
		#define NEXUSC_API __declspec(dllimport)
	#endif // 
#else
	#error NexusC only support Windows!


#endif // NX_PLATFORM_WINDOWS

#ifdef NX_ENABLE_ASSERTS

	#define NX_ASSERT(x, ...) {if(!(x)) {NX_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define NX_CORE_ASSERT(x, ...) {if(!(x)) {NX_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define NX_ASSERT(x, ...)
	#define NX_CORE_ASSERT(x, ...)

#endif



#define BIT(x) (1 << x)
