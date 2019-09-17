#include "raylib.h"
#include "background.h"

Image cat_staring;
Texture2D texturaFondo;

void initBackground() {
	cat_staring = LoadImage("imagenes/fat cat staring.jpg");
	ImageResize(&cat_staring, GetScreenWidth(), GetScreenHeight());
	texturaFondo = LoadTextureFromImage(cat_staring);
	UnloadImage(cat_staring);
}