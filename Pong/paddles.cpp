#include "paddles.h"

#include "raylib.h"

Player player1;
Player player2;
float paddle_speed = 300.0f;
float paddle_height = 60.0f;
float paddle_width = 10.0f;
int winner = 1;
Texture2D texturaBarra;
Image standing_cat;
int total_points = 0;
int winning_points = 10;

void initPaddle() {
player1.bar.height = paddle_height;
player1.bar.width = paddle_width;
player2.bar.height = paddle_height;
player2.bar.width = paddle_width;
player1.bar.x = GetScreenWidth() / 8 - 20;
player1.bar.y = GetScreenHeight() / 2;
player2.bar.x = GetScreenWidth() - GetScreenWidth() / 8 + 20;
player2.bar.y = GetScreenHeight() / 2;
player1.color = RED;
player2.color = BLUE;
}

void initPaddleTex() {
	standing_cat = LoadImage("imagenes/cat_standing.png");
	ImageResize(&standing_cat, paddle_width * 4, paddle_height);
	texturaBarra = LoadTextureFromImage(standing_cat);
	UnloadImage(standing_cat);
}