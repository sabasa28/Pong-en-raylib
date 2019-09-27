#include "menu.h"

#include "raylib.h"

#include "background.h"
#include "game.h"
#include "paddles.h"
#include "musicSounds.h"
#include "console.h"
#include "general.h"
#include "ball.h"		//SACAR CUANDO HAYAS HECHO UNA FUNCION PARA CARGAR TODOS LOS VALORES
#include "powerUPs.h"	//SACAR CUANDO HAYAS HECHO UNA FUNCION PARA CARGAR TODOS LOS VALORES

Rectangle PlayButton;
Rectangle ExitButton;
Rectangle RedButton;
Rectangle GreenButton;
Rectangle BlueButton;
Rectangle RedButton2;
Rectangle GreenButton2;
Rectangle BlueButton2;
static float coloredbuttonsHeightDivider = 15.0f;
static float coloredbuttonsWidthDivider = 8.0f;
static float p1ColoredButtonsYDivider = 1.285714285714286f;
static float p2ColoredButtonsYDivider = 1.125f;
static float redButtonsXDivider = 3.2f;
static float greenButtonsXDivider = 2.28;
static float blueButtonsXDivider = 1.777777777778f;
static float selectedButtonDifference = 45.0f; 
static float playButtonXDivider = 4.44444444444444f;
static float playButtonYDivider = 3.75f;
static float playButtonWidthDivider = 2.0f;
static float playButtonHeightDivider = 4.5f;
static float exitButtonXDivider = 3.478260869565217f;
static float exitButtonYDivider = 1.875f;
static float exitButtonWidthDivider = 2.666666666667f;
static float exitButtonHeightDivider = 5.625f;
static float playTextXDivider = 2.66666666667f;
static float playTextYDivider = 3.4615384615f;
static float playTextFontDivider = 5.625f;
static float exitTextXDivider = 2.424242424f;
static float exitTextYDivider = 1.73076923f;
static float exitTextFontDivider = 9.0f;
static float ColorSelecTextXDivider = 10.0f;
static float ColorSelecTextFontDivider = 12.857142857f;

