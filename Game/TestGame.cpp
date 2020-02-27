#pragma once
#include"Hiraeth.h"
#include<iostream>
class TestGame : public Hiraeth::Game {
public:
	TestGame() {
		
		HIRAETH_CLIENT_INFO("Test Game constructor."); 
	}

	~TestGame() {}
	
};


Hiraeth::Game* Hiraeth::createGameApplication() {
	return new TestGame();
}

