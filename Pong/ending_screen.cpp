#include "ending_screen.h"

#include "raylib.h"

#include "musicSounds.h"
#include "paddles.h"
#include "console.h"
#include "game.h"
#include "general.h"

static float winnerTextFontDivider = 9.0f;
static float winnerTextYDivider = 4.090909f;
static float winner1TextXDivider = 4.44444444f;
static float winner2TextXDivider = 1.77777778f;
static float optionsTextXDivider = 10.0f;
static float optionsTextFontDivider = 15.0f;
static float restartTextYDivider = 1.8f;
static float menuTextYDivider = 1.5517242f;
static float quitTextYDivider = 1.3636364f;
static float matchesTextFontDivider = 22.5f;
static float matchesTextXDivider = 1.6f;
static float matchesP1TextYDivider = 1.3636364f;
static float matchesP2TextYDivider = 1.25f;

namespace catPong {
	void updateEndingScreen() {
		PlayMusicStream(metalNyan);
		UpdateMusicStream(metalNyan);
		if (player1.points >= winning_points){
			winner = 1;
		}
		else if (player2.points >= winning_points){
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
		resetValues();
	}

	void drawEndingScreen() {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText(TextFormat("PLAYER %i", winner), static_cast<int>(screenWidth / winner1TextXDivider), static_cast<int>(screenHeight/ winnerTextYDivider), static_cast<int>(screenHeight / winnerTextFontDivider), BLACK);
		DrawText("WINS.", static_cast<int>(screenWidth / winner2TextXDivider), static_cast<int>(screenHeight / winnerTextYDivider), static_cast<int>(screenHeight / winnerTextFontDivider), BLACK);
		DrawText("Press 'R' to play again.", static_cast<int>(screenWidth / optionsTextXDivider), static_cast<int>(screenHeight / restartTextYDivider), static_cast<int>(screenHeight / optionsTextFontDivider), BLACK);
		DrawText("Press 'M' to go to menu.", static_cast<int>(screenWidth / optionsTextXDivider), static_cast<int>(screenHeight / menuTextYDivider), static_cast<int>(screenHeight / optionsTextFontDivider), BLACK);
		DrawText("Press 'ESC' to quit.", static_cast<int>(screenWidth / optionsTextXDivider), static_cast<int>(screenHeight / quitTextYDivider), static_cast<int>(screenHeight / optionsTextFontDivider), BLACK);
		DrawText(TextFormat("Won matches P1: %i", player1.wonMatches), static_cast<int>(screenWidth / matchesTextXDivider), static_cast<int>(screenHeight / matchesP1TextYDivider), static_cast<int>(screenHeight / matchesTextFontDivider), player1.color);
		DrawText(TextFormat("Won matches P2: %i", player2.wonMatches), static_cast<int>(screenWidth / matchesTextXDivider), static_cast<int>(screenHeight / matchesP2TextYDivider), static_cast<int>(screenHeight / matchesTextFontDivider), player2.color);
		EndDrawing();
	}
}