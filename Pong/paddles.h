#include "raylib.h"

struct Player
{
	float speed = 300.0f;
	int points = 0;
	int wonMatches = 0;
	int gravityPills = 3;
	Color color;
	Rectangle bar;
	Texture textura;
};
extern Player player1;
extern Player player2;
extern float paddle_height;
extern float paddle_width;
extern Image standing_cat;
extern int winner;
extern int total_points;
extern int winning_points;
namespace sabasa {
	extern void initPaddle();
	extern void initPaddleTex();
}