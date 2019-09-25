#include "raylib.h"
extern const int screenWidth;
extern const int screenHeight;
extern int cronometer;
extern float cronometerFlo;
extern bool pause;
extern int framesCounter;
namespace sabasa {
	void initCronometers();
	void initFPS();
}