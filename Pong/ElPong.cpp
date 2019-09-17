#include <time.h>
#include "raylib.h"
#include <stdlib.h>
#include "console.h"
#include "paddles.h"
#include "powerUPs.h"
#include "ball.h"
#include "background.h"
#include "musicSounds.h"

int main(void)
{
	initCronometers();
	srand(time(NULL));
	InitWindow(screenWidth, screenHeight, "PONG - Inaki Diez Galarza");//(Iñaki)
	InitAudioDevice();
	initPaddle();
	initPaddleTex();
	initPowerUP();
	initPowerUPTex();
	initBall();
	initBallTex();
	initBackground();
	initMusicSounds();
	
	//ball
	bool colliding = false;
	bool colliding2 = false;
	int lastPlayerHit = 1;

	//console
	float FPS = 120;
	float StartigFPS = FPS;
	bool pause = 0;
	int framesCounter = 0;
	
	bool restarted =false;
	bool menu = true;

	//menu
	Rectangle PlayButton;
	PlayButton.x = 180;
	PlayButton.y = 120;
	PlayButton.width = 400;
	PlayButton.height = 100;
	Rectangle ExitButton;
	ExitButton.x = 230;
	ExitButton.y = 240;
	ExitButton.width = 300;
	ExitButton.height = 80;
	Rectangle RedButton;
	Rectangle GreenButton;
	Rectangle BlueButton;
	Rectangle RedButton2;
	Rectangle GreenButton2;
	Rectangle BlueButton2;
	int coloredbuttons_height = 30;
	int coloredbuttons_width = 100;
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
	int P1_colored_buttons_y = 350;
	int P2_colored_buttons_y = 400;
	int red_buttons_x = 250;
	int green_buttons_x = 350;
	int blue_buttons_x = 450;
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


	int lastTimer = 0;
	int lastTimer2 = 0;

	//ball creo, yo que se, vofi
	bool invisible = false;
	float invisibility_timer;
	
	while (!WindowShouldClose())
	{
		
		if (restarted == true)
		{
			PlayMusicStream(metalNyan);
			while (!IsKeyPressed('R')&&!WindowShouldClose())
			{
				UpdateMusicStream(metalNyan);
				BeginDrawing();
				ClearBackground(RAYWHITE);
				if (pointsP1 >= 10)
				{
					winner = 1;
				}
				else if (pointsP2 >= 10)
				{
					winner = 2;
				}
				DrawText(TextFormat("PLAYER %i", winner), 180, 110, 50, BLACK);
				DrawText("WINS.", 450, 110, 50, BLACK);
				DrawText("Press 'R' to play again.", 80, 250, 30, BLACK);
				DrawText("Press 'M' to go to menu.", 80, 290, 30, BLACK);
				DrawText("Press 'ESC' to quit.", 80, 330, 30, BLACK);
				DrawText(TextFormat("Won matches P1: %i", won_matchesP1), 500, 330, 20, P1color);
				DrawText(TextFormat("Won matches P2: %i", won_matchesP2), 500, 360, 20, P2color);
				if (IsKeyPressed('M'))
				{
					menu = true;
					break;
				}
				if (IsKeyPressed('R'))
				{
					restarted = true;
				}
				EndDrawing();
			}
			StopMusicStream(metalNyan);
		}
		if (menu == true)
		{
			PlayMusicStream(gatitos);
			while (!WindowShouldClose())
			{
				UpdateMusicStream(gatitos);
				BeginDrawing();
				ClearBackground(RAYWHITE);
				DrawTexture(texturaFondo, 0, 0, WHITE);
				won_matchesP1 = 0;
				won_matchesP2 = 0;
				DrawRectangle(PlayButton.x,PlayButton.y,PlayButton.width,PlayButton.height,BLUE);
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
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), ExitButton)) CloseWindow();
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(),PlayButton)) break;
				EndDrawing();
				menu = false;
			}
			StopMusicStream(gatitos);
		}

		ballPosition.x = GetScreenWidth() / 2;
		ballPosition.y = GetScreenHeight() / 2;
		colliding = false;
		colliding2 = false;
		pointsP1 = 0;
		pointsP2 = 0;
		total_points = 0;
		P1.x = GetScreenWidth() / 8 -20;
		P1.y = GetScreenHeight() / 2;
		P2.x = GetScreenWidth() - GetScreenWidth() / 8 + 20;
		P2.y = GetScreenHeight() / 2;
		FPS = 120;
		StartigFPS = FPS;
		pause = true;
		framesCounter = 0;
		power_gravityP1 = 3;
		power_gravityP2 = 3;
		SetTargetFPS(FPS);
		PlayMusicStream(nihaoNyan);
		cronometer = (double)clock() / 1000;
		cronometerflo = (double)clock() / 1000;
		lastTimer = cronometer;
		lastTimer2 = cronometer;
		while (!WindowShouldClose())   
		{
			UpdateMusicStream(nihaoNyan);
			DrawTexture(texturaFondo, 0, 0, WHITE);
			cronometer = (double)clock() / 1000;
			cronometerflo = (double)clock() / 1000;
			if (pointsP1 >= 10)
			{
				won_matchesP1 += 1;
				break;
			}
			if (pointsP2 >= 10)
			{
				won_matchesP2 += 1;
				break;
			}
		
			if (IsKeyPressed(KEY_SPACE)) pause = !pause;
			if (!pause)
			{
				if (CheckCollisionCircleRec(ballPosition,ball_radius,PowerUP1)&&powerUPexists==true)
				{
					PowerUP1.y = -10;
					if (lastPlayerHit==1)
					{
						power_gravityP1 += 1;
					}
					if (lastPlayerHit==2)
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
				if(IsKeyPressed(KEY_LEFT_CONTROL)&&power_gravityP1>0)
				{
					ballSpeed.y *= -1.0f;
					power_gravityP1 -= 1;
				}
				if (IsKeyPressed(KEY_RIGHT_CONTROL)&&power_gravityP2>0)
				{
					ballSpeed.y *= -1.0f;
					power_gravityP2 -= 1;
				}

				if (ballPosition.x + ball_radius >= GetScreenWidth())
				{
					ballPosition.x = GetScreenWidth()- GetScreenWidth() / 8 ;
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

			BeginDrawing();

			ClearBackground(RAYWHITE);
			if (invisible==false)
			{
				DrawTexture(texturaBola, ballPosition.x - 27, ballPosition.y - 17, BallColor);
			}
			if (invisible==true&&cronometerflo>=invisibility_timer+0.75)
			{
				invisible = false;
			}

			DrawTexture(texturaBarra, P2.x - 18, P2.y, P2color);
			DrawTexture(texturaBarra, P1.x - 18, P1.y, P1color);
			

			//ESTO SE PUEDE HACER MUCHO MAS HERMOSO CON UN SWITCH SIN BREAKS
			if (power_gravityP1 > 0)DrawCircle(70, 20, 5, BLACK);
			if (power_gravityP1 > 1)DrawCircle(85, 20, 5, BLACK);
			if (power_gravityP1 > 2)DrawCircle(100, 20, 5, BLACK);
			if (power_gravityP1 > 3)DrawCircle(115, 20, 5, BLACK);
			if (power_gravityP1 > 4)DrawCircle(130, 20, 5, BLACK);
			if (power_gravityP2 > 0)DrawCircle(655, 20, 5, BLACK);
			if (power_gravityP2 > 1)DrawCircle(670, 20, 5, BLACK);
			if (power_gravityP2 > 2)DrawCircle(685, 20, 5, BLACK);
			if (power_gravityP2 > 3)DrawCircle(700, 20, 5, BLACK);
			if (power_gravityP2 > 4)DrawCircle(715, 20, 5, BLACK);

			if (cronometer >= lastTimer + 15)
			{
				PowerUP1.y = rand() % (GetScreenHeight() - 40) + 20;
				powerUPexists = true;
				lastTimer = cronometer;
			}
			if (cronometer >= lastTimer2 + 15)
			{
				PowerUP2.y = rand() % (GetScreenHeight() - 40) + 20;
				powerUP2exists = true;
				lastTimer2 = cronometer;
			}
			if (powerUPexists==true)
			{
				DrawTexture(texturaPowerUP, PowerUP1.x, PowerUP1.y, WHITE);
			}
			if (powerUP2exists == true)
			{	
				DrawTexture(texturaPowerUP2, PowerUP2.x, PowerUP2.y, PINK);
			}

			DrawText(TextFormat("P1: %i", pointsP1), 10, 10, 20, P1color);
			DrawText(TextFormat("P2: %i", pointsP2), GetScreenWidth() - 70, 10, 20, P2color);

			if (pause && ((framesCounter / 30) % 4)) DrawText("PRESS SPACE TO PLAY", 230, 200, 30, BLACK);

			EndDrawing();
		}
		StopMusicStream(nihaoNyan);
	}

	UnloadTexture(texturaBola);
	UnloadTexture(texturaFondo);
	UnloadTexture(texturaBarra);
	UnloadMusicStream(gatitos);
	UnloadMusicStream(metalNyan);
	CloseAudioDevice();
	CloseWindow();        
	
	return 0;
}