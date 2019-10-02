#include "powerUPs.h"

#include "raylib.h"

#include "general/console.h"


PowerUPCharge pwrUPcharge1;
PowerUPCharge pwrUPcharge2;
PowerUPCharge pwrUPcharge3;
PowerUPCharge pwrUPcharge4;
PowerUPCharge pwrUPcharge5;
PowerUPCharge pwrUPcharge6;
PowerUPCharge pwrUPcharge7;
PowerUPCharge pwrUPcharge8;
PowerUPCharge pwrUPcharge9;
PowerUPCharge pwrUPcharge10;
const static float chargesYDivider = 22.5f;
const static float chargesRadiusDivider = 90.0f;
const static float charge1XDivider = 11.42857f;
const static float charge2XDivider = 9.41176f;
const static float charge3XDivider = 8.0f;
const static float charge4XDivider = 6.95652f;
const static float charge5XDivider = 6.15384f;
const static float charge6XDivider = 1.11888f;
const static float charge7XDivider = 1.14285f;
const static float charge8XDivider = 1.16788f;
const static float charge9XDivider = 1.19402f;
const static float charge10XDivider = 1.22137f;
const float pwrUPMinRespawnPosDivider = 11.25f;
const float pwrUPMaxRespawnPosDivider = 22.25f;

Rectangle PowerUP1;
Rectangle PowerUP2;
bool powerUPexists = false;
bool powerUP2exists = false;
Image mouse1;
Texture2D texturaPowerUP;
Texture2D texturaPowerUP2;
int lastTimer = 0;
int lastTimer2 = 0;
const int delayToRespawn = 15;
const static float heightDivider = 15.0f;
const static float widthDivider = 26.666666667f; 
const float powerUPTexOffsetXDivider = 50.0f;
const float powerUPTexOffsetYDivider = 60.0f;
namespace catPong {
	void initPowerUP() {
		PowerUP1.height = screenHeight / heightDivider;
		PowerUP2.height = screenHeight / heightDivider;
		PowerUP1.width = screenWidth / widthDivider;
		PowerUP2.width = screenWidth / widthDivider;
		PowerUP1.x = screenWidth / 2;
		PowerUP2.x = screenWidth / 2;
		PowerUP1.y = screenHeight / 2;
		PowerUP2.y = screenHeight / 2;
		pwrUPcharge1.x = screenWidth / charge1XDivider;
		pwrUPcharge2.x = screenWidth / charge2XDivider;
		pwrUPcharge3.x = screenWidth / charge3XDivider;
		pwrUPcharge4.x = screenWidth / charge4XDivider;
		pwrUPcharge5.x = screenWidth / charge5XDivider;
		pwrUPcharge6.x = screenWidth / charge6XDivider;
		pwrUPcharge7.x = screenWidth / charge7XDivider;
		pwrUPcharge8.x = screenWidth / charge8XDivider;
		pwrUPcharge9.x = screenWidth / charge9XDivider;
		pwrUPcharge10.x = screenWidth / charge10XDivider;
		pwrUPcharge1.y = screenHeight / chargesYDivider;
		pwrUPcharge2.y = screenHeight / chargesYDivider;
		pwrUPcharge3.y = screenHeight / chargesYDivider;
		pwrUPcharge4.y = screenHeight / chargesYDivider;
		pwrUPcharge5.y = screenHeight / chargesYDivider;
		pwrUPcharge6.y = screenHeight / chargesYDivider; 
		pwrUPcharge7.y = screenHeight / chargesYDivider;
		pwrUPcharge8.y = screenHeight / chargesYDivider;
		pwrUPcharge9.y = screenHeight / chargesYDivider;
		pwrUPcharge10.y = screenHeight / chargesYDivider;
		pwrUPcharge1.radius = screenHeight / chargesRadiusDivider;
		pwrUPcharge2.radius = screenHeight / chargesRadiusDivider;
		pwrUPcharge3.radius = screenHeight / chargesRadiusDivider;
		pwrUPcharge4.radius = screenHeight / chargesRadiusDivider;
		pwrUPcharge5.radius = screenHeight / chargesRadiusDivider;
		pwrUPcharge6.radius = screenHeight / chargesRadiusDivider;
		pwrUPcharge7.radius = screenHeight / chargesRadiusDivider;
		pwrUPcharge8.radius = screenHeight / chargesRadiusDivider;
		pwrUPcharge9.radius = screenHeight / chargesRadiusDivider;
		pwrUPcharge10.radius = screenHeight / chargesRadiusDivider;
	}

	void initPowerUPTex() {
		mouse1 = LoadImage("assets/imagenes/PowerUP.png");
		ImageResize(&mouse1, PowerUP1.width*2.4f, PowerUP1.height*2);
		texturaPowerUP = LoadTextureFromImage(mouse1);
		texturaPowerUP2 = LoadTextureFromImage(mouse1);
		UnloadImage(mouse1);
	}
}