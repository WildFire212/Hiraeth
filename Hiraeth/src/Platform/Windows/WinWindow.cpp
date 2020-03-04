#include"pch.h"
#include "WinWindow.h"
#include"Hiraeth/Core/Log.h"
#include"Hiraeth/Events/ApplicationEvent.h"
#include"Hiraeth/Events/KeyEvent.h"
#include"Hiraeth/Events/MouseEvent.h"
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
		glfwMakeContextCurrent(m_Window); 
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		//glfwSetWindowUserPointer(m_Window, &m_Data); 

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) ->void
			{
				WindowData& data = *(WindowData*)(glfwGetWindowUserPointer(window));
				WindowCloseEvent* closeEvent = new WindowCloseEvent();
				EventQueue::getInstance()->publish<WindowCloseEvent>(closeEvent);
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window,double xPos, double yPos) ->void
			{
				WindowData& data = *(WindowData*)(glfwGetWindowUserPointer(window)); 
				MouseMovedEvent * mouseMovedEvent = new MouseMovedEvent(xPos, yPos);
				EventQueue::getInstance()->publish<MouseMovedEvent>(mouseMovedEvent);
			});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button , int action , int mods) ->void 
			{
				WindowData& data = *(WindowData*)(glfwGetWindowUserPointer(window)); 
				if (action == GLFW_PRESS)
				{
				MouseButtonPressedEvent* mouseButtonPressed = new MouseButtonPressedEvent(button);
				EventQueue::getInstance()->publish<MouseButtonPressedEvent>(mouseButtonPressed);
				}
				else if (action == GLFW_RELEASE)
				{

				MouseButtonReleasedEvent* mouseButtonReleased = new MouseButtonReleasedEvent(button);
				EventQueue::getInstance()->publish<MouseButtonReleasedEvent>(mouseButtonReleased);
				}

			}); 

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window,int key,int scancode , int action , int mods) ->void
			{
				WindowData& data = *(WindowData*)(glfwGetWindowUserPointer(window));
				Event* event; 
				switch (action)
				{
				case GLFW_REPEAT: 
					event = new KeyPressedEvent(key, 1);
					EventQueue::getInstance()->publish< KeyPressedEvent>(event); 
					break; 
				case GLFW_PRESS: 
					event = new KeyPressedEvent(key, 0); 
					EventQueue::getInstance()->publish< KeyPressedEvent>(event);
					break; 
				case GLFW_RELEASE:
					event = new KeyReleasedEvent(key); 
					EventQueue::getInstance()->publish< KeyReleasedEvent>(event);
					break;
				}
			});

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) ->void
			{
				WindowData& data = *(WindowData*)(glfwGetWindowUserPointer(window));
				WindowResizeEvent* windowResizeEvent= new WindowResizeEvent(width, height);
				EventQueue::getInstance()->publish<WindowResizeEvent>(windowResizeEvent);
			});

		//glViewport(0, 0, m_Data.m_Width, m_Data.m_Height);
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