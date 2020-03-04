#include "pch.h"



#include"Platform/OpenGL/OpenglImGUI.h"

#include "ImGUILayer.h"
#include"Hiraeth/Core/Game.h"

#include<GLFW/glfw3.h>
#include"Hiraeth/Core/EventQueue.h"

namespace Hiraeth
{
	ImGUILayer::ImGUILayer()
		:Layer("ImGUILayer")
	{
		//EventQueue::getInstance()->subscribe<ImGUILayer,>(this, )
	}
	

	void Hiraeth::ImGUILayer::onAttach()
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext(); 
		ImGui::StyleColorsDark(); 

		// Setup back-end capabilities flags
		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;         // We can honor GetMouseCursor() values (optional)
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;          // We can honor io.WantSetMousePos requests (optional, rarely used)
		

		// Keyboard mapping. ImGui will use those indices to peek into the io.KeysDown[] array.
		io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
		io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
		io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
		io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
		io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
		io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
		io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
		io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
		io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
		io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
		io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
		io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
		io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
		io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
		io.KeyMap[ImGuiKey_KeyPadEnter] = GLFW_KEY_KP_ENTER;
		io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
		io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
		io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
		io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
		io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
		io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

	
		GLFWwindow* window = static_cast<GLFWwindow*>(Game::getInstance().getWindow().getNativeWindow()); 
		ImGui_ImplOpenGL3_Init("#version 410");
		
		EventQueue::getInstance()->subscribe<ImGUILayer, KeyPressedEvent>(this, &ImGUILayer::onKeyPressed);
		EventQueue::getInstance()->subscribe<ImGUILayer, MouseMovedEvent>(this, &ImGUILayer::onMouseMoved);
		EventQueue::getInstance()->subscribe<ImGUILayer, MouseButtonPressedEvent>(this, &ImGUILayer::onMouseButtonPressed);
		EventQueue::getInstance()->subscribe<ImGUILayer, MouseButtonReleasedEvent>(this, &ImGUILayer::onMouseButtonReleased);
		EventQueue::getInstance()->subscribe<ImGUILayer, WindowResizeEvent>(this, &ImGUILayer::onWindowResize);
	}

	void ImGUILayer::onDetach()
	{
		
	}
	

	void ImGUILayer::begin()
	{
		ImGuiIO& io = ImGui::GetIO(); 
		Game& game = Game::getInstance(); 
		io.DisplaySize = ImVec2(game.getWindow().getWidth(), game.getWindow().getHeight()); 
		
		ImGui_ImplOpenGL3_NewFrame();
		//ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void ImGUILayer::end()
	{
		static bool show = true;
		ImGui::ShowDemoWindow(&show);
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	}
	void ImGUILayer::onKeyPressed(KeyPressedEvent* keyPressedEvent)
	{

		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[keyPressedEvent->getKeyCode()] = true;
	
		// Modifiers are not reliable across systems
		io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
		io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
		io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
	} 
	void ImGUILayer::onMouseMoved(MouseMovedEvent* mouseMovedEvent)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(mouseMovedEvent->getX(), mouseMovedEvent->getY());
	}

	void ImGUILayer::onMouseButtonPressed(MouseButtonPressedEvent* mouseButtonEvent)
	{
		ImGuiIO& io = ImGui::GetIO(); 
		io.MouseDown[mouseButtonEvent->getMouseButton()] = true; 
	}

	void ImGUILayer::onMouseButtonReleased(MouseButtonReleasedEvent* mouseButtonEvent)
	{
		ImGuiIO& io = ImGui::GetIO(); 
		io.MouseDown[mouseButtonEvent->getMouseButton()] = false; 
	}

	void ImGUILayer::onWindowResize(WindowResizeEvent* windowResizeEvent)
	{
		ImGuiIO& io = ImGui::GetIO(); 
		io.DisplaySize = ImVec2(windowResizeEvent->getWidth(), windowResizeEvent->getHeight()); 
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.f); 
		glViewport(0, 0, windowResizeEvent->getWidth(), windowResizeEvent->getHeight());
	}
}
