#include "raylib.h"
#include "menu.h"

Rectangle PlayButton;
Rectangle ExitButton;
Rectangle RedButton;
Rectangle GreenButton;
Rectangle BlueButton;
Rectangle RedButton2;
Rectangle GreenButton2;
Rectangle BlueButton2;
int coloredbuttons_height = 30;
int coloredbuttons_width = 100;
int P1_colored_buttons_y = 350;
int P2_colored_buttons_y = 400;
int red_buttons_x = 250;
int green_buttons_x = 350;
int blue_buttons_x = 450;

void initMenu() {
	PlayButton.x = 180;
	PlayButton.y = 120;
	PlayButton.width = 400;
	PlayButton.height = 100;
	ExitButton.x = 230;
	ExitButton.y = 240;
	ExitButton.width = 300;
	ExitButton.height = 80;
	RedButton.width = coloredbuttons_width;
	RedButton.height = coloredbuttons_height;
	RedButton2.width = coloredbuttons_width;
	RedButton2.height = coloredbuttons_height;
	GreenButton.width = coloredbuttons_width;
	GreenButton.height = coloredbuttons_height;
	GreenButton2.width = coloredbuttons_width;
	GreenButton2.height = coloredbuttons_height;
	BlueButton.width = coloredbuttons_width;
	BlueButton.height = coloredbuttons_height;
	BlueButton2.width = coloredbuttons_width;
	BlueButton2.height = coloredbuttons_height;
	RedButton.x = red_buttons_x;
	RedButton.y = P1_colored_buttons_y;
	RedButton2.x = red_buttons_x;
	RedButton2.y = P2_colored_buttons_y;
	GreenButton.x = green_buttons_x;
	GreenButton.y = P1_colored_buttons_y;
	GreenButton2.x = green_buttons_x;
	GreenButton2.y = P2_colored_buttons_y;
	BlueButton.x = blue_buttons_x;
	BlueButton.y = P1_colored_buttons_y;
	BlueButton2.x = blue_buttons_x;
	BlueButton2.y = P2_colored_buttons_y;
}