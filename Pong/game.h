enum state {
	Menu,
	Gameplay,
	EndScreen,
	Close
}; //ESTO SEGURO ESTA MAL :(
extern state gamestate;//cuando todo este en game.cpp va a ser innecesaria esta linea
void initGeneral();