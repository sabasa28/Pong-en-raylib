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
extern Rectangle VsBotButton;
extern Rectangle VsPlayerButton;
extern Rectangle ScreenSize1Button;
extern Rectangle ScreenSize2Button;
extern Rectangle ScreenSize3Button;

enum ScreenSizeSelected{
	x800y450,
	x1200y675,
	fullscreen,
	none
};
enum ColorSelected{
	Red,
	Green,
	Blue
};

namespace catPong {
	void initMenu();
	void updateMenu();
	void drawMenu();
}
#endif // MENU_H