#include "musicSounds.h"

#include "raylib.h"

Music gatitos;
Music metalNyan;
Music nihaoNyan;

void initMusicSounds() {
	gatitos = LoadMusicStream("sonidos/gatitos_song.ogg");
	metalNyan = LoadMusicStream("sonidos/nyanHype.ogg");
	nihaoNyan = LoadMusicStream("sonidos/NyanNyan_RockVersion.ogg");
	SetMusicVolume(metalNyan, 0.25);
}
