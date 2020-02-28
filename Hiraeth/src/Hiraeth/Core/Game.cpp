#include"pch.h"
#include "Game.h"
#include"Hiraeth/Events/KeyEvent.h"
#include"Hiraeth/Core/EventQueue.h"
#include"Platform/Windows/WinWindow.h"
#include"Hiraeth/Core/Log.h"

namespace Hiraeth {

	Game::Game():
		m_Running(true)
	{
		std::unique_ptr<Window> mWIndow = Window::createWindow();

		glClearColor(1, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		mWIndow->onUpdate();

		EventQueue::getInstance()->subscribe<Game, WindowCloseEvent>(this, &Game::OnWindowClose);
	}

	Game::~Game()
	{
	}

	void Game::OnWindowClose(WindowCloseEvent* windowCloseEvent)
	{
		m_Running = false; 
		
	}

	
	void Game::run()
	{
		HIRAETH_CORE_INFO("Engine is now running."); 
		while (m_Running) 
		{
			glClearColor(1, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			glfwPollEvents();
			EventQueue::getInstance()->relayEvents(); 
		}
	}

}