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
extern int coloredbuttons_height;
extern int coloredbuttons_width;
extern int P1_colored_buttons_y;
extern int P2_colored_buttons_y;
extern int red_buttons_x;
extern int green_buttons_x;
extern int blue_buttons_x;
namespace catPong {
	void initMenu();
	void updateMenu();
	void drawMenu();
}
#endif // MENU_H