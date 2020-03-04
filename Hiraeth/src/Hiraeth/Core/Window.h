#pragma once
#include"Hiraeth/Core/CoreEngine.h"
namespace Hiraeth
{
	struct WindowProperties 
	{
		unsigned int m_Width; 
		unsigned int m_Height;
		std::string m_WindowName;
		WindowProperties(const std::string& windowname = "Hiraeth Engine",
						unsigned int width = 1280, 
						unsigned int height = 720):
			m_WindowName(windowname),
			m_Width(width),
			m_Height(height)
		{
		}

	};
	class Window
	{
	public: 
		virtual ~Window() = 0{};
		virtual void onUpdate() = 0; 
		virtual unsigned int getWidth() const = 0; 
		virtual unsigned int getHeight() const = 0 ;

		virtual void* getNativeWindow() const = 0; 

	public:
		static std::unique_ptr<Window> createWindow(const WindowProperties& props = WindowProperties());

	};

}
