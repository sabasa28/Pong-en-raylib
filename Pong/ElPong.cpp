#include <time.h>
#include <stdlib.h>
#include "raylib.h"
#include "console.h"
#include "paddles.h"
#include "powerUPs.h"
#include "ball.h"
#include "background.h"
#include "musicSounds.h"
#include "menu.h"
#include "ending_screen.h"
#include "game.h"
#include "general.h"
#include "gameplay.h"
//FALTA ORGANIZAR EL MAIN, LAS FUNCIONES DENTRO DEL MAIN TIENEN QUE SER POR EJ EL UPDATE QUE TIENE ADENTO EL UPDATE DEL MENU, GAMEPLAY
//Y PANTALLA FINAL O SON VARIOS UPDATES?? O ES UNA FUNCION "MENU" CON UPDATE, DRAW, CLOSE, ETC Y OTRA ASI PARA PLAY??? 

//SE PUEDEN HACER MAS STRUCTS EJEMPLO EN PLAYER

//CAMBIAR LO DEL AUMENTO FPS A AUMENTO DE VELOCIDAD DE PELOTA Y PALETAS

//HACER ALGO CON EL ENUM QUE NO ESTA COMO EXTERN

void main()
{
	initGeneral();
	while (!WindowShouldClose()&&gamestate!=Close)
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

