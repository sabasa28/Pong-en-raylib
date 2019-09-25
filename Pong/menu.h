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
//extern int coloredbuttonsHeightDivider;
//extern int coloredbuttonsWidthDivider;
//extern int p1ColoredButtonsYDivider;
//extern int p2ColoredButtonsYDivider;
//extern int redButtonsXDivider;
//extern int greenButtonsXDivider;
//extern int blueButtonsXDivider;
namespace catPong {
	void initMenu();
	void updateMenu();
	void drawMenu();
}
#endif // MENU_H