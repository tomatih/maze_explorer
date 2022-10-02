#include <ScreenManager.h>

#include <iostream>
#include <stdexcept>

void ScreenManager::add_screen(std::string name, Screen *screen){
	screen->manager = this;
	screens[name] = screen;
}

void ScreenManager::go_to_screen(std::string screen_name){
	std::cout<<"Switching to screen "<<screen_name<<std::endl;
	std::cout<<"Performed by: "<<this<<std::endl;
	// ensure new screen exist
	if(screens.count(screen_name)==0){
		throw std::runtime_error("Condn't find screen named"+screen_name);
	}
	std::cout<<"Target screen exists!"<<std::endl;
	// unload current screen
	if(current_screen!=nullptr){
		current_screen->on_leave();
	}
	current_screen = screens[screen_name];
	current_screen->on_enter();
}
