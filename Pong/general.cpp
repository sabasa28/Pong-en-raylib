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

float speedMultiplier =1.0f;

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
	initMenu();
	gamestate = Menu;
}

void resetValues() {
	speedMultiplier = 1.0f;
	ball.position.x = GetScreenWidth() / 2;
	ball.position.y = GetScreenHeight() / 2;
	colliding = false;
	colliding2 = false;
	player1.points = 0;
	player2.points = 0;
	total_points = 0;
	player1.bar.x = GetScreenWidth() / 8 - 20;
	player1.bar.y = GetScreenHeight() / 2;
	player2.bar.x = GetScreenWidth() - GetScreenWidth() / 8 + 20;
	player2.bar.y = GetScreenHeight() / 2;
	pause = true;
	powerUPexists = false;
	powerUP2exists = false;
	player1.gravityPills = 3;
	player2.gravityPills = 3;
	cronometer = (double)clock() / 1000;
	cronometerFlo = (double)clock() / 1000;
	lastTimer = cronometer;
	lastTimer2 = cronometer;
}

void close() {
	UnloadTexture(ballTexture);
	UnloadTexture(texturaFondo);
	UnloadTexture(texturaBarra);
	UnloadMusicStream(gatitos);
	UnloadMusicStream(metalNyan);
	CloseAudioDevice();
	CloseWindow();
}