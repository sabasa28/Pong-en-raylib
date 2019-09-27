#ifndef MENU_H
#define MENU_H
#include "raylib.h"
extern Rectangle PlayButton;
extern Rectangle ExitButton;
extern Rectangle RedButton;
extern Rectangle GreenButton;
extern Rectangle BlueButton;
extern Rectangle RedButton2;
extern Rectangle GreenButton2;
extern Rectangle BlueButton2;

namespace catPong {
	void initMenu();
	void updateMenu();
	void drawMenu();
}
#endif // MENU_H