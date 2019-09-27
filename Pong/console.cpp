#include "console.h"

#include <time.h>

#include "raylib.h"

int screenWidth = 800;
int screenHeight = 450;
int cronometer;
float cronometerFlo;
static float FPS = 120;
bool pause = 0;
namespace catPong {
	void initCronometers() {
		cronometer = (double)clock() / 1000;
		cronometerFlo = (double)clock() / 1000;
	}

	void initFPS() {
		FPS = 120;
		SetTargetFPS(FPS);
	}
}