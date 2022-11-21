#include <WelcomeScreen.h>
#include <iostream>

WelcomeScreen::WelcomeScreen() : handler(),
                                 title_text("Maze Explorer", 75, {}),
                                 hint_text("Press Enter to play",30, {}){
	game_objects.push_back(&handler);
    float screen_half_width = (float)GetRenderWidth() / 2.0f;
    float screen_half_height = (float)GetRenderHeight() / 2.0f;
    title_text.updatePosition({screen_half_width, screen_half_height});
    game_objects.push_back(&title_text);
    hint_text.updatePosition({screen_half_width, screen_half_height+70});
    game_objects.push_back(&hint_text);
	camera3D = nullptr;
}

void WelcomeScreen::on_enter(){
}

void WelcomeScreen::on_leave(){
}