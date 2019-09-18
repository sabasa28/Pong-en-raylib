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