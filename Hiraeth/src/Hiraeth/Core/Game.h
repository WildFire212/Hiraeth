#pragma once
#include"Hiraeth/Core/CoreEngine.h"#include"Hiraeth/Core/Window.h"
#include"Hiraeth/Events/ApplicationEvent.h"
//why not make it a singleton 
namespace Hiraeth {
	class HIRAETH_API Game {
	public : 
		Game();
		virtual ~Game();
		void run();
		
		//Event call back functions 
		void OnWindowClose(WindowCloseEvent* windowCloseEvent);
	private: 		  
		bool m_Running; 
	};
	//to be defined by the user when derived game created
	 Game* createGameApplication(); 
}

