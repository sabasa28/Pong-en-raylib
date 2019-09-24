enum State {
	Menu,
	Gameplay,
	EndScreen,
	Close
};
extern State gamestate;
void executeGame();