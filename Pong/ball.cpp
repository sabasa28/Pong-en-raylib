#include "raylib.h"
#include "ball.h"
Vector2 ballPosition;
Vector2 ballSpeed;
int ball_radius;
Color BallColor;
Image worsted;
Texture2D texturaBola;
void initBall() {
	ballPosition.x = GetScreenWidth() / 2;
	ballPosition.y = GetScreenHeight() / 2;
	ballSpeed.x = 3.0f;
	ballSpeed.y = 3.0f;
	ball_radius = 10;
	BallColor = YELLOW;
}

void initBallTex() {
	worsted = LoadImage("imagenes/estambre_rojo.png");
	ImageResize(&worsted, ball_radius * 4, ball_radius * 4);
	texturaBola = LoadTextureFromImage(worsted);
	UnloadImage(worsted);
}
