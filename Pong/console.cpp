#include "console.h"

#include <time.h>

#include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 450;
const int halfScreenWidth = 400;
const int halfScreenHeight = 225;
int cronometer;
float cronometerFlo;
static float FPS = 120;
bool pause = 0;
int framesCounter = 0;
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