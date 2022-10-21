#include <WelcomeScreen.h>
#include <iostream>

WelcomeScreen::WelcomeScreen(){
	welcome_text = WelcomeScreenHandler();
	game_objects.push_back(&welcome_text);
    title_text = TextObject("Maze Explorer",75);
    game_objects.push_back(&title_text);
	camera3D = nullptr;
}

void WelcomeScreen::on_enter(){
	welcome_text.manager = manager;
}

void WelcomeScreen::on_leave(){
}