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
extern float ballTexOffsetXDivider;
extern float ballTexOffsetYDivider;
extern float speedMultiplier;
extern float boost;
extern bool colliding;
extern bool colliding2;
extern float leftResetPos;
extern float rightResetPos;

namespace catPong {
	void initBall();
	void initBallTex();
}
#endif // BALL_H