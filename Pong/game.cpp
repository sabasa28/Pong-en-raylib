#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "menu.h"
#include "ending_screen.h"
#include "general.h"
#include "gameplay.h"
//#include "console.h"
//#include "paddles.h"
//#include "powerUPs.h"
//#include "ball.h"
//#include "background.h"
//#include "musicSounds.h"

//enum state;
state gamestate;

void executeGame(){
	initGeneral();
	while (!WindowShouldClose() && gamestate != Close)
	{
		switch (gamestate)
		{
		case Menu:
			menuUpdate();
			menuDraw();
			resetValues();
			break;

		case Gameplay:
			gameplayUpdate();
			gameplayDraw();
			break;

		case EndScreen:
			endingScreenUpdate();
			endingScreenDraw();
			resetValues();
			break;
		}
	}
	close();
}
