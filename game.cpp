#include "raylib_rzf.h"

#include <iostream>

float randFloatRange(float mn, float mx) {
	return static_cast<float>(GetRandomValue(mn, mx));
}

// I know it's stupid. I'm still learning cpp and cmake
// I used to js and csharp shenanigans
#ifndef DEBUG_MODE
int WinMain()
#else
int main()
#endif
{
	const int screenWidth{ 1280 };
	const int screenHeight{ 720 };

	InitWindow(screenWidth, screenHeight, "RAYLIB RZF");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);

		DrawText("RAYLIB RZF!!", 24, 16, 72, WHITE);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
