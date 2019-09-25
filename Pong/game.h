enum State {
	Menu,
	Gameplay,
	EndScreen,
	Close
};
extern State gamestate;
namespace sabasa {
	void executeGame();
}