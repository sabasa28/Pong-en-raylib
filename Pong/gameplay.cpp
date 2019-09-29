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


Gamemode gamemode = vsPlayer;
static float PointsTextYDivider = 45.0f;
static float PointsTextFontSizeDivider = 22.5f;
static float p1PointsTextXDivider = 80.0f;
static float p2PointsTextXDivider = 1.09589f;
static float pauseTextXDivider = 3.47826f;
static float pauseTextYDivider = 2.25f;
static float pauseTextFontSizeDivider = 15.0f;

namespace catPong {
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
			if (IsKeyDown('W') && player1.bar.y > 0) player1.bar.y -= player1.speed * GetFrameTime() *speedMultiplier;
			if (IsKeyDown('S') && player1.bar.y + player1.bar.height < screenHeight) player1.bar.y += player1.speed * GetFrameTime()*speedMultiplier;
			if (IsKeyPressed(KEY_LEFT_CONTROL) && player1.gravityPills > 0)
			{
				ball.speed.y *= -1.0f;
				player1.gravityPills -= 1;
			}
			if (gamemode==vsPlayer)
			{
				if (IsKeyDown(KEY_UP) && player2.bar.y > 0) player2.bar.y -= player2.speed * GetFrameTime()*speedMultiplier;
				if (IsKeyDown(KEY_DOWN) && player2.bar.y + player2.bar.height < screenHeight) player2.bar.y += player2.speed * GetFrameTime()*speedMultiplier;
				if (IsKeyPressed(KEY_RIGHT_CONTROL) && player2.gravityPills > 0)
				{
					ball.speed.y *= -1.0f;
					player2.gravityPills -= 1;
				}
			}
			else if (gamemode==vsBot)
			{
				if (ball.position.y>player2.bar.y+player2.bar.height/2&& player2.bar.y + player2.bar.height < screenHeight) player2.bar.y += player2.speed * GetFrameTime()*speedMultiplier;
				if (ball.position.y < player2.bar.y + player2.bar.height / 2 && player2.bar.y > 0) player2.bar.y -= player2.speed * GetFrameTime()*speedMultiplier;
			}
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
			if (ball.position.x + ball.radius >= screenWidth)
			{
				ball.speed.x *= -1.0f;
				ball.position.x = rightResetPos;
				ball.position.y = screenHeight / 2;
				player1.points += 1;
				total_points += 1;
				speedMultiplier += boost;
				ball.color = player2.color;
				ball.lastPlayerHit = 2;
			}
			if (ball.position.x - ball.radius <= 0)
			{
				ball.speed.x *= -1.0f;
				ball.position.x = leftResetPos;
				ball.position.y = screenHeight / 2;
				player2.points += 1;
				total_points += 1;
				speedMultiplier += boost;
				ball.color = player1.color;
				ball.lastPlayerHit = 1;
			}
			ball.position.x += ball.speed.x*GetFrameTime()*speedMultiplier;
			ball.position.y += ball.speed.y*GetFrameTime()*speedMultiplier;
			if (CheckCollisionCircleRec(ball.position, ball.radius, player1.bar) && ball.speed.x<0) {
				if (ball.position.y < player1.bar.y + player1.bar.height / 2&&ball.speed.y > 0)
				{
					ball.speed.y *= -1.0f;
				}
				if (ball.position.y > player1.bar.y + player1.bar.height / 2&& ball.speed.y < 0)
				{
					ball.speed.y *= -1.0f;
				}
				ball.speed.x *= -1.0f;
				ball.color = player1.color;
				ball.lastPlayerHit = 1;
				PlaySound(kittenMeow);
			}
			if (CheckCollisionCircleRec(ball.position, ball.radius, player2.bar)&& ball.speed.x > 0) {
				if (ball.position.y < player2.bar.y + player2.bar.height / 2&& ball.speed.y > 0)
				{
					ball.speed.y *= -1.0f;
				}
				if (ball.position.y > player2.bar.y + player2.bar.height / 2&& ball.speed.y < 0)
				{
					ball.speed.y *= -1.0f;
				}
				ball.speed.x *= -1.0f;
				ball.color = player2.color;
				ball.lastPlayerHit = 2;
				PlaySound(catMeow);
			}

