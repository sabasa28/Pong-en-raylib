#include "powerUPs.h"

#include "raylib.h"

Rectangle PowerUP1;
Rectangle PowerUP2;
bool powerUPexists = false;
bool powerUP2exists = false;
Image mouse1;
Image mouse2;
Texture2D texturaPowerUP;
Texture2D texturaPowerUP2;
int lastTimer = 0;
int lastTimer2 = 0;
namespace sabasa {
	void initPowerUP() {
		PowerUP1.height = 30;
		PowerUP2.height = 30;
		PowerUP1.width = 30;
		PowerUP2.width = 30;
		PowerUP1.x = 400;
		PowerUP1.y = -10;
		PowerUP2.x = 400;
		PowerUP2.y = -10;
	}

	void initPowerUPTex() {
		mouse1 = LoadImage("imagenes/white_mouse.png");
		mouse2 = LoadImage("imagenes/gray_mouse.png");
		ImageResize(&mouse1, PowerUP1.width, PowerUP1.height);
		ImageResize(&mouse2, PowerUP2.width, PowerUP2.height);
		texturaPowerUP = LoadTextureFromImage(mouse1);
		texturaPowerUP2 = LoadTextureFromImage(mouse2);
		UnloadImage(mouse2);
		UnloadImage(mouse1);
	}
}