#include "ball.h"

#include "raylib.h"

#include "console.h"
Ball ball;
Image worsted;
Texture2D ballTexture;
float leftResetPos;
float rightResetPos;
float speedMultiplier = 1.0f;
const float boost = 0.05f;
const float ballTexOffsetXDivider = 45.0f;
const float ballTexOffsetYDivider = 23.0f;
const float BallSpeed1XDivider = 2.28571f;
const float BallSpeed1YDivider = 1.28571f;
const float BallSpeed2XDivider = 1.93939f;
const float BallSpeed2YDivider = 2.4f;
const float BallSpeed3XDivider = 1.68421f;
const float BallSpeed3YDivider = 3.6f;
const static float BallRadiusDivider = 45.0f;

namespace catPong{
	void initBall(){
		leftResetPos = screenWidth / 8;
		rightResetPos = screenWidth - screenWidth / 8;
		ball.position.x = screenWidth / 2;
		ball.position.y = screenHeight / 2;
		ball.speed.x = screenWidth/ BallSpeed1XDivider;
		ball.speed.y = screenHeight / BallSpeed1YDivider;
		ball.radius = screenHeight / BallRadiusDivider;
		ball.color = YELLOW;
	}

	void initBallTex(){
		worsted = LoadImage("imagenes/bola1.png");
		ImageResize(&worsted, ball.radius * 4, ball.radius * 4);
		ballTexture = LoadTextureFromImage(worsted);
		UnloadImage(worsted);
	}
}