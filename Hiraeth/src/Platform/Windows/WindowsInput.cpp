#include "pch.h"
#include "WindowsInput.h"
#include"Hiraeth/Core/Game.h"
#include<GLFW/glfw3.h>
namespace Hiraeth
{
	bool WindowsInput::isKeyPressedPlatSpecImpl(int key)
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Game::getInstance().getWindow().getNativeWindow()); 
		auto state = glfwGetKey(window, static_cast<int32_t>(key)); 
		return state == GLFW_PRESS || GLFW_REPEAT;
	}

	bool WindowsInput::isMouseButtonPressedPlatSpecImpl(int mouseButton)
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Game::getInstance().getWindow().getNativeWindow());
		auto state = glfwGetMouseButton(window, mouseButton); 
		return state == GLFW_PRESS; //return true if glfw_press is the state
	}

	std::pair<float, float> WindowsInput::getMousePositionPlatSpecImpl()
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Game::getInstance().getWindow().getNativeWindow());
		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);
		return { (float)xPos, (float)yPos };
	}

	float WindowsInput::getMouseXPlatSpecImpl()
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Game::getInstance().getWindow().getNativeWindow());
		double xPos; 
		glfwGetCursorPos(window, &xPos, nullptr);
		return (float)xPos; 
	}

	float WindowsInput::getMouseYPlatSpecImpl()
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Game::getInstance().getWindow().getNativeWindow());
		double yPos;
		glfwGetCursorPos(window, nullptr, &yPos);
		return yPos;
		//or could do it like auto [x,y] = getMousePosition...() C++17
	}

}