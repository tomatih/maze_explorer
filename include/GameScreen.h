#include <Screen.h>
#include <Player.h>
#include <Maze.h>

#ifndef _GAMESCREENH_
#define _GAMESCREENH_

class GameScreen: public Screen{
private:
	Player player;
	Maze maze;
public:
	void on_enter() override;

	void on_leave() override;
};

#endif
