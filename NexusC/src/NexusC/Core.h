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
