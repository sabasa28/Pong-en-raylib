#include <stdlib.h>
#include <time.h>
#include "raylib.h"
#include "game.h"
#include "console.h"
#include "paddles.h"
#include "powerUPs.h"
#include "ball.h"
#include "background.h"
#include "musicSounds.h"
#include "menu.h"
#include "ending_screen.h"

//enum state;
state gamestate;

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
