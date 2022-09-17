#include <ostream>
#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <math.h>
#include <vector>

struct Maze{
private:
	// caches
	Vector2 floor_size;
	Vector3 cube_size;
	Vector3 wire_size;

public:
	float maze_scale;
	std::vector<std::vector<bool>> map;

	Maze(){
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

	void Draw(){
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

};

struct Player{
public:
	Vector3 position; // player position
	Camera camera;
	Maze* maze;
private:
	float speed; // movement speed
	float rotation; // player world orientation
	float head_rotation; // up/down head rotation
	float rotation_speed; // head rotation speed
	Vector3 last_position;
	//Camera camera; // 3D camera object
	Vector3 camera_postion_offset; // basically player height
	Vector3 camera_target_offset; // where player is lookign

	void update_position(){
		// init travel vector
		Vector3 travel_distance = {0.0f, 0.0f, 0.0f};
		// get player input
		if(IsKeyDown(KEY_W)){
			travel_distance.z += 1.0f;
		}
		if(IsKeyDown(KEY_S)){
			travel_distance.z -= 1.0f;
		}
		if(IsKeyDown(KEY_D)){
			travel_distance.x -= 1.0f;
		}
		if(IsKeyDown(KEY_A)){
			travel_distance.x += 1.0f;
		}
		// rotate to move where looking
		travel_distance = Vector3RotateByAxisAngle(travel_distance, camera.up, rotation);
		// account for diagonal movement
		travel_distance = Vector3Normalize(travel_distance);
		// scale by speed (framerate independent)
		travel_distance = Vector3Scale(travel_distance, speed*GetFrameTime());
		// actually move the player
		last_position = position;
		position = Vector3Add(position, travel_distance);
	}

	void update_orientation(){
		// user input
		if(IsKeyDown(KEY_RIGHT)){
			rotation -= GetFrameTime()*rotation_speed;
		}
		if(IsKeyDown(KEY_LEFT)){
			rotation += GetFrameTime()*rotation_speed;
		}
		if(IsKeyDown(KEY_DOWN)){
			head_rotation -= GetFrameTime()*rotation_speed;
		}
		if(IsKeyDown(KEY_UP)){
			head_rotation += GetFrameTime()*rotation_speed;
		}
		auto mouse_delta = GetMouseDelta();
		SetMousePosition(GetRenderWidth()/2, GetRenderHeight()/2);

		rotation -= GetFrameTime()*rotation_speed*mouse_delta.x;
		head_rotation -= GetFrameTime()*rotation_speed*mouse_delta.y;
		
		// angle security
		if(rotation > 2*PI){
			rotation -= 2*PI;
		}
		else if(rotation < 0){
			rotation += 2*PI;
		}

		// head angle limitation
		if(head_rotation > PI/4){
			head_rotation = PI/4;
		}
		else if(head_rotation < -PI/4){
			head_rotation = -PI/4;
		}
	}

	void update_camera(){
		// move with player
		camera.position = Vector3Add(position, camera_postion_offset);
		// horizontal rotation
		auto tmp_target = Vector3RotateByAxisAngle(camera_target_offset, camera.up, rotation);
		// vertical rotation
		tmp_target = Vector3RotateByAxisAngle(tmp_target, Vector3Perpendicular(tmp_target), head_rotation);
		/// to player space
		camera.target = Vector3Add(camera.position, tmp_target);
	}

	void check_collisions(){
		// calculate grid position
		Vector2 grid_pos = {
			round(position.x / maze->maze_scale) + maze->map.size()/2,
			round(position.z / maze->maze_scale) + maze->map[0].size()/2
		};
		// check occupancy
		if(!maze->map[grid_pos.x][grid_pos.y]){
			return;
		}
		// correct position
		position = last_position;
	}

public:
	Player(){
		// basic init
		position = {0.0f, 0.0f,0.0f};
		speed = 5.0f;
		rotation = PI/2;
		head_rotation = 0.0f;
		rotation_speed = 1.0f;
		// camera init
		camera_postion_offset = {0.0f,1.0f,0.0f};
		camera_target_offset = {0.0f, 0.0f, 1.0f};
		camera = {
			.position = Vector3Add(position, camera_postion_offset),
			.target = Vector3Add(Vector3Add(position, camera_postion_offset), camera_target_offset),
			.up = {0.0f, 1.0f, 0.0f},
			.fovy = 60.0f,
			.projection = CAMERA_PERSPECTIVE,
		};
		SetCameraMode(camera, CAMERA_CUSTOM);
	}

	// camera draw API forward
	void beginDrawing3D(){
		BeginMode3D(camera);
	}

	void update(){
		update_orientation();
		update_position();
		check_collisions();
		update_camera();
	}
};

int main(int argc, char const *argv[])
{

	// screen constants
	const int screenWidth = 800;
	const int screenHeigth = 450;

	// Game variables
	Player player = Player{};
	Maze maze = Maze{};
	player.maze = &maze;

	// Initial setup
	InitWindow(screenWidth, screenHeigth, "Maze Explorer");
	SetTargetFPS(60);

	HideCursor();
	SetMousePosition(GetRenderWidth()/2, GetRenderHeight()/2);

	// Game loop
	while (!WindowShouldClose()) {
		// Update Stage
		player.update();
		// Drawing stage
		BeginDrawing();
			ClearBackground(RAYWHITE); // clean screen
			player.beginDrawing3D();
				maze.Draw();
			EndMode3D();
			// DEBUG DISPLAY
			DrawFPS(0, 0);
		EndDrawing();
	}

	// Cleanup
	CloseWindow();

	return 0;
}