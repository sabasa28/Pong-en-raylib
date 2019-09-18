#include "ending_screen.h"
#include "raylib.h"
#include "musicSounds.h"
#include "paddles.h"
#include "console.h"

void endScreenUpdate() {
	UpdateMusicStream(metalNyan);
	if (pointsP1 >= 10)
	{
		winner = 1;
	}
	else if (pointsP2 >= 10)
	{
		winner = 2;
	}
	if (IsKeyPressed('M'))
	{
		menu = true;
		//break; //no estoy en un loop
	}
	if (IsKeyPressed('R'))
	{
		restarted = true;
	}
}

void endScreenDraw() {
	BeginDrawing();
	ClearBackground(RAYWHITE);
	DrawText(TextFormat("PLAYER %i", winner), 180, 110, 50, BLACK);
	DrawText("WINS.", 450, 110, 50, BLACK);
	DrawText("Press 'R' to play again.", 80, 250, 30, BLACK);
	DrawText("Press 'M' to go to menu.", 80, 290, 30, BLACK);
	DrawText("Press 'ESC' to quit.", 80, 330, 30, BLACK);
	DrawText(TextFormat("Won matches P1: %i", won_matchesP1), 500, 330, 20, P1color);
	DrawText(TextFormat("Won matches P2: %i", won_matchesP2), 500, 360, 20, P2color);
	EndDrawing();
}