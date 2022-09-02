#include <ostream>
#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <math.h>

struct Player{
public:
	Vector3 position; // player position
	Vector3 front;
	Camera camera;
private:
	float speed; // movement speed
	//Camera camera; // 3D camera object
	Vector3 camera_postion_offset; // basically player height

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
		// account for diagonal movement
		travel_distance = Vector3Normalize(travel_distance);
		// scale by speed (framerate independent)
		travel_distance = Vector3Scale(travel_distance, speed*GetFrameTime());
		// actually move the player
		position = Vector3Add(position, travel_distance);
	}

	void update_orientation(){
		/*if(IsKeyDown(KEY_UP)){
			front.z += 1.0f;
		}
		if(IsKeyDown(KEY_DOWN)){
			front.z -= 1.0f;
		}
		if(IsKeyDown(KEY_RIGHT)){
			front.x -= 1.0f;
		}
		if(IsKeyDown(KEY_LEFT)){
			front.x += 1.0f;
		}*/
		if(IsKeyPressed(KEY_RIGHT)){
			std::cout << "before:" << front.x << " " << front.z << std::endl;
			float x = front.x * cos(PI/2) - front.z*sin(PI/2);
			float z = front.x * sin(PI/2) - front.z*cos(PI/2);
			front.x = x;
			front.z = z;
			std::cout << "after:" << front.x << " " << front.z << std::endl;
		}
	}

	void update_camera(){
		camera.position = Vector3Add(position, camera_postion_offset);
		camera.target = Vector3Add(camera.position, front);
	}

public:
	Player(){
		// basic init
		position = {0.0f, 0.0f,0.0f};
		speed = 5.0f;
		front = {0.0f, 0.0f, 1.0f};
		// camera init
		camera_postion_offset = {0.0f,1.0f,0.0f};
		camera = {
			.position = Vector3Add(position, camera_postion_offset),
			.target = Vector3Add(Vector3Add(position, camera_postion_offset), front),
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

	// Initial setup
	InitWindow(screenWidth, screenHeigth, "Maze Explorer");
	SetTargetFPS(60);


	// Game loop
	while (!WindowShouldClose()) {
		// Update Stage
		player.update();
		// Drawing stage
		BeginDrawing();
			ClearBackground(RAYWHITE); // clean screen
			player.beginDrawing3D();
				DrawPlane({0.0f, 0.0f, 0.0f}, {32.0f, 32.0f}, LIGHTGRAY);
				DrawCube({1.0f,0.5f,7.0f}, 1, 1, 1, RED);
				DrawCubeWires({1.0f,0.5f,7.0f}, 1, 1, 1, BLACK);
			EndMode3D();
			// DEBUG DISPLAY
			DrawFPS(0, 0);
			DrawRectangle(GetScreenWidth()-64, 0, 64, 64, LIGHTGRAY);
			DrawRectangle((-2*player.position.x) + GetScreenWidth() - 32 -1, (-2*player.position.z) + 32 -1, 2, 2, BLUE);
			DrawRectangle((-2*player.camera.target.x) + GetScreenWidth() - 32 -1, (-2*player.camera.target.z) + 32 -1, 2, 2, RED);
		EndDrawing();
	}

	// Cleanup
	CloseWindow();

	return 0;
}