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

#ifdef SAPP_ENABLE_ASSERTS
	#define SAPP_ASSERT(x, ...) { if(!(x)) { SAPP_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SAPP_CORE_ASSERT(x, ...) { if(!(x)) { SAPP_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SAPP_ASSERT(x, ...)
	#define SAPP_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)