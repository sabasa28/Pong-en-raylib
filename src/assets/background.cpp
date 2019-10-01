#include "background.h"

#include "raylib.h"

#include "general/console.h"
Image backgroundCats;
Texture2D texturaFondo;
namespace catPong{
	void initBackground(){
		backgroundCats = LoadImage("assets/imagenes/fondo_gatos_original.png");
		ImageResize(&backgroundCats, screenWidth, screenHeight);
		texturaFondo = LoadTextureFromImage(backgroundCats);
		UnloadImage(backgroundCats);
	}
}