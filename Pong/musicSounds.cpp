#include "musicSounds.h"

#include "raylib.h"

Music gatitos;
Music metalNyan;
Music nihaoNyan;
static Wave kittenMeowWav;
static Wave catMeowWav;
Sound kittenMeow;
Sound catMeow;


namespace catPong {
	void initMusicSounds() {
		gatitos = LoadMusicStream("sonidos/gatitos_song.ogg");
		metalNyan = LoadMusicStream("sonidos/nyanHype.ogg");
		nihaoNyan = LoadMusicStream("sonidos/NyanNyan_RockVersion.ogg");
		kittenMeowWav = LoadWave("sonidos/kitten_meow.wav");
		catMeowWav = LoadWave("sonidos/cat_meow.wav");
		kittenMeow = LoadSoundFromWave(kittenMeowWav);
		catMeow = LoadSoundFromWave(catMeowWav);
		UnloadWave(kittenMeowWav);
		UnloadWave(catMeowWav);
		SetMusicVolume(metalNyan, 0.25f);
		SetSoundVolume(kittenMeow, 1.0f);
		SetSoundVolume(catMeow, 0.3f);
	}
}
