#include "pch.h"
#include "Input.h"
#ifdef HI_WINDOWS_PLATFORM
	#include"Platform/Windows/WindowsInput.h"
#endif
namespace Hiraeth 
{
	Input* Input::m_Instance = Input::create(); 

	Input* Input::create()
	{
		#ifdef HI_WINDOWS_PLATFORM
		return new WindowsInput(); 
		#else
			HI_CORE_ASSERT(false, "Unknown Platform"); 
			return nullptr
		#endif 
		return nullptr; 
	}

}