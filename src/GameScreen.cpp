#include <GameScreen.h>

void GameScreen::on_enter(){
	// initialise mouse
	HideCursor();
	SetMousePosition(GetRenderWidth()/2, GetRenderHeight()/2);
    //reset player
    player.initialize();
    if(handler.isPaused()){
        handler.pauseGame();
    }
    tutorialPrompt.reset();
}

void GameScreen::on_leave(){
	// free mouse
	ShowCursor();
}

GameScreen::GameScreen() : handler(&player), tutorialPrompt(handler) {
    // initialise game objects
    player = Player();
    game_objects.push_back(&player);
    camera3D = &player.camera;

    //tutorialPrompt = TutorialPrompt();
    game_objects.push_back(&tutorialPrompt);

    //handler = GameHandler(&player);
    game_objects.push_back(&handler);

    maze = Maze();
    player.maze = &maze;
    game_objects.push_back(&maze);

    player.pos_text = &pos_text;
    game_objects.push_back(&pos_text);
}
