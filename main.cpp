#include <raylib.h>
#include <iostream>

#include <GameScreen.h>
#include <WelcomeScreen.h>
#include <ScreenManager.h>

int main(int argc, char const *argv[])
{
	// screen constants
	const int screenWidth = 800;
	const int screenHeigth = 450;

	// Game variables
	GameScreen game_screen = GameScreen();
	WelcomeScreen welcome_screen = WelcomeScreen();

	ScreenManager screen_manager= ScreenManager();
	std::cout<<"Screen manager at adress: "<<&screen_manager<<std::endl;
	std::cout<<"Addr before adding: "<<game_screen.manager<<std::endl;
	screen_manager.add_screen("Game", &game_screen);
	std::cout<<"Addr after  adding: "<<game_screen.manager<<std::endl;
	std::cout<<"Addr before adding: "<<welcome_screen.manager<<std::endl;
	screen_manager.add_screen("Welcome", &welcome_screen);
	std::cout<<"Addr before adding: "<<welcome_screen.manager<<std::endl;

	// Initial setup
	InitWindow(screenWidth, screenHeigth, "Maze Explorer");
	SetTargetFPS(60);
	// DPI awareness
	auto DPI_settings = GetWindowScaleDPI();
	auto scaled_y = DPI_settings.y * GetScreenHeight();
	auto scaled_x = DPI_settings.x * GetScreenWidth();
	SetWindowSize(scaled_x, scaled_y);

	screen_manager.go_to_screen("Welcome");
	// Game loop
	while (!WindowShouldClose()) {
		screen_manager.current_screen->run();
	}

	// Cleanup
	screen_manager.current_screen->on_leave();
	CloseWindow();

	return 0;
}
