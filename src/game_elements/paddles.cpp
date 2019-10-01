#include "paddles.h"

#include "raylib.h"

#include "general/console.h"
#include "states/game.h"

Player player1;
Player player2;
float paddle_height;
float paddle_width; 
int winner = 1;
Image weirdCat;
int total_points = 0;
int winning_points = 10;
bool botUsedPowerUP = false;
const int minTimeBetweenBotPwrUp = 8;
const static float p1PosXDivider = 10.0f;
const static float p2PosXDivider = 1.11111f;
const static float playerSpeedDivider = 1.5f;
const static float paddleTexWidthResizer = 7.0f;
const static float paddleTexHeightResizer = 1.6f;
float paddleTexOffsetXDivider = 27.0f;
float paddleTexOffsetYDivider = 30.0f;

namespace catPong {
	void initPaddles() {
		paddle_height = screenHeight / 7.5f;
		paddle_width = screenWidth / 80.0f;
		player1.speed = screenHeight / playerSpeedDivider;
		player2.speed = screenHeight / playerSpeedDivider;
		player1.bar.height = paddle_height;
		player2.bar.height = paddle_height;
		player1.bar.width = paddle_width;
		player2.bar.width = paddle_width;
		player1.bar.x = screenWidth / p1PosXDivider;
		player2.bar.x = screenWidth / p2PosXDivider;
		player1.bar.y = screenHeight / 2;
		player2.bar.y = screenHeight / 2;

	}

	void initPaddleTex() {
		player1.color = RED;
		player2.color = BLUE;
		weirdCat = LoadImage("assets/imagenes/gato_original.png");
		ImageResize(&weirdCat, paddle_width *7, paddle_height*1.6);
		player1.textura = LoadTextureFromImage(weirdCat);
		player2.textura = LoadTextureFromImage(weirdCat);
		UnloadImage(weirdCat);
	}
}