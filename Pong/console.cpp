#include "console.h"

#include <time.h>

#include "raylib.h"

int screenWidth = 800;
int screenHeight = 450;
int cronometer;
float cronometerFlo;
Vector2 screensize1 = { {screensize1.x = 800}, {screensize1.y=450} };
Vector2 screensize2 = { {screensize2.x = 1200}, {screensize2.y = 675} };
static float FPS = 120;
bool pause = 0;
namespace catPong {
	void initConsole() {
		cronometer = (double)clock() / 1000;
		cronometerFlo = static_cast<float>(clock()) / 1000;
		FPS = 120;
		SetTargetFPS(FPS);
	}
}