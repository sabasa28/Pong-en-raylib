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

//FALTA ORGANIZAR EL MAIN, LAS FUNCIONES DENTRO DEL MAIN TIENEN QUE SER POR EJ EL UPDATE QUE TIENE ADENTO EL UPDATE DEL MENU, GAMEPLAY
//Y PANTALLA FINAL O SON VARIOS UPDATES?? O ES UNA FUNCION "MENU" CON UPDATE, DRAW, CLOSE, ETC Y OTRA ASI PARA PLAY??? 

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
		PlayMusicStream(gatitos);
		UpdateMusicStream(gatitos);
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawTexture(texturaFondo, 0, 0, WHITE);
		won_matchesP1 = 0;
		won_matchesP2 = 0;
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
		restarted = true;
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), RedButton))
		{
			RedButton.y = P1_colored_buttons_y - 10;
			BlueButton.y = P1_colored_buttons_y;
			GreenButton.y = P1_colored_buttons_y;
			P1color = RED;
		}
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), GreenButton))
		{
			RedButton.y = P1_colored_buttons_y;
			BlueButton.y = P1_colored_buttons_y;
			GreenButton.y = P1_colored_buttons_y - 10;
			P1color = GREEN;
		}
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), BlueButton))
		{
			RedButton.y = P1_colored_buttons_y;
			BlueButton.y = P1_colored_buttons_y - 10;
			GreenButton.y = P1_colored_buttons_y;
			P1color = BLUE;
		}
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), RedButton2))
		{
			RedButton2.y = P2_colored_buttons_y - 10;
			BlueButton2.y = P2_colored_buttons_y;
			GreenButton2.y = P2_colored_buttons_y;
			P2color = RED;
		}
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), GreenButton2))
		{
			RedButton2.y = P2_colored_buttons_y;
			BlueButton2.y = P2_colored_buttons_y;
			GreenButton2.y = P2_colored_buttons_y - 10;
			P2color = GREEN;
		}
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), BlueButton2))
		{
			RedButton2.y = P2_colored_buttons_y;
			BlueButton2.y = P2_colored_buttons_y - 10;
			GreenButton2.y = P2_colored_buttons_y;
			P2color = BLUE;
		}
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), ExitButton)) gamestate=Close;
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), PlayButton)) {
			StopMusicStream(gatitos);
			gamestate = Gameplay;
		}
		EndDrawing();
		resetValues();
		break;
		case Gameplay:
		PlayMusicStream(nihaoNyan);
		UpdateMusicStream(nihaoNyan);
		DrawTexture(texturaFondo, 0, 0, WHITE);
		cronometer = (double)clock() / 1000;
		cronometerflo = (double)clock() / 1000;
		if (pointsP1 >= 10)//PUESTO PARA TESTEAR, VOLVER A PONER EN 10, ALSO CREAR VARIABLE DE "MAX POINTS"
		{
			won_matchesP1 += 1;
			StopMusicStream(nihaoNyan);
			gamestate = EndScreen;
		}
		if (pointsP2 >= 10)
		{
			won_matchesP2 += 1;
			StopMusicStream(nihaoNyan);
			gamestate = EndScreen;
		}
		if (IsKeyPressed(KEY_SPACE)) pause = !pause;
		if (!pause)
		{
			if (CheckCollisionCircleRec(ballPosition, ball_radius, PowerUP1) && powerUPexists == true)
			{
				PowerUP1.y = -10;
				if (lastPlayerHit == 1)
				{
					power_gravityP1 += 1;
				}
				if (lastPlayerHit == 2)
				{
					power_gravityP2 += 1;
				}
				powerUPexists = false;
			}
			if (CheckCollisionCircleRec(ballPosition, ball_radius, PowerUP2) && powerUP2exists == true)
			{
				PowerUP2.y = -10;
				invisible = true;
				invisibility_timer = cronometerflo;

				powerUP2exists = false;
			}
			if (IsKeyPressed(KEY_LEFT_CONTROL) && power_gravityP1 > 0)
			{
				ballSpeed.y *= -1.0f;
				power_gravityP1 -= 1;
			}
			if (IsKeyPressed(KEY_RIGHT_CONTROL) && power_gravityP2 > 0)
			{
				ballSpeed.y *= -1.0f;
				power_gravityP2 -= 1;
			}
			if (ballPosition.x + ball_radius >= GetScreenWidth())
			{
				ballPosition.x = GetScreenWidth() - GetScreenWidth() / 8;
				ballPosition.y = GetScreenHeight() / 2;
				pointsP1 += 1;
				total_points += 1;
				SetTargetFPS(120 + total_points * 5);
				colliding2 = true;
				colliding = true;
				BallColor = P2color;
				lastPlayerHit = 2;
			}
			if (ballPosition.x - ball_radius == 0)
			{
				ballPosition.x = GetScreenWidth() / 8;
				ballPosition.y = GetScreenHeight() / 2;
				pointsP2 += 1;
				total_points += 1;
				SetTargetFPS(120 + total_points * 2.5);
				colliding = true;
				colliding2 = true;
				BallColor = P1color;
				lastPlayerHit = 1;
			}
			if (IsKeyDown('W') && P1.y > 0) P1.y -= paddle_speed;
			if (IsKeyDown('S') && P1.y + P1.height < GetScreenHeight()) P1.y += paddle_speed;
			if (IsKeyDown(KEY_UP) && P2.y > 0) P2.y -= paddle_speed;
			if (IsKeyDown(KEY_DOWN) && P2.y + P2.height < GetScreenHeight()) P2.y += paddle_speed;
			ballPosition.x += ballSpeed.x;
			ballPosition.y += ballSpeed.y;
			if (!CheckCollisionCircleRec(ballPosition, ball_radius, P1))
			{
				colliding = false;
			}
			if (CheckCollisionCircleRec(ballPosition, ball_radius, P1) && colliding == false) {
				colliding = true;
				if (ballPosition.y < P1.y + P1.height / 2)
				{
					if (ballSpeed.y > 0)
					{
						ballSpeed.y *= -1.0f;
					}
				}
				if (ballPosition.y > P1.y + P1.height / 2)
				{
					if (ballSpeed.y < 0)
					{
						ballSpeed.y *= -1.0f;
					}
				}
				ballSpeed.x *= -1.0f;
				BallColor = P1color;
				lastPlayerHit = 1;
			}
			if (!CheckCollisionCircleRec(ballPosition, ball_radius, P2))
			{
				colliding2 = false;
			}
			if (CheckCollisionCircleRec(ballPosition, ball_radius, P2) && colliding2 == false) {
				colliding2 = true;
				if (ballPosition.y < P2.y + P2.height / 2)
				{
					if (ballSpeed.y > 0)
					{
						ballSpeed.y *= -1.0f;
					}
				}
				if (ballPosition.y > P2.y + P2.height / 2)
				{
					if (ballSpeed.y < 0)
					{
						ballSpeed.y *= -1.0f;
					}
				}
				ballSpeed.x *= -1.0f;
				BallColor = P2color;
				lastPlayerHit = 2;
			}

			if ((ballPosition.x >= (GetScreenWidth() - ball_radius)) || (ballPosition.x <= ball_radius)) ballSpeed.x *= -1.0f;
			if ((ballPosition.y >= (GetScreenHeight() - ball_radius)) || (ballPosition.y <= ball_radius)) ballSpeed.y *= -1.0f;
		}
		else framesCounter++;
		//
		break;
		
		case EndScreen:
		endingScreenUpdate();
		endingScreenDraw();
		resetValues();
		break;
		}
	}

	UnloadTexture(texturaBola);
	UnloadTexture(texturaFondo);
	UnloadTexture(texturaBarra);
	UnloadMusicStream(gatitos);
	UnloadMusicStream(metalNyan);
	CloseAudioDevice();
	CloseWindow();
}

