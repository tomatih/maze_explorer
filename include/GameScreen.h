#include <Screen.h>
#include <Player.h>
#include <Maze.h>
#include "TextObject.h"

#ifndef _GAMESCREENH_
#define _GAMESCREENH_

class GameScreen: public Screen{
private:
	Player player;
	Maze maze;
    TextObject pos_text = TextObject("-1,-1",20,{100,10});;
public:
	void on_enter() override;

	void on_leave() override;
};

#endif
