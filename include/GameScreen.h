#include <Screen.h>
#include <Player.h>
#include <Maze.h>
#include "TextObject.h"
#include "GameHandler.h"
#include "TutorialPrompt.h"

#ifndef _GAMESCREENH_
#define _GAMESCREENH_

class GameScreen: public Screen{
private:
	Player player;
	Maze maze;
    GameHandler handler;
    TutorialPrompt tutorialPrompt;
    TextObject pos_text = TextObject("-1,-1",20,{0.085,0.02});;
public:
    GameScreen();
	void on_enter() override;
	void on_leave() override;
};

#endif
