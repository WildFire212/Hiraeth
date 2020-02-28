#pragma once
#include"pch.h"
#ifdef HI_WINDOWS_PLATFORM
	#ifdef HIBUILD_DLL_
		#define HIRAETH_API __declspec(dllexport) 
	#else 
		#define HIRAETH_API __declspec(dllimport)	
	#endif
#else 
#error Hiraeth supports only windows 
#endif

#define BIT(x)	1<<x

#ifdef	HI_DEBUG
	#define HI_ENABLE_ASSERTS
#endif

#ifdef HI_ENABLE_ASSERTS
		#define HI_ASSERT(x, ...) {if(!(x)) {HIRAETH_CLIENT_ERROR("Assertion Failed: {0}" , __VA_ARGS__); __debugbreak(); }}
		#define HI_CORE_ASSERT(x, ...) { if(!(x)) { HIRAETH_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
		#define HI_ASSERT(x, ...)
		#define HI_CORE_ASSERT(x, ...)
#endif




