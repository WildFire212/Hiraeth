#include "pch.h"

#include<imgui.h>
#include<examples/imgui_impl_opengl3.h>
#include<examples/imgui_impl_glfw.h>

#include "ImGUILayer.h"

#include"Hiraeth/Core/Game.h"
#include"Hiraeth/Core/EventQueue.h"

#include<glad/glad.h>
#include<GLFW/glfw3.h>


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
	
		// Setup Config flags capabilities flags	
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;		//enable docking 
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;	//enable keyboard
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;	//enable keyboard
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;		//Enable multiviewport
	
		ImGuiStyle& style = ImGui::GetStyle(); 
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.WindowRounding = 0.0f; 
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}
		GLFWwindow* window = static_cast<GLFWwindow*>(Game::getInstance().getWindow().getNativeWindow()); 
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 410");
		
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
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void ImGUILayer::end()
	{
		ImGuiIO& io = ImGui::GetIO();
		static bool show = true;
		ImGui::ShowDemoWindow(&show);
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{

			GLFWwindow* backup_current_context = glfwGetCurrentContext();

			ImGui::UpdatePlatformWindows();

			ImGui::RenderPlatformWindowsDefault();

			glfwMakeContextCurrent(backup_current_context);

		}

	}
	
}
