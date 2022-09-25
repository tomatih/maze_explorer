#include <ostream>
#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <math.h>
#include <stdexcept>
#include <string>
#include <vector>
#include <map>

#include <Screen.h>
#include <Maze.h>
#include <Player.h>

class ScreenManager{
private:
	std::map<std::string, Screen*> screens;

public:
	Screen* current_screen;

	void add_screen(std::string name, Screen* screen){
		screens[name] = screen;
	}

	void go_to_screen(std::string screen_name){
		// ensure new screen exist
		if(screens.find(screen_name)==screens.end()){
			throw std::runtime_error("Condn't find screen named"+screen_name);
		}
		// unload current screen
		if(current_screen!=nullptr){
			current_screen->on_leave();
		}
		current_screen = screens[screen_name];
		current_screen->on_enter();
	}

};


class GameScreen: public Screen{
private:
	Player player;
	Maze maze;
public:
	void on_enter() override{
		// initialise game objects
		player = Player();
		game_objects.push_back(&player);
		camera3D = &player.camera;

		maze = Maze();
		player.maze = &maze;
		game_objects.push_back(&maze);

		// initialise mouse
		HideCursor();
		SetMousePosition(GetRenderWidth()/2, GetRenderHeight()/2);
	}

	void on_leave() override{
		// free mouse
		ShowCursor();
	}
};

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