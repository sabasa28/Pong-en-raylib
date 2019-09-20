#include "general.h"
#include <time.h>
#include <stdlib.h>
#include "raylib.h"
#include "console.h"
#include "paddles.h"
#include "powerUPs.h"
#include "ball.h"
#include "musicSounds.h"
#include "background.h"
#include "menu.h"
#include "game.h"

void initGeneral() {
	initCronometers();
	srand(time(NULL));
	InitWindow(screenWidth, screenHeight, "PONG - Inaki Diez Galarza");//(Iñaki)
	InitAudioDevice();
	initPaddle();
	initPaddleTex();
	initPowerUP();
	initPowerUPTex();
	initBall();
	initBallTex();
	initBackground();
	initMusicSounds();
	initFPS();
	menuInit();
	gamestate = Menu;
}

void resetValues() { //CAMBIAR LO DEL AUMENTO FPS A AUMENTO DE VELOCIDAD DE PELOTA Y PALETAS

	ballPosition.x = GetScreenWidth() / 2;
	ballPosition.y = GetScreenHeight() / 2;
	colliding = false;
	colliding2 = false;
	pointsP1 = 0;
	pointsP2 = 0;
	total_points = 0;
	P1.x = GetScreenWidth() / 8 - 20;
	P1.y = GetScreenHeight() / 2;
	P2.x = GetScreenWidth() - GetScreenWidth() / 8 + 20;
	P2.y = GetScreenHeight() / 2;
	FPS = 120;
	StartigFPS = FPS;
	pause = true;
	framesCounter = 0;
	powerUPexists = false;
	powerUP2exists = false;
	power_gravityP1 = 3;
	power_gravityP2 = 3;
	SetTargetFPS(FPS);
	cronometer = (double)clock() / 1000;
	cronometerflo = (double)clock() / 1000;
	lastTimer = cronometer;
	lastTimer2 = cronometer;
}

void close() {
	UnloadTexture(texturaBola);
	UnloadTexture(texturaFondo);
	UnloadTexture(texturaBarra);
	UnloadMusicStream(gatitos);
	UnloadMusicStream(metalNyan);
	CloseAudioDevice();
	CloseWindow();
}