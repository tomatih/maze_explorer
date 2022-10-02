#include <WelcomeScreen.h>

WelcomeScreen::WelcomeScreen(){
	welcome_text = WelcomeText();
	welcome_text.manager = manager;
	game_objects.push_back(&welcome_text);
	camera3D = nullptr;
}

void WelcomeScreen::on_enter(){

}

void WelcomeScreen::on_leave(){

}