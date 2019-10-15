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
		PowerUP1.height = static_cast<float>(screenHeight) / heightDivider;
		PowerUP2.height = static_cast<float>(screenHeight) / heightDivider;
		PowerUP1.width = static_cast<float>(screenWidth) / widthDivider;
		PowerUP2.width = static_cast<float>(screenWidth) / widthDivider;
		PowerUP1.x = static_cast<float>(screenWidth) / 2;
		PowerUP2.x = static_cast<float>(screenWidth) / 2;
		PowerUP1.y = static_cast<float>(screenHeight) / 2;
		PowerUP2.y = static_cast<float>(screenHeight) / 2;
		pwrUPcharge1.x = static_cast<float>(screenWidth) / charge1XDivider;
		pwrUPcharge2.x = static_cast<float>(screenWidth) / charge2XDivider;
		pwrUPcharge3.x = static_cast<float>(screenWidth) / charge3XDivider;
		pwrUPcharge4.x = static_cast<float>(screenWidth) / charge4XDivider;
		pwrUPcharge5.x = static_cast<float>(screenWidth) / charge5XDivider;
		pwrUPcharge6.x = static_cast<float>(screenWidth) / charge6XDivider;
		pwrUPcharge7.x = static_cast<float>(screenWidth) / charge7XDivider;
		pwrUPcharge8.x = static_cast<float>(screenWidth) / charge8XDivider;
		pwrUPcharge9.x = static_cast<float>(screenWidth) / charge9XDivider;
		pwrUPcharge10.x = static_cast<float>(screenWidth) / charge10XDivider;
		pwrUPcharge1.y = static_cast<float>(screenHeight) / chargesYDivider;
		pwrUPcharge2.y = static_cast<float>(screenHeight) / chargesYDivider;
		pwrUPcharge3.y = static_cast<float>(screenHeight) / chargesYDivider;
		pwrUPcharge4.y = static_cast<float>(screenHeight) / chargesYDivider;
		pwrUPcharge5.y = static_cast<float>(screenHeight) / chargesYDivider;
		pwrUPcharge6.y = static_cast<float>(screenHeight) / chargesYDivider; 
		pwrUPcharge7.y = static_cast<float>(screenHeight) / chargesYDivider;
		pwrUPcharge8.y = static_cast<float>(screenHeight) / chargesYDivider;
		pwrUPcharge9.y = static_cast<float>(screenHeight) / chargesYDivider;
		pwrUPcharge10.y = static_cast<float>(screenHeight) / chargesYDivider;
		pwrUPcharge1.radius = static_cast<float>(screenHeight) / chargesRadiusDivider;
		pwrUPcharge2.radius = static_cast<float>(screenHeight) / chargesRadiusDivider;
		pwrUPcharge3.radius = static_cast<float>(screenHeight) / chargesRadiusDivider;
		pwrUPcharge4.radius = static_cast<float>(screenHeight) / chargesRadiusDivider;
		pwrUPcharge5.radius = static_cast<float>(screenHeight) / chargesRadiusDivider;
		pwrUPcharge6.radius = static_cast<float>(screenHeight) / chargesRadiusDivider;
		pwrUPcharge7.radius = static_cast<float>(screenHeight) / chargesRadiusDivider;
		pwrUPcharge8.radius = static_cast<float>(screenHeight) / chargesRadiusDivider;
		pwrUPcharge9.radius = static_cast<float>(screenHeight) / chargesRadiusDivider;
		pwrUPcharge10.radius = static_cast<float>(screenHeight) / chargesRadiusDivider;
	}

	void initPowerUPTex() {
		mouse1 = LoadImage("assets/imagenes/PowerUP.png");
		ImageResize(&mouse1, static_cast<int>(PowerUP1.width*2.4f), PowerUP1.height*2);
		texturaPowerUP = LoadTextureFromImage(mouse1);
		texturaPowerUP2 = LoadTextureFromImage(mouse1);
		UnloadImage(mouse1);
	}
}