namespace catPong {
	void initMenu() {
		SetWindowSize(screenWidth, screenHeight); //VA EN INIT GENERAL
		
		PlayButton.x = screenWidth / playButtonXDivider;		
		PlayButton.y = screenHeight / playButtonYDivider;		
		PlayButton.width = screenWidth / playButtonWidthDivider;	
		PlayButton.height = screenHeight / playButtonHeightDivider;	
		ExitButton.x = screenWidth / exitButtonXDivider;		
		ExitButton.y = screenHeight / exitButtonYDivider;		
		ExitButton.width = screenWidth / exitButtonWidthDivider;	
		ExitButton.height = screenHeight / exitButtonHeightDivider;	
		RedButton.width = screenWidth / coloredbuttonsWidthDivider;
		RedButton.height = screenHeight / coloredbuttonsHeightDivider;
		RedButton2.width = screenWidth / coloredbuttonsWidthDivider;
		RedButton2.height = screenHeight / coloredbuttonsHeightDivider;
		GreenButton.width = screenWidth / coloredbuttonsWidthDivider;
		GreenButton.height = screenHeight / coloredbuttonsHeightDivider;
		GreenButton2.width = screenWidth / coloredbuttonsWidthDivider;
		GreenButton2.height = screenHeight / coloredbuttonsHeightDivider;
		BlueButton.width = screenWidth / coloredbuttonsWidthDivider;
		BlueButton.height = screenHeight / coloredbuttonsHeightDivider;
		BlueButton2.width = screenWidth / coloredbuttonsWidthDivider;
		BlueButton2.height = screenHeight / coloredbuttonsHeightDivider;
		RedButton.x = screenWidth / redButtonsXDivider;
		RedButton.y = screenHeight / p1ColoredButtonsYDivider;
		RedButton2.x = screenWidth / redButtonsXDivider;
		RedButton2.y = screenHeight / p2ColoredButtonsYDivider;
		GreenButton.x = screenWidth / greenButtonsXDivider;
		GreenButton.y = screenHeight / p1ColoredButtonsYDivider;
		GreenButton2.x = screenWidth / greenButtonsXDivider;
		GreenButton2.y = screenHeight / p2ColoredButtonsYDivider;
		BlueButton.x = screenWidth / blueButtonsXDivider;
		BlueButton.y = screenHeight / p1ColoredButtonsYDivider;
		BlueButton2.x = screenWidth / blueButtonsXDivider;
		BlueButton2.y = screenHeight / p2ColoredButtonsYDivider;
	}
	void updateMenu() {
		PlayMusicStream(gatitos);
		UpdateMusicStream(gatitos);
		player1.wonMatches = 0;
		player2.wonMatches = 0;
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), RedButton))
		{
			RedButton.y = screenHeight / p1ColoredButtonsYDivider - screenHeight / selectedButtonDifference;
			BlueButton.y = screenHeight / p1ColoredButtonsYDivider;
			GreenButton.y = screenHeight / p1ColoredButtonsYDivider;
			player1.color = RED;
		}
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), GreenButton))
		{
			RedButton.y = screenHeight / p1ColoredButtonsYDivider;
			BlueButton.y = screenHeight / p1ColoredButtonsYDivider;
			GreenButton.y = screenHeight / p1ColoredButtonsYDivider - screenHeight / selectedButtonDifference;
			player1.color = GREEN;
		}
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), BlueButton))
		{
			RedButton.y = screenHeight / p1ColoredButtonsYDivider;
			BlueButton.y = screenHeight / p1ColoredButtonsYDivider - screenHeight / selectedButtonDifference;
			GreenButton.y = screenHeight / p1ColoredButtonsYDivider;
			player1.color = BLUE;
		}
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), RedButton2))
		{
			RedButton2.y = screenHeight / p2ColoredButtonsYDivider - screenHeight / selectedButtonDifference;
			BlueButton2.y = screenHeight / p2ColoredButtonsYDivider;
			GreenButton2.y = screenHeight / p2ColoredButtonsYDivider;
			player2.color = RED;
		}
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), GreenButton2))
		{
			RedButton2.y = screenHeight / p2ColoredButtonsYDivider;
			BlueButton2.y = screenHeight / p2ColoredButtonsYDivider;
			GreenButton2.y = screenHeight / p2ColoredButtonsYDivider - screenHeight / selectedButtonDifference;
			player2.color = GREEN;
		}
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), BlueButton2))
		{
			RedButton2.y = screenHeight / p2ColoredButtonsYDivider;
			BlueButton2.y = screenHeight / p2ColoredButtonsYDivider - screenHeight / selectedButtonDifference;
			GreenButton2.y = screenHeight / p2ColoredButtonsYDivider;
			player2.color = BLUE;
		}
		if (IsKeyDown('L'))
		{
			screenHeight = 600;
			screenWidth = 1000;
			SetWindowSize(screenWidth, screenHeight);
			initMenu();
			initBackground();
			initPaddles();
			initPaddleTex();
			initBall();
			initBallTex();
			initPowerUP();
			initPowerUPTex();
			

		}
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), ExitButton)) gamestate = Close;
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), PlayButton)) {
			StopMusicStream(gatitos);
			gamestate = Gameplay;
		}
		resetValues();
	}
	void drawMenu() {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawTexture(texturaFondo, 0, 0, WHITE);
		DrawRectangle(PlayButton.x, PlayButton.y, PlayButton.width, PlayButton.height, BLUE);
		DrawRectangle(ExitButton.x, ExitButton.y, ExitButton.width, ExitButton.height, RED);
		DrawRectangle(RedButton.x, RedButton.y, RedButton.width, RedButton.height, RED);
		DrawRectangle(RedButton2.x, RedButton2.y, RedButton2.width, RedButton2.height, RED);
		DrawRectangle(GreenButton.x, GreenButton.y, GreenButton.width, GreenButton.height, GREEN);
		DrawRectangle(GreenButton2.x, GreenButton2.y, GreenButton2.width, GreenButton2.height, GREEN);
		DrawRectangle(BlueButton.x, BlueButton.y, BlueButton.width, BlueButton.height, BLUE);
		DrawRectangle(BlueButton2.x, BlueButton2.y, BlueButton2.width, BlueButton2.height, BLUE);
		DrawText("P1 color:", screenWidth/ColorSelecTextXDivider, screenHeight / p1ColoredButtonsYDivider, screenHeight / ColorSelecTextFontDivider, BLACK);
		DrawText("P2 color:", screenWidth/ColorSelecTextXDivider, screenHeight / p2ColoredButtonsYDivider, screenHeight / ColorSelecTextFontDivider, BLACK);
		DrawText("Play", screenWidth / playTextXDivider, screenHeight / playTextYDivider, screenHeight / playTextFontDivider, BLACK);
		DrawText("Exit", screenWidth / exitTextXDivider, screenHeight / exitTextYDivider, screenHeight / exitTextFontDivider, BLACK);
		EndDrawing();
	}
}