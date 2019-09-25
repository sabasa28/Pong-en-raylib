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
extern bool colliding;
extern bool colliding2;
namespace sabasa {
	void initBall();
	void initBallTex();
}