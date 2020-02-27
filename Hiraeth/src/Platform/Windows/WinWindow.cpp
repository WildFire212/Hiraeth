#include "WinWindow.h"
#include"Hiraeth/Core/Log.h"
#include"Hiraeth/Events/ApplicationEvent.h"
#include"Hiraeth/Core/EventQueue.h"	
namespace Hiraeth {
	static uint8_t m_GLFWWindowCount= 0;
	WinWindow::WinWindow(const WindowProperties& props)
	{
		init(props); 
	}

	void WinWindow::onUpdate()
	{
		glfwSwapBuffers(m_Window);
	}

	void WinWindow::init(const WindowProperties& props) {
		//initialize Window data from props 
		m_Data.m_Height = props.m_Height; 
		m_Data.m_Width= props.m_Width; 
		m_Data.m_WindowName = props.m_WindowName;
		
		if (!m_GLFWWindowCount)
		{
			int result = glfwInit(); 
			HI_CORE_ASSERT(result, "Could not initialize GLFW"); 
			
			glfwSetErrorCallback(glfw_error_callback); 
		}
		

		m_Window = glfwCreateWindow(m_Data.m_Width, m_Data.m_Height, m_Data.m_WindowName.c_str(), nullptr, nullptr);
		m_GLFWWindowCount++;

		HIRAETH_CORE_INFO("Window Created"); 

		//glfwMakeContextCurrent(m_Window); 
		//glfwSetWindowUserPointer(m_Window, &m_Data); 

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)(glfwGetWindowUserPointer(window));
				WindowCloseEvent* closeEvent = new WindowCloseEvent();
				EventQueue::getInstance()->publish<WindowCloseEvent>(closeEvent);
			});

	}

	void WinWindow::shutDown()
	{
		glfwDestroyWindow(m_Window); 
		m_GLFWWindowCount--; 
		if (m_GLFWWindowCount == 0)
		{
			
		}
		glfwTerminate(); 
		
	}

	void WinWindow::glfw_error_callback(int error, const char* errorStr)
	{
		HIRAETH_CORE_ERROR("GLFW ERROR: {0} : {1}", error, errorStr);
	}

}