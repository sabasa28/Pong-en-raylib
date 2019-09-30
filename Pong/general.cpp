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


namespace catPong {
	void initGeneral() {
		initConsole();
		srand(time(NULL));
		InitWindow(screensize1.x, screensize1.y, "PONG - Inaki Diez Galarza");//(I�aki)
		InitAudioDevice();
		initPaddles();
		initPaddleTex();
		initPowerUP();
		initPowerUPTex();
		initBall();
		initBallTex();
		initBackground();
		initMusicSounds();
		initMenu();
		gamestate = Menu;
	}

	void resetValues() {
		initPaddles();
		speedMultiplier = 1.0f;
		ball.position.x = screenWidth / 2;
		ball.position.y = screenHeight / 2;
		player1.points = 0;
		player2.points = 0;
		total_points = 0;
		pause = true;
		powerUPexists = false;
		powerUP2exists = false;
		player1.gravityPills = 3;
		player2.gravityPills = 3;
		cronometer = (double)clock() / 1000;
		cronometerFlo = static_cast<float>(clock()) / 1000;
		lastTimer = cronometer;
		lastTimer2 = cronometer;
	}

	void close() {
		UnloadTexture(ballTexture);
		UnloadTexture(texturaFondo);
		UnloadTexture(player1.textura);
		UnloadTexture(player2.textura);
		UnloadSound(kittenMeow);
		UnloadMusicStream(gatitos);
		UnloadMusicStream(metalNyan);
		CloseAudioDevice();
		CloseWindow();
	}
}