#include "ending_screen.h"

#include "raylib.h"

#include "musicSounds.h"
#include "paddles.h"
#include "console.h"
#include "game.h"
namespace sabasa {
	void updateEndingScreen() {
		PlayMusicStream(metalNyan);
		UpdateMusicStream(metalNyan);
		if (player1.points >= winning_points)
		{
			winner = 1;
		}
		else if (player2.points >= winning_points)
		{
			winner = 2;
		}
		if (IsKeyPressed('M')) {
			StopMusicStream(metalNyan);
			gamestate = Menu;
		}
		if (IsKeyPressed('R')) {
			StopMusicStream(metalNyan);
			gamestate = Gameplay;
		}
	}

	void drawEndingScreen() {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText(TextFormat("PLAYER %i", winner), 180, 110, 50, BLACK);
		DrawText("WINS.", 450, 110, 50, BLACK);
		DrawText("Press 'R' to play again.", 80, 250, 30, BLACK);
		DrawText("Press 'M' to go to menu.", 80, 290, 30, BLACK);
		DrawText("Press 'ESC' to quit.", 80, 330, 30, BLACK);
		DrawText(TextFormat("Won matches P1: %i", player1.wonMatches), 500, 330, 20, player1.color);
		DrawText(TextFormat("Won matches P2: %i", player2.wonMatches), 500, 360, 20, player2.color);
		EndDrawing();
	}
}