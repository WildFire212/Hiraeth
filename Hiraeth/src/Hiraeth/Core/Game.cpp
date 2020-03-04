#include"pch.h"
#include "Game.h"
#include"Hiraeth/Events/KeyEvent.h"
#include"Hiraeth/Core/EventQueue.h"
#include"Platform/Windows/WinWindow.h"
#include"Hiraeth/Core/Log.h"

namespace Hiraeth {
	
	Game* Game::m_Instance = nullptr; 
	
	Game::Game():
		m_Running(true)
	{
		m_Window= Window::createWindow();
		EventQueue::getInstance()->subscribe<Game, WindowCloseEvent>(this, &Game::OnWindowClose);
		m_Instance = this; 
		m_ImGUILayer = new ImGUILayer();
		m_LayerStack.pushOverLay(m_ImGUILayer); 
		m_ImGUILayer->onAttach(); 
	}

	Game::~Game()
	{
	}

	void Game::OnWindowClose(WindowCloseEvent* windowCloseEvent)
	{
		m_Running = false; 
	}
		

	Window& Game::getWindow()
	{
		return *m_Window; 
	}

	 Game& Game::getInstance()
	{
		return *m_Instance; 
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
			m_ImGUILayer->begin(); 
			m_ImGUILayer->end(); 
			m_Window->onUpdate(); 
		}
	}

}