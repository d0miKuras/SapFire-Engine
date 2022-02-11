#pragma once

#ifdef SAPP_PLATFORM_WINDOWS
	#ifdef SAPP_BUILD_DLL
		#define SAPP_API __declspec(dllexport)
	#else
		#define SAPP_API __declspec(dllimport)
	#endif

	#else
	#error SapFire only supports Windows

#endif

#define BIT(x) (1 << x)