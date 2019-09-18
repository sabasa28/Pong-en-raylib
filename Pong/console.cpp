#include "console.h"
#include "raylib.h"
#include <time.h>
const int screenWidth = 800;
const int screenHeight = 450;
int cronometer;
float cronometerflo;
float FPS = 120;
bool pause = 0;
int framesCounter = 0;
float StartigFPS;
bool restarted = false;
bool menu = true;

void initCronometers() {
	cronometer = (double)clock() / 1000;
	cronometerflo = (double)clock() / 1000;
}

void initFPS() {
	StartigFPS = FPS;
}