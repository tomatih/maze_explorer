#include <raylib.h>

#include <GameObject.h>
#include <Maze.h>
#include "TextObject.h"

#ifndef _PLAYERH_
#define _PLAYERH_

class Player: public GameObject{
public:
	Vector3 position; // player position
	Camera camera;
	Maze* maze;
    bool paused = false;
    TextObject* pos_text;

	Player();

	void Update();
private:
    float speed; // movement speed
	float rotation; // player world orientation
	float head_rotation; // up/down head rotation
	float rotation_speed; // head rotation speed
	Vector3 last_position;
	//Camera camera; // 3D camera object
	Vector3 camera_postion_offset; // basically player height
	Vector3 camera_target_offset; // where player is lookign

	void update_position();

	void update_orientation();

	void update_camera();

	void check_collisions();

	// unvirtualising
	void Draw2D(); 
	void Draw3D();
};

#endif
