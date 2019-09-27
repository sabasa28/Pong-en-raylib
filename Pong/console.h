#ifndef CONSOLE_H
#define CONSOLE_H
#include "raylib.h"
extern int screenWidth;
extern int screenHeight;
extern int cronometer;
extern float cronometerFlo;
extern bool pause;
namespace catPong {
	void initCronometers();
	void initFPS();
}
#endif // CONSOLE_H