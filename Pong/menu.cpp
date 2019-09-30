#include "menu.h"

#include "raylib.h"

#include "background.h"
#include "game.h"
#include "paddles.h"
#include "musicSounds.h"
#include "console.h"
#include "general.h"
#include "gameplay.h"
#include "ball.h"
#include "powerUPs.h"

Rectangle PlayButton;
Rectangle ExitButton;
Rectangle RedButton;
Rectangle GreenButton;
Rectangle BlueButton;
Rectangle RedButton2;
Rectangle GreenButton2;
Rectangle BlueButton2;
Rectangle VsBotButton;
Rectangle VsPlayerButton;
Rectangle ScreenSize1Button;
Rectangle ScreenSize2Button;
Rectangle ScreenSize3Button;
static ScreenSizeSelected screenSizeSelected;
static ColorSelected p1ColorSelected=Red;
static ColorSelected p2ColorSelected=Blue;
static float coloredbuttonsHeightDivider = 15.0f;
static float coloredbuttonsWidthDivider = 8.0f;
static float p1ColoredButtonsYDivider = 1.28571f;
static float p2ColoredButtonsYDivider = 1.125f;
static float redButtonsXDivider = 3.2f;
static float greenButtonsXDivider = 2.285f;
static float blueButtonsXDivider = 1.77778f;
static float selectedButtonDifference = 45.0f; 
static float playButtonXDivider = 4.44444f;
static float playButtonYDivider = 3.75f;
static float playButtonWidthDivider = 2.0f;
static float playButtonHeightDivider = 4.5f;
static float exitButtonXDivider = 3.47826f;
static float exitButtonYDivider = 1.875f;
static float exitButtonWidthDivider = 2.66667f;
static float exitButtonHeightDivider = 5.625f;
static float playTextXDivider = 2.66667f;
static float playTextYDivider = 3.46154f;
static float playTextFontDivider = 5.625f;
static float exitTextXDivider = 2.42424f;
static float exitTextYDivider = 1.73077f;
static float exitTextFontDivider = 9.0f;
static float colorSelecTextXDivider = 10.0f;
static float colorSelecTextFontDivider = 12.85714f;
static float vsBotButtonYDivider = 2.0f;
static float vsBotButtonWidthDivider = 8.0f;
static float vsBotButtonHeightDivider = 6.0f;
static float vsPlayerButtonYDivider = 4.0f;
static float vsPlayerButtonWidthDivider = 8.0f;
static float vsPlayerButtonHeightDivider = 6.0f;
static float gamemodeSelectedButtonXDivider = 800.0f;
static float gamemodeNotSelectedButtonXDivider = -16.0f;
static float vsPlayerTextXDivider = 790.0f;
static float vsPlayerTextYDivider = 5.25f;
static float vsBotTextXDivider = 790.0f;
static float vsBotTextYDivider = 2.3f;
static float gamemodeSelectFontSizeDivider = 20.0f;
static float screenSizeButtonsWidthDivider = 8.0f;
static float screenSizeButtonsHeightDivider = 7.0f;
static float screenSizeSelectedButtonXDivider = 1.14f;
static float screenSizeNotSelectedButtonXDivider = 1.05f;
static float screenSize1ButtonYDivider = 6.0f;
static float screenSize2ButtonYDivider = 2.5f;
static float screenSize3ButtonYDivider = 1.55f;
static float screenSizeTextFontSizeDivider = 20.0f;
static float screenSizeTextXDivider = 1.2f;
static float screenSize1TextYDivider = 10.0f;
static float screenSize2TextYDivider = 3.0f;
static float screenSize3TextYDivider = 1.75;
static int timerToClickAgain = 0;
namespace catPong {
	void AdjustGameSize(int newHeight, int newWidth);
	void FullscreenGameSize();
	void initMenu() {
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
		VsPlayerButton.x = screenWidth / gamemodeSelectedButtonXDivider;
		VsPlayerButton.y = screenHeight / vsPlayerButtonYDivider;
		VsPlayerButton.width = screenWidth / vsPlayerButtonWidthDivider;
		VsPlayerButton.height = screenHeight / vsPlayerButtonHeightDivider;
		VsBotButton.x = screenWidth / gamemodeNotSelectedButtonXDivider;
		VsBotButton.y = screenHeight / vsBotButtonYDivider;
		VsBotButton.width = screenWidth / vsBotButtonWidthDivider;
		VsBotButton.height = screenHeight / vsBotButtonHeightDivider;
		ScreenSize1Button.x = screenWidth / screenSizeSelectedButtonXDivider;
		ScreenSize1Button.y = screenHeight / screenSize1ButtonYDivider;
		ScreenSize1Button.width = screenWidth / screenSizeButtonsWidthDivider;
		ScreenSize1Button.height = screenHeight / screenSizeButtonsHeightDivider;
		ScreenSize2Button.x = screenWidth / screenSizeNotSelectedButtonXDivider;
		ScreenSize2Button.y = screenHeight / screenSize2ButtonYDivider;
		ScreenSize2Button.width = screenWidth / screenSizeButtonsWidthDivider;
		ScreenSize2Button.height = screenHeight / screenSizeButtonsHeightDivider;
		ScreenSize3Button.x = screenWidth / screenSizeNotSelectedButtonXDivider;
		ScreenSize3Button.y = screenHeight / screenSize3ButtonYDivider;
		ScreenSize3Button.width = screenWidth / screenSizeButtonsWidthDivider;
		ScreenSize3Button.height = screenHeight / screenSizeButtonsHeightDivider;
	}
	void updateMenu() {
		PlayMusicStream(gatitos);
		UpdateMusicStream(gatitos);
		player1.wonMatches = 0;
		player2.wonMatches = 0;
		

		if (cronometer >= timerToClickAgain) {
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), ExitButton)) gamestate = Close;
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), PlayButton)) {
				StopMusicStream(gatitos);
				gamestate = Gameplay;
			}
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), RedButton))p1ColorSelected = Red;
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), GreenButton))p1ColorSelected = Green;
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), BlueButton))p1ColorSelected = Blue;
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), RedButton2))p2ColorSelected = Red;
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), GreenButton2))p2ColorSelected = Green;
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), BlueButton2))p2ColorSelected = Blue;
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), VsPlayerButton))gamemode = vsPlayer;
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), VsBotButton))gamemode = vsBot;
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), ScreenSize1Button)){
				screenSizeSelected = x800y450;
				AdjustGameSize(screensize1.x, screensize1.y);
				timerToClickAgain = cronometer + 1;			
			}
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), ScreenSize2Button)){
				screenSizeSelected = x1200y675;
				AdjustGameSize(screensize2.x, screensize2.y);
				timerToClickAgain = cronometer + 1;
			}
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), ScreenSize3Button)){
				screenSizeSelected = fullscreen;
				FullscreenGameSize();
				timerToClickAgain = cronometer+1;
			}
		}
		switch (screenSizeSelected){
		case x800y450:
			ScreenSize1Button.x = screenWidth / screenSizeSelectedButtonXDivider;
			ScreenSize2Button.x = screenWidth / screenSizeNotSelectedButtonXDivider;
			ScreenSize3Button.x = screenWidth / screenSizeNotSelectedButtonXDivider;
			screenSizeSelected = none;
			break;
		case x1200y675:
			ScreenSize2Button.x = screenWidth / screenSizeSelectedButtonXDivider;
			ScreenSize1Button.x = screenWidth / screenSizeNotSelectedButtonXDivider;
			ScreenSize3Button.x = screenWidth / screenSizeNotSelectedButtonXDivider;
			screenSizeSelected = none;
			break;
		case fullscreen:
			ScreenSize3Button.x = screenWidth / screenSizeSelectedButtonXDivider;
			ScreenSize1Button.x = screenWidth / screenSizeNotSelectedButtonXDivider;
			ScreenSize2Button.x = screenWidth / screenSizeNotSelectedButtonXDivider;
			screenSizeSelected = none;
			break;
		default:
			break;
		}
		switch (p1ColorSelected){
		case Red:
			RedButton.y = screenHeight / p1ColoredButtonsYDivider - screenHeight / selectedButtonDifference;
			BlueButton.y = screenHeight / p1ColoredButtonsYDivider;
			GreenButton.y = screenHeight / p1ColoredButtonsYDivider;
			player1.color = RED;
			break;
		case Green:
			RedButton.y = screenHeight / p1ColoredButtonsYDivider;
			BlueButton.y = screenHeight / p1ColoredButtonsYDivider;
			GreenButton.y = screenHeight / p1ColoredButtonsYDivider - screenHeight / selectedButtonDifference;
			player1.color = GREEN;
			break;
		case Blue:
			RedButton.y = screenHeight / p1ColoredButtonsYDivider;
			BlueButton.y = screenHeight / p1ColoredButtonsYDivider - screenHeight / selectedButtonDifference;
			GreenButton.y = screenHeight / p1ColoredButtonsYDivider;
			player1.color = BLUE;
			break;
		}
		switch (p2ColorSelected){
		case Red:
			RedButton2.y = screenHeight / p2ColoredButtonsYDivider - screenHeight / selectedButtonDifference;
			BlueButton2.y = screenHeight / p2ColoredButtonsYDivider;
			GreenButton2.y = screenHeight / p2ColoredButtonsYDivider;
			player2.color = RED;
			break;
		case Green:
			RedButton2.y = screenHeight / p2ColoredButtonsYDivider;
			BlueButton2.y = screenHeight / p2ColoredButtonsYDivider;
			GreenButton2.y = screenHeight / p2ColoredButtonsYDivider - screenHeight / selectedButtonDifference;
			player2.color = GREEN;
			break;
		case Blue:
			RedButton2.y = screenHeight / p2ColoredButtonsYDivider;
			BlueButton2.y = screenHeight / p2ColoredButtonsYDivider - screenHeight / selectedButtonDifference;
			GreenButton2.y = screenHeight / p2ColoredButtonsYDivider;
			player2.color = BLUE;
			break;
		}
		switch (gamemode){
		case vsPlayer:
			VsPlayerButton.x = screenWidth / gamemodeSelectedButtonXDivider;
			VsBotButton.x = screenWidth / gamemodeNotSelectedButtonXDivider;
			break;
		case vsBot:
			VsBotButton.x = screenWidth / gamemodeSelectedButtonXDivider;
			VsPlayerButton.x = screenWidth / gamemodeNotSelectedButtonXDivider;
			break;
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
		DrawRectangle(VsBotButton.x, VsBotButton.y, VsBotButton.width, VsBotButton.height, ORANGE);
		DrawRectangle(VsPlayerButton.x, VsPlayerButton.y, VsPlayerButton.width, VsPlayerButton.height, DARKGREEN);
		DrawRectangle(ScreenSize1Button.x, ScreenSize1Button.y, ScreenSize1Button.width, ScreenSize1Button.height, GRAY);
		DrawRectangle(ScreenSize2Button.x, ScreenSize2Button.y, ScreenSize2Button.width, ScreenSize2Button.height, GRAY);
		DrawRectangle(ScreenSize3Button.x, ScreenSize3Button.y, ScreenSize3Button.width, ScreenSize3Button.height, GRAY);
		DrawText("Play", screenWidth / playTextXDivider, screenHeight / playTextYDivider, screenHeight / playTextFontDivider, BLACK);
		DrawText("Exit", screenWidth / exitTextXDivider, screenHeight / exitTextYDivider, screenHeight / exitTextFontDivider, BLACK);
		DrawText("Vs Player:", screenWidth / vsPlayerTextXDivider, screenHeight / vsPlayerTextYDivider, screenHeight / gamemodeSelectFontSizeDivider, BLACK);
		DrawText("Vs Bot:", screenWidth / vsBotTextXDivider, screenHeight / vsBotTextYDivider, screenHeight / gamemodeSelectFontSizeDivider, BLACK);
		DrawText("P1 color:", screenWidth/colorSelecTextXDivider, screenHeight / p1ColoredButtonsYDivider, screenHeight / colorSelecTextFontDivider, BLACK);
		DrawText("P2 color:", screenWidth/colorSelecTextXDivider, screenHeight / p2ColoredButtonsYDivider, screenHeight / colorSelecTextFontDivider, BLACK);
		DrawText("800 x 450:", screenWidth / screenSizeTextXDivider, screenHeight / screenSize1TextYDivider, screenHeight / screenSizeTextFontSizeDivider, BLACK);
		DrawText("1200 x 675:", screenWidth / screenSizeTextXDivider, screenHeight / screenSize2TextYDivider, screenHeight / screenSizeTextFontSizeDivider, BLACK);
		DrawText("Fullscreen:", screenWidth / screenSizeTextXDivider, screenHeight / screenSize3TextYDivider, screenHeight / screenSizeTextFontSizeDivider, BLACK);
		EndDrawing();
	}
	void AdjustGameSize(int newWidth, int newHeight) {
		if (screenWidth==GetMonitorWidth(0)){
			ToggleFullscreen();
		}
		screenWidth = newWidth;
		screenHeight = newHeight;
		SetWindowPosition((GetMonitorWidth(0)-screenWidth)/2, (GetMonitorHeight(0) -screenHeight)/2);
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
	void FullscreenGameSize() {
		screenHeight = GetMonitorHeight(0);
		screenWidth = GetMonitorWidth(0);
		SetWindowPosition(0, 0);
		ToggleFullscreen();
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
}