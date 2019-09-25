#include "background.h"

#include "raylib.h"

#include "console.h"
Image cat_staring;
Texture2D texturaFondo;
namespace catPong {
	void initBackground() {
		cat_staring = LoadImage("imagenes/fat cat staring.jpg");
		ImageResize(&cat_staring, screenWidth, screenHeight);
		texturaFondo = LoadTextureFromImage(cat_staring);
		UnloadImage(cat_staring);
	}
}