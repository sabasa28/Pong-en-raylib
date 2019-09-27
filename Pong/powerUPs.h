#ifndef POWERUPS_H
#define POWERUPS_H
#include "raylib.h"
struct PowerUPCharge
{
	int x;
	int y;
	int radius;
};
extern PowerUPCharge pwrUPcharge1;
extern PowerUPCharge pwrUPcharge2;
extern PowerUPCharge pwrUPcharge3;
extern PowerUPCharge pwrUPcharge4;
extern PowerUPCharge pwrUPcharge5;
extern PowerUPCharge pwrUPcharge6;
extern PowerUPCharge pwrUPcharge7;
extern PowerUPCharge pwrUPcharge8;
extern PowerUPCharge pwrUPcharge9;
extern PowerUPCharge pwrUPcharge10;
extern Rectangle PowerUP1;
extern Rectangle PowerUP2;
extern float pwrUPMinRespawnPosDivider;
extern float pwrUPMaxRespawnPosDivider;
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
