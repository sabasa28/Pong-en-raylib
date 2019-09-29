#ifndef GAMEPLAY_H
#define GAMEPLAY_H
enum Gamemode {
	vsPlayer,
	vsBot
};
extern Gamemode gamemode;
namespace catPong {
	void updateGameplay();
	void drawGameplay();
}
#endif // GAMEPLAY_H