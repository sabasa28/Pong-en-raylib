#include "powerUPs.h"

#include "raylib.h"

#include "console.h"

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

static float heightDivider = 15.0f;
static float widthDivider = 26.666666667f;
namespace catPong {
	void initPowerUP() {
		PowerUP1.height = screenHeight / heightDivider;
		PowerUP2.height = screenHeight / heightDivider;
		PowerUP1.width = screenWidth / widthDivider;
		PowerUP2.width = screenWidth / widthDivider;
		PowerUP1.x = halfScreenWidth;
		PowerUP2.x = halfScreenWidth;
		PowerUP1.y = halfScreenHeight;
		PowerUP2.y = halfScreenHeight;
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