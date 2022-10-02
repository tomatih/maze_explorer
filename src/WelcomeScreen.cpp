#include <WelcomeScreen.h>
#include <iostream>

WelcomeScreen::WelcomeScreen(){
	welcome_text = WelcomeText();
	game_objects.push_back(&welcome_text);
	camera3D = nullptr;
}

void WelcomeScreen::on_enter(){
	welcome_text.manager = manager;
}

void WelcomeScreen::on_leave(){
}