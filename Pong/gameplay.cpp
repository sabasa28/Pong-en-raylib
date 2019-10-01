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
const static float PointsTextYDivider = 45.0f;
const static float PointsTextFontSizeDivider = 22.5f;
const static float p1PointsTextXDivider = 80.0f;
const static float p2PointsTextXDivider = 1.09589f;
const static float pauseTextFontSizeDivider = 15.0f;
const static float pauseTextXDivider = 3.47826f;
const static float pauseTextYDivider = 2.25f;
const static float controlsTextColumn1XDivider = 80.0f;
const static float controlsTextColumn2XDivider = 2.0f;
const static float controlsTextRow1YDivider = 1.50f;
const static float controlsTextRow2YDivider = 1.30f;
const static float controlsTextRow3YDivider = 1.20f;
const static float controlsTextRow4YDivider = 1.12f;






namespace catPong {
	void updateGameplay() {
		PlayMusicStream(gameSong);
		UpdateMusicStream(gameSong);
		DrawTexture(texturaFondo, 0, 0, WHITE);
		cronometer = static_cast<int>(clock() / 1000);
		cronometerFlo = static_cast<float>(clock()) / 1000;
		if (player1.points >= winning_points){
			player1.wonMatches += 1;
			StopMusicStream(gameSong);
			gamestate = EndScreen;
		}
		if (player2.points >= winning_points){
			player2.wonMatches += 1;
			StopMusicStream(gameSong);
			gamestate = EndScreen;
		}
		if (IsKeyPressed(KEY_SPACE)) pause = !pause;
		if (!pause){
			if (IsKeyDown('W') && player1.bar.y > 0) player1.bar.y -= player1.speed * GetFrameTime() *speedMultiplier;
			if (IsKeyDown('S') && player1.bar.y + player1.bar.height < screenHeight) player1.bar.y += player1.speed * GetFrameTime()*speedMultiplier;
			if (IsKeyPressed(KEY_LEFT_CONTROL) && player1.gravityPills > 0){
				ball.speed.y *= -1.0f;
				player1.gravityPills -= 1;
			}
			if (gamemode==vsPlayer){
				if (IsKeyDown(KEY_UP) && player2.bar.y > 0) player2.bar.y -= player2.speed * GetFrameTime()*speedMultiplier;
				if (IsKeyDown(KEY_DOWN) && player2.bar.y + player2.bar.height < screenHeight) player2.bar.y += player2.speed * GetFrameTime()*speedMultiplier;
				if (IsKeyPressed(KEY_RIGHT_CONTROL) && player2.gravityPills > 0){
					ball.speed.y *= -1.0f;
					player2.gravityPills -= 1;
				}
			}
			else if (gamemode==vsBot){
				if (ball.position.y>player2.bar.y+player2.bar.height/2&& player2.bar.y + player2.bar.height < screenHeight) player2.bar.y += player2.speed * GetFrameTime()*speedMultiplier;
				if (ball.position.y < player2.bar.y + player2.bar.height / 2 && player2.bar.y > 0) player2.bar.y -= player2.speed * GetFrameTime()*speedMultiplier;
				if (botUsedPowerUP==true &&(cronometer-1)%minTimeBetweenBotPwrUp==0)botUsedPowerUP = false;
				if(cronometer%minTimeBetweenBotPwrUp==0&& ball.speed.x<0 && player2.gravityPills >0 && botUsedPowerUP==false){
					ball.speed.y *= -1.0f;
					player2.gravityPills -= 1;
					botUsedPowerUP = true;
				}
			}
			if (CheckCollisionCircleRec(ball.position, static_cast<float>(ball.radius), PowerUP1) && powerUPexists == true){
				if (ball.lastPlayerHit == 1){
					player1.gravityPills += 1;
				}
				if (ball.lastPlayerHit == 2){
					player2.gravityPills += 1;
				}
				powerUPexists = false;
			}
			if (CheckCollisionCircleRec(ball.position, static_cast<float>(ball.radius), PowerUP2) && powerUP2exists == true){
				ball.invisibility = true;
				ball.invisibilityTimer = cronometerFlo;
				powerUP2exists = false;
			}
			if (ball.position.x + ball.radius >= screenWidth){
				ball.speed.x = -(screenWidth / BallSpeed2XDivider);
				ball.speed.y = -(screenHeight/ BallSpeed2YDivider);
				ball.position.x = rightResetPos;
				ball.position.y = static_cast<float>(screenHeight / 2);
				player1.points += 1;
				total_points += 1;
				speedMultiplier += boost;
				ball.color = player2.color;
				ball.lastPlayerHit = 2;
			}
			if (ball.position.x - ball.radius <= 0){
				ball.speed.x = screenWidth / BallSpeed2XDivider;
				ball.speed.y = -(screenHeight / BallSpeed2YDivider);
				ball.position.x = leftResetPos;
				ball.position.y = static_cast<float>(screenHeight / 2);
				player2.points += 1;
				total_points += 1;
				speedMultiplier += boost;
				ball.color = player1.color;
				ball.lastPlayerHit = 1;
			}
			ball.position.x += ball.speed.x*GetFrameTime()*speedMultiplier;
			ball.position.y += ball.speed.y*GetFrameTime()*speedMultiplier;
			if (CheckCollisionCircleRec(ball.position, static_cast<float>(ball.radius), player1.bar) && ball.speed.x<0) {
				if (ball.position.y < player1.bar.y + player1.bar.height / 6){
					ball.speed.x = screenWidth / BallSpeed1XDivider;
					ball.speed.y = - (screenHeight / BallSpeed1YDivider);
				}
				if (ball.position.y < player1.bar.y + player1.bar.height / 3 && ball.position.y > player1.bar.y + player1.bar.height / 6) {
					ball.speed.x = screenWidth / BallSpeed2XDivider;
					ball.speed.y = -(screenHeight / BallSpeed2YDivider);
				}
				if (ball.position.y < player1.bar.y + player1.bar.height / 2 && ball.position.y> player1.bar.y + player1.bar.height / 3) {
					ball.speed.x = screenWidth / BallSpeed3XDivider;
					ball.speed.y = -(screenHeight / BallSpeed3YDivider);
				}
				if (ball.position.y > player1.bar.y + player1.bar.height - player1.bar.height/6){
					ball.speed.x = screenWidth / BallSpeed1XDivider;
					ball.speed.y = screenHeight / BallSpeed1YDivider;
				}
				if (ball.position.y > player1.bar.y + player1.bar.height - player1.bar.height / 3 && ball.position.y < player1.bar.y + player1.bar.height - player1.bar.height / 6) {
					ball.speed.x = screenWidth / BallSpeed2XDivider;
					ball.speed.y = screenHeight / BallSpeed2YDivider;
				}
				if (ball.position.y > player1.bar.y + player1.bar.height / 2 && ball.position.y < player1.bar.y + player1.bar.height - player1.bar.height / 3) {
					ball.speed.x = screenWidth / BallSpeed3XDivider;
					ball.speed.y = screenHeight / BallSpeed3YDivider;
				}
				ball.color = player1.color;
				ball.lastPlayerHit = 1;
				PlaySound(kittenMeow);
			}
			if (CheckCollisionCircleRec(ball.position, static_cast<float>(ball.radius), player2.bar)&& ball.speed.x > 0) {
				if (ball.position.y < player2.bar.y + player2.bar.height / 6) {
					ball.speed.x = -(screenWidth / BallSpeed1XDivider);
					ball.speed.y = -(screenHeight / BallSpeed1YDivider);
				}
				if (ball.position.y < player2.bar.y + player2.bar.height / 3 && ball.position.y > player2.bar.y + player2.bar.height / 6) {
					ball.speed.x = -(screenWidth / BallSpeed2XDivider);
					ball.speed.y = -(screenHeight / BallSpeed2YDivider);
				}
				if (ball.position.y < player2.bar.y + player2.bar.height / 2 && ball.position.y> player2.bar.y + player2.bar.height / 3) {
					ball.speed.x = -(screenWidth / BallSpeed3XDivider);
					ball.speed.y = -(screenHeight / BallSpeed3YDivider);
				}
				if (ball.position.y > player2.bar.y + player2.bar.height - player2.bar.height / 6) {
					ball.speed.x = -(screenWidth / BallSpeed1XDivider);
					ball.speed.y = screenHeight / BallSpeed1YDivider;
				}
				if (ball.position.y > player2.bar.y + player2.bar.height - player2.bar.height / 3 && ball.position.y < player2.bar.y + player2.bar.height - player2.bar.height / 6) {
					ball.speed.x = -(screenWidth / BallSpeed2XDivider);
					ball.speed.y = screenHeight / BallSpeed2YDivider;
				}
				if (ball.position.y > player2.bar.y + player2.bar.height / 2 && ball.position.y < player2.bar.y + player2.bar.height -player2.bar.height / 3) {
					ball.speed.x = -(screenWidth / BallSpeed3XDivider);
					ball.speed.y = screenHeight / BallSpeed3YDivider;
				}
				ball.color = player2.color;
				ball.lastPlayerHit = 2;
				PlaySound(catMeow);
			}

			if (cronometer >= lastTimer + delayToRespawn){
				PowerUP1.y = static_cast<float>(rand() % static_cast<int>(screenHeight - screenHeight / pwrUPMinRespawnPosDivider) + static_cast<int>(screenHeight / pwrUPMaxRespawnPosDivider));
				powerUPexists = true;
				lastTimer = cronometer;
			}
			if (cronometer >= lastTimer2 + delayToRespawn){
				PowerUP2.y = static_cast<float>(rand() % static_cast<int>(screenHeight - screenHeight / pwrUPMinRespawnPosDivider) + static_cast<int>(screenHeight / pwrUPMaxRespawnPosDivider));
				powerUP2exists = true;
				lastTimer2 = cronometer;
			}
			if (ball.position.y >= (screenHeight - ball.radius) && ball.speed.y > 0) ball.speed.y *= -1.0f;
			if (ball.position.y <= ball.radius && ball.speed.y < 0) ball.speed.y *= -1.0f;
			if (ball.invisibility == true && cronometerFlo >= (ball.invisibilityTimer + 1.0f))ball.invisibility = false;
		}
	}
	void drawGameplay(){
		BeginDrawing();
		ClearBackground(RAYWHITE);
		switch (player1.gravityPills){
		default:
		case 5:DrawCircle(pwrUPcharge5.x, pwrUPcharge5.y, static_cast<float>(pwrUPcharge5.radius), YELLOW);
		case 4:DrawCircle(pwrUPcharge4.x, pwrUPcharge4.y, static_cast<float>(pwrUPcharge4.radius), YELLOW);
		case 3:DrawCircle(pwrUPcharge3.x, pwrUPcharge3.y, static_cast<float>(pwrUPcharge3.radius), YELLOW);
		case 2:DrawCircle(pwrUPcharge2.x, pwrUPcharge2.y, static_cast<float>(pwrUPcharge2.radius), YELLOW);
		case 1:DrawCircle(pwrUPcharge1.x, pwrUPcharge1.y, static_cast<float>(pwrUPcharge1.radius), YELLOW);
		case 0:break;
		}
		switch (player2.gravityPills){
		default:								 
		case 5:DrawCircle(pwrUPcharge10.x, pwrUPcharge10.y, static_cast<float>(pwrUPcharge10.radius), YELLOW);
		case 4:DrawCircle(pwrUPcharge9.x, pwrUPcharge9.y, static_cast<float>(pwrUPcharge9.radius), YELLOW);	 
		case 3:DrawCircle(pwrUPcharge8.x, pwrUPcharge8.y, static_cast<float>(pwrUPcharge8.radius), YELLOW);	 
		case 2:DrawCircle(pwrUPcharge7.x, pwrUPcharge7.y, static_cast<float>(pwrUPcharge7.radius), YELLOW);	 
		case 1:DrawCircle(pwrUPcharge6.x, pwrUPcharge6.y, static_cast<float>(pwrUPcharge6.radius), YELLOW);	 
		case 0:break;
		}

		if (powerUPexists == true)DrawTexture(texturaPowerUP, static_cast<int>(PowerUP1.x- screenWidth / powerUPTexOffsetXDivider), static_cast<int>(PowerUP1.y - screenHeight / powerUPTexOffsetYDivider), WHITE);
		if (powerUP2exists == true)DrawTexture(texturaPowerUP2, static_cast<int>(PowerUP2.x - screenWidth / powerUPTexOffsetXDivider), static_cast<int>(PowerUP2.y - screenHeight / powerUPTexOffsetYDivider), DARKPURPLE);
		if (ball.invisibility == false) {
			DrawCircle(ball.position.x, ball.position.y, static_cast<int>(ball.radius), BLACK);
			DrawTexture(ballTexture, static_cast<int>(ball.position.x - screenWidth / ballTexOffsetXDivider), static_cast<int>(ball.position.y - screenHeight / ballTexOffsetYDivider), ball.color);
		}
		DrawTexture(player1.textura, static_cast<int>(player1.bar.x - screenWidth / paddleTexOffsetXDivider), static_cast<int>(player1.bar.y - screenHeight / paddleTexOffsetYDivider), player1.color);
		DrawTexture(player2.textura, static_cast<int>(player2.bar.x - screenWidth / paddleTexOffsetXDivider), static_cast<int>(player2.bar.y - screenHeight / paddleTexOffsetYDivider), player2.color);
		DrawTexture(player1.textura, static_cast<int>(player1.bar.x - screenWidth / paddleTexOffsetXDivider), static_cast<int>(player1.bar.y - screenHeight / paddleTexOffsetYDivider), player1.color);
		DrawTexture(player2.textura, static_cast<int>(player2.bar.x - screenWidth / paddleTexOffsetXDivider), static_cast<int>(player2.bar.y - screenHeight / paddleTexOffsetYDivider), player2.color);
		DrawText(TextFormat("P1: %i", player1.points), static_cast<int>(screenWidth / p1PointsTextXDivider), static_cast<int>(screenHeight / PointsTextYDivider), static_cast<int>(screenHeight / PointsTextFontSizeDivider), player1.color);
		DrawText(TextFormat("P2: %i", player2.points), static_cast<int>(screenWidth / p2PointsTextXDivider), static_cast<int>(screenHeight / PointsTextYDivider), static_cast<int>(screenHeight / PointsTextFontSizeDivider), player2.color);
		if (pause==true && (cronometer % 2 == 0)) DrawText("PRESS SPACE TO PLAY", static_cast<int>(screenWidth / pauseTextXDivider), static_cast<int>(screenHeight / pauseTextYDivider), static_cast<int>(screenHeight / pauseTextFontSizeDivider), ORANGE);
		if (pause) {
			DrawText("Player1:", static_cast<int>(screenWidth / controlsTextColumn1XDivider), static_cast<int>(screenHeight / controlsTextRow1YDivider), static_cast<int>(screenHeight / pauseTextFontSizeDivider), player1.color);
			DrawText("Player2:", static_cast<int>(screenWidth / controlsTextColumn2XDivider), static_cast<int>(screenHeight / controlsTextRow1YDivider), static_cast<int>(screenHeight / pauseTextFontSizeDivider), player2.color);
			DrawText("Up = W", static_cast<int>(screenWidth / controlsTextColumn1XDivider), static_cast<int>(screenHeight / controlsTextRow2YDivider), static_cast<int>(screenHeight / pauseTextFontSizeDivider), ORANGE);
			DrawText("Up = Arrow-up", static_cast<int>(screenWidth / controlsTextColumn2XDivider), static_cast<int>(screenHeight / controlsTextRow2YDivider), static_cast<int>(screenHeight / pauseTextFontSizeDivider), ORANGE);
			DrawText("Down = S", static_cast<int>(screenWidth / controlsTextColumn1XDivider), static_cast<int>(screenHeight / controlsTextRow3YDivider), static_cast<int>(screenHeight / pauseTextFontSizeDivider), ORANGE);
			DrawText("Down = Arrow-down", static_cast<int>(screenWidth / controlsTextColumn2XDivider), static_cast<int>(screenHeight / controlsTextRow3YDivider), static_cast<int>(screenHeight / pauseTextFontSizeDivider), ORANGE);
			DrawText("Gravity = Left ctrl", static_cast<int>(screenWidth / controlsTextColumn1XDivider), static_cast<int>(screenHeight / controlsTextRow4YDivider), static_cast<int>(screenHeight / pauseTextFontSizeDivider), ORANGE);
			DrawText("Gravity = Right ctrl", static_cast<int>(screenWidth / controlsTextColumn2XDivider), static_cast<int>(screenHeight / controlsTextRow4YDivider), static_cast<int>(screenHeight / pauseTextFontSizeDivider), ORANGE);
		}
		EndDrawing();
	}
}