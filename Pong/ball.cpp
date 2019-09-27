#include "ball.h"

#include "raylib.h"

#include "console.h"
Ball ball;
Image worsted;
Texture2D ballTexture; //agregar a struct?
bool colliding = false; //ESTO HAY QUE RESOLVERLO ENUM DE COLISION??
bool colliding2 = false; //ESTO HAY QUE RESOLVERLO/ POR AHI UN ENUM SOLO ENTRE LAS DOS PALETAS
float ballTexOffsetXDivider = 29.62963f;
float ballTexOffsetYDivider = 26.47059f;
static float BallXSpeedDivider = 2.28571f;
static float BallYSpeedDivider = 1.28571f;
static float BallRadiusDivider = 45.0f; //SE PUEDE HACER SUMANDO HEIGHT Y WIDTH Y RECIEN AHI HACIENDO LA DIVISION, CREO LO MISMO LAS FONTS
float leftResetPos;
float rightResetPos;
float speedMultiplier = 1.0f;
float boost = 0.05f;

namespace catPong {
	void initBall() {
		leftResetPos = screenWidth / 8;
		rightResetPos = screenWidth - screenWidth / 8;
		ball.position.x = screenWidth / 2;
		ball.position.y = screenHeight / 2;
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