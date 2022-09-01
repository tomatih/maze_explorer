#include <raylib.h>
#include <raymath.h>

struct Player{
public:
	Vector3 position;
	Quaternion rotation;
private:
	float speed;
	Camera camera;
	Vector3 camera_postion_offset;
public:
	Player(){
		position = {0.0f, 0.0f,0.0f};
		speed = 5.0f;
		camera_postion_offset = {0.0f,1.0f,0.0f};
		camera = {
			.position = Vector3Add(position, camera_postion_offset),
			.target = {0.0f, 1.0f, 1.0f},
			.up = {0.0f, 1.0f, 0.0f},
			.fovy = 60.0f,
			.projection = CAMERA_PERSPECTIVE,
		};
		SetCameraMode(camera, CAMERA_CUSTOM);
	}

	void beginDrawing3D(){
		BeginMode3D(camera);
	}

	void update(){
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
				DrawCube({2.5f,0.5f,0.0f}, 1, 1, 1, RED);
				DrawCubeWires({2.5f,0.5f,0.0f}, 1, 1, 1, BLACK);
			EndMode3D();
			DrawFPS(0, 0);
		EndDrawing();
	}

	// Cleanup
	CloseWindow();

	return 0;
}