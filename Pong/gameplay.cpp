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
#include "general.h"

void updateGameplay() {
	PlayMusicStream(nihaoNyan);
	UpdateMusicStream(nihaoNyan);
	DrawTexture(texturaFondo, 0, 0, WHITE);
	cronometer = (double)clock() / 1000;
	cronometerFlo = (double)clock() / 1000;
	if (player1.points >= winning_points)
	{
		player1.wonMatches += 1;
		StopMusicStream(nihaoNyan);
		gamestate = EndScreen;
	}
	if (player2.points >= winning_points)
	{
		player2.wonMatches += 1;
		StopMusicStream(nihaoNyan);
		gamestate = EndScreen;
	}
	if (IsKeyPressed(KEY_SPACE)) pause = !pause;
	if (!pause)
	{
		if (CheckCollisionCircleRec(ball.position, ball.radius, PowerUP1) && powerUPexists == true)
		{
			if (ball.lastPlayerHit == 1)
			{
				player1.gravityPills += 1;
			}
			if (ball.lastPlayerHit == 2)
			{
				player2.gravityPills += 1;
			}
			powerUPexists = false;
		}
		if (CheckCollisionCircleRec(ball.position, ball.radius, PowerUP2) && powerUP2exists == true)
		{
			ball.invisibility = true;
			ball.invisibilityTimer = cronometerFlo;
			powerUP2exists = false;
		}
		if (IsKeyPressed(KEY_LEFT_CONTROL) && player1.gravityPills > 0)
		{
			ball.speed.y *= -1.0f ;
			player1.gravityPills -= 1;
		}
		if (IsKeyPressed(KEY_RIGHT_CONTROL) && player2.gravityPills > 0)
		{
			ball.speed.y *= -1.0f;
			player2.gravityPills -= 1;
		}
		if (ball.position.x + ball.radius >= GetScreenWidth())
		{
			ball.speed.x*=-1.0f;
			ball.position.x = GetScreenWidth() - GetScreenWidth() / 8;
			ball.position.y = GetScreenHeight() / 2;
			player1.points += 1;
			total_points += 1;
			speedMultiplier += 0.05;
			colliding2 = true;
			colliding = true;
			ball.color = player2.color;
			ball.lastPlayerHit = 2;
		}
		if (ball.position.x - ball.radius <= 0)
		{
			ball.speed.x *= -1.0f;
			ball.position.x = GetScreenWidth() / 8;
			ball.position.y = GetScreenHeight() / 2;
			player2.points += 1;
			total_points += 1;
			speedMultiplier += 0.05;
			colliding = true;
			colliding2 = true;
			ball.color = player1.color;
			ball.lastPlayerHit = 1;
		}
		if (IsKeyDown('W') && player1.bar.y > 0) player1.bar.y -= player1.speed * GetFrameTime() *speedMultiplier;
		if (IsKeyDown('S') && player1.bar.y + player1.bar.height < GetScreenHeight()) player1.bar.y += player1.speed * GetFrameTime()*speedMultiplier;
		if (IsKeyDown(KEY_UP) && player2.bar.y > 0) player2.bar.y -= player2.speed * GetFrameTime()*speedMultiplier;
		if (IsKeyDown(KEY_DOWN) && player2.bar.y + player2.bar.height < GetScreenHeight()) player2.bar.y += player2.speed * GetFrameTime()*speedMultiplier;
		ball.position.x += ball.speed.x*GetFrameTime()*speedMultiplier;
		ball.position.y += ball.speed.y*GetFrameTime()*speedMultiplier;
		if (!CheckCollisionCircleRec(ball.position, ball.radius, player1.bar))
		{
			colliding = false;
		}
		if (CheckCollisionCircleRec(ball.position, ball.radius, player1.bar) && colliding == false) {
			colliding = true;
			if (ball.position.y < player1.bar.y + player1.bar.height / 2)
			{
				if (ball.speed.y > 0)
				{
					ball.speed.y *= -1.0f;
				}
			}
			if (ball.position.y > player1.bar.y + player1.bar.height / 2)
			{
				if (ball.speed.y < 0)
				{
					ball.speed.y *= -1.0f;
				}
			}
			ball.speed.x *= -1.0f;
			ball.color = player1.color;
			ball.lastPlayerHit = 1;
		}
		if (!CheckCollisionCircleRec(ball.position, ball.radius, player2.bar))
		{
			colliding2 = false;
		}
		if (CheckCollisionCircleRec(ball.position, ball.radius, player2.bar) && colliding2 == false) {
			colliding2 = true;
			if (ball.position.y < player2.bar.y + player2.bar.height / 2)
			{
				if (ball.speed.y > 0)
				{
					ball.speed.y *= -1.0f;
				}
			}
			if (ball.position.y > player2.bar.y + player2.bar.height / 2)
			{
				if (ball.speed.y < 0)
				{
					ball.speed.y *= -1.0f;
				}
			}
			ball.speed.x *= -1.0f;
			ball.color = player2.color;
			ball.lastPlayerHit = 2;
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
		if ((ball.position.y >= (GetScreenHeight() - ball.radius)) || (ball.position.y <= ball.radius)) ball.speed.y *= -1.0f;
	}
	else framesCounter++;
}
void drawGameplay() {
	BeginDrawing();
	ClearBackground(RAYWHITE);

	switch (player1.gravityPills)
	{
	default:
	case 5:DrawCircle(130, 20, 5, BLACK);
	case 4:DrawCircle(115, 20, 5, BLACK);
	case 3:DrawCircle(100, 20, 5, BLACK);
	case 2:DrawCircle(85, 20, 5, BLACK);
	case 1:DrawCircle(70, 20, 5, BLACK);
	case 0:break;
	}
	switch (player2.gravityPills)
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
	if (ball.invisibility == false)
	{
		DrawTexture(ballTexture, ball.position.x - 27, ball.position.y - 17, ball.color);
	}
	if (ball.invisibility == true && cronometerFlo >= ball.invisibilityTimer + 0.75)
	{
		ball.invisibility = false;
	}
	DrawTexture(texturaBarra, player2.bar.x - 18, player2.bar.y, player2.color);
	DrawTexture(texturaBarra, player1.bar.x - 18, player1.bar.y, player1.color);
	DrawText(TextFormat("P1: %i", player1.points), 10, 10, 20, player1.color);
	DrawText(TextFormat("P2: %i", player2.points), GetScreenWidth() - 70, 10, 20, player2.color);
	if (pause && ((framesCounter / 30) % 4)) DrawText("PRESS SPACE TO PLAY", 230, 200, 30, BLACK);
	EndDrawing();
}