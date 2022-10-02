#include <Maze.h>
#include <raymath.h>

Maze::Maze() {
	maze_scale = 5;
	map = {
		{1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 0, 0, 1, 0, 0, 1},
		{1, 0, 0, 0, 1, 1, 0, 1, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 1},
		{1, 1, 0, 0, 1, 1, 1, 0, 1},
		{1, 1, 0, 1, 1, 0, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	// cache
	floor_size = {(float)map.size(), (float)map[0].size()};
	floor_size = Vector2Scale(floor_size, maze_scale);
	cube_size = Vector3Scale({1.0f, 1.0f, 1.0f}, maze_scale-0.01); // ofset so wires visible
	wire_size = Vector3Scale({1.0f, 1.0f, 1.0f}, maze_scale);
};

void Maze::Draw3D(){
	// Draw floor
	DrawPlane({0.0f, 0.0f, 0.0f}, floor_size, GRAY);
	// Draw walls
	for(int i=0; i<(int)map.size(); i++){
		for(int j=0; j<(int)map[i].size(); j++){
			// skip empty spaces
			if(!map[i][j]){
				continue;
			}
			// calculate positions
			Vector3 position = {
				maze_scale*(0.5f+i) - floor_size.x/2.0f,
				maze_scale/2,
				maze_scale*(0.5f+j)- floor_size.y/2.0f,
			};
			// Draw calls
			DrawCubeV(position, cube_size, BLUE);
			DrawCubeWiresV(position, wire_size, BLACK);
		}
	}
}

// Devirtualizing
void Maze::Draw2D(){}
void Maze::Update(){}
