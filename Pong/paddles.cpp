#include "paddles.h"

#include "raylib.h"

#include "console.h"
#include "game.h"

Player player1;
Player player2;
float paddle_height = screenHeight / 7.5f;
float paddle_width = screenWidth / 80.0f;
int winner = 1;
Image standing_cat;
int total_points = 0;
int winning_points = 10;
static float xPosDividerP1 = 10.0f;
static float xPosDividerP2 = 1.111111111f;
static float playerSpeedDivider = 1.5f;
namespace catPong {
	void initPaddles() {
		player1.speed = screenHeight / playerSpeedDivider;
		player2.speed = screenHeight / playerSpeedDivider;
		player1.bar.height = paddle_height;
		player2.bar.height = paddle_height;
		player1.bar.width = paddle_width;
		player2.bar.width = paddle_width;
		player1.bar.x = screenWidth / xPosDividerP1;
		player2.bar.x = screenWidth / xPosDividerP2;
		player1.bar.y = halfScreenHeight;
		player2.bar.y = halfScreenHeight;

	}

	void initPaddleTex() {
		player1.color = RED;
		player2.color = BLUE;
		standing_cat = LoadImage("imagenes/cat_standing.png");
		ImageResize(&standing_cat, paddle_width * 4, paddle_height);
		player1.textura = LoadTextureFromImage(standing_cat);
		player2.textura = LoadTextureFromImage(standing_cat);
		UnloadImage(standing_cat);
	}
}