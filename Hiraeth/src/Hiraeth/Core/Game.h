#pragma once
#include"Hiraeth/Core/CoreEngine.h"#include"Hiraeth/Core/Window.h"
#include"Hiraeth/Events/ApplicationEvent.h"
#include"Hiraeth/Core/LayerStack.h"
#include"Hiraeth/ImGUI/ImGUILayer.h"
//TEMPORARY 
#include"Hiraeth/Core/Window.h"
//why not make it a singleton 
namespace Hiraeth {
	class HIRAETH_API Game {
	public:
	
		
		void run();

		//Event call back functions 
		void OnWindowClose(WindowCloseEvent* windowCloseEvent);

		Window& getWindow();
		static Game& getInstance();// { return *m_Instance; }
		Game();
		virtual ~Game();

		//functions that can be implemented by user
		virtual void UserRun() {};
	private: 
		LayerStack m_LayerStack; 
		ImGUILayer* m_ImGUILayer; 
		std::unique_ptr<Window> m_Window; 
		bool m_Running; 

	private: 
		static Game* m_Instance; 
	};
	//to be defined by the user when derived game created
	 Game* createGameApplication(); 
}

