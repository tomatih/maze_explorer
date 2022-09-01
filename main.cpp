#include <raylib.h>

int main(int argc, char const *argv[])
{

	// screen constants
	const int screenWidth = 800;
	const int screenHeigth = 450;

	// Initial setup
	InitWindow(screenWidth, screenHeigth, "Maze Explorer");
	SetTargetFPS(60);

	// Camera setup
	Camera camera = {
		.position = {0.0f, 1.0f, 0.0f},
		.target = {0.0f, 1.0f, 1.0f},
		.up = {0.0f, 1.0f, 0.0f},
		.fovy = 60.0f,
		.projection = CAMERA_PERSPECTIVE,
	};
	SetCameraMode(camera, CAMERA_CUSTOM);

	// Game loop
	while (!WindowShouldClose()) {
		// Update Stage
		
		// Drawing stage
		BeginDrawing();
			ClearBackground(RAYWHITE); // clean screen
			BeginMode3D(camera);
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