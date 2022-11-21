#include <WelcomeScreenHandler.h>
#include <raylib.h>

void WelcomeScreenHandler::Draw2D(){}

void WelcomeScreenHandler::Update(){
	if(IsKeyPressed(KEY_ENTER)){
		ScreenManager::getInstance().go_to_screen("Game");
	}

}

void WelcomeScreenHandler::Draw3D(){};