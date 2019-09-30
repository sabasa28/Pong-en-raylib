#include "ball.h"

#include "raylib.h"

#include "console.h"
Ball ball;
Image worsted;
Texture2D ballTexture; //agregar a struct?
float leftResetPos;
float rightResetPos;
float speedMultiplier = 1.0f;
float boost = 0.05f;
float ballTexOffsetXDivider = 29.62963f;
float ballTexOffsetYDivider = 26.47059f;
float BallSpeed1XDivider = 2.28571f;
float BallSpeed1YDivider = 1.28571f;
float BallSpeed2XDivider = 1.93939f;
float BallSpeed2YDivider = 2.4f;
float BallSpeed3XDivider = 1.68421f;
float BallSpeed3YDivider = 3.6f;
static float BallRadiusDivider = 45.0f; //SE PUEDE HACER SUMANDO HEIGHT Y WIDTH Y RECIEN AHI HACIENDO LA DIVISION, CREO LO MISMO LAS FONTS

namespace catPong {
	void initBall() {
		leftResetPos = screenWidth / 8;
		rightResetPos = screenWidth - screenWidth / 8;
		ball.position.x = screenWidth / 2;
		ball.position.y = screenHeight / 2;
		ball.speed.x = screenWidth/ BallSpeed1XDivider;
		ball.speed.y = screenHeight / BallSpeed1YDivider;
		ball.radius = screenHeight / BallRadiusDivider;
		ball.color = YELLOW;
	}

	void initBallTex() {
		worsted = LoadImage("imagenes/estambre_rojo.png");
		ImageResize(&worsted, ball.radius * 4, ball.radius * 4);
		ballTexture = LoadTextureFromImage(worsted);
		UnloadImage(worsted);
	}
}