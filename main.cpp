#include <ostream>
#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <math.h>
#include <stdexcept>
#include <string>
#include <vector>
#include <map>

#include <GameScreen.h>
#include <ScreenManager.h>

int main(int argc, char const *argv[])
{
	// screen constants
	const int screenWidth = 800;
	const int screenHeigth = 450;

	// Game variables
	GameScreen game_screen = GameScreen();

	ScreenManager screen_manager= ScreenManager();
	screen_manager.add_screen("Game", &game_screen);

	// Initial setup
	InitWindow(screenWidth, screenHeigth, "Maze Explorer");
	SetTargetFPS(60);
	// DPI awareness
	auto DPI_settings = GetWindowScaleDPI();
	auto scaled_y = DPI_settings.y * GetScreenHeight();
	auto scaled_x = DPI_settings.x * GetScreenWidth();
	SetWindowSize(scaled_x, scaled_y);

	screen_manager.go_to_screen("Game");
	// Game loop
	while (!WindowShouldClose()) {
		screen_manager.current_screen->run();
	}

	// Cleanup
	screen_manager.current_screen->on_leave();
	CloseWindow();

	return 0;
}