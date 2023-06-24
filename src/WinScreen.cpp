#include "WinScreen.h"

WinScreen::WinScreen() : win_text("You have escaped the maze!", 50, {0.5, 0.5}) {
    game_objects.push_back(&win_text);
}

void WinScreen::on_enter() {
}

void WinScreen::on_leave() {

}
