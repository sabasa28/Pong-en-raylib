#ifndef CONSOLE_H
#define CONSOLE_H
#include "raylib.h"
extern int screenWidth;	
extern int screenHeight;
extern Vector2 screensize1;
extern Vector2 screensize2;
extern int cronometer;
extern float cronometerFlo;
extern bool pause;
namespace catPong {
	void initConsole();
}
#endif // CONSOLE_H