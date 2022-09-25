#include <Screen.h>

void Screen::run(){
	// update
	for(auto obj : game_objects){
		obj -> Update();
	}
	// draw
	BeginDrawing();
	ClearBackground(RAYWHITE);
	// 3D stage
	if(camera3D != nullptr){
		BeginMode3D(*camera3D);
		for(auto obj: game_objects){
			obj -> Draw3D();
		}
		EndMode3D();
	}
	// 2D stage
	for(auto obj: game_objects){
		obj -> Draw2D();
	}
	EndDrawing();
};