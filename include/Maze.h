#include <GameObject.h>
#include <raylib.h>
#include <vector>

#ifndef _MAZEH_
#define _MAZEH_


class Maze: public GameObject{
private:
	// caches
	Vector2 floor_size;
	Vector3 cube_size;
	Vector3 wire_size;
	// Devirtualizing
	void Draw2D() override;
	void Update() override;
public:
	float maze_scale;
	std::vector<std::vector<bool>> map;
	Maze();
	void Draw3D() override;
};

#endif