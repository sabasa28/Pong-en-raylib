#ifndef CONSOLE_H
#define CONSOLE_H
#include "raylib.h"
extern const int screenWidth;
extern const int screenHeight;
extern const int halfScreenWidth;
extern const int halfScreenHeight;
extern int cronometer;
extern float cronometerFlo;
extern bool pause;
extern int framesCounter;
namespace catPong {
	void initCronometers();
	void initFPS();
}
#endif // CONSOLE_H