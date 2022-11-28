#include <GameScreen.h>

void GameScreen::on_enter(){
	// initialise game objects
	player = Player();
	game_objects.push_back(&player);
	camera3D = &player.camera;

	maze = Maze();
	player.maze = &maze;
	game_objects.push_back(&maze);

    player.pos_text = &pos_text;
    game_objects.push_back(&pos_text);

	// initialise mouse
	HideCursor();
	SetMousePosition(GetRenderWidth()/2, GetRenderHeight()/2);
}

void GameScreen::on_leave(){
	// free mouse
	ShowCursor();
}
