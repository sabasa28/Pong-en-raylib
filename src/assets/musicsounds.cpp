#include "musicSounds.h"

#include "raylib.h"

Music menuSong;
Music gameSong;
static Wave kittenMeowWav;
static Wave catMeowWav;
Sound kittenMeow;
Sound catMeow;


namespace catPong {
	void initMusicSounds() {
		menuSong = LoadMusicStream("assets/sonidos/menus_song.ogg");
		gameSong = LoadMusicStream("assets/sonidos/game_song.ogg");	
		kittenMeowWav = LoadWave("assets/sonidos/kitten_meow.wav");		
		catMeowWav = LoadWave("assets/sonidos/cat_meow.wav");				
		kittenMeow = LoadSoundFromWave(kittenMeowWav);				
		catMeow = LoadSoundFromWave(catMeowWav);					
		UnloadWave(kittenMeowWav);									
		UnloadWave(catMeowWav);										
		SetMusicVolume(gameSong, 0.25f);							
		SetSoundVolume(kittenMeow, 0.5f);
		SetSoundVolume(catMeow, 0.2f);
	}
}
