#include <raylib.h>

int main(int argc, char const *argv[])
{

	// screen constants
	const int screenWidth = 800;
	const int screenHeigth = 450;

	// Initial setup
	InitWindow(screenWidth, screenHeigth, "Maze Explorer");
	SetTargetFPS(60);

	// Game loop
	while (!WindowShouldClose()) {
		// Drawing stage
		BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawText("Hello World!", 190, 200, 20, LIGHTGRAY);
		EndDrawing();
	}

	// Cleanup
	CloseWindow();

	return 0;
}