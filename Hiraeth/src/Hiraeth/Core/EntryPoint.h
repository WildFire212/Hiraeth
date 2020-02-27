#pragma once
#ifdef HI_WINDOWS_PLATFORM
extern Hiraeth::Game* Hiraeth::createGameApplication();		//for extending the scope of the function 
int main(int argc , char** argv) {
		Hiraeth::Log::init(); 
		
		auto* game = Hiraeth::createGameApplication();
		game->run(); 
		delete game; 

}
#endif