#include "WinScreen.h"

WinScreen::WinScreen() : win_text("You have escaped the maze!", 50, {}) {
    float screen_half_width = (float)GetRenderWidth() / 2.0f;
    float screen_half_height = (float)GetRenderHeight() / 2.0f;
    win_text.updatePosition({screen_half_width, screen_half_height});
    game_objects.push_back(&win_text);
}

void WinScreen::on_enter() {
}

void WinScreen::on_leave() {

}