			if (cronometer >= lastTimer + delayToRespawn)
			{
				PowerUP1.y = rand() % static_cast<int>(screenHeight - screenHeight / pwrUPMinRespawnPosDivider) + static_cast<int>(screenHeight / pwrUPMaxRespawnPosDivider);
				powerUPexists = true;
				lastTimer = cronometer;
			}
			if (cronometer >= lastTimer2 + delayToRespawn)
			{
				PowerUP2.y = rand() % static_cast<int>(screenHeight - screenHeight / pwrUPMinRespawnPosDivider) + static_cast<int>(screenHeight / pwrUPMaxRespawnPosDivider);
				powerUP2exists = true;
				lastTimer2 = cronometer;
			}
			if (ball.position.y >= (screenHeight - ball.radius) && ball.speed.y > 0) ball.speed.y *= -1.0f;
			if (ball.position.y <= ball.radius && ball.speed.y < 0) ball.speed.y *= -1.0f;
		}
	}
	void drawGameplay() {
		BeginDrawing();
		ClearBackground(RAYWHITE);

		switch (player1.gravityPills)
		{
		default:
		case 5:DrawCircle(pwrUPcharge5.x, pwrUPcharge5.y, pwrUPcharge5.radius, BLACK);
		case 4:DrawCircle(pwrUPcharge4.x, pwrUPcharge4.y, pwrUPcharge4.radius, BLACK);
		case 3:DrawCircle(pwrUPcharge3.x, pwrUPcharge3.y, pwrUPcharge3.radius, BLACK);
		case 2:DrawCircle(pwrUPcharge2.x, pwrUPcharge2.y, pwrUPcharge2.radius, BLACK);
		case 1:DrawCircle(pwrUPcharge1.x, pwrUPcharge1.y, pwrUPcharge1.radius, BLACK);
		case 0:break;							 
		}										 
		switch (player2.gravityPills)			 
		{										 
		default:								 
		case 5:DrawCircle(pwrUPcharge10.x, pwrUPcharge10.y, pwrUPcharge10.radius, BLACK);
		case 4:DrawCircle(pwrUPcharge9.x, pwrUPcharge9.y, pwrUPcharge9.radius, BLACK);	 
		case 3:DrawCircle(pwrUPcharge8.x, pwrUPcharge8.y, pwrUPcharge8.radius, BLACK);	 
		case 2:DrawCircle(pwrUPcharge7.x, pwrUPcharge7.y, pwrUPcharge7.radius, BLACK);	 
		case 1:DrawCircle(pwrUPcharge6.x, pwrUPcharge6.y, pwrUPcharge6.radius, BLACK);	 
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
			DrawTexture(ballTexture, ball.position.x - screenWidth/ballTexOffsetXDivider, ball.position.y - screenHeight/ballTexOffsetYDivider, ball.color);
		}
		if (ball.invisibility == true && cronometerFlo >= ball.invisibilityTimer + 0.75)
		{
			ball.invisibility = false;
		}
		DrawTexture(player1.textura, player1.bar.x - screenWidth / paddleTexOffsetXDivider, player1.bar.y, player1.color);
		DrawTexture(player2.textura, player2.bar.x - screenWidth / paddleTexOffsetXDivider, player2.bar.y, player2.color);
		DrawText(TextFormat("P1: %i", player1.points), screenWidth / p1PointsTextXDivider, screenHeight / PointsTextYDivider, screenHeight / PointsTextFontSizeDivider, player1.color);
		DrawText(TextFormat("P2: %i", player2.points), screenWidth / p2PointsTextXDivider, screenHeight / PointsTextYDivider, screenHeight / PointsTextFontSizeDivider, player2.color);
		if (pause && (cronometer % 2 == 0)) DrawText("PRESS SPACE TO PLAY", screenWidth / pauseTextXDivider, screenHeight / pauseTextYDivider, screenHeight / pauseTextFontSizeDivider, DARKPURPLE);
		EndDrawing();
	}
}