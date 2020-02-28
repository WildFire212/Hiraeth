#include"pch.h"
#include "Window.h"
//#include "Hiraeth/Core/Log.h"
#ifdef  HI_WINDOWS_PLATFORM 
#include"Platform/Windows/WinWindow.h"
#endif
namespace Hiraeth  
{
	std::unique_ptr<Window> Window::createWindow(const WindowProperties& props)
	{
		#ifdef  HI_WINDOWS_PLATFORM  
		return std::make_unique<WinWindow>(props);
		#else	
		HIRAETH_CORE_ASSERT(false, "Unknow Platform!"); 
		return nullptr;
		#endif
		return nullptr;
	}
}
