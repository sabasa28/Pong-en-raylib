#include "general.h"

#include <time.h>
#include <stdlib.h>

#include "raylib.h"

#include "console.h"
#include "game_elements/paddles.h"
#include "game_elements/powerUPs.h"
#include "game_elements/ball.h"
#include "assets/musicSounds.h"
#include "assets/background.h"
#include "states/menu.h"
#include "states/game.h"


namespace catPong {
	void initGeneral() {
		initConsole();
		srand(static_cast<unsigned int>(time(NULL)));
		InitWindow(static_cast<int>(screensize1.x), static_cast<int>(screensize1.y), "PONG - Inaki Diez Galarza");//(Iñaki)
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
		ball.position.x = static_cast<float>(screenWidth) / 2;
		ball.position.y = static_cast<float>(screenHeight) / 2;
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
		UnloadSound(catMeow);
		UnloadMusicStream(menuSong);
		UnloadMusicStream(gameSong);
		CloseAudioDevice();
		CloseWindow();
	}
}