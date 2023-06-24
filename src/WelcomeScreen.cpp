#include <WelcomeScreen.h>
#include <iostream>

WelcomeScreen::WelcomeScreen() : handler(),
                                 title_text("Maze Explorer", 75, {0.5, 0.5}),
                                 hint_text("Press Enter to play",30, {0.5, 0.6}){
	game_objects.push_back(&handler);
    game_objects.push_back(&title_text);
    game_objects.push_back(&hint_text);
	camera3D = nullptr;
}

void WelcomeScreen::on_enter(){
}

void WelcomeScreen::on_leave(){
}