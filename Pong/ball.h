#ifndef BALL_H
#define BALL_H
#include "raylib.h"

struct Ball {
	Vector2 position;
	Vector2 speed;
	int radius;
	Color color;
	int lastPlayerHit=1;
	bool invisibility = false;
	float invisibilityTimer = 0;
};

extern Ball ball;
extern Image worsted;
extern Texture2D ballTexture;
extern float leftResetPos;
extern float rightResetPos;
extern float speedMultiplier;
extern float boost;
extern float ballTexOffsetXDivider;
extern float ballTexOffsetYDivider;
extern float BallSpeed1XDivider;
extern float BallSpeed1YDivider;
extern float BallSpeed2XDivider;
extern float BallSpeed2YDivider;
extern float BallSpeed3XDivider;
extern float BallSpeed3YDivider;

namespace catPong {
	void initBall();
	void initBallTex();
}
#endif // BALL_H