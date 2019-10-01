#ifndef GAME_H
#define GAME_H
enum State {
	Menu,
	Gameplay,
	EndScreen,
	Close
};
extern State gamestate;
namespace catPong {
	void executeGame();
}
#endif // GAME_H