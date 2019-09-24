#include "ball.h"

#include "raylib.h"

Ball ball;
Image worsted;
Texture2D ballTexture; //agregar a struct?
bool colliding = false; //ESTO HAY QUE RESOLVERLO ENUM DE COLISION?? no funcionaria con la pared
bool colliding2 = false; //ESTO HAY QUE RESOLVERLO/ POR AHI UN ENUM SOLO ENTRE LAS DOS PALETAS
void initBall() {
	ball.position.x = GetScreenWidth() / 2;
	ball.position.y = GetScreenHeight() / 2;
	ball.speed.x = 350.0f;
	ball.speed.y = 350.0f;
	ball.radius = 10;
	ball.color = YELLOW;
}

void initBallTex() {
	worsted = LoadImage("imagenes/estambre_rojo.png");
	ImageResize(&worsted, ball.radius * 4, ball.radius * 4);
	ballTexture = LoadTextureFromImage(worsted);
	UnloadImage(worsted);
}
