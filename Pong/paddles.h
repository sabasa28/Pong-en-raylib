#ifndef PADDLES_H
#define PADDLES_H
#include "raylib.h"

struct Player
{
	float speed;
	int points = 0;
	int wonMatches = 0;
	int gravityPills = 3;
	Color color = GRAY;
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
extern float paddleTexOffsetXDivider;
namespace catPong {
	extern void initPaddles();
	extern void initPaddleTex();
}
#endif // PADDLES_H