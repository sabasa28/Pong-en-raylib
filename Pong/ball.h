#include "raylib.h"
extern Vector2 ballPosition;
extern Vector2 ballSpeed;
extern int ball_radius;
extern Color BallColor;
extern Image worsted;
extern Texture2D texturaBola;
extern bool colliding;
extern bool colliding2;
extern int lastPlayerHit;
extern bool invisible;
extern float invisibility_timer;
void initBall();
void initBallTex();