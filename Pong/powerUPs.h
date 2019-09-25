#ifndef POWERUPS_H
#define POWERUPS_H
#include "raylib.h"
extern Rectangle PowerUP1;
extern Rectangle PowerUP2;
extern bool powerUPexists;
extern bool powerUP2exists;
extern Image mouse1;
extern Image mouse2;
extern Texture2D texturaPowerUP;
extern Texture2D texturaPowerUP2;
extern int lastTimer;
extern int lastTimer2;
extern int delayToRespawn;
namespace catPong {
	void initPowerUP();
	void initPowerUPTex();
}
#endif // POWERUPS_H
