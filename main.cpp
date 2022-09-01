#include <raylib.h>

int main(int argc, char const *argv[])
{

	const int screenWidth = 800;
	const int screenHeigth = 450;

	InitWindow(screenWidth, screenHeigth, "Maze Explorer");

	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawText("Hello World!", 190, 200, 20, LIGHTGRAY);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}