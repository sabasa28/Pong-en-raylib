#include "gameplay.h"
#include <stdlib.h>
#include <time.h>
#include "raylib.h"
#include "powerUPs.h"
#include "paddles.h"
#include "console.h"
#include "ball.h"
#include "musicSounds.h"
#include "game.h"
#include "background.h"
void gameplayUpdate() {
	PlayMusicStream(nihaoNyan);
	UpdateMusicStream(nihaoNyan);
	DrawTexture(texturaFondo, 0, 0, WHITE);
	cronometer = (double)clock() / 1000;
	cronometerflo = (double)clock() / 1000;
	if (pointsP1 >= winning_points)
	{
		won_matchesP1 += 1;
		StopMusicStream(nihaoNyan);
		gamestate = EndScreen;
	}
	if (pointsP2 >= winning_points)
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
		if ((ballPosition.x >= (GetScreenWidth() - ball_radius)) || (ballPosition.x <= ball_radius)) ballSpeed.x *= -1.0f;
		if ((ballPosition.y >= (GetScreenHeight() - ball_radius)) || (ballPosition.y <= ball_radius)) ballSpeed.y *= -1.0f;
	}
	else framesCounter++;
}
void gameplayDraw() {
	BeginDrawing();
	ClearBackground(RAYWHITE);

	switch (power_gravityP1)
	{
	default:
	case 5:DrawCircle(130, 20, 5, BLACK);
	case 4:DrawCircle(115, 20, 5, BLACK);
	case 3:DrawCircle(100, 20, 5, BLACK);
	case 2:DrawCircle(85, 20, 5, BLACK);
	case 1:DrawCircle(70, 20, 5, BLACK);
	case 0:break;
	}
	switch (power_gravityP2)
	{
	default:
	case 5:DrawCircle(655, 20, 5, BLACK);
	case 4:DrawCircle(670, 20, 5, BLACK);
	case 3:DrawCircle(685, 20, 5, BLACK);
	case 2:DrawCircle(700, 20, 5, BLACK);
	case 1:DrawCircle(715, 20, 5, BLACK);
	case 0:break;
	}


	if (powerUPexists == true)
	{
		DrawTexture(texturaPowerUP, PowerUP1.x, PowerUP1.y, WHITE);
	}
	if (powerUP2exists == true)
	{
		DrawTexture(texturaPowerUP2, PowerUP2.x, PowerUP2.y, PINK);
	}
	if (invisible == false)
	{
		DrawTexture(texturaBola, ballPosition.x - 27, ballPosition.y - 17, BallColor);
	}
	if (invisible == true && cronometerflo >= invisibility_timer + 0.75)
	{
		invisible = false;
	}
	DrawTexture(texturaBarra, P2.x - 18, P2.y, P2color);
	DrawTexture(texturaBarra, P1.x - 18, P1.y, P1color);
	DrawText(TextFormat("P1: %i", pointsP1), 10, 10, 20, P1color);
	DrawText(TextFormat("P2: %i", pointsP2), GetScreenWidth() - 70, 10, 20, P2color);
	if (pause && ((framesCounter / 30) % 4)) DrawText("PRESS SPACE TO PLAY", 230, 200, 30, BLACK);
	EndDrawing();
}