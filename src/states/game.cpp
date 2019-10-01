#include "states/game.h"

#include "states/menu.h"
#include "states/ending_screen.h"
#include "general/general.h"
#include "states/gameplay.h"

State gamestate;

namespace catPong {
	void executeGame() {
		initGeneral();
		while (!WindowShouldClose() && gamestate != Close){
			switch (gamestate){
			case Menu:
				updateMenu();
				drawMenu();
				break;

			case Gameplay:
				updateGameplay();
				drawGameplay();
				break;

			case EndScreen:
				updateEndingScreen();
				drawEndingScreen();
				break;
			}
		}
		close();
	}
}