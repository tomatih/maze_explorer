#include <ostream>
#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <math.h>

struct Player{
public:
	Vector3 position; // player position
	Quaternion orientation;
	Camera camera;
private:
	float speed; // movement speed
	float rotation_speed;
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
		travel_distance = Vector3RotateByQuaternion(travel_distance, orientation);
		// ignore vertical componet of orientaion (no flying)
		travel_distance = {travel_distance.x, 0.0f, travel_distance.z};
		// account for diagonal movement
		travel_distance = Vector3Normalize(travel_distance);
		// scale by speed (framerate independent)
		travel_distance = Vector3Scale(travel_distance, speed*GetFrameTime());
		// actually move the player
		position = Vector3Add(position, travel_distance);
	}

	void update_orientation(){
		// start assuming no rotation
		Quaternion new_rotation = QuaternionIdentity();
		// crate a rotaion quatrnion based on imput
		Vector2 mouse_delta = GetMouseDelta();
		// ignore the first frame
		if(Vector2Equals(mouse_delta, {(float)GetScreenWidth()/2, (float)GetScreenHeight()/2})){
			return;
		}
		new_rotation = QuaternionFromEuler(rotation_speed*mouse_delta.y, -rotation_speed*mouse_delta.x, 0.0f);
		
		// add desired rotation to current orientaion
		orientation = QuaternionMultiply(new_rotation, orientation);
		orientation = QuaternionNormalize(orientation);
		//reset mouse position
		SetMousePosition(GetScreenWidth()/2, GetScreenHeight()/2);
	}

	void update_camera(){
		camera.position = Vector3Add(position, camera_postion_offset);
		camera.target = Vector3Add(camera.position,Vector3RotateByQuaternion(camera_target_offset, orientation));
	}

public:
	Player(){
		// basic init
		position = {0.0f, 0.0f,0.0f};
		speed = 5.0f;
		orientation = QuaternionIdentity();
		rotation_speed = PI/1000;
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
	HideCursor();
	SetMousePosition(GetScreenWidth()/2, GetScreenHeight()/2);
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