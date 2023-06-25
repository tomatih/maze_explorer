#include <raylib.h>
#include <iostream>

#include <GameScreen.h>
#include <WelcomeScreen.h>
#include <ScreenManager.h>
#include "WinScreen.h"

int main(int argc, char const *argv[])
{
	// screen constants
	const int screenWidth = 800;
	const int screenHeigth = 450;

    // Initial setup
    InitWindow(screenWidth, screenHeigth, "Maze Explorer");
    SetTargetFPS(60);
    SetExitKey(KEY_NULL);
    // DPI awareness
    auto DPI_settings = GetWindowScaleDPI();
    auto scaled_y = DPI_settings.y * GetScreenHeight();
    auto scaled_x = DPI_settings.x * GetScreenWidth();
    SetWindowSize(scaled_x, scaled_y);

	// Game variables
	GameScreen game_screen = GameScreen();
	WelcomeScreen welcome_screen = WelcomeScreen();
    WinScreen win_screen = WinScreen();

	ScreenManager& screen_manager= ScreenManager::getInstance();
	screen_manager.add_screen("Game", &game_screen);
	screen_manager.add_screen("Welcome", &welcome_screen);
    screen_manager.add_screen("Win", &win_screen);

	screen_manager.go_to_screen("Welcome");
	// Game loop
	while (!screen_manager.shouldClose) {
        screen_manager.shouldClose = WindowShouldClose();
		screen_manager.current_screen->run();
	}

	// Cleanup
	screen_manager.current_screen->on_leave();
	CloseWindow();

	return 0;
}
