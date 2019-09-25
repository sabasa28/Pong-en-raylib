#include "ball.h"

#include "raylib.h"

#include "console.h"
Ball ball;
Image worsted;
Texture2D ballTexture; //agregar a struct?
bool colliding = false; //ESTO HAY QUE RESOLVERLO ENUM DE COLISION??
bool colliding2 = false; //ESTO HAY QUE RESOLVERLO/ POR AHI UN ENUM SOLO ENTRE LAS DOS PALETAS
static float BallXSpeedDivider = 2.285714f;
static float BallYSpeedDivider = 1.285714f;
static float BallRadiusDivider = 45.0f; //SE PUEDE HACER SUMANDO HEIGHT Y WIDTH Y RECIEN AHI HACIENDO LA DIVISION, CREO LO MISMO LAS FONTS
float leftResetPos= screenWidth / 8;
float rightResetPos= screenWidth - screenWidth / 8;
float speedMultiplier = 1.0f;
float boost = 0.05f;

namespace catPong {
	void initBall() {
		ball.position.x = halfScreenWidth;
		ball.position.y = halfScreenHeight;
		ball.speed.x = screenWidth/ BallXSpeedDivider;
		ball.speed.y = screenHeight / BallYSpeedDivider;
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