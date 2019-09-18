#include "raylib.h"
#include "paddles.h"
float paddle_speed = 2.5f;
float paddle_height = 60.0f;
float paddle_width = 10.0f;
Rectangle P1;
Rectangle P2;
int pointsP1 = 0;
int pointsP2 = 0;
int winner = 1;
Texture2D texturaBarra;
Image standing_cat;
int total_points = 0;
int won_matchesP1 = 0;
int won_matchesP2 = 0;
int power_gravityP1 = 3;
int power_gravityP2 = 3;
Color P1color;
Color P2color;
int winning_points = 10;

void initPaddle() {
P1.height = paddle_height;
P1.width = paddle_width;
P2.height = paddle_height;
P2.width = paddle_width;
P1.x = GetScreenWidth() / 8 - 20;
P1.y = GetScreenHeight() / 2;
P2.x = GetScreenWidth() - GetScreenWidth() / 8 + 20;
P2.y = GetScreenHeight() / 2;
P1color = RED;
P2color = BLUE;
}

void initPaddleTex() {
	standing_cat = LoadImage("imagenes/cat_standing.png");
	ImageResize(&standing_cat, paddle_width * 4, paddle_height);
	texturaBarra = LoadTextureFromImage(standing_cat);
	UnloadImage(standing_cat);
}