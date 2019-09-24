#include "menu.h"

#include "raylib.h"

#include "background.h"
#include "game.h"
#include "paddles.h"
#include "musicSounds.h"

Rectangle PlayButton;
Rectangle ExitButton;
Rectangle RedButton;
Rectangle GreenButton;
Rectangle BlueButton;
Rectangle RedButton2;
Rectangle GreenButton2;
Rectangle BlueButton2;
int coloredbuttons_height = 30;
int coloredbuttons_width = 100;
int P1_colored_buttons_y = 350;
int P2_colored_buttons_y = 400;
int red_buttons_x = 250;
int green_buttons_x = 350;
int blue_buttons_x = 450;

void initMenu() {
	PlayButton.x = 180;
	PlayButton.y = 120;
	PlayButton.width = 400;
	PlayButton.height = 100;
	ExitButton.x = 230;
	ExitButton.y = 240;
	ExitButton.width = 300;
	ExitButton.height = 80;
	RedButton.width = coloredbuttons_width;
	RedButton.height = coloredbuttons_height;
	RedButton2.width = coloredbuttons_width;
	RedButton2.height = coloredbuttons_height;
	GreenButton.width = coloredbuttons_width;
	GreenButton.height = coloredbuttons_height;
	GreenButton2.width = coloredbuttons_width;
	GreenButton2.height = coloredbuttons_height;
	BlueButton.width = coloredbuttons_width;
	BlueButton.height = coloredbuttons_height;
	BlueButton2.width = coloredbuttons_width;
	BlueButton2.height = coloredbuttons_height;
	RedButton.x = red_buttons_x;
	RedButton.y = P1_colored_buttons_y;
	RedButton2.x = red_buttons_x;
	RedButton2.y = P2_colored_buttons_y;
	GreenButton.x = green_buttons_x;
	GreenButton.y = P1_colored_buttons_y;
	GreenButton2.x = green_buttons_x;
	GreenButton2.y = P2_colored_buttons_y;
	BlueButton.x = blue_buttons_x;
	BlueButton.y = P1_colored_buttons_y;
	BlueButton2.x = blue_buttons_x;
	BlueButton2.y = P2_colored_buttons_y;
}
void updateMenu() {
	PlayMusicStream(gatitos);
	UpdateMusicStream(gatitos);
	player1.wonMatches = 0;
	player2.wonMatches = 0;
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), RedButton))
	{
		RedButton.y = P1_colored_buttons_y - 10;
		BlueButton.y = P1_colored_buttons_y;
		GreenButton.y = P1_colored_buttons_y;
		player1.color = RED;
	}
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), GreenButton))
	{
		RedButton.y = P1_colored_buttons_y;
		BlueButton.y = P1_colored_buttons_y;
		GreenButton.y = P1_colored_buttons_y - 10;
		player1.color = GREEN;
	}
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), BlueButton))
	{
		RedButton.y = P1_colored_buttons_y;
		BlueButton.y = P1_colored_buttons_y - 10;
		GreenButton.y = P1_colored_buttons_y;
		player1.color = BLUE;
	}
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), RedButton2))
	{
		RedButton2.y = P2_colored_buttons_y - 10;
		BlueButton2.y = P2_colored_buttons_y;
		GreenButton2.y = P2_colored_buttons_y;
		player2.color = RED;
	}
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), GreenButton2))
	{
		RedButton2.y = P2_colored_buttons_y;
		BlueButton2.y = P2_colored_buttons_y;
		GreenButton2.y = P2_colored_buttons_y - 10;
		player2.color = GREEN;
	}
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), BlueButton2))
	{
		RedButton2.y = P2_colored_buttons_y;
		BlueButton2.y = P2_colored_buttons_y - 10;
		GreenButton2.y = P2_colored_buttons_y;
		player2.color = BLUE;
	}
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), ExitButton)) gamestate = Close;
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), PlayButton)) {
		StopMusicStream(gatitos);
		gamestate = Gameplay;
	}
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
	DrawText("P1 color:", 80, P1_colored_buttons_y, 35, BLACK);
	DrawText("P2 color:", 75, P2_colored_buttons_y, 35, BLACK);
	DrawText("Play", 300, 130, 80, BLACK);
	DrawText("Exit", 330, 260, 50, BLACK);
	EndDrawing();
}