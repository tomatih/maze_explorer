#include <raylib.h>
#include <vector>

#include <GameObject.h>

#ifndef _SCREENH_
#define _SCREENH_


class Screen{
public:
	Camera* camera3D;
	std::vector<GameObject*> game_objects;

	virtual void on_enter() = 0;
	virtual void on_leave() = 0;

	void run();
};

#endif
