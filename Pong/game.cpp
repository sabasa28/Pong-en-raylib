#include "game.h"

#include "menu.h"
#include "ending_screen.h"
#include "general.h"
#include "gameplay.h"

State gamestate;
namespace catPong {
	void executeGame() {
		initGeneral();
		while (!WindowShouldClose() && gamestate != Close)
		{
			switch (gamestate)
			{
			case Menu:
				updateMenu();
				drawMenu();
				resetValues();
				break;

			case Gameplay:
				updateGameplay();
				drawGameplay();
				break;

			case EndScreen:
				updateEndingScreen();
				drawEndingScreen();
				resetValues();
				break;
			}
		}
		close();
	}
}