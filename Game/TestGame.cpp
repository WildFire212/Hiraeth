#pragma once
#include"Hiraeth.h"


class TestGame : public Hiraeth::Game {
public:
	TestGame() {
		HIRAETH_CLIENT_INFO("Test Game constructor."); 
	
	}

	virtual void UserRun() override
	{
		//HIRAETH_CLIENT_INFO(Hiraeth::Input::getMouseX()); 
	}
	~TestGame() {}
	
};


Hiraeth::Game* Hiraeth::createGameApplication() {
	return new TestGame();
}
