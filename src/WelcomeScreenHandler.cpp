#include <WelcomeScreenHandler.h>
#include <raylib.h>

WelcomeScreenHandler::WelcomeScreenHandler(){}

void WelcomeScreenHandler::Draw2D(){}

void WelcomeScreenHandler::Update(){
	if(IsKeyPressed(KEY_ENTER)){
		manager->go_to_screen("Game");
	}

}

void WelcomeScreenHandler::Draw3D(){};