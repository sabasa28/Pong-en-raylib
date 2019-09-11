#include <time.h>
#include "raylib.h"
#include <stdlib.h>
//CAMBIOS. REINICIAR LAS CANCIONES CADA VEZ, HACER QUE LOS POWERUP SPAWNEEN CON UN TIMER DE JUEGO Y NO DE EJECUCION
enum exist
{
	yeah,
	nope
}powerUPexists = nope; powerUP2exists = nope;

int main(void)
{
	// Initialization
	//---------------------------------------------------------
	const int screenWidth = 800;
	const int screenHeight = 450;
	int cronometro = (double)clock() / 1000;
	float cronometroflo = (double)clock() / 1000;
	srand(time(NULL));
	InitWindow(screenWidth, screenHeight, "PONG - un intento humilde");
	InitAudioDevice();
	Rectangle PowerUP1;
	Rectangle PowerUP2;
	PowerUP1.height = 30;
	PowerUP2.height = 30;
	PowerUP1.width = 30;
	PowerUP2.width = 30;
	PowerUP1.x = 400;
	PowerUP1.y = -10;
	PowerUP2.x = 400;
	PowerUP2.y = -10;
	Vector2 ballPosition = { GetScreenWidth() / 2, GetScreenHeight() / 2 };
	Vector2 ballSpeed = { 3.0f, 3.0f };
	float Paleta_speed = 2.5f;
	float Altura_paletas = 60.0f;
	float Ancho_paletas = 10.0f;
	int ballRadius = 10;
	Image raton = LoadImage("imagenes/white_mouse.png");
	Image raton2 = LoadImage("imagenes/gray_mouse.png");
	Image estambre = LoadImage("imagenes/estambre_rojo.png");
	Image barras = LoadImage("imagenes/cat_standing.png");
	Image lasercat = LoadImage("imagenes/fat cat staring.jpg");
	//ImageCrop(&lasercat, (Rectangle) { 100, 10, 280, 380 });
	ImageResize(&raton2, PowerUP2.width, PowerUP2.height);
	ImageResize(&raton, PowerUP1.width, PowerUP1.height);
	ImageResize(&barras, Ancho_paletas*4, Altura_paletas);
	ImageResize(&lasercat, screenWidth, screenHeight);
	ImageResize(&estambre, ballRadius * 4, ballRadius * 4);
	Texture2D texturaPowerUP2 = LoadTextureFromImage(raton2);
	Texture2D texturaPowerUP = LoadTextureFromImage(raton);
	Texture2D texturaFondo = LoadTextureFromImage(lasercat);
	Texture2D texturaBarra = LoadTextureFromImage(barras);
	Texture2D texturaBola = LoadTextureFromImage(estambre);
	UnloadImage(raton2);
	UnloadImage(raton);
	UnloadImage(estambre);
	UnloadImage(barras);
	UnloadImage(lasercat);
	Music gatitos = LoadMusicStream("sonidos/gatitos_song.ogg");
	Music metalNyan = LoadMusicStream("sonidos/nyanHype.ogg");
	Music nihaoNyan = LoadMusicStream("sonidos/NyanNyan_RockVersion.ogg");
	SetMusicVolume(metalNyan, 0.25);
	bool isColliding = false;
	bool isColliding2 = false;
	int lastPlayerHit = 1;
	int puntosP1 = 0;
	int puntosP2 = 0;
	int partidasGanadasP1 = 0;
	int partidasGanadasP2 = 0;
	int puntosTotales = 0;
	Rectangle P1;
	Rectangle P2;
	int powerGravityP1 = 3;
	int powerGravityP2 = 3;
	P1.height = Altura_paletas;
	P1.width = Ancho_paletas;
	P2.height = Altura_paletas;
	P2.width = Ancho_paletas;
	P1.x = GetScreenWidth() / 8 - 20;
	P1.y = GetScreenHeight() / 2;
	P2.x = GetScreenWidth() - GetScreenWidth() / 8 +20;
	P2.y = GetScreenHeight() / 2;
	Color P1color = RED;
	Color P2color = BLUE;
	Color BallColor = YELLOW;
	float FPS = 120;
	float StartigFPS = FPS;
	bool pause = 0;
	int framesCounter = 0;
	int winner = 1;
	bool restarted =false;
	bool menu = true;
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
	int heightColorButtons = 30;
	int widthColorButtons = 100;
	RedButton.width = widthColorButtons;
	RedButton.height = heightColorButtons;
	RedButton2.width = widthColorButtons;
	RedButton2.height = heightColorButtons;
	GreenButton.width = widthColorButtons;
	GreenButton.height = heightColorButtons;
	GreenButton2.width = widthColorButtons;
	GreenButton2.height = heightColorButtons;
	BlueButton.width = widthColorButtons;
	BlueButton.height = heightColorButtons;
	BlueButton2.width = widthColorButtons;
	BlueButton2.height = heightColorButtons;
	int yP1buttons = 350;
	int yP2buttons = 400;
	int xRedButtons = 250;
	int xGreenButtons = 350;
	int xBlueButtons = 450;
	RedButton.x = xRedButtons;
	RedButton.y = yP1buttons;
	RedButton2.x = xRedButtons;
	RedButton2.y = yP2buttons;
	GreenButton.x = xGreenButtons;
	GreenButton.y = yP1buttons;
	GreenButton2.x = xGreenButtons;
	GreenButton2.y = yP2buttons;
	BlueButton.x = xBlueButtons;
	BlueButton.y = yP1buttons;
	BlueButton2.x = xBlueButtons;
	BlueButton2.y = yP2buttons;
	int lastTimer = 0;
	int lastTimer2 = 0;
	bool invisible = false;
	float invisiTimer;
	
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
				if (puntosP1 >= 10)
				{
					winner = 1;
				}
				else if (puntosP2 >= 10)
				{
					winner = 2;
				}
				DrawText(TextFormat("PLAYER %i", winner), 180, 110, 50, BLACK);
				DrawText("WINS.", 450, 110, 50, BLACK);
				DrawText("Press 'R' to play again.", 80, 250, 30, BLACK);
				DrawText("Press 'M' to go to menu.", 80, 290, 30, BLACK);
				DrawText("Press 'ESC' to quit.", 80, 330, 30, BLACK);
				DrawText(TextFormat("Partidas ganadas P1: %i", partidasGanadasP1), 500, 330, 20, P1color);
				DrawText(TextFormat("Partidas ganadas P2: %i", partidasGanadasP2), 500, 360, 20, P2color);
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
				partidasGanadasP1 = 0;
				partidasGanadasP2 = 0;
				DrawRectangle(PlayButton.x,PlayButton.y,PlayButton.width,PlayButton.height,BLUE);
				DrawRectangle(ExitButton.x, ExitButton.y, ExitButton.width, ExitButton.height, RED);
				DrawRectangle(RedButton.x, RedButton.y, RedButton.width, RedButton.height, RED);
				DrawRectangle(RedButton2.x, RedButton2.y, RedButton2.width, RedButton2.height, RED);
				DrawRectangle(GreenButton.x, GreenButton.y, GreenButton.width, GreenButton.height, GREEN);
				DrawRectangle(GreenButton2.x, GreenButton2.y, GreenButton2.width, GreenButton2.height, GREEN);
				DrawRectangle(BlueButton.x, BlueButton.y, BlueButton.width, BlueButton.height, BLUE);
				DrawRectangle(BlueButton2.x, BlueButton2.y, BlueButton2.width, BlueButton2.height, BLUE);
				DrawText("P1 color:", 80, yP1buttons, 35, BLACK);
				DrawText("P2 color:", 75, yP2buttons, 35, BLACK);
				DrawText("Play", 300, 130, 80, BLACK);
				DrawText("Exit", 330, 260, 50, BLACK);
				restarted = true;
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), RedButton))
				{
					RedButton.y = yP1buttons - 10;
					BlueButton.y = yP1buttons;
					GreenButton.y = yP1buttons;
					P1color = RED;
				}
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), GreenButton))
				{
					RedButton.y = yP1buttons;
					BlueButton.y = yP1buttons;
					GreenButton.y = yP1buttons - 10;
					P1color = GREEN;
				}
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), BlueButton))
				{
					RedButton.y = yP1buttons;
					BlueButton.y = yP1buttons - 10;
					GreenButton.y = yP1buttons;
					P1color = BLUE;
				}
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), RedButton2))
				{
					RedButton2.y = yP2buttons - 10;
					BlueButton2.y = yP2buttons;
					GreenButton2.y = yP2buttons;
					P2color = RED;
				}
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), GreenButton2))
				{
					RedButton2.y = yP2buttons;
					BlueButton2.y = yP2buttons;
					GreenButton2.y = yP2buttons - 10;
					P2color = GREEN;
				}
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), BlueButton2))
				{
					RedButton2.y = yP2buttons;
					BlueButton2.y = yP2buttons - 10;
					GreenButton2.y = yP2buttons;
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
		isColliding = false;
		isColliding2 = false;
		puntosP1 = 0;
		puntosP2 = 0;
		puntosTotales = 0;
		P1.x = GetScreenWidth() / 8 -20;
		P1.y = GetScreenHeight() / 2;
		P2.x = GetScreenWidth() - GetScreenWidth() / 8 + 20;
		P2.y = GetScreenHeight() / 2;
		FPS = 120;
		StartigFPS = FPS;
		pause = true;
		framesCounter = 0;
		powerGravityP1 = 3;
		powerGravityP2 = 3;
		SetTargetFPS(FPS);
		PlayMusicStream(nihaoNyan);
		while (!WindowShouldClose())   // Detect window close button or ESC key
		{
			UpdateMusicStream(nihaoNyan);
			DrawTexture(texturaFondo, 0, 0, WHITE);
			cronometro = (double)clock() / 1000;
			cronometroflo = (double)clock() / 1000;
			if (puntosP1 >= 10)
			{
				partidasGanadasP1 += 1;
				break;
			}
			if (puntosP2 >= 10)
			{
				partidasGanadasP2 += 1;
				break;
			}
			// Update
			//-----------------------------------------------------
			if (IsKeyPressed(KEY_SPACE)) pause = !pause;
			if (!pause)
			{
				if (CheckCollisionCircleRec(ballPosition,ballRadius,PowerUP1)&&powerUPexists==yeah)
				{
					PowerUP1.y = -10;
					if (lastPlayerHit==1)
					{
						powerGravityP1 += 1;
					}
					if (lastPlayerHit==2)
					{
						powerGravityP2 += 1;
					}
					powerUPexists = nope;
				}
				if (CheckCollisionCircleRec(ballPosition, ballRadius, PowerUP2) && powerUP2exists == yeah)
				{
					PowerUP2.y = -10;
					invisible = true;
					invisiTimer = cronometroflo;
					
					powerUP2exists = nope;
				}
				if(IsKeyPressed(KEY_LEFT_CONTROL)&&powerGravityP1>0)
				{
					ballSpeed.y *= -1.0f;
					powerGravityP1 -= 1;
				}
				if (IsKeyPressed(KEY_RIGHT_CONTROL)&&powerGravityP2>0)
				{
					ballSpeed.y *= -1.0f;
					powerGravityP2 -= 1;
				}

				if (ballPosition.x + ballRadius >= GetScreenWidth())
				{
					ballPosition.x = GetScreenWidth()- GetScreenWidth() / 8 ;
					ballPosition.y = GetScreenHeight() / 2;
					puntosP1 += 1;
					puntosTotales += 1;
					SetTargetFPS(120 + puntosTotales * 5);
					isColliding2 = true;
					isColliding = true;
					BallColor = P2color;
					lastPlayerHit = 2;
				}
				if (ballPosition.x - ballRadius == 0)
				{
					ballPosition.x = GetScreenWidth() / 8;
					ballPosition.y = GetScreenHeight() / 2;
					puntosP2 += 1;
					puntosTotales += 1;
					SetTargetFPS(120 + puntosTotales * 2.5);
					isColliding = true;
					isColliding2 = true;
					BallColor = P1color;
					lastPlayerHit = 1;
				}

				if (IsKeyDown('W') && P1.y > 0) P1.y -= Paleta_speed;
				if (IsKeyDown('S') && P1.y + P1.height < GetScreenHeight()) P1.y += Paleta_speed;
				if (IsKeyDown(KEY_UP) && P2.y > 0) P2.y -= Paleta_speed;
				if (IsKeyDown(KEY_DOWN) && P2.y + P2.height < GetScreenHeight()) P2.y += Paleta_speed;
				ballPosition.x += ballSpeed.x;
				ballPosition.y += ballSpeed.y;
				if (!CheckCollisionCircleRec(ballPosition, ballRadius, P1))
				{
					isColliding = false;
				}
				if (CheckCollisionCircleRec(ballPosition, ballRadius, P1) && isColliding == false) {
					isColliding = true;
					if (ballPosition.y < P1.y + P1.height / 2)
					{
						if (ballSpeed.y > 0)
						{
							ballSpeed.y *= -1.0f;
						}
						if (ballSpeed.y < 0)
						{
							//no pasa nada
						}
					}
					if (ballPosition.y > P1.y + P1.height / 2)
					{
						if (ballSpeed.y > 0)
						{
							//no pasa nada
						}
						if (ballSpeed.y < 0)
						{
							ballSpeed.y *= -1.0f;
						}
					}
					ballSpeed.x *= -1.0f;
					BallColor = P1color;
					lastPlayerHit = 1;
				}
				if (!CheckCollisionCircleRec(ballPosition, ballRadius, P2))
				{
					isColliding2 = false;
				}
				if (CheckCollisionCircleRec(ballPosition, ballRadius, P2) && isColliding2 == false) {
					isColliding2 = true;
					if (ballPosition.y < P2.y + P2.height / 2)
					{
						if (ballSpeed.y > 0)
						{
							ballSpeed.y *= -1.0f;
						}
						if (ballSpeed.y < 0)
						{
							//no pasa nada
						}
					}
					if (ballPosition.y > P2.y + P2.height / 2)
					{
						if (ballSpeed.y > 0)
						{
							//no pasa nada
						}
						if (ballSpeed.y < 0)
						{
							ballSpeed.y *= -1.0f;
						}
					}
					ballSpeed.x *= -1.0f;
					BallColor = P2color;
					lastPlayerHit = 2;
				}
				// Check walls collision for bouncing
				if ((ballPosition.x >= (GetScreenWidth() - ballRadius)) || (ballPosition.x <= ballRadius)) ballSpeed.x *= -1.0f;
				if ((ballPosition.y >= (GetScreenHeight() - ballRadius)) || (ballPosition.y <= ballRadius)) ballSpeed.y *= -1.0f;
			}
			else framesCounter++;
			//-----------------------------------------------------

			// Draw
			//-----------------------------------------------------
			BeginDrawing();

			ClearBackground(RAYWHITE);
			if (invisible==false)
			{
				DrawTexture(texturaBola, ballPosition.x - 27, ballPosition.y - 17, BallColor);
			}
			if (invisible==true&&cronometroflo>=invisiTimer+0.75)
			{
				invisible = false;
			}
			//DrawCircleV(ballPosition, ballRadius, BallColor);
			//DrawRectangle(P1.x, P1.y, P1.width, P1.height, P1color);
			//DrawRectangle(P2.x, P2.y, P2.width, P2.height, P2color);
			DrawTexture(texturaBarra, P2.x - 18, P2.y, P2color);
			DrawTexture(texturaBarra, P1.x - 18, P1.y, P1color);
			//DrawText("PRESS SPACE to PAUSE BALL MOVEMENT", 10, GetScreenHeight() - 25, 20, LIGHTGRAY);
			if (powerGravityP1 > 0)DrawCircle(70, 20, 5, BLACK);
			if (powerGravityP1 > 1)DrawCircle(85, 20, 5, BLACK);
			if (powerGravityP1 > 2)DrawCircle(100, 20, 5, BLACK);
			if (powerGravityP1 > 3)DrawCircle(115, 20, 5, BLACK);
			if (powerGravityP1 > 4)DrawCircle(130, 20, 5, BLACK);
			if (powerGravityP2 > 0)DrawCircle(655, 20, 5, BLACK);
			if (powerGravityP2 > 1)DrawCircle(670, 20, 5, BLACK);
			if (powerGravityP2 > 2)DrawCircle(685, 20, 5, BLACK);
			if (powerGravityP2 > 3)DrawCircle(700, 20, 5, BLACK);
			if (powerGravityP2 > 4)DrawCircle(715, 20, 5, BLACK);

			/*if (cronometro%10==0&&cronometro>0&&powerUPexists==nope)
			{
				PowerUP1.y = rand() % GetScreenHeight() + 1;
				powerUPexists = yes;
				lastTimer = cronometro;
			}*/
			if (cronometro >= lastTimer + 15)
			{
				PowerUP1.y = rand() % (GetScreenHeight() - 40) + 20;
				powerUPexists = yeah;
				lastTimer = cronometro;
			}
			if (cronometro >= lastTimer2 + 15)
			{
				PowerUP2.y = rand() % (GetScreenHeight() - 40) + 20;
				powerUP2exists = yeah;
				lastTimer2 = cronometro;
			}
			if (powerUPexists==yeah)
			{
				//DrawRectangle(400, PowerUP1.y, PowerUP1.width, PowerUP1.height, YELLOW);
				DrawTexture(texturaPowerUP, PowerUP1.x, PowerUP1.y, WHITE);
			}
			if (powerUP2exists == yeah)
			{
				//DrawRectangle(400, PowerUP2.y, PowerUP2.width, PowerUP2.height, YELLOW);
				DrawTexture(texturaPowerUP2, PowerUP2.x, PowerUP2.y, PINK);
			}

			DrawText(TextFormat("P1: %i", puntosP1), 10, 10, 20, P1color);
			DrawText(TextFormat("P2: %i", puntosP2), GetScreenWidth() - 70, 10, 20, P2color);
			// On pause, we draw a blinking message
			if (pause && ((framesCounter / 30) % 4)) DrawText("PRESS SPACE TO PLAY", 230, 200, 30, BLACK);

			EndDrawing();
			//-----------------------------------------------------
		}
		StopMusicStream(nihaoNyan);
	}
	// De-Initialization
	//---------------------------------------------------------
	UnloadTexture(texturaBola);
	UnloadTexture(texturaFondo);
	UnloadTexture(texturaBarra);
	UnloadMusicStream(gatitos);
	UnloadMusicStream(metalNyan);
	CloseAudioDevice();
	CloseWindow();        // Close window and OpenGL context
	//----------------------------------------------------------
	
	return 0;
}