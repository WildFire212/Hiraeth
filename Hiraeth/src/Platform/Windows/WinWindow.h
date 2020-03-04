#pragma once
#include<GLFW/glfw3.h>
#include"glad/glad.h"
#include"Hiraeth/Core/Window.h"


namespace Hiraeth {
	class WinWindow : public Window
	{
	public:
		WinWindow(const WindowProperties& props);
		
		void onUpdate() override;
		inline unsigned int getWidth() const override { return m_Data.m_Width;  }
		inline unsigned int getHeight() const override { return m_Data.m_Height; }
	
		inline void* getNativeWindow() const { return m_Window; }
	private: 
		virtual void init(const WindowProperties& props); 
		virtual void shutDown(); 
	private: 
		GLFWwindow* m_Window; 

		struct WindowData {
			unsigned int m_Height, m_Width; 
			std::string m_WindowName;
		};
		WindowData m_Data; 
		static void glfw_error_callback(int error, const char* errorStr); 
	};
